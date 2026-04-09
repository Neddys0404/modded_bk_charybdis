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

bool encoder_update_user(uint8_t index, bool clockwise) {
     if (is_keyboard_left()) {
          // Left encoder behavior
          switch (get_highest_layer(layer_state)) {
               case LAYER_BASE:
                    if (clockwise) {
                         tap_code(KC_VOLU);
                    } else {
                         tap_code(KC_VOLD);
                    }
                    break;

               case LAYER_MAC_ONE:
                    if (clockwise) {
                         tap_code(KC_PGDN);
                    } else {
                         tap_code(KC_PGUP);
                    }
                    break;

               case LAYER_MAC_TWO:
                    if (clockwise) {
                         tap_code(KC_RIGHT);
                    } else {
                         tap_code(KC_LEFT);
                    }
                    break;

               default:
                    break;
          }
     } else {
          // Right encoder behavior
          switch (get_highest_layer(layer_state)) {
               case LAYER_BASE:
                    if (clockwise) {
                         tap_code(KC_VOLU);
                    } else {
                         tap_code(KC_VOLD);
                    }
                    break;

               case LAYER_MAC_ONE:
                    if (clockwise) {
                         tap_code(KC_PGDN);
                    } else {
                         tap_code(KC_PGUP);
                    }
                    break;

               case LAYER_MAC_TWO:
                    if (clockwise) {
                         tap_code(KC_RIGHT);
                    } else {
                         tap_code(KC_LEFT);
                    }
                    break;

               default:
                    break;
          }
     }
     return true;
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
  // ╭───────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────╮
          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_BSPC,
  // ├───────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────┤
          KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    MSE_L,    KC_SCLN,  KC_ENT,
  // ├───────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────┤
          KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM,  KC_DOT,  SFT_SLSH, KC_RSFT,
  // ╰───────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────╯
                         KC_LCTL, KC_LALT, GUI_SPC,  KC_ENT,       KC_ENT,  NUM_ENT, QUOTE_BSPC
  //                   ╰─────────────────────────────────────╯ ╰────────────────────────────────╯
  ),

  [LAYER_QUOTE] = LAYOUT(
  // ╭───────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────╮
          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_BSPC,
  // ├───────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────┤
          KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    MSE_L,    KC_SCLN,  KC_ENT,
  // ├───────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────┤
          KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM,  KC_DOT,  SFT_SLSH, KC_RSFT,
  // ╰───────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────╯
                         KC_LCTL, KC_LALT, GUI_SPC,  KC_ENT,       KC_ENT,  XXXXXXX, _______
  //                   ╰─────────────────────────────────────╯ ╰─────────────────────────────╯
  ),

  [LAYER_NUM] = LAYOUT(
  // ╭───────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────╮
          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_BSPC,
  // ├───────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────┤
          KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    MSE_L,    KC_SCLN,  KC_ENT,
  // ├───────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────┤
          KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM,  KC_DOT,  SFT_SLSH, KC_RSFT,
  // ╰───────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────╯
                         KC_LCTL, KC_LALT, GUI_SPC,  KC_ENT,       KC_ENT,  _______, XXXXXXX
  //                   ╰─────────────────────────────────────╯ ╰─────────────────────────────╯
  ),

};
// clang-format on
