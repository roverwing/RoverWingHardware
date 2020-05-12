.. _neopixel:

========
NeoPixel
========
RoverWing allows connecting a strip of "smart" LEDs, using WS2812b or SK6812
chips. These LEDs, commonly called "NeoPixels", contain small chips which make
them individually addressable: you can independently set colors of different
LEDs using just one data line. You can read more about them in
Adafruit's Uberguide: https://learn.adafruit.com/adafruit-neopixel-uberguide.
Note that RoverWing only allows the RGB NeoPixels; RGB W NeoPixels, which add
white LED to the usual RGB, are not supported.

RoverWing NeoPixel port uses JST PH3 connector, with the same pin order as
used by Adafruit's `Hallowing board <https://learn.adafruit.com/adafruit-hallowing/overview>`_ and
some of their `NeoPixel strips <https://www.adafruit.com/product/3919>`_
(clockwise looking from top):

* Data
* 5V
* GND

You can connect up to 128 NeoPixels; note, however, that RoverWing can only
provide up to 3.5A currrent for NeoPixels and servos combined. Since each
NeoPixel can use up to 60mA, it means that you can not power more than 60
NeoPixels at full power, and that only if you do not use any servos. (It
shoudl be noted, though, that 60 mA is absolute maximum - much more typical
power consumption is 20 mA).
