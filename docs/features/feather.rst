.. _feather:

=======================
Feather Board Connector
=======================
RoverWing can not be used without a Feather board. You can use any Feather
board from Adafruit, or any 3rd party board that meets
`Adafruit's specifications <https://learn.adafruit.com/adafruit-feather/feather-specification>`_.
To connect the Feather board, plug it in the dual row female headers at the
center of RoverWing. These headers provide connection between the RoverWing and
the Feather, using power pins (ground and 3.3V), I2C pins (SDA and SCL) and
reset pin, so that pressing the reset button on either the RoverWing or the
Feather resets both of them. RoverWing contains the necessary pull-up resistors
(1.8K) for the I2C bus.

The second row of the female header gives an easy way of connecting additional
electronics to the Feather. Each pin of the second row is connected to the
adjacent pin of the Feather, except the two pins noted below:

* USB bus pin of the Feather is not connected. Instead,
  the adjacent pin in the second row is connected to the output of 5V voltage
  converter of the RoverWing, which can be used to provide 5V power to
  additional electronics.

* VBAT pin of the Feather is not connected. Instead, the adjacent pin of the
  second row is connected to the ``NEOPIXEL_OUT`` signal of the RoverWing
  (see :ref:`neopixel` section).

.. warning::
   It is recommended that you disconnect the power from the RoverWing before
   plugging or unplugging the Feather board. Also, be very careful when
   unplugging  the Feather board so that you do not bend the pins.
