emulate-the-f1 binaries
=======================

Here is a hex file suitable for loading into your Arduino Uno R3 (in case you can't get the firmware build process to work on your own).

You can load it using the following sequence of commands:

	dfu-programmer atmega16u2 erase
	dfu-programmer atmega16u2 flash SerialToF1.hex
	dfu-programmer atmega16u2 reset

Remember to power cycle the Uno afterwards.

See license.txt for details on the licenses under which this software is distributed.

Copyright (C) 2014 Christopher Albin Edmonds where applicable.
