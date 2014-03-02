emulate-the-f1 firmware
=======================

To build the firmware:

- Download or clone the latest version of LUFA from http://www.fourwalledcubicle.com/LUFA.php

- Install dfu-programmer and ensure that it is in your path - see http://www.tunecrew.com/2014/03/02/building-dfu-programmer-on-mac-os-x/

- Link to the LUFA subdirectory in the LUFA directory (normally lufa/LUFA) in the firmware directory - ln -s /path/to/lufa/LUFA ./LUFA

- Setup your hardware as described at http://www.tunecrew.com/2013/07/02/emulating-the-traktor-kontrol-f1-part-2/

- Execute make

To load the firmware:

- Connect the Uno to the computer via USB

- Momentarily press the DFU button to put the UNO into DFU mode

- Execute “make dfu”

- Power cycle the Uno

To see more discussion on the firmware see http://www.tunecrew.com/2014/03/02/emulating-the-traktor-kontrol-f1-part-3

See license.txt for details on the licenses under which this software is distributed.

Copyright (C) 2014 Christopher Albin Edmonds where applicable.
