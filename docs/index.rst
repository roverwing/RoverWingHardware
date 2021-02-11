===============
RoverWing board
===============
.. figure:: images/MainView-2020-12.jpg
    :alt: RoverWing
    :width: 80%

    RoverWing (without the Feather), top view.

RoverWing is an extension board  (or "wing", following Adafruit's terminology) for
Adafruit's `Feather boards <https://www.adafruit.com/feather>`__.
This extension board  provides motor drivers, Inertial Motion Unit (IMU), and connection
ports for servos, sonars, GPS, and other peripherals commonly used by small
mobile robots. It also contains a microcontroller preloaded with firmware
to control these peripherals, which communicates with the Feather board using
I2C protocol, thus freeing resources of the Feather board for other purposes.

The RoverWing was heavily influenced by Adafruit's
`CRICKIT <https://www.adafruit.com/crickit>`__ board
(in particular, it has exact same dimensions and  mounting holes as the
CRICKIT board). However, unlike CRICKIT, it is intended for use with more
powerful 6-12V motors and provides a slightly different set of peripherals.

Below is the list of key features of the RoverWing:

* Can be powered by 7-14V power source; contains a voltage regulator
  providing power to the Feather board

* Only uses 2 pins (SDA and SCL) of the Feather board.

* Contains on-board microcontroller, which takes care of low-level operations
  such as counting motor encoder pulses, using preloaded firmware

* Contains on-board 6DOF  Inertial Motion Unit (IMU), based on ICM-42605 chip
  by Invensense which can be used for tracking robot orientation in space

* Provides the hardware and firmware support for connecting the following
  external peripherals

  - **Motors**: two brushed DC motors, at up to 2.9A at 14V per motor
  - **Quadrature encoders** for each motor
  - **Sonars**: support for three HC-SR04 or compatible ultrasonic sensors (sonars)
  - **Servos**: four servos (5V)
  - Six **analog inputs** (3.3V maximum)
  - **Neopixel** smart LED strips
  - **GPS  sensor**
  - one additional **I2C port**

The RoverWing uses same connectors for power supply, motors, and encoders
as the `REV Robotics Expansion hub <http://www.revrobotics.com/rev-31-1153>`__
used in `First Tech Challenge <https://www.firstinspires.org/robotics/ftc>`__
robotics competition, so it can be easily used with the same motors. The I2C
port uses Qwiic/Stemma QT connector, making it easy to connect additional
sensors from Sparkfun or Adafruit.

Ordering
--------
RoverWing can be ordered from the following vendors:
  - CrowdSupply: https://www.crowdsupply.com/alexander-kirillov/roverwing 
  - Mouser: use part numbers `ROVERWING-01 <https://www.mouser.com/ProductDetail/ROVERWING-01>`__ ** for the RoverWing board and 
    `ROVERWING-T-02 <https://www.mouser.com/ProductDetail/ROVERWING-T-02>`__ for the optional RoverWing top board,a s described below. 


.. toctree::
    :caption: Table of Contents
    :maxdepth: 2

    quickstart
    details
    top-intro
    library
    accessories
    license
