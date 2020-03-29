====================
Inertial Motion Unit
====================

RoverWing contains a  Inertial Motion Unit, based on MPU6050 chip by Invensense.
This is a 6 degree of freedom sensor (3 axis gyro and 3 axis accelerometer),
which can be used for  determining robot orientation in space. Provided firmware
contains appropriate data fusion algorithm, combining the sensor data and
filtering out noise to return the robot orientation, either as roll-pitch-yaw
angles, or in a quaternion form.

.. note::
   Even with noise filtering, data obtained from this sensor alone will always
   suffer from accumulating error (drift).
