#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.


enum custom_keycodes {
    XXCOPY = 0,
	XXPASTE,
	XXCUT,
	XXUNDO
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case XXCOPY:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
             SEND_STRING("coy");
        } else {
            // when keycode QMKBEST is released
        }
        break;
	case XXPASTE:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("paste"); 
        } else {
            // when keycode QMKBEST is released
        }
        break;
	case XXCUT:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
           SEND_STRING(SS_LCTL("x")); 
        } else {
            // when keycode QMKBEST is released
        }
        break;
	case XXUNDO:
        if (record->event.pressed) {
            // when keycode QMKBEST is fzz
            SEND_STRING(SS_LCTL("Z")); 
        } else {
           
        }
        break;
	}
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
  KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_PGUP,
  TO(1),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,            KC_PGDN,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_END,
  KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(1),    KC_LEFT,  KC_DOWN,  KC_RGHT),

[1] = LAYOUT(
   KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,  KC_INS,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,  KC_SCRL,  KC_PAUS,   _______,  _______,
  TO(0),  RGB_HUI,  RGB_HUD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  
  _______,  XXUNDO,  XXCUT,  XXCOPY,  XXPASTE,  KC_MUTE,  KC_VOLU,  KC_VOLD,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,   RGB_VAI,  KC_HOME,
  _______,  _______,  _______,                                RESET,                                  _______,  _______,  RGB_RMOD,  RGB_VAD,  RGB_MOD),

[2] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,
  _______,  _______,  _______,                                _______,                                _______,  _______,  _______,   _______,  _______)
};

