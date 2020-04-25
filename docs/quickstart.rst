================
QuickStart Guide
================

.. warning::
   RoverWing board contains a number of through the hole components whose
   pins protrude at the bottom of the board and are not insulated. If these
   pins come in contact with any metal, it could result in a short circuit
   which could permanently damage the board or even cause a fire. Thus, make
   sure to only place RoverWing on  insulated surfaces - for example, do not
   place it on your work table littered with random screws.

To get started with your RoverWing board:

1. Plug in your Feather board into the socket in the middle of RoverWing.
   You can use any Feather board or a 3rd party board that meets Adafruit's
   Feather specifications.

2. Connect a power source (7-14V) to RoverWing, using the XT30 connector.
   Make sure that you use correct polarity! The green LED next to the power
   connector should light up, and the small  NeoPixel indicator LED should
   start blinking green. Also, your Feather should now be powered, so
   you should see the LEDs on the Feather board light up.

3. Connect the Feather board to the computer using a USB cable. Start Arduino
   IDE on your computer and install the RoverWing Arduino Library as described
   in |library-guide|.

.. warning::
   The USB cable should be connected to the USB port of the Feather board, not
   the USB port of RoverWing board! (The USB port of the RoverWing should only
   be used for updating the firmware.)

4. Go to :guilabel:`File->Examples` menu in the Arduino IDE. Scroll down to
   section  :guilabel:`Examples from custom libraries`, and among other libraries,
   you should see :guilabel:`RoverWing`. (If you do not see it, you may need
   to restart the Arduino IDE; if you still do not see it, it means something
   went wrong with library installation.) Select   :guilabel:`ConnectionTest`.

5. Open the serial monitor of Arduino IDE (from the  :guilabel:`Tools` menu) at
   9600 baud. After it opens, upload  and run :guilabel:`ConnectionTest` sketch.
   If you see on serial monitor :code:`RoverWing is connected!` followed by the
   firmware version and voltage level, then everything is set. You can now
   connect other peripherals (motors, sonars, servos,...) and run other example
   sketches.

.. note::
   It is advised that you disconnect the power from the RoverWing board before
   connecting peripherals.
