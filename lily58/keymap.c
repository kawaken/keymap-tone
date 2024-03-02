#include QMK_KEYBOARD_H
#include "private.h"

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD,

  // Send keys
  MY_BKAR, // <- : back arrow
  MY_ARRW, // -> : arrow
  MY_DEQL, // == : double equal
  MY_NTEQ, // != : not equal
  MY_3GRV, // ``` : the phrase "```""

  MYS_ID, MYS_1P, MYS_MM, CMS_2P, CMS_VP, CMS_OK
};

#define MC_KANA KC_LNG1               // Mac KANA
#define MC_EISU KC_LNG2               // Mac EISU
#define MC_SCSH SGUI(KC_4)            // Mac Screen Shot selected area
#define MC_SCMV SGUI(KC_5)            // Mac Screen movie
#define MY_ESC  LT(_LOWER, KC_ESC)    // Held L1, Tap ESC
#define MY_ENT  LT(_RAISE, KC_ENT)    // Held L2, Tap Enter
#define MY_STRL MO(_ADJUST)           // MO L3
#define MY_MINS MT(MOD_RSFT, KC_MINS) // Held Shift, Tap -

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | EISU |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | KANA |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   `   |    |    =  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |L1/ESC| /Space  /       \  -   \  |L2/Ent|BackSP|ADJST |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  MC_EISU,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MC_KANA,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_GRV,   KC_EQL,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                           KC_LALT, KC_LGUI, MY_ESC, KC_SPC,   MY_MINS,  MY_ENT,  KC_BSPC, MY_STRL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   {  |   [  |   (  |  <-  |                    |  ->  |   )  |   ]  |   }  |      |   |  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   _  |   :  |   "  |
 * |------+------+------+------+------+------|   ~   |    |   +   |------+------+------+------+------+------|
 * |      |      |      |      |      | ```  |-------|    |-------|  ==  |  !=  |   <  |   >  |   ?  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |(HOLD)| /       /       \ KANA \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, XXXXXXX, KC_LCBR, KC_LBRC, KC_LPRN, MY_BKAR,                   MY_ARRW, KC_RPRN, KC_RBRC, KC_RCBR, KC_TRNS, KC_PIPE,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_COLN, KC_DQUO,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MY_3GRV, KC_TILD, KC_PLUS, MY_DEQL, MY_NTEQ, KC_LABK, KC_RABK, KC_QUES, _______,
                             _______, _______, _______, _______, MC_KANA, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Home | PgUp |PgDown| End  |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | / EISU  /       \      \  |(HOLD)|      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  _______, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                             _______, _______, _______,  MC_EISU, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |STR_OK|STR_VP|STR_2P|-------|    |-------|STR_1P|STR_MM|      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, CMS_OK,  CMS_VP,  CMS_2P,  XXXXXXX, XXXXXXX, MYS_1P,  MYS_MM,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case MY_BKAR:
        SEND_STRING ("<-");
        return false;
      case MY_ARRW:
        SEND_STRING ("->");
        return false;
      case MY_DEQL:
        SEND_STRING ("==");
        return false;
      case MY_NTEQ:
        SEND_STRING ("!=");
        return false;
      case MY_3GRV:
        SEND_STRING ("```");
        return false;
      case MYS_1P:
        send_string(MY_STR_1P);
        return false;
      case MYS_MM:
        send_string(MY_STR_MM);
        return false;
      case CMS_2P:
        send_string(CM_STR_2P);
        return false;
      case CMS_VP:
        send_string(CM_STR_VP);
        return false;
      case CMS_OK:
        send_string(CM_STR_OK);
        return false;
    }
  }
  return true;
}
