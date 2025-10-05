// Copyright 2025 J. Russell Smyth

#pragma once


// not sure i want this?
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define BOOTMAGIC_LITE_ROW    0
#define BOOTMAGIC_LITE_COLUMN 5

// When USB_VBUS_PIN is not defined, SPLIT_USB_DETECT is used.
#define USB_VBUS_PIN GP24 // for Raspberry Pi Pico
