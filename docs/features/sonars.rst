======
Sonars
======
RoverWing provides connections for three ultrasonic distance sensors (HC-SR04 or
compatible). These sonar sensors are very popular with hobby robot builders due
to their low price  (about $2.50/piece) and reliability. Note that these sonars
use 5V power, so they can not be directly connected to 3.3V boards such as
Adafruit Feather boards. RoverWing solves this problem by  including a voltage
level shifter  chip (TX1004EWR).

The sonars ports use JST PH4 connectors; see :ref:`cables` section  
for advice on choosing connector cables. The pin order is as follows:

* GND (closest to board edge)
* 5V
* Trig
* Echo
