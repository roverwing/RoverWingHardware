===============
Microcontroller
===============
The brains of the board is the SAMD21G microcontroller - same MCU used by
Arduino ZERO and Adafruit Feather M0 boards. It comes preloaded with firmware,
which is described in [Firmware](README.md#Firmware) section below. Normally there is no need to
change it.


The MCU communicates with the Feather board via I2C bus; it uses the slave
address of 0x11 (or 17 in decimal form).
