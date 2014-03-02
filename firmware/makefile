# emulate-the-f1
#
# Version 1.0
# Christopher Albin Edmonds - christopher@tunecrew.com - http://www.tunecrew.com/
#
# Copyright (C) 2014 Christopher Albin Edmonds where applicable. See license.txt for further details on copyright, licensing and distribution of emulate-the-f1.
#
# Parts of emulate-the-f1 are adapted from the LUFA Library, and are distributed under the following license:
#
#             LUFA Library
#     Copyright (C) Dean Camera, 2013.
#
#  dean [at] fourwalledcubicle [dot] com
#           www.lufa-lib.org
#
#  Copyright 2013  Dean Camera (dean [at] fourwalledcubicle [dot] com)
#
#  Permission to use, copy, modify, distribute, and sell this
#  software and its documentation for any purpose is hereby granted
#  without fee, provided that the above copyright notice appear in
#  all copies and that both that the copyright notice and this
#  permission notice and warranty disclaimer appear in supporting
#  documentation, and that the name of the author not be used in
#  advertising or publicity pertaining to distribution of the
#  software without specific, written prior permission.
#
#  The author disclaims all warranties with regard to this
#  software, including all implied warranties of merchantability
#  and fitness.  In no event shall the author be liable for any
#  special, indirect or consequential damages or any damages
#  whatsoever resulting from loss of use, data or profits, whether
#  in an action of contract, negligence or other tortious action,
#  arising out of or in connection with the use or performance of
#  this software.

# Run "make help" for target help.

MCU          = atmega16u2
ARCH         = AVR8
BOARD        = UNO
F_CPU        = 16000000
F_USB        = $(F_CPU)
OPTIMIZATION = s
TARGET       = SerialToF1
SRC          = $(TARGET).c Descriptors.c $(LUFA_SRC_USB) $(LUFA_SRC_USBCLASS)
LUFA_PATH    = ./LUFA
CC_FLAGS     = -DUSE_LUFA_CONFIG_HEADER -IConfig/
LD_FLAGS     =

# Default target
all:

# Include LUFA build script makefiles
include $(LUFA_PATH)/Build/lufa_core.mk
include $(LUFA_PATH)/Build/lufa_sources.mk
include $(LUFA_PATH)/Build/lufa_build.mk
include $(LUFA_PATH)/Build/lufa_cppcheck.mk
include $(LUFA_PATH)/Build/lufa_doxygen.mk
include $(LUFA_PATH)/Build/lufa_dfu.mk
include $(LUFA_PATH)/Build/lufa_hid.mk
include $(LUFA_PATH)/Build/lufa_avrdude.mk
include $(LUFA_PATH)/Build/lufa_atprogram.mk
