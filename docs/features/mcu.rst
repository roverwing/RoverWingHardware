============================
Microcontroller and Firmware
============================
The brains of the board is the SAMD21G microcontroller, using the 32-bit
ARM® Cortex®-M0+ processor (the same MCU is used by
Arduino ZERO and Adafruit Feather M0 boards). It comes preloaded with firmware;
normally there is no need to change it.,

If you want to learn more about the firmware, install an update, or compile
your own firmware from source, please visit
`RoverWing Firmware <https://github.com/roverwing/RoverWingFirmware>`__ github
repository.

The MCU communicates with the Feather board via I2C bus; it uses the slave
address of 0x11 (or 17 in decimal form).
