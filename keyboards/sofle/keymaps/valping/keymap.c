// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
	_GAMING,
    _LOWER,
    _RAISE,
    _ADJUST,
    _DISABLE,
};

enum custom_keycodes {
    KEYLOG_ON = SAFE_RANGE,
    KEYLOG_OFF,
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_GAMING PDF(_GAMING)
#define KC_DISABLE PDF(_DISABLE)
#define KC_LOCK_SCREEN LGUI(KC_L)
#define KC_QUIT LALT(KC_F4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |-------.    ,-------|   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|  VolU |    | ScrolU|- -----+------+------+------+------+-----|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |-------.    ,-------|   Y  |   U  |   I  |   O  |   P  |   |\ |
 * |------+------+------+------+------+------|  MUTE |    | PRINT |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  VolD |    | ScrolD|------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LGUI | LAlt |RAISE | /Space  /       \Enter \  |LOWER | DEL  | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------------------------------------'
 */



[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,     KC_PSCR, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                 KC_CAPS,    KC_LGUI, KC_LALT, TL_LOWR, KC_SPC,      KC_ENT,  TL_UPPR, KC_RALT, KC_RGUI, KC_DEL
),
/*
 * GAMING
 * ,-----------------------------------------.                               ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |-------.               ,-------|      |      |  /   |   *  |      |      |
 * |------+------+------+------+------+------|  VolU |               | ScrolU|------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |-------.               ,-------|      | Num7 | Num8 | Num9 |  -   |      |
 * |------+------+------+------+------+------|  MUTE |               | PRINT |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.               ,-------|      | Num4 | Num5 | Num6 |  +   |      |
 * |------+------+------+------+------+------|  VolUD|               | ScrolD|------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|               |-------| Num0 | Num1 | Num2 | Num3 |      | Enter|
 * `-----------------------------------------/       /                \      \-----------------------------------------'
 *            | ESC  | LGUI | LAlt |RAISE | /Space  /                  \Enter \  |LOWER | Del  | RAlt | RCtr |
 *            |      |      |      |      |/       /                    \      \ |      |      |      |      |
 *            `----------------------------------'                      '-----------------------------------'
 */

