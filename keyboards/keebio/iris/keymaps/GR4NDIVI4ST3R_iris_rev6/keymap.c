#include QMK_KEYBOARD_H


#define _CL 0  // Keymap _CL: Colemak-DH Base Layer (Default Layer)
#define _QW 1  // Keymap _QW: QWERTY Layer
#define _NAV 2  // Keymap _NAV: Navigation Layer
#define _NUM 3  // Keymap _NUM: Numpad and Symbol Layer
#define _MAC 4  // Keymap _MAC: Macro and Function Key Layer
#define _GM 5  // Keymap _GM: Gaming Layer

enum custom_keycodes {
    // Custom Keycodes/Keycode Aliases
    CAPS = SAFE_RANGE,
    // Tap Dance Keycodes
    TD_LAYER,
    // Macro Keycodes
    EMAIL_PS, // Type Out Personal Email
    EMAIL_PR, // Type Out Professional Email
    BRANCH_XP // Type Out Name of Frequently Used Git Branch
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t *state);

// Putting these here means td_layer can be used in any keymap
void td_layer_finished(qk_tap_dance_state_t *state, void *user_data);
void td_layer_reset(qk_tap_dance_state_t *state, void *user_data);

// TODO: (UNICODE) Include special characters like +/- and implement needed changes to rules.mk, config.h, etc files
// Define Desired Special Characters Using Unicode
/* enum unicode_names {
    BANG,
    IRONY,
    SNEK
};
const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
}; */

// TODO: add ctrl + shift osm key on bottom left corner for one-handed commands
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_CL] = LAYOUT(
    //┌──────────────────────┬──────────────────────┬──────────────────────┬──────────────────────┬──────────────────────┬──────────────────────┐                                                      ┌──────────────────────┬──────────────────────┬──────────────────────┬──────────────────────┬──────────────────────┬──────────────────────┐
       KC_ESC,                KC_1,                  KC_2,                  KC_3,                  KC_4,                  KC_5,                                                                         KC_6,                  KC_7,                  KC_8,                  KC_9,                  KC_0,                  KC_BSPC,               
    //├──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┤                                                      ├──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┤
       KC_TAB,                KC_Q,                  KC_W,                  KC_F,                  KC_P,                  KC_B,                                                                         KC_J,                  KC_L,                  KC_U,                  KC_Y,                  KC_SCLN,               KC_DEL,                
    //├──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┤                                                      ├──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┤
       KC_LALT,               KC_A,                  KC_R,                  KC_S,                  KC_T,                  KC_G,                                                                         KC_M,                  KC_N,                  KC_E,                  KC_I,                  KC_O,                  KC_QUOT,               
    //├──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┐        ┌──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┼──────────────────────┤
       OSM(MOD_LCTL|MOD_LSFT),KC_Z,                  KC_X,                  KC_C,                  KC_D,                  KC_V,                  TD_LAYER,                       LGUI_T(KC_CAPS),       KC_K,                  KC_H,                  KC_COMM,               KC_DOT,                KC_SLSH,               KC_MINS,               
    //└──────────────────────┴──────────────────────┴──────────────────────┴───┬──────────────────┴───┬──────────────────┴───┬──────────────────┴───┬──────────────────┘        └──────────────────┬───┴──────────────────┬───┴──────────────────┬───┴──────────────────┬───┴──────────────────────┴──────────────────────┴──────────────────────┘
                                                                                LCTL_T(TG(_NAV)),      KC_SPC,                LSFT_T(KC_ENT),                                                       KC_LCTL,               TT(_NUM),              LALT_T(OSL(_MAC))
                                                                            // └──────────────────────┴──────────────────────┴──────────────────────┘                                              └──────────────────────┴──────────────────────┴──────────────────────┘
    ),

    [_QW] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, 
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, 
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, 
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,          _______, KC_N,    KC_M,    _______, _______, _______, _______, 
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └────┬───┴────┬───┴────┬───┴────┬───┴────────┴────────┴────────┘
                                      _______, _______, _______,                    _______, _______, _______
                                  // └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),

    [_NAV] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, 
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, XXXXXXX, XXXXXXX, KC_UP,   KC_HOME, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, _______, _______, _______, KC_END,  _______, XXXXXXX,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └────┬───┴────┬───┴────┬───┴────┬───┴────────┴────────┴────────┘
                                      _______, _______, _______,                    _______, XXXXXXX, XXXXXXX
                                  // └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),

    [_NUM] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_PAST, KC_LPRN, KC_RPRN, _______, 
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_TILD, KC_LBRC, KC_RBRC, KC_HOME, KC_PMNS,                            XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PCMM, _______, 
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_PIPE, KC_LCBR, KC_RCBR, KC_BSLS, KC_PPLS,                            KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PDOT, KC_PEQL, 
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_GRV,  KC_LT,   KC_GT,   KC_END,  KC_EQL,  XXXXXXX,          _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PSLS, KC_UNDS, 
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └────┬───┴────┬───┴────┬───┴────┬───┴────────┴────────┴────────┘
                                      XXXXXXX, _______, _______,                    _______, _______, XXXXXXX
                                  // └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    ),

    [_MAC] = LAYOUT(
    //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                            ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
       QK_BOOT,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                                 KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
       _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                               XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F12,   
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
       _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                               XXXXXXX,  EMAIL_PS, EMAIL_PR, BRANCH_XP,XXXXXXX,  XXXXXXX,  
    //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
       _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  
    //└─────────┴─────────┴─────────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┘        └─────┬───┴─────┬───┴─────┬───┴─────┬───┴─────────┴─────────┴─────────┘
                                         XXXXXXX,  _______,  _______,                       _______,  XXXXXXX,  _______
                                     // └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘
    ),

    [_GM] = LAYOUT(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, 
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, 
    //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, 
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, 
    //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └────┬───┴────┬───┴────┬───┴────┬───┴────────┴────────┴────────┘
                                      KC_SPC,  _______, _______,                    _______, XXXXXXX, XXXXXXX
                                  // └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    )
};

