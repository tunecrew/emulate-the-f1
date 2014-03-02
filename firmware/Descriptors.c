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
 *  USB Device Descriptors, for library use when in USB device mode. Descriptors are special
 *  computer-readable structures which the host requests upon device enumeration, to determine
 *  the device's capabilities and functions.
 */
#include "Descriptors.h"

/** HID class report descriptor. This is a special descriptor constructed with values from the
 *  USBIF HID class specification to describe the reports and capabilities of the HID device. This
 *  descriptor is parsed by the host and its contents used to determine what data (and in what encoding)
 *  the device will send, and what it may be sent back from the host. Refer to the HID specification for
 *  more details on HID report descriptors.
 */
const USB_Descriptor_HIDReport_Datatype_t PROGMEM F1Report[] =
{
	0x06, 0x01, 0xFF,
	0x09, 0x00,
	0xA1, 0x01,
	0x09, 0x01,
	0xA1, 0x02,
	0x85, 0x01,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x09, 0x02,
	0x15, 0x00,
	0x25, 0x01,
	0x75, 0x01,
	0x95, 0x20,
	0x81, 0x02,
	0x09, 0x03,
	0x15, 0x00,
	0x26, 0xFF, 0x00,
	0x75, 0x08,
	0x95, 0x01,
	0x81, 0x02,
	0x09, 0x04,
	0x09, 0x04,
	0x09, 0x04,
	0x09, 0x04,
	0x15, 0x00,
	0x26, 0xFF, 0x0F,
	0x75, 0x10,
	0x95, 0x04,
	0x81, 0x02,
	0x09, 0x05,
	0x09, 0x05,
	0x09, 0x05,
	0x09, 0x05,
	0x15, 0x00,
	0x26, 0xFF, 0x0F,
	0x75, 0x10,
	0x95, 0x04,
	0x81, 0x02,
	0xC0,
	0x09, 0x80,
	0xA1, 0x02,
	0x85, 0x80,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x15, 0x00,
	0x25, 0x7F,
	0x75, 0x08,
	0x95, 0x50,
	0x91, 0x02,
	0xC0,
	0x09, 0x01,
	0xA1, 0x02,
	0x85, 0xF0,
	0x09, 0x04,
	0x09, 0x04,
	0x09, 0x04,
	0x09, 0x04,
	0x09, 0x05,
	0x09, 0x05,
	0x09, 0x05,
	0x09, 0x05,
	0x15, 0x00,
	0x46, 0xFF, 0x00,
	0x75, 0x08,
	0x95, 0x08,
	0xB1, 0x02,
	0xC0,
	0x09, 0xD0,
	0xA1, 0x02,
	0x85, 0xD0,
	0x09, 0xD1,
	0x15, 0x00,
	0x26, 0xFF, 0x00,
	0x75, 0x08,
	0x95, 0x3F,
	0xB1, 0x02,
	0xC0,
	0x09, 0x01,
	0xA1, 0x02,
	0x85, 0xF1,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x09, 0x81,
	0x15, 0x00,
	0x26, 0xFF, 0x00,
	0x75, 0x08,
	0x95, 0x30,
	0xB1, 0x02,
	0xC0,
	0xC0
};

/** Device descriptor structure. This descriptor, located in FLASH memory, describes the overall
 *  device characteristics, including the supported USB version, control endpoint size and the
 *  number of device configurations. The descriptor is read out by the USB host when the enumeration
 *  process begins.
 */
const USB_Descriptor_Device_t PROGMEM DeviceDescriptor =
{
	.Header                 = {.Size = sizeof(USB_Descriptor_Device_t), .Type = DTYPE_Device},
	.USBSpecification       = VERSION_BCD(2,0,0),
	.Class                  = USB_CSCP_NoDeviceClass,
	.SubClass               = USB_CSCP_NoDeviceSubclass,
	.Protocol               = USB_CSCP_NoDeviceProtocol,
	.Endpoint0Size          = FIXED_CONTROL_ENDPOINT_SIZE,
	.VendorID               = 0x17CC,
	.ProductID              = 0x1120,
	.ReleaseNumber          = VERSION_BCD(0,0,9),
	.ManufacturerStrIndex   = STRING_ID_Manufacturer,
	.ProductStrIndex        = STRING_ID_Product,
	.SerialNumStrIndex      = STRING_ID_Serial,
	.NumberOfConfigurations = FIXED_NUM_CONFIGURATIONS
};

/** Configuration descriptor structure. This descriptor, located in FLASH memory, describes the usage
 *  of the device in one of its supported configurations, including information about any device interfaces
 *  and endpoints. The descriptor is read out by the USB host during the enumeration process when selecting
 *  a configuration so that the host may correctly communicate with the USB device.
 */