  [_GAMING] = LAYOUT(
    KC_GRV  , KC_1  ,   KC_2,   KC_3 ,  KC_4,    KC_5,                      XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, XXXXXXX, KC_BSPC,
    KC_TAB  , KC_Q  ,   KC_W,   KC_E,   KC_R,    KC_T,                      XXXXXXX,   KC_7 ,  KC_8  ,  KC_9  , KC_PMNS, XXXXXXX,
    KC_LSFT , KC_A  ,   KC_S,   KC_D,   KC_F,    KC_G,                      XXXXXXX,   KC_4 ,  KC_5  ,  KC_6  , KC_PPLS, XXXXXXX,
    KC_LCTL , KC_Z  ,   KC_X,   KC_C,   KC_V,    KC_B, KC_MUTE,     KC_PSCR, KC_0 ,   KC_1 ,  KC_2  ,  KC_3  , XXXXXXX , KC_ENT,
            KC_ESC , KC_LGUI, KC_LALT, TL_LOWR, KC_SPC,     			      KC_SPC, TL_UPPR, KC_DEL  , KC_RALT, KC_RCTL
  ),
/* RAISE
 * ,-----------------------------------------.                               ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |-------.               ,-------|  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|ScrolL |               | ScrolU|------+------+------+------+------+------|
 * |  `/~ |  6   |  7   |  8   |  9   |  0   |-------.               ,-------|      |      |      |      |      | F12  |
 * |------+------+------+------+------+------|  MUTE |               | PRINT |------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |  4   |  5   |-------.               ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|ScrolR |               | ScrolD|------+------+------+------+------+------|
 * |      |  =   |  -   |  +   |  {   |   }  |-------|               |-------|   [  |   ]  |   ;  |   :  |   \  |      |
 * `-----------------------------------------/       /                \      \-----------------------------------------'
 *            | LAlt | LGUI |  Del |RAISE | /Space  /                  \Enter \  |      |      |      |      |
 *            |      |      |      |      |/       /                    \      \ |      |      |      |      |
 *            `----------------------------------'                      '------------------------------------'
 */
[_RAISE] = LAYOUT(
  _______,    KC_F1,  KC_F2, KC_F3,   KC_F4,   KC_F5,                                  KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_GRV,     KC_6,   KC_7,  KC_8,    KC_9,    KC_0,                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,
  _______,    KC_1,   KC_2,  KC_3,    KC_4,    KC_5,                                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, _______,              _______, KC_LCBR, KC_RCBR, KC_SCLN, KC_COLN, KC_BSLS, _______,
                   KC_LALT, _______, KC_DEL, _______, _______,                     _______, _______, _______, _______, _______
),
/* LOWER
 * ,----------------------------------------.                                ,-----------------------------------------.
 * |      |Foward|B-Ward|      |      |      |-------.              ,-------|      |      |      |      |      |       |
 * |------+------+------+------+------+------|  VolU |              | TabU  |------+------+------+------+------+-------|
 * |      |Mouse1|  UP  |MOUSE2|MOUSE3|      |-------.              ,-------|PageUp| Del  |  Up  | Ins  | Acc0 |  Acc1 |
 * |------+------+------+------+------+------|  MUTE |              | PRINT |------+------+------+------+------+-------|
 * |      | LEFT | DOWN |RIGHT |      |      |-------.              ,-------|PageDn| Left | Down | Rigth|  End |  Home |
 * |------+------+------+------+------+------| VolUD |              | TabD  |------+------+------+------+------+------|
 * |      | Acc2 | Acc1 | Acc0 |      |      |-------|              |-------|Mouse1|Whel-L|Whel-U|Whel-D|Whel-R| Shift|
 * `-----------------------------------------/       /               \      \-----------------------------------------'
 *            |      |      |      |RAISE | /Space  /                 \Enter \  |LOWER | Prev | Stop | Next |
 *            |      |      |      |      |/       /                   \      \ |      |      |      |      |
 *            `----------------------------------'                     '------------------------------------'
 */
[_LOWER] = LAYOUT(
  _______, MS_BTN4 , MS_BTN5 , _______ , _______ , _______,                      _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,  MS_BTN1,  MS_UP,   MS_BTN2,  MS_BTN3, XXXXXXX,                       KC_PGUP, KC_DEL,  KC_UP,   KC_INS,  MS_ACL0, MS_ACL1,
  _______, MS_LEFT,  MS_DOWN,  MS_RGHT,  XXXXXXX, XXXXXXX,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_HOME,
  _______, MS_ACL2, MS_ACL1, MS_ACL0, _______, XXXXXXX,  _______,       _______, MS_BTN1, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, _______,
                   _______, _______, _______, _______, _______,             KC_LOCK_SCREEN, _______, KC_MPRV, KC_MPLY, KC_MNXT
),
/* ADJUST
 * ,-----------------------------------------.                               ,-----------------------------------------.
 * |      |      |LOG_ON|LOGOFF|      |      |-------.               ,-------|      | NumP |  /   |   *  |      |      |
 * |------+------+------+------+------+------|  VolU |               | ScrolU|------+------+------+------+------+------|
 * |QKBOOT|      |QWERTY|GAMING|DISABL|      |-------.               ,-------|      | Numu | Num8 | Num9 |  -   |      |
 * |------+------+------+------+------+------|  MUTE |               |ScrolLk|------+------+------+------+------+------|
 * |S-WAKE|S-Slep|      |      |      |MACWIN|-------.               ,-------|      | Num4 | Num5 | Num6 |  +   |      |
 * |------+------+------+------+------+------|  VolU |               | ScrolD|------+------+------+------+------+------|
 * |S-Down|      |C-Pnel| CALC |      | QUIT |-------|               |-------| Num0 | Num1 | Num2 | Num3 | Enter|      |
 * `-----------------------------------------/       /                \      \-----------------------------------------'
 *            | LGUI | LAlt |      |RAISE | /Enter  /                  \Space \  |LOWER | DOT  | RAlt | RGUI |
 *            |      |      |      |      |/       /                    \      \ |      |      |      |      |
 *            `----------------------------------'                      '------------------------------------'
 */
  [_ADJUST] = LAYOUT(
  _______ ,_______,  KEYLOG_ON ,KEYLOG_OFF , _______, _______,                       XXXXXXX, KC_NUM, KC_PSLS, KC_PAST, XXXXXXX, _______,
  QK_BOOT  ,XXXXXXX,KC_QWERTY,KC_GAMING,KC_DISABLE,XXXXXXX,                        XXXXXXX, KC_P7,  KC_P8,   KC_P9,   KC_PMNS, XXXXXXX,
  KC_WAKE , KC_SLEP,XXXXXXX, XXXXXXX, XXXXXXX,  CG_TOGG,                        XXXXXXX, KC_P4,  KC_P5,   KC_P6,   KC_PPLS, XXXXXXX,
  KC_PWR , XXXXXXX, KC_CPNL, KC_CALC, XXXXXXX,  KC_QUIT,_______,      KC_SCRL, KC_P0,   KC_P1,  KC_P2,   KC_P3,   KC_PENT, _______,
                   _______, _______, _______, _______, _______,          _______, _______, KC_PDOT, _______, _______
  ),
/* DISABLE
 * ,----------------------------------------.                                ,-----------------------------------------.
 * |      |      |      |      |      |      |-------.              ,-------|      |      |      |      |      |       |
 * |------+------+------+------+------+------|  VolU |              | ScrolU|------+------+------+------+------+-------|
 * |      |      |      |      |      |      |-------.              ,-------|      |      |      |      |      |       |
 * |------+------+------+------+------+------|  Base |              |  Game |------+------+------+------+------+-------|
 * |      |      |      |      |      |      |-------.              ,-------|      |      |      |      |      |       |
 * |------+------+------+------+------+------| VolUD |              | ScrolD|------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|              |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /               \      \-----------------------------------------'
 *            |      |      |      |      | /       /                 \      \  |      |      |      |      |
 *            |      |      |      |      |/       /                   \      \ |      |      |      |      |
 *            `----------------------------------'                     '------------------------------------'
 */
  [_DISABLE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QWERTY,       KC_GAMING, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};


const char *keycode_to_string(uint16_t keycode, bool shifted) {

    static char keylog_char[2] = {' ', '\0'};

    // A-Z
    if (keycode >= KC_A && keycode <= KC_Z) {
        keylog_char[0] =
            (shifted ? 'A' : 'a') + (keycode - KC_A);
        return keylog_char;
    }

    // 0-9
    if (keycode >= KC_1 && keycode <= KC_9) {

        const char normal[]  = "123456789";
        const char shifted_[] = "!@#$%^&*(";

        keylog_char[0] =
            shifted
            ? shifted_[keycode - KC_1]
            : normal[keycode - KC_1];

        return keylog_char;
    }

    if (keycode == KC_0) {
        keylog_char[0] = shifted ? ')' : '0';
        return keylog_char;
    }

    switch (keycode) {

        case KC_SPC:
            keylog_char[0] = ' ';
            return keylog_char;

        case KC_DOT:
            keylog_char[0] = shifted ? '>' : '.';
            return keylog_char;

        case KC_COMM:
            keylog_char[0] = shifted ? '<' : ',';
            return keylog_char;

        case KC_SLSH:
            keylog_char[0] = shifted ? '?' : '/';
            return keylog_char;

        case KC_SCLN:
            keylog_char[0] = shifted ? ':' : ';';
            return keylog_char;

        case KC_QUOT:
            keylog_char[0] = shifted ? '"' : '\'';
            return keylog_char;

        case KC_BSPC:
            return "BSP";

        case KC_ENT:
            return "ENT";

        default:
            return NULL;
    }
}


#include "oled.c"
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {

        last_typing_time = timer_read32();

        switch (keycode) {

            case KEYLOG_ON:
                show_keylog = true;
                return false;

            case KEYLOG_OFF:
                show_keylog = false;
                return false;
        }

        if (show_keylog) {

            bool shifted =
                (get_mods() & MOD_MASK_SHIFT) ||
                (host_keyboard_led_state().caps_lock &&
                keycode >= KC_A &&
                keycode <= KC_Z);

            const char *key_str = keycode_to_string(keycode, shifted);

            if (key_str != NULL) {
                snprintf(
                    keylog_str,
                    sizeof(keylog_str),
                    "%s",
                    key_str
                );

                keylog_timer = timer_read32();
            }
        }
    }

