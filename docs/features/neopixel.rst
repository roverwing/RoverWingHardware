.. _neopixel:

========
NeoPixel
========
RoverWing  provides a port for connecting
`NeoPixel smart LEDs <https://learn.adafruit.com/adafruit-neopixel-uberguide>`_.
This port uses JST PH3 connector, with the same pin order as used by Adafruit's
`Hallowing board <https://learn.adafruit.com/adafruit-hallowing/overview>`_ and
some of their `NeoPixel strips <https://www.adafruit.com/product/3919>`_:

* GND (closest to board edge)
* 5V
* Data

In addition, RoverWing contains an internal small NeoPixel LED. Normally it
blinks green (about 4 times per second); if the battery voltage drops below
preset limit, it turns yellow to warn the user. The battery level cutoff can be
hanged as described in the  documentation of RoverWing library. Other than that,
the internal NeoPixel LED can not be controlled by the user.
