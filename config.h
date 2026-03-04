#pragma once

#define DEBOUNCE 5

/* Reset. (May not be needed) */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

// Encoder Pins and resolutions
#define ENCODERS_PAD_A { B1, B3 }
#define ENCODERS_PAD_B { B2, B4 }
#define ENCODER_RESOLUTION 4
