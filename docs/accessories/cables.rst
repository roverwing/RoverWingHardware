.. _cables:

======
Cables
======
Below is the list of suggested cables and places to buy them.

* **Power**. RoverWing board uses XT30 connector for main power; the  same
  connector is  used
  by REV Robotics Expansion hub used in First Tech Challenge competition. In
  addition, an adapter cable is included, allowing you to use a battery with
  the XT60 connector, popular among quadcopter and RC car enthusiasts. If you
  have a battery with a different connector (Dean's, 2.1mm barrel, Anderson
  Power Poles), try searching for an adapter cable on Amazon or Banggood.
  We recommend using 18 gauge or larger cables for 12 V power supply.

* **Motor cables**. RoverWing uses JST VH connectors. Two motor cables (JST VH
  to bare wire, 22 AWG) are included with the board. If you need longer or
  higher current cables, you can buy JST VH 2-pin cables from many sources, including

  - `REV Robotics <http://www.revrobotics.com/ftc/electronics/cables>`__
    (JST VH - JST VH, JST VH to Anderson PowerPole).
  - `ServoCity <https://www.servocity.com/electronics/wiring/adaptors>`__
  - Amazon, eBay, AliExpress

* **Encoders, Sonars**. RoverWing uses JST PH 4pin connectors for all of
  these ports. For the encoders, the pin order matches the one used by REV
  Robotics hub, so if you are using REV Robotics motors, you can
  directly connect the encoders using a JST PH - JST PH cable, which can be
  bought from `REV Robotics <http://www.revrobotics.com/ftc/electronics/cables>`__.
  For other peripherals, you can use JST PH - female headers cable from Adafruit:
  https://www.adafruit.com/product/3950.

  You can also use SEEED Studio `Grove cables <https://www.seeedstudio.com/cables-c-949.html>`__,
  available from `Arrow <https://www.arrow.com/en/products/110990031/seeed-technology-limited>`_.
  The contacts and spacing are identical, but the plastic housing of Grove cable
  does not completely fit in the PH4 connector, so the fit will not be perfect -
  but good enough for a solid electrical connection.

* **I2C port**. RoverWing uses JST SH 4-pin connector, also known under names
  Qwiic (SparkFun) and Stemma QT (Adafruit).   You can use a Qwiic/Stemma QT
  cable such as these ones (`1 <https://www.sparkfun.com/products/14427>`__,
  `2 <https://www.adafruit.com/product/4210>`__) to connect any 3.3V I2C device
  with a compatible connector. You can also use an adapter cable such as
  `this one <https://www.adafruit.com/product/4397>`__ for connecting other I2C devices.


* **NeoPixel**. Roverwing uses JST PH 3-pin connector for the NeoPixel port.
  This is the same connector and same pin order as used by
  `Adafruit Hallowing <https://learn.adafruit.com/adafruit-hallowing>`__. You
  can plug in a NeoPixel strip such as this one from Adafruit directly:
  https://www.adafruit.com/product/3919 or you can use the JST PH3 to female
  socket adapter cable such as `this one <https://www.adafruit.com/product/3894>`__.
