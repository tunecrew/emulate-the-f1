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

/** \file
 *
 *  Main source file for the SerialToF1 programme. This file contains the main tasks of
 *  the demo and is responsible for the initial application hardware configuration.
 */

#include "SerialToF1.h"

/** Buffer to hold the previously generated HID report, for comparison purposes inside the HID class driver. */
static uint8_t PrevHIDReportBuffer[F1_REPORT_SIZE];

/** LUFA HID Class driver interface configuration and state information. This structure is
 *  passed to all HID Class driver functions, so that multiple instances of the same class
 *  within a device can be differentiated from one another.
 */
USB_ClassInfo_HID_Device_t F1_HID_Interface =
	{
		.Config =
			{
				.InterfaceNumber              = 0,
				.ReportINEndpoint             =
					{
						.Address              = F1_IN_EPADDR,
						.Size                 = F1_EPSIZE,
						.Banks                = 1,
					},
				.PrevReportINBuffer           = PrevHIDReportBuffer,
				.PrevReportINBufferSize       = sizeof(PrevHIDReportBuffer),
			},
	};

// #define SERIAL_EPSIZE                22
/** Circular buffer to hold data from the serial port before it is sent to the host. */
// static RingBuffer_t USARTtoUSB_Buffer;
/** Underlying data buffer for \ref USARTtoUSB_Buffer, where the stored bytes are located. */
// static uint8_t      USARTtoUSB_Buffer_Data[128];

/** Main program entry point. This routine contains the overall program flow, including initial
 *  setup of all components and the main program loop.
 */
static uint8_t ReportData[F1_REPORT_SIZE];

int main(void)
{
	SetupHardware();
	GlobalInterruptEnable();
	Serial_Init(38400, false);

	int ReportDataFill = 0;

	for (;;)
	{
		if (ReportDataFill < F1_REPORT_SIZE)
		{
			int16_t DataByte = Serial_ReceiveByte();
			if (DataByte > -1)
			{
				ReportData[ReportDataFill] = DataByte;
				ReportDataFill++;
			}
		}
		else
		{
			ReportDataFill = 0;

			if (USB_DeviceState != DEVICE_STATE_Configured)
			{
			}
			else
			{
				Endpoint_SelectEndpoint(F1_OUT_EPADDR);

				if (Endpoint_IsINReady())
				{
					// for (int i = 0; i < F1_REPORT_SIZE; i++)
					// {
					// 	ReportData[i] = 0x0f;
					// }
					//
					// ReportData[0] = 0x01;

					Endpoint_Write_Stream_LE(&ReportData, sizeof(ReportData), NULL);
					Endpoint_ClearIN();
				}
			}
		}

		USB_USBTask();
	}
}

/** Configures the board hardware and chip peripherals for the demo's functionality. */
void SetupHardware(void)
{
#if (ARCH == ARCH_AVR8)
	/* Disable watchdog if enabled by bootloader/fuses */
	MCUSR &= ~(1 << WDRF);
	wdt_disable();

	/* Disable clock division */
	clock_prescale_set(clock_div_1);
#elif (ARCH == ARCH_XMEGA)
	/* Start the PLL to multiply the 2MHz RC oscillator to 32MHz and switch the CPU core to run from it */
	XMEGACLK_StartPLL(CLOCK_SRC_INT_RC2MHZ, 2000000, F_CPU);
	XMEGACLK_SetCPUClockSource(CLOCK_SRC_PLL);

	/* Start the 32MHz internal RC oscillator and start the DFLL to increase it to 48MHz using the USB SOF as a reference */
	XMEGACLK_StartInternalOscillator(CLOCK_SRC_INT_RC32MHZ);
	XMEGACLK_StartDFLL(CLOCK_SRC_INT_RC32MHZ, DFLL_REF_INT_USBSOF, F_USB);

	PMIC.CTRL = PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_HILVLEN_bm;
#endif

	/* Hardware Initialization */
	// LEDs_Init();
	USB_Init();
}

/** Event handler for the library USB Connection event. */
void EVENT_USB_Device_Connect(void)
{
	// LEDs_SetAllLEDs(LEDMASK_USB_ENUMERATING);
}

/** Event handler for the library USB Disconnection event. */
void EVENT_USB_Device_Disconnect(void)
{
	// LEDs_SetAllLEDs(LEDMASK_USB_NOTREADY);
}

/** Event handler for the library USB Configuration Changed event. */
void EVENT_USB_Device_ConfigurationChanged(void)
{
	bool ConfigSuccess = true;

	ConfigSuccess &= HID_Device_ConfigureEndpoints(&F1_HID_Interface);

	USB_Device_EnableSOFEvents();

	// LEDs_SetAllLEDs(ConfigSuccess ? LEDMASK_USB_READY : LEDMASK_USB_ERROR);
}

/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest(void)
{
	HID_Device_ProcessControlRequest(&F1_HID_Interface);
}

/** Event handler for the USB device Start Of Frame event. */
void EVENT_USB_Device_StartOfFrame(void)
{
	HID_Device_MillisecondElapsed(&F1_HID_Interface);
}

/** HID class driver callback function for the creation of HID reports to the host.
 *
 *  \param[in]     HIDInterfaceInfo  Pointer to the HID class interface configuration structure being referenced
 *  \param[in,out] ReportID    Report ID requested by the host if non-zero, otherwise callback should set to the generated report ID
 *  \param[in]     ReportType  Type of the report to create, either HID_REPORT_ITEM_In or HID_REPORT_ITEM_Feature
 *  \param[out]    ReportData  Pointer to a buffer where the created report should be stored
 *  \param[out]    ReportSize  Number of bytes written in the report (or zero if no report is to be sent)
 *
 *  \return Boolean \c true to force the sending of the report, \c false to let the library determine if it needs to be sent
 */
bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
                                         uint8_t* const ReportID,
                                         const uint8_t ReportType,
                                         void* ReportData,
                                         uint16_t* const ReportSize)
{
	uint8_t* Data        = (uint8_t*)ReportData;
	// uint8_t  CurrLEDMask = LEDs_GetLEDs();
	//
	// Data[0] = ((CurrLEDMask & LEDS_LED1) ? 1 : 0);
	// Data[1] = ((CurrLEDMask & LEDS_LED2) ? 1 : 0);
	// Data[2] = ((CurrLEDMask & LEDS_LED3) ? 1 : 0);
	// Data[3] = ((CurrLEDMask & LEDS_LED4) ? 1 : 0);

	*ReportSize = F1_REPORT_SIZE;
	return false;
}

/** HID class driver callback function for the processing of HID reports from the host.
 *
 *  \param[in] HIDInterfaceInfo  Pointer to the HID class interface configuration structure being referenced
 *  \param[in] ReportID    Report ID of the received report from the host
 *  \param[in] ReportType  The type of report that the host has sent, either HID_REPORT_ITEM_Out or HID_REPORT_ITEM_Feature
 *  \param[in] ReportData  Pointer to a buffer where the received report has been stored
 *  \param[in] ReportSize  Size in bytes of the received HID report
 */
void CALLBACK_HID_Device_ProcessHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
                                          const uint8_t ReportID,
                                          const uint8_t ReportType,
                                          const void* ReportData,
                                          const uint16_t ReportSize)
{
	uint8_t* Data       = (uint8_t*)ReportData;
	// uint8_t  NewLEDMask = LEDS_NO_LEDS;
	//
	// if (Data[0])
	//   NewLEDMask |= LEDS_LED1;
	//
	// if (Data[1])
	//   NewLEDMask |= LEDS_LED2;
	//
	// if (Data[2])
	//   NewLEDMask |= LEDS_LED3;
	//
	// if (Data[3])
	//   NewLEDMask |= LEDS_LED4;
	//
	// LEDs_SetAllLEDs(NewLEDMask);
}

// void F1_Send_Report_Task(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo, void* ReportData)
// {
// 	if (USB_DeviceState != DEVICE_STATE_Configured)
// 	  return;
//
// 	// if (HIDInterfaceInfo->State.PrevFrameNum == USB_Device_GetFrameNumber())
// 	// {
// 	// 	#if defined(USB_DEVICE_OPT_LOWSPEED)
// 	// 	if (!(USB_Options & USB_DEVICE_OPT_LOWSPEED))
// 	// 	  return;
// 	// 	#else
// 	// 	return;
// 	// 	#endif
// 	// }
//
// 	Endpoint_SelectEndpoint(F1_OUT_EPADDR);
// 	uint8_t Data2[SERIAL_EPSIZE];
//
// 	if (Endpoint_IsINReady())
// 	{
// 		uint8_t* Data        = (uint8_t*)ReportData;
//
// 		for (int i = 0; i < SERIAL_EPSIZE; i++)
// 		{
// 			Data2[i] = 0x00;
// 		}
//
// 		Data2[0] = 0x01;
//
// 		Endpoint_Write_Stream_LE(&Data2, sizeof(Data2), NULL);
// 		Endpoint_ClearIN();
// 	}
//
	// if (Endpoint_IsReadWriteAllowed())
	// {
	// 	uint8_t  ReportINData[HIDInterfaceInfo->Config.PrevReportINBufferSize];
	// 	uint8_t  ReportID     = 0;
	// 	uint16_t ReportINSize = 0;
	//
	// 	memset(ReportINData, 0, sizeof(ReportINData));
	//
	// 	bool ForceSend         = CALLBACK_HID_Device_CreateHIDReport(HIDInterfaceInfo, &ReportID, HID_REPORT_ITEM_In,
	// 	                                                             ReportINData, &ReportINSize);
	// 	bool StatesChanged     = false;
	// 	bool IdlePeriodElapsed = (HIDInterfaceInfo->State.IdleCount && !(HIDInterfaceInfo->State.IdleMSRemaining));
	//
	// 	if (HIDInterfaceInfo->Config.PrevReportINBuffer != NULL)
	// 	{
	// 		StatesChanged = (memcmp(ReportINData, HIDInterfaceInfo->Config.PrevReportINBuffer, ReportINSize) != 0);
	// 		memcpy(HIDInterfaceInfo->Config.PrevReportINBuffer, ReportINData, HIDInterfaceInfo->Config.PrevReportINBufferSize);
	// 	}
	//
	// 	if (ReportINSize && (ForceSend || StatesChanged || IdlePeriodElapsed))
	// 	{
	// 		HIDInterfaceInfo->State.IdleMSRemaining = HIDInterfaceInfo->State.IdleCount;
	//
	// 		Endpoint_SelectEndpoint(HIDInterfaceInfo->Config.ReportINEndpoint.Address);
	//
	// 		if (ReportID)
	// 		  Endpoint_Write_8(ReportID);
	//
	// 		Endpoint_Write_Stream_LE(ReportINData, ReportINSize, NULL);
	//
	// 		Endpoint_ClearIN();
	// 	}
	//
	// 	HIDInterfaceInfo->State.PrevFrameNum = USB_Device_GetFrameNumber();
	// }
// }

