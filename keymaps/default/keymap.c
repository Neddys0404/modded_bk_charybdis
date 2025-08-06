// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum modded_charybdis_keymap_layers {
     LAYER_BASE = 0,
     LAYER_QUOTE,
     LAYER_NUM,
     LAYER_MACRO,
     LAYER_MSE,
};

enum custom_keys {
     AUTO_IF_P = SAFE_RANGE,
     AUTO_FOR_P,
     AUTO_WHILE_P,
     AUTO_CASE_P,
     AUTO_IF_C,
     AUTO_FOR_C,
     AUTO_WHILE_C,
     AUTO_CASE_C,
     DRAG_SCROLL,
     SWITCH_TAB,
     OPEN_YT,
     OPEN_WS,
     OPEN_VSC,
     OPEN_PUTTY,
     OPEN_STEAM,
     OPEN_YTM,
     OPEN_FOLDER,
     SCREENSNIP,
};

bool set_scrolling = false;

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 12.0
#define SCROLL_DIVISOR_V 12.0

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Check if drag scrolling is active
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)-mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

// Function to handle layer changes and disable drag scrolling when not in AUTO_MOUSE_DEFAULT_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    // Disable set_scrolling if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
    if (get_highest_layer(state) != LAYER_MSE) {
        set_scrolling = false;
    }
    return state;
}

#define QUOTE MO(LAYER_QUOTE)
#define NUM MO(LAYER_NUM)
#define MACRO MO(LAYER_MACRO)

#define SFT_Z SFT_T(KC_Z)
#define SFT_SLSH SFT_T(KC_SLSH)
#define GUI_SPC GUI_T(KC_SPC)
#define NUM_ENT LT(LAYER_NUM,KC_ENT)
#define QUOTE_BSPC  LT(LAYER_QUOTE,KC_BSPC)
#define MSE_L LT(LAYER_MSE,KC_L)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     switch (keycode) {
          case AUTO_IF_P:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("if ():\n" SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               break;
          case AUTO_FOR_P:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("for i in range(len()):\n" SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               break;
          case AUTO_WHILE_P:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("while ():\n" SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               break;
          case AUTO_IF_C:
               if   (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("if () {\n\n\n\n}\n" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               break;
          case AUTO_FOR_C:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("for (int i = 0; i < var.length; i++) {\n\n\n\n}\n" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               break;
          case AUTO_WHILE_C:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING("while () {\n\n\n\n}\n" SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_UP) SS_TAP(X_TAB));
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case DRAG_SCROLL:
               // Toggle set_scrolling when DRAG_SCROLL key is pressed or released
               set_scrolling = record->event.pressed;
               break;

          case SWITCH_TAB:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_UP(X_LCTL) SS_UP(X_LSFT));
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_YT:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING_DELAY(SS_LGUI("r"), 200);
                    SEND_STRING("chrome "); 
                    SEND_STRING("https://www.youtube.com"); 
                    SEND_STRING(SS_TAP(X_ENTER)); 
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_WS:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_LGUI("4")); //this requires whatsapp to be at first icon in the task bar 
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_VSC:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING_DELAY(SS_LGUI("r"), 200);
                    SEND_STRING("Code"); 
                    SEND_STRING(SS_TAP(X_ENTER)); 
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_PUTTY:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING_DELAY(SS_LGUI("r"), 200); 
                    SEND_STRING("PUTTY"); 
                    SEND_STRING(SS_TAP(X_ENTER)); 
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_STEAM:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_LGUI("1")); //this requires steam to be at first icon in the task bar
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_YTM:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_LGUI("2")); //this requires youtube music to be at second icon in the task bar
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case OPEN_FOLDER:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING(SS_LGUI("3")); //this requires File Explorer to be at third icon in the task bar
               } else {
                    // when keycode QMKURL is released
               }
               break;

          case SCREENSNIP:
               if (record->event.pressed) {
                    // when keycode QMKURL is pressed
                    SEND_STRING_DELAY(SS_LGUI("r"), 200);
                    SEND_STRING("SnippingTool"); 
                    SEND_STRING(SS_TAP(X_ENTER)); 
               } else {
                    // when keycode QMKURL is released
               }
               break;
     }
     return true;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    MSE_L, KC_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          SFT_Z,   KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, SFT_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_LCTL, KC_TAB, GUI_SPC,       KC_LALT, NUM_ENT, QUOTE_BSPC
  //                   ╰───────────────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_QUOTE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮     
       KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  KC_COLN,    KC_TILD, KC_MRWD, KC_MPLY, KC_MFFD,  KC_DEL,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_PIPE,    KC_ESC,  KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LBRC, KC_QUOT, KC_DQUO, KC_RBRC, KC_BSLS,    KC_CAPS, KC_VOLD, KC_MUTE, KC_VOLU, KC_RSFT,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, XXXXXXX, _______,    _______, XXXXXXX, _______
  //                   ╰───────────────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_NUM] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_CAPS, KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT, KC_PGUP, KC_PGDN,  KC_END, MACRO,      XXXXXXX, XXXXXXX, KC_COMM, KC_DOT, SFT_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, XXXXXXX, _______,    _______, _______, XXXXXXX
  //                   ╰───────────────────────────╯ ╰───────────────────────────╯
  ),

  [LAYER_MACRO] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, OPEN_PUTTY, OPEN_STEAM, SCREENSNIP,    OPEN_YT,     AUTO_IF_P,  AUTO_FOR_P,   AUTO_WHILE_P, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, OPEN_YTM,  OPEN_FOLDER,    XXXXXXX,    OPEN_WS,     AUTO_IF_C,  AUTO_FOR_C,   AUTO_WHILE_C, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,    _______,    OPEN_VSC,   SWITCH_TAB,     XXXXXXX,        XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────────────╯
                         _______,       XXXXXXX,    _______,    _______,     _______,    XXXXXXX
  //                   ╰────────────────────────────────────╯ ╰──────────────────────────────────╯
  ),

  [LAYER_MSE] = LAYOUT(
  // ╭─────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,    XXXXXXX, DRAG_SCROLL, MS_BTN3, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,    XXXXXXX, MS_BTN1, MS_BTN2, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, DRAG_SCROLL, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______,     _______,    _______, XXXXXXX, XXXXXXX
  //                   ╰───────────────────────────────╯ ╰───────────────────────────╯
  ),

};
// clang-format on
