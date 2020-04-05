====================
Additional I2C Port
====================
RoverWing has a  port for connecting additional I2C devices. This port is
connected to the I2C bus of the Feather board and thus is controlled directly
by the Feather. The ports use JST PH4 connectors, with the following pin order:

* GND (closest to board edge)
* 3.3V
* SDA
* SCL

This is the same connector and   pin order as used by REV Robotics hub and
by `Adafruit's STEMMA cables <https://www.adafruit.com/product/3950>`_. You can
also use SEEED Studio Grove cables; see :ref:`cables` section for details.

RoverWing contains I2C bus pullup resistors, so no additional pullups are necessary.

.. note::
   If you need to connect more than one I2C device, you can use an I2C 
   multiplexer such as `this one <https://learn.adafruit.com/adafruit-tca9548a-1-to-8-i2c-multiplexer-breakout>`__.