const USB_Descriptor_Configuration_t PROGMEM ConfigurationDescriptor =
{
	.Config =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Configuration_Header_t), .Type = DTYPE_Configuration},
		.TotalConfigurationSize = sizeof(USB_Descriptor_Configuration_t),
		.TotalInterfaces        = 2,
		.ConfigurationNumber    = 1,
		.ConfigurationStrIndex  = STRING_ID_F1HID,
		.ConfigAttributes       = 0x80,
		.MaxPowerConsumption    = USB_CONFIG_POWER_MA(480)
	},

	.HID_Interface =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},
		.InterfaceNumber        = 0x00,
		.AlternateSetting       = 0x00,
		.TotalEndpoints         = 2,
		.Class                  = HID_CSCP_HIDClass,
		.SubClass               = HID_CSCP_NonBootSubclass,
		.Protocol               = HID_CSCP_NonBootProtocol,
		.InterfaceStrIndex      = NO_DESCRIPTOR
	},

	.HID_F1HID =
	{
		.Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},
		.HIDSpec                = VERSION_BCD(1,1,0),
		.CountryCode            = 0x00,
		.TotalReportDescriptors = 1,
		.HIDReportType          = HID_DTYPE_Report,
		.HIDReportLength        = sizeof(F1Report)
	},

	.HID_ReportINEndpoint =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},
		.EndpointAddress        = F1_IN_EPADDR,
		.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
		.EndpointSize           = F1_EPSIZE,
		.PollingIntervalMS      = 0x04
	},

	.HID_ReportOUTEndpoint =
	{
		.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},
		.EndpointAddress        = F1_OUT_EPADDR,
		.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
		.EndpointSize           = F1_EPSIZE,
		.PollingIntervalMS      = 0x04
	},

	.DFU_Interface =
	{
		.Header = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},
		.InterfaceNumber = 1,
		.AlternateSetting = 0,
		.TotalEndpoints = 0,
		.Class = 0xFE,
		.SubClass = 0x01,
		.Protocol = 0x01,
		.InterfaceStrIndex = 0x05
	},
	.DFU_Functional =
	{
		.Header = {.Size = sizeof(USB_Descriptor_DFU_Functional_t), .Type = DTYPE_DFUFunctional},
		.Attributes = 0x07,	/* CanDnload, CanUpload, ManifestationTolerant */
		.DetachTimeout = 0x00FA,
		.TransferSize = 0x0040,
	}
};

/** Language descriptor structure. This descriptor, located in FLASH memory, is returned when the host requests
 *  the string descriptor with index 0 (the first index). It is actually an array of 16-bit integers, which indicate
 *  via the language ID table available at USB.org what languages the device supports for its string descriptors.
 */
const USB_Descriptor_String_t PROGMEM LanguageString =
{
	.Header                 = {.Size = USB_STRING_LEN(1), .Type = DTYPE_String},
	.UnicodeString          = {LANGUAGE_ID_ENG}
};

const USB_Descriptor_String_t PROGMEM ManufacturerString =
{
	.Header                 = {.Size = USB_STRING_LEN(18), .Type = DTYPE_String},
	.UnicodeString          = L"Native Instruments"
};

const USB_Descriptor_String_t PROGMEM ProductString =
{
	.Header = {.Size = USB_STRING_LEN(18), .Type = DTYPE_String},
	.UnicodeString = L"Traktor Kontrol F1"
};

const USB_Descriptor_String_t PROGMEM SerialString =
{
	.Header = {.Size = USB_STRING_LEN(8), .Type = DTYPE_String},
	.UnicodeString = L"00000000"
};

const USB_Descriptor_String_t PROGMEM ConfigurationString =
{
	.Header = {.Size = USB_STRING_LEN(22), .Type = DTYPE_String},
	.UnicodeString = L"Traktor Kontrol F1 HID"
};

const USB_Descriptor_String_t PROGMEM DFUString =
{
	.Header = {.Size = USB_STRING_LEN(22), .Type = DTYPE_String},
	.UnicodeString = L"Traktor Kontrol F1 DFU"
};

/** This function is called by the library when in device mode, and must be overridden (see library "USB Descriptors"
 *  documentation) by the application code so that the address and size of a requested descriptor can be given
 *  to the USB library. When the device receives a Get Descriptor request on the control endpoint, this function
 *  is called so that the descriptor details can be passed back and the appropriate descriptor sent back to the
 *  USB host.
 */
uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
                                    const uint8_t wIndex,
                                    const void** const DescriptorAddress)
{
	const uint8_t  DescriptorType   = (wValue >> 8);
	const uint8_t  DescriptorNumber = (wValue & 0xFF);

	const void* Address = NULL;
	uint16_t    Size    = NO_DESCRIPTOR;

	switch (DescriptorType)
	{
		case DTYPE_Device:
			Address = &DeviceDescriptor;
			Size    = sizeof(USB_Descriptor_Device_t);
			break;
		case DTYPE_Configuration:
			Address = &ConfigurationDescriptor;
			Size    = sizeof(USB_Descriptor_Configuration_t);
			break;
		case DTYPE_String:
			switch (DescriptorNumber)
			{
				case 0x00:
					Address = &LanguageString;
					Size    = pgm_read_byte(&LanguageString.Header.Size);
					break;
				case 0x01:
					Address = &ManufacturerString;
					Size    = pgm_read_byte(&ManufacturerString.Header.Size);
					break;
				case 0x02:
					Address = &ProductString;
					Size    = pgm_read_byte(&ProductString.Header.Size);
					break;
				case 0x03:
					Address = (void*)&SerialString;
					Size    = pgm_read_byte(&SerialString.Header.Size);
					break;
				case 0x04:
					Address = (void*)&ConfigurationString;
					Size    = pgm_read_byte(&ConfigurationString.Header.Size);
					break;
				case 0x05:
					Address = (void*)&DFUString;
					Size    = pgm_read_byte(&DFUString.Header.Size);
					break;
			}
			break;
		case HID_DTYPE_HID:
			Address = &ConfigurationDescriptor.HID_F1HID;
			Size    = sizeof(USB_HID_Descriptor_HID_t);
			break;
		case HID_DTYPE_Report:
			Address = &F1Report;
			Size    = sizeof(F1Report);
			break;
	}

	*DescriptorAddress = Address;
	return Size;
}

