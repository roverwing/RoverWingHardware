#include <Wire.h>
#include <RoverWing.h>



Rover r; //this is the name of the rover!
float v = 0; //voltage
bool blink = false;
float servoPos[] = {0.0f, 0.0f, 0.0f, 0.0f};
#define ENCODERCPR 1220 //encoder counts per revolution (of motor output shaft). Set to 0 if not using encoders
#define NOLOADRPM 160 //motor no-load RPM
#define TARGETSPEED 100 //target motr speed, in RPM
float speed = TARGETSPEED; //target motor speed in RPM
motorconfig_t myMotor; //to hold configuration data for the motor

float yaw, pitch, roll;
bool needCalibration = false;

bool Testing = true;
bool analogpass;
bool servopass;
bool motorpass;
bool sonarpass;
bool imupass;
bool neopass;
bool Pass;
bool Fail;
bool sonartemp;
float analogconstant = 3.23;
int sonarconstant[] = {65, 90, 37};
bool done = false;

void setup() {
  r.setPixelCount(1);
  r.setPixelBrightness(255);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  Wire.begin();
  Wire.setClock(400000); //use fast mode (400 kHz)
  Serial.begin(9600); //debugging terminal
  delay(1000); //wait for 1 second, so that roverwing initializes
  //activates RoverWing and prints basic info to Serial
  Serial.println("Hello");
  r.beginVerbose();

  r.IMUbegin();
  delay(500);
  if (! r.IMUisActive() ) {
    Serial.println("IMU not found!");
    return;
  }

  myMotor.encoderCPR = ENCODERCPR;   // encoder counts per revolution of output shaft
  myMotor.noloadRPM = NOLOADRPM;
  float maxspeed = myMotor.encoderCPR * myMotor.noloadRPM / 60.0; //max speed in encoder counts/s
  myMotor.Kp = 0.8 / maxspeed; //suggested proportional  gain. If the motor is too slow to achieve desired speed, increase; if the motor starts oscillating, decrease.
  myMotor.Ti = 0.5;         // time constant for integral gain, in seconds
  myMotor.Td = 0.0;         // time constant for differential gain, in seconds. to disable differential term, make Td=0
  myMotor.iLim = 0.2 * myMotor.Ti / myMotor.Kp;
  // limit on integral error; this value guarantees that integral term will be at most 0.2*maxspeed
  // to disable integral limit, make iLim negative e.g. -1.0
  //finally, configure the motors
  r.configureMotor(MOTOR1, myMotor);
  r.configureMotor(MOTOR2, myMotor);

  r.setServoRange(SERVO1, 900, 2100); //this is  the range for HiTec servos,
  r.setServoRange(SERVO2, 900, 2100); //see https://hitecrcd.com/faqs/servos/general-servos
  r.setServoRange(SERVO3, 900, 2100);
  r.setServoRange(SERVO4, 900, 2100);
  r.setAllServo(servoPos);

  r.activateSonars(SONAR1 + SONAR2 + SONAR3, 3000);
}