// Macro Execution
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

switch (keycode) {
    
    case LCTL_T(TG(_NAV)): // LCTL_T(TG(_NAV)) doesn't work on its own because TG(_NAV) is a 16-bit keycode and LCTL_T(kc) only accepts 8-bit keycodes for kc.
        if (record->tap.count && record->event.pressed) { // intercept key tap. Notice record->tap.count is "true" for tap.
            tap_code16(TG(_NAV)); // send TG(_NAV)
            return false;         // returning false ignores further processing of key tap
        }
        return true;              // return true processes the rest of the key normally. Therefore, LCTL_T(TG(_NAV)) will still output Left CTRL on hold as described by the keycode.
    
    case LALT_T(OSL(_MAC)):
        if (record->tap.count && record->event.pressed) { // intercept key tap.
            tap_code16(OSL(_MAC)); // send OSL(_MAC)
            return false;
        }
        return true;

    case EMAIL_PS:
        if (record->event.pressed) { // when given keycode is pressed
        SEND_STRING("xp.pk116@gmail.com");
        } else { // when given keycode is released

        }
        break;
    
    case EMAIL_PR:
        if (record->event.pressed) {
        SEND_STRING("ihsxaviorp@gmail.com");
        } else {

        }
        break;

    case BRANCH_XP:
        if (record->event.pressed) {
        SEND_STRING("GR4NDIVI4ST3R_gmmk2");
        } else {

        }
        break;
}

return true;
};

/* Assign Encoder Functionality
//bool encoder_update_user(uint8_t index, bool clockwise) {
//    if (index == 0) {
//        if (clockwise) {
//            tap_code(KC_VOLU);
//        } else {
//            tap_code(KC_VOLD);
//        }
//    }
//    else if (index == 1) {
//        if (clockwise) {
//            tap_code(KC_PGDN);
//        } else {
//            tap_code(KC_PGUP);
//        }
//    }
//    return false;
//} */

// TAP DANCE
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP'. See 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t td_layer_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void td_layer_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_layer_tap_state.state = cur_dance(state);
    switch (td_layer_tap_state.state) {
        case TD_SINGLE_TAP: register_code(TG(_GM)); break;
        case TD_TRIPLE_TAP: register_code(DF(_QW)); break;
    }
}

void td_layer_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_layer_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(TG(_GM)); break;
        case TD_TRIPLE_TAP: unregister_code(DF(_QW)); break;
    }
    td_layer_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_layer_finished, td_layer_reset)
};
