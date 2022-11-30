/*
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016 - 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __USB_DEVICE_DESCRIPTOR_H__
#define __USB_DEVICE_DESCRIPTOR_H__

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define USB_DEVICE_SPECIFIC_BCD_VERSION (0x0200U)
#define USB_DEVICE_DEMO_BCD_VERSION (0x0101U)

#define USB_DEVICE_VID (0x1FC9U)
#define USB_DEVICE_PID (0x0091U)

//#define USB_DEVICE_VID (0x1FC9U)
//#define USB_DEVICE_PID (0x0091U)

#define USB_DEVICE_CLASS (0xFFU)
#define USB_DEVICE_SUBCLASS (0xFFU)
#define USB_DEVICE_PROTOCOL (0xFFU)

#define USB_DEVICE_MAX_POWER (0xFAU)

#define USB_DESCRIPTOR_LENGTH_CONFIGURATION_ALL (sizeof(g_UsbDeviceConfigurationDescriptor))
#define USB_DESCRIPTOR_LENGTH_HID_XINPUT_REPORT (sizeof(g_UsbDeviceHidXInputReportDescriptor))
#define USB_DESCRIPTOR_LENGTH_HID (9U)
#define USB_DESCRIPTOR_LENGTH_STRING0 (sizeof(g_UsbDeviceString0))
#define USB_DESCRIPTOR_LENGTH_STRING1 (sizeof(g_UsbDeviceString1))
#define USB_DESCRIPTOR_LENGTH_STRING2 (sizeof(g_UsbDeviceString2))

#define USB_DEVICE_CONFIGURATION_COUNT (1U)
#define USB_DEVICE_STRING_COUNT (3U)
#define USB_DEVICE_LANGUAGE_COUNT (1U)

#define USB_HID_XINPUT_CONFIGURE_INDEX (1U)
#define USB_HID_XINPUT_INTERFACE_COUNT (1U)

#define USB_HID_XINPUT_IN_BUFFER_LENGTH (8U)
#define USB_HID_XINPUT_ENDPOINT_COUNT (2U)
#define USB_HID_XINPUT_INTERFACE_INDEX (0U)
#define USB_HID_XINPUT_ENDPOINT_IN (1U)
#define USB_HID_XINPUT_ENDPOINT_OUT (2U)

#define USB_HID_XINPUT_INTERFACE_ALTERNATE_COUNT (1U)
#define USB_HID_XINPUT_INTERFACE_ALTERNATE_0 (0U)

#define USB_HID_XINPUT_CLASS (0xFFU)
#define USB_HID_XINPUT_SUBCLASS (0x5DU)
#define USB_HID_XINPUT_PROTOCOL (0x01U)

#define HS_HID_XINPUT_INTERRUPT_IN_PACKET_SIZE (32U)
#define FS_HID_XINPUT_INTERRUPT_IN_PACKET_SIZE (32U)
#define HS_HID_XINPUT_INTERRUPT_IN_INTERVAL (0x06U) /* 2^(6-1) = 4ms */
#define FS_HID_XINPUT_INTERRUPT_IN_INTERVAL (0x01U)
#define HS_HID_XINPUT_INTERRUPT_OUT_PACKET_SIZE (32U)
#define FS_HID_XINPUT_INTERRUPT_OUT_PACKET_SIZE (32U)
#define HS_HID_XINPUT_INTERRUPT_OUT_INTERVAL (0x06U) /* 2^(6-1) = 4ms */
#define FS_HID_XINPUT_INTERRUPT_OUT_INTERVAL (0x08U)

#define OS_STRING_DESCRIPTOR_LENGTH 0x12U
#define OS_STRING_DESCRIPTOR_VENDOE_CODE 0xAE

#define OS_FEATURE_DESCRIPTOR_LENGTH 0x0028
#define OS_FEATURE_DESCRIPTOR_VERSION 0x0100

/*******************************************************************************
 * API
 ******************************************************************************/

/* Configure the device according to the USB speed. */
extern usb_status_t USB_DeviceSetSpeed(usb_device_handle handle, uint8_t speed);

/* Get device descriptor request */
usb_status_t USB_DeviceGetDeviceDescriptor(usb_device_handle handle,
                                           usb_device_get_device_descriptor_struct_t *deviceDescriptor);

#if (defined(USB_DEVICE_CONFIG_CV_TEST) && (USB_DEVICE_CONFIG_CV_TEST > 0U))
/* Get device qualifier descriptor request */
usb_status_t USB_DeviceGetDeviceQualifierDescriptor(
    usb_device_handle handle, usb_device_get_device_qualifier_descriptor_struct_t *deviceQualifierDescriptor);
#endif

/* Get device configuration descriptor request */
usb_status_t USB_DeviceGetConfigurationDescriptor(
    usb_device_handle handle, usb_device_get_configuration_descriptor_struct_t *configurationDescriptor);

/* Get device string descriptor request */
usb_status_t USB_DeviceGetStringDescriptor(usb_device_handle handle,
                                           usb_device_get_string_descriptor_struct_t *stringDescriptor);

/* Get hid descriptor request */
usb_status_t USB_DeviceGetHidDescriptor(usb_device_handle handle,
                                        usb_device_get_hid_descriptor_struct_t *hidDescriptor);

/* Get hid report descriptor request */
usb_status_t USB_DeviceGetHidReportDescriptor(usb_device_handle handle,
                                              usb_device_get_hid_report_descriptor_struct_t *hidReportDescriptor);

/* Get hid physical descriptor request */
usb_status_t USB_DeviceGetHidPhysicalDescriptor(usb_device_handle handle,
                                                usb_device_get_hid_physical_descriptor_struct_t *hidPhysicalDescriptor);

/* Handle Vendor Request*/
usb_status_t USB_DeviceHandleVendorRequest(usb_device_handle handle, usb_device_control_request_struct_t* req);
#endif /* __USB_DEVICE_DESCRIPTOR_H__ */