void loop() {

  r.stopMotors();
  r.resetAllEncoder();
  if (Testing == true) {
    r.setPixelColor(1, BLUE);
    delay(500);
    v = r.getVoltage();
    Serial.print("Voltage: "); Serial.println(v);

    //get and print analog inputs

    r.getAllAnalog(); //fetches values from RoverBoard and saves them in r.analog[] array
    Serial.print("Analog inputs Test:");
    for (int i = 1; i <= 6; i++) {
      Serial.print("  ");
      Serial.print(r.analog[i]); //note that index i runs 1..6, not 0..5 !
      // values of analog[i] are floats, representing
      // the voltage; they range 0 - 3.3 volts
      if (abs(r.analog[i] - 3.23) <= .02) {
        analogpass = true;
        digitalWrite(13, HIGH);
        r.setPixelColor(1, WHITE);
        delay(500);
      }
      else {
        analogpass = false;
        Fail = true;
        Pass = false;
        digitalWrite(13, LOW);
        digitalWrite(5, HIGH);
        r.setPixelColor(1, RED);
        delay(2000);
      }
    }
    Serial.println("Analog test done");
    r.setPixelColor(1, BLUE);
    delay(500);
    Serial.println("Servo Test:");
    for (int i = 0; i < 4; i++) {
      servoPos[i] = 1;
    }
    delay(1000);
    r.setAllServo(servoPos);
    for (int i = 0; i < 4; i++) {
      servoPos[i] = 0;
    }
    delay(1000);
    r.setAllServo(servoPos);
    if (true) {
      servopass = true;
      digitalWrite(12, HIGH);
      r.setPixelColor(1, WHITE);
      delay(500);
    }
    Serial.println("Servo Test done:");
    r.setPixelColor(1, BLUE);
    delay(500);



    Serial.println("IMU Test:");


    Serial.print("Yaw: "); Serial. print(r.getYaw());  Serial.print(" ");
    Serial.print("Pitch: "); Serial. print(r.getPitch());  Serial.print(" ");
    Serial.print("Roll: "); Serial. print(r.getRoll());  Serial.println(" ");

    if (r.getYaw() < 5 && r.getPitch() < 5  && r.getPitch() < 5 ) {
      imupass = true;
      digitalWrite(11, HIGH);
      r.setPixelColor(1, WHITE);
      delay(500);
    }
    else {
      imupass = false;
      Fail = true;
      Pass = false;
      digitalWrite(11, LOW);
      digitalWrite(5, HIGH);
      r.setPixelColor(1, RED);
      delay(500);
    }

    Serial.println("IMU Test done:");
    r.setPixelColor(1, BLUE);
    delay(500);
    Serial.println("Motor Test:");

    Serial.print("Yaw: "); Serial. print(r.getYaw());  Serial.print(" ");
    Serial.print("Pitch: "); Serial. print(r.getPitch());  Serial.print(" ");
    Serial.print("Roll: "); Serial. print(r.getRoll());  Serial.println(" ");
    bool motorpasstemp = true;
    float yaw1 = r.getYaw();
    int motortesttimer = millis();
    while (r.getPosition(MOTOR1) < 10) {
      r.setMotorPwr(MOTOR1, 1.0);
      Serial.println(r.getPosition(MOTOR1));
    }
    if (millis() - motortesttimer >=  10000) {
      motorpasstemp = false;
    }
    r.setMotorPwr(MOTOR1, 0);
    float yaw2 = r.getYaw();
    motortesttimer = millis();
    while (r.getPosition(MOTOR1) > 0) {
      r.setMotorPwr(MOTOR1, -1.0);
      Serial.println(r.getPosition(MOTOR1));
    }
    if (millis() - motortesttimer >=  10000) {
      motorpasstemp = false;
    }
    motortesttimer = millis();
    r.setMotorPwr(MOTOR1, 0);
    float yaw3 = r.getYaw();
    delay(1000);
    float roll_1 = r.getRoll();
    while (r.getPosition(MOTOR2) < 10) {
      r.setMotorPwr(MOTOR2, 1.0);
      Serial.println(r.getPosition(MOTOR2));
    }
    if (millis() - motortesttimer >=  10000) {
      motorpasstemp = false;
    }
    motortesttimer = millis();
    r.setMotorPwr(MOTOR2, 0);
    float roll_2 = r.getRoll();
    while (r.getPosition(MOTOR2) > 0) {
      r.setMotorPwr(MOTOR2, -1.0);
      Serial.println(r.getPosition(MOTOR2));
    }
    if (millis() - motortesttimer >=  10000) {
      motorpasstemp = false;
    }
    r.setMotorPwr(MOTOR2, 0);

    if (motorpasstemp == true) {
      motorpass = true;
      digitalWrite(10, HIGH);
      r.setPixelColor(1, WHITE);
      delay(500);
    }
    else {
      motorpass = false;
      Fail = true;
      Pass = false;
      digitalWrite(10, LOW);
      digitalWrite(5, HIGH);
      r.setPixelColor(1, RED);
      delay(500);
    }
    Serial.println("Motor Test done:");

    r.setPixelColor(1, BLUE);
    delay(500);

    Serial.println("Sonar Test:");
    r.getAllSonar(); //fetches values from RoverWing and saves them in r.sonar[] array
    Serial.print("Sonar readings (mm): ");
    for (int i = 0; i < 3; i++) {
      Serial.print("  ");
      Serial.print(r.sonar[i]); // values of sonar[i] are floats, representing
      if (abs(r.sonar[i] - (float)sonarconstant[i]) < 10 && i != 2) {
        sonartemp = true;
      }
      else if (i == 2 && abs(r.sonar[i] - (float)sonarconstant[i]) >= 10) {
        sonartemp = true;
      }
      else {
        sonartemp = false;
        r.setPixelColor(1, RED);
        delay(500);
      }
    }
    if (sonartemp == true) {
      sonarpass = true;
      digitalWrite(9, HIGH);
      r.setPixelColor(1, WHITE);
      delay(500);
    }
    else {
      sonarpass = false;
      Fail = true;
      Pass = false;
      digitalWrite(9, LOW);
      digitalWrite(5, HIGH);
      r.setPixelColor(1, RED);
      delay(500);
    }
    r.setPixelColor(1, BLUE);
    delay(500);

    Serial.println("Sonar Test done:");


    r.setPixelColor(1, RED);
    delay(500);
    r.setPixelColor(1, GREEN);
    delay(500);
    r.setPixelColor(1, BLUE);
    delay(500);
    r.setPixelColor(1, WHITE);
    delay(500);
    r.setPixelColor(1, YELLOW);
    delay(500);
    neopass = true;
    digitalWrite(6, HIGH);


    digitalWrite(LED_BUILTIN, blink);
    blink = !blink;

    Testing = false;
  }
  if (Testing == false && done != true) {
    if (Fail == true) {
      r.setPixelColor(1, RED);
      digitalWrite(5, HIGH);
    }
    else {
      r.setPixelColor(1, GREEN);
    }
    Serial.print("ANALOG: ");
    Serial.println(analogpass);
    Serial.print("SERVO: ");
    Serial.println(servopass);
    Serial.print("MOTOR: ");
    Serial.println(motorpass);
    Serial.print("SONAR: ");
    Serial.println(sonarpass);
    Serial.print("IMU: ");
    Serial.println(imupass);
    Serial.print("NEO: ");
    Serial.println(neopass);
    done = true;
  }
}

//analogpass = null;
//servopass = null;
//motorpass = null;
//sonarpass = null;
//imupass = null;
//neopass = null;
//Pass = null;
//Fail = null;
