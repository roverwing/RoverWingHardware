===========
Power
===========
The board can be powered by a 7-14V DC power supply such as 2 or 3 cell LiPO
battery or  a 10-cell NiMH battery. The battery port uses JST VH male connector.
We recommend using 18 AWG or larger cables for power supply;  see
section :doc:`Cables <cables>`_ for list of compatible cables and adapters.
There is also a power indicator LED next to the power connector. Note that the
RoverWing **can not be powered via USB cable**.

.. warning::

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
which is then made available to the Feather board using `getVoltage()` function.
