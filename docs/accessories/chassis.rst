=============
Robot Chassis
=============
RoverWing is typically used for small mobile robots. You can use it with any
robot chassis as long as the chassis is using two brushed DC motors at voltage
between 6--12V. You can even use it with motors intended for 5V power, such as
popular `TT motors <https://www.adafruit.com/product/3777>`__ if you limit the
power in software.

Below are some of the chassis we recommend:

* **Adafruit's Mini Robot Rover Chassis**: https://www.adafruit.com/product/2939.
  Cheap, small, and nimble.

* **Pololu's Romi Chassis**: https://www.pololu.com/category/202/romi-chassis-and-accessories
  Larger, more powerful; you can use it with encoder-equipped motors. Has lots
  of room for attaching various sensors.

.. warning::

   The encoders which Pololu recommends for use with Romi chassis are rated for
   3.5V and above. Since the RoverWing encoder port provides only 3.3V voltage,
   there is no guarantee that these encoders will work with RoverWing. Instead,
   use one of the encoders on `this page <https://www.pololu.com/category/201/encoders>`__,
   which can use voltage between 2.7-18 V.

* **DAGU 5 tracked chassis**: https://www.pololu.com/product/1550 or
  https://www.pololu.com/product/1551

* **TS100 tank chassis** by DoIT: https://www.aliexpress.com/item/32776140631.html
  Combined with a 3-cell LiPo battery, this becomes a great outdoor tank. Note
  that the motors do not come with encoders; instead, you can use GPS for
  outdoors navigation.
