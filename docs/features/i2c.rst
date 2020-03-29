====================
Additional I2C Port
====================
RoverWing has a  port for connecting additional I2C sensors. This port are
connected to the I2C bus of the Feather board and thus are controlled directly
by the Feather. The ports use JST PH4 connectors, with the following pin order:

* GND (closest to board edge)
* 3.3V
* SDA
* SCL

This is the same connector and   pin order as used by REV Robotics hub and
by `Adafruit's STEMMA cables <https://www.adafruit.com/product/3950>`_. You can
also use SEEED Studio Grove cables; see :ref:`cables` section for details.

RoverWing contains I2C bus pullup resistors, so no additional pullups are necessary.
