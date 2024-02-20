/* Copyright 2021 peraneko
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "private.h"

// zoom shortcut
// https://support.zoom.us/hc/en-us/articles/205683899-Hot-Keys-and-Keyboard-Shortcuts-for-Zoom

#define ZM_AUDIO  G(S(KC_F11)) // Mute/unmute audio (shortcut customization required)
#define ZM_PTT    KC_SPACE     // Push to talk
#define ZM_VIDEO  G(S(KC_F12)) // Start/stop video (shortcut customization required)
#define ZM_SCREEN G(S(KC_S))   // Start/stop screen share
#define ZM_VIEW   G(S(KC_W))   // Switch to active speaker view or gallery view
#define ZM_LEAVE  G(KC_W)      // Prompt to End or Leave Meeting
#define ZM_CONTRL C(KC_BSLS)   // Toggle the "Always Show meeting controls" options in Settings/Accessibility

// Magnet shortcut

#define MG_LEFT  LCA(KC_LEFT)  // Left
#define MG_RIGHT LCA(KC_RIGHT) // Right
#define MG_L1THD LCA(KC_D)     // Left one third
#define MG_C1THD LCA(KC_F)     // Center one third
#define MG_R1THD LCA(KC_G)     // Right one third
#define MG_L2THD LCA(KC_E)     // Left two third
#define MG_R2THD LCA(KC_T)     // Right two third
#define MG_MAX   LCA(KC_ENTER) // Maximum Screen
#define MG_RESET LCA(KC_BSPC)  // Reset

#define MY_STR SAFE_RANGE


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        MG_LEFT,  MG_RIGHT, ZM_VIDEO, ZM_AUDIO,
        MG_L1THD, MG_R2THD, MG_MAX,   MY_STR
    )
};

/* Rotary encoder settings */
bool encoder_update_user(uint8_t index, bool clockwise) {
   if (clockwise) {
        tap_code(KC_VOLD);    //Rotary encoder clockwise
    } else {
        tap_code(KC_VOLU);  //Rotary encoder Reverse clockwise
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_STR:
            if (record->event.pressed) {
                send_string(MY_STRING);
            }
            return false;
    }
    return true;
}