/*
emulate-the-f1

Version 1.0
Christopher Albin Edmonds - christopher@tunecrew.com - http://www.tunecrew.com/

Copyright (C) 2014 Christopher Albin Edmonds where applicable. See license.txt for further details on copyright, licensing and distribution of emulate-the-f1.

Parts of emulate-the-f1 are adapted from the LUFA Library, and are distributed under the following license:

             LUFA Library
     Copyright (C) Dean Camera, 2013.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org

  Copyright 2013  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/*
 *  Header file for Descriptors.c.
 */

#ifndef _DESCRIPTORS_H_
#define _DESCRIPTORS_H_

/* Includes: */
	#include <avr/pgmspace.h>
	#include <LUFA/Drivers/USB/USB.h>
	#include "Config/AppConfig.h"

/* Type Defines: */
	typedef struct
	{
		USB_Descriptor_Header_t Header;
		uint8_t  Attributes;
		uint16_t DetachTimeout;
		uint16_t TransferSize;
	} USB_Descriptor_DFU_Functional_t;

	/** Type define for the device configuration descriptor structure. This must be defined in the
	 *  application code, as the configuration descriptor contains several sub-descriptors which
	 *  vary between devices, and which describe the device's usage to the host.
	 */
	typedef struct
	{
		USB_Descriptor_Configuration_Header_t Config;
		USB_Descriptor_Interface_t            HID_Interface;
		USB_HID_Descriptor_HID_t              HID_F1HID;
		USB_Descriptor_Endpoint_t             HID_ReportINEndpoint;
		USB_Descriptor_Endpoint_t             HID_ReportOUTEndpoint;
		USB_Descriptor_Interface_t            DFU_Interface;
		USB_Descriptor_DFU_Functional_t       DFU_Functional;
	} USB_Descriptor_Configuration_t;

	/** Enum for the device string descriptor IDs within the device. Each string descriptor should
	 *  have a unique ID index associated with it, which can be used to refer to the string from
	 *  other descriptors.
	 */
	enum StringDescriptors_t
	{
	    STRING_ID_Language      = 0, /**< Supported Languages string descriptor ID (must be zero) */
	    STRING_ID_Manufacturer  = 1, /**< Manufacturer string ID */
	    STRING_ID_Product       = 2, /**< Product string ID */
	    STRING_ID_Serial        = 3,
	    STRING_ID_F1HID         = 4,
	    STRING_ID_F1DFU         = 5,
	};

	/* Macros: */
		/** Endpoint address of the F1 HID reporting IN endpoint. */
		#define F1_IN_EPADDR         (ENDPOINT_DIR_IN | 1)
		#define F1_OUT_EPADDR        (ENDPOINT_DIR_OUT | 1)

		/** Size in bytes of the F1 HID reporting endpoint. */
		#define F1_EPSIZE            64
		#define DTYPE_DFUFunctional  0x21

	/* Function Prototypes: */
		uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
		                                    const uint8_t wIndex,
		                                    const void** const DescriptorAddress)
		                                    ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL_PTR_ARG(3);

#endif