    return true;
}


// =======================
// KEY OVERRIDES
// =======================

// Alt + BSPC => DEL
const key_override_t delete_key_override =
    ko_make_basic(MOD_MASK_ALT, KC_BSPC, KC_DEL);
    
// Shift + DEL => BSPC
const key_override_t backspace_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_DEL, KC_BSPC);

const key_override_t *key_overrides[] = {
    &backspace_key_override,
    &delete_key_override,
    NULL
};

// !IMPORTANT (Make sure you disable the default encoder behavior)
//
// This function is called when the encoder is turned
// It is used to change the volume and scroll the screen
// The encoder is set to change the volume when the layer is 0 or 1
// and to scroll the screen when the layer is 2 or 3
#ifdef ENCODER_ENABLE

bool encoder_update_kb(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _RAISE:
        
            if (index == 0) {
                if (clockwise) {
                    tap_code(MS_WHLL);
                } else {
                    tap_code(MS_WHLR);
                }
            }
            
            else if (index == 1) {
                if (clockwise) {
                    tap_code(MS_WHLU);
                } else {
                    tap_code(MS_WHLD);
                }
            }
            break;
        case _LOWER:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            }
            else if(index == 1){
                if (clockwise) {
                    tap_code(MS_WHLR);
                } else {
                    tap_code(MS_WHLL);
                }

            }                                       

        break;
        
        case _ADJUST:
            if (index == 0) {
                if (clockwise) {
                    tap_code16(C(KC_EQL));
                } else {
                    tap_code16(C(KC_MINS));
                }
            }   
            else if (index == 1) {
                if (clockwise) {
                    tap_code(MS_WHLU);
                } else {
                    tap_code(MS_WHLD);
                }
            }                               
        break;

        default:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
            }
            else if (index == 1) {
                if (clockwise) {
                    tap_code(MS_WHLU);
                } else {
                    tap_code(MS_WHLD);
                }
            }
        break;
    }
    return true;
}

#endif
