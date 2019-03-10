
*******************
RoverWing: Hardware
*******************


Introduction
============
RoverWing is a  shield (or "wing", following Adafruit's terminology) for Adafruit's [Feather boards](https://www.adafruit.com/feather).
This wing provides motor drivers, Inertial Motion Unit (IMU), and connection ports for servos, sonars, GPS,
and other peripherals commonly used by mobile robots. It also contains a microcontroller preloaded with firmware
to control these peripherals, which communicates with the Feather board using I2C protocol, thus freeing resources
of the Feather board for other purposes.

The RoverWing was heavily influenced by Adafruit's [CRICKIT] (https://www.adafruit.com/crickit) board
(in particular, it has exact same dimensions and  mounting holes as the CRICKIT board). However, unlike CRICKIT,
it is intended for use with more powerful 6-12V motors and provides a slightly different set of peripherals.

Below is the list of key features of the RoverWing:

* Can be powered by 7-14V power source; contains a voltage regulator providing power to the Feather board

* Only uses 2 pins (SDA and SCL) of the Feather board.

* Contains on-board microcontroller, which takes care of low-level operations such as counting motor encoder pulses, using preloaded firmware

* Contains on-board 6DOF  Inertial Motion Unit (IMU), based on MPU6050 chip, which can be used for tracking robot orientation in space

* Provides the hardware and firmware support for connecting the following external peripherals

  - Motors: two brushed DC motors, at up to 2.9A at 14V per motor
  - Quadrature encoders for each motor
  - Sonars: support for three HC-SR04 or compatible ultrasonic sensors (sonars)
  - Servos: four servos (5V) (see note on power limit below)
  - Six analog inputs (3.3V)
  - Neopixel smart LED (see note on power limit below)
  - GPS and magnetometer (compass) sensors
  - two additional I2C sensors

The RoverWing uses same connectors for power supply, motors, encoders, and I2C
sensors as the [REV Robotics Expansion hub]
(http://www.revrobotics.com/rev-31-1153)  used in [First Tech Challenge]
(https://www.firstinspires.org/robotics/ftc)  robotics competition, so it can
be easily used with the same motors and sensors.

The sections below discuss these features in detail.

![alt text](https://raw.githubusercontent.com/roverwing/RoverWingHardware/master/MainView.jpg)
   RoverWing (without the Feather), top view.

Power
=====

The board can be powered by a 7-14V DC power supply such as 2 or 3 cell LiPO
battery or  a 10-cell NiMH battery. The battery port uses JST VH male connector.
We recommend using 18 AWG or larger cables for power supply;  see section
`Cables`_ for list of compatible cables and adapters. There is also a power
indicator LED next to the power connector. Note that the RoverWing **can not be
powered via USB cable**.

.. Warning::
   The VH connectors are polarized, so they can only be plugged in one way.
   Because of this, there  is no reverse  polarity protection on the board. If
   you are making your own power cables, make sure to use the same polarity
   convention as the RoverWing, otherwise you will permanently damage the
   board!!


The board has a 5V high-efficiency  buck voltage converter  which powers the
sonars, Neopixel LEDs, servos, and a 3.3V linear regulator. The linear regulator
in turn   provides power to  the Feather board (via 3.3V pin),  built-in
microcontroller, and IMU.

Note that 5V converter is capable of producing 4.5A output. Some of it is used by
on-board electronics, leaving about 4A  available for  servos and NeoPixel LEDs.

RoverWing also includes internal circuit for measuring power supply voltage,
which is then made available to the Feather board using ``getVoltage()`` function.

Feather board connector
=======================
RoverWing can not be used without a Feather board. To connect the Feather board,
plug it in the dual row female headers at the center of RoverWing. These headers
provide connection between the RoverWing and the Feather, using power pins
(ground and 3.3V), I2C pins (SDA and SCL) and reset pin, so that pressing the
reset button on either the RoverWing or the Feather resets both of them.
RoverWing contains the necessary pull-up resistors (2.7K) for the I2C bus.

The second row of the female header gives an easy way of connecting additional
electronics to the Feather. Each pin of the second row is connected to the
adjacent pin of the Feather, except the two pins noted below:

* USB bus pin of the Feather is not connected. Instead,
  the adjacent pin in the second row is connected to the output of 5V voltage
  converter of the RoverWing, which can be used to provide 5V power to
  additional electronics.

* VBAT pin of the Feather is not connected. Instead, the adjacent pin of the
  second row is connected to the NEOPIXEL_OUT signal of the RoverWing
  (see section on NeoPixels_ below).

Microcontroller
===============
The brains of the board is the SAMD21G microcontroller - same MCU used by
Arduino ZERO and Adafruit Feather M0 boards. It comes preloaded with firmware,
which is described in Firmware_ section below. Normally there is no need to
change it.


The MCU communicates with the Feather board via I2C bus; it uses the slave
address of 0x11 (or 17 in decimal form).

Inertial Motion Unit
====================

RoverWing contains a  Inertial Motion Unit, based on MPU6050 chip by Invensense.
This is a 6 degree of freedom sensor (3 axis gyro and 3 axis accelerometer),
which can be used for  determining robot orientation in space. Provided firmware
contains appropriate data fusion algorithm, combining the sensor data and
filtering out noise to return the robot orientation, either as roll-pitch-yaw
angles, or in a quaternion form.

.. Note::
   Even with noise filtering, data obtained from this sensor alone will always
   suffer from accumulating error (drift); to compensate for it, you need to
   use  an additional magnetometer (compass) sensor as described in GPS_ section.



Motors and encoders
===================

The RoverWing provides connections for two brushed DC motors, at the same
voltage as the main power supply (7-14V). You can also use motors rated for
lower voltage and limit the power in software: for example, you can use 6V
motors with 7.4V power supply by limiting the maximal output power to 80\%. Each
motor is controlled by DRV8871 motor driver by Texas Instruments, which can
provide up to 2.9A per motor. The drivers are current limited, so the current
will not exceed 2.9A even if the motor is stalled, which helps prevent motor
burnout. The motor ports use JST VH connectors; see section Cables_ for list
of compatible cables and adapters.

To avoid overheating, it is recommended to attach  additional heatsinks to the
motor drivers if you intend to run the motors at more than 2A continuous.


In addition, the RoverWing provides two ports for connecting quadrature
encoders, one for each motor. The encoder ports use
[JST PH4] (http://www.jst-mfg.com/product/detail_e.php?series=199) connectors,
and pin order is  shown below:

* Ground (pin closest to board edge)
* 3.3V
* Channel B
* Channel A

These are the same connectors and pinouts as used
by REV Robotics hubs, so one can use the same encoder cables. For other
suggested cables, see Cables_ section.



Servos
======
RoverWing provides four servo connections. They can be used for any servo which
are controlled by standard PWM signal (500 us - 2500 us pulse duration) and
5V power.

.. Note::
   That the total current available for servos and NeoPixel LEDs is about 4A.
   This is sufficient for most applications, but might not be enough for large
   loads.  For example, for a popular [HS485HB]
   (https://hitecrcd.com/products/servos/sport-servos/analog-sport-servos/hs-485hb/product)
   standard size servo, no-load current draw is 0.3A, but the stall draw  can be
   as high as 1.2A. Note also that digital servos usually are much more
   power-hungry than analog servos.





Sonars
======
RoverWing provides connections for three ultrasonic distance sensors (HC-SR04 or
compatible). These sonar sensors are very popular with hobby robot builders due
to their low price  (about $2.50/piece) and reliability. Note that these sonars
use 5V power, so they can not be directly connected to 3.3V boards such as
Adafruit Feather boards. RoverWing solves this problem by  including a voltage
level shifter  chip (TX1004EWR).

The sonars ports use JST PH4 connectors; see Cables_ for advice on choosing
connector cables. The pin order is as follows:

* GND (closest to board edge)
* 5V
* Trig
* Echo


Analog inputs
=============
RoverWing provides connectors for 6 analog sensors, together with 3.3V power and
ground connectors. Note that the analog signal should not exceed 3.3V, otherwise
you might damage the board!

To filter out the noise, RoverWing firmware uses so-called  [low pass filter]
(https://en.wikipedia.org/wiki/Exponential_smoothing); slightly simplifying,
one can say that it averages  several last readings
of each sensor. Raw values can also be accessed, for those
(uncommon) situations when it becomes necessary.

.. _NeoPixel:
NeoPixel
========
RoverWing  provides a port for connecting
[NeoPixel smart LEDs] (https://learn.adafruit.com/adafruit-neopixel-uberguide).
This port uses JST PH3 connector, with the same pin order as used by Adafruit's
Hallowing board:

* GND (closest to board edge)
* 5V
* Data

In addition, RoverWing contains an internal small NeoPixel LED. Normally it
blinks green (about 4 times/s); if the battery voltage drops below preset limit,
it turns yellow to warn the user. The battery level cutoff can be changed as
described in the  documentation of RoverWing library. Other than that, the
internal NeopIxel LED can not be controlled by the user.

.. _GPS:
GPS and compass
===============
RoverWing provides connectors for external GPS and magnetometer (compass)
sensors. It uses the same connectors (Hirose DF13 6-pin + 4-pin) and pinouts as
popular [Pixhawk flight controller board]
(http://ardupilot.org/copter/docs/common-pixhawk-overview.html)  used in
quadcopters. Thus, you can use  any GPS and compass combination sensor which is
compatible with Pixhawk 2.4. Such sensors can be found on eBay or AliExpress for
as little as $15 (here is an [example]
(https://www.aliexpress.com/item/Ublox-NEO-M8N-M8N-8N-High-Precision-GPS-Built-in-Compass-w-Stand-Holder-for-APM/32370714787.html)).

The provided firmware takes care of reading the GPS and magnetometer sensors,
providing an easy to use interface for the user. It can also combine the data
from the IMU and magnetometer to provide a more reliable orientation data.


.. Note::
   TO avoid interference, it is recommended to place the magnetometer at least 15 cm (6 in) away from
   the  motors and other electronics.
   A GPS+compass sensor with a stand intended for quadcopters should work well.


Additional I2C ports
====================
RoverWing has two ports for connecting additional I2C sensors. These ports are
connected to the I2C bus of the Feather board and thus are controlled directly
by the Feather. The ports use JST PH4 connectors, with the following pin order:

* GND (closest to board edge)
* 3.3V
* SDA
* SCL

This is the same connector and same  pin order as used by REV Robotics hub and
by [Adafruit's STEMMA cables] (https://www.adafruit.com/product/3950). You can
aslo use SEEED Studio Grove cables; see Cables_ section for details.

RoverWing contains I2C bus pullup resistors, so no additional pullups are necessary.







Add-ons
=======

.. _Cables:
Cables
======
Below is the list of suggested cables and places to buy them.

* **Power and motor cables**. RoverWing uses JST VH connectors. You can buy JST VH 2-pin cables from many sources, including
 - REV Robotics (JST VH - JST VH, JST VH to PowerPoles).
 - ServoCity
 - Amazon, eBay, AliExpress

* **Encoders, Sonars, I2C**. RoverWing uses JST PH 4pin connectors for all of these ports. For the encoders,
the pin order matches the one used by REV Robotics hub, so if you are using REV Robotics motors, you can
directly connect the encoders using a JST PH - JST PH cable, which can be bought from REV Robotics.
For other peripherals, you can use JST PH - female headers cable from Adafruit: https://www.adafruit.com/product/3950

You can also use SEEED Studio Grove connectors. The contacts and spacing are identical, but the the plastic housing
of Grove cable does not completely fit in the PH4 connector, so the fit will nto be perfect - but good enough
for a solid electrical connection.

* **Neopixel**. Roverwing uses JST PH 3pin connector for the NeoPixel port.
This is the same connector and same pin order as used by Adafruit Hallowing. You
can plug in a Neopixel strip such as this one from Adafruit directly:
https://www.adafruit.com/product/3919 or you can use the JST ph3 to female
socket adapter cable such as `this one <https://www.adafruit.com/product/3894>`__.


<a href="https://roverwing.readthedocs.io/en/latest//">Roverwing Home Page</a>

<a href="https://roverwing.github.io/RoverWingLibrary/">Library</a>

<a href="https://roverwing.github.io/RoverWingFirmware/">Firmware</a>



License
=======
