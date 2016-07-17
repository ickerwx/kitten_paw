
const uint8_t PROGMEM keymaps[][MATRIX_COLS][MATRIX_ROWS] = {
    /* Layer 0: Standard ANSI layer */
    KEYMAP(\
         ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11,  F12,        PSCR,SLCK,PAUS,                         \
         GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS, EQL,BSPC,   INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS, \
         TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,   DEL, END, PGDN,    P7,  P8,  P9,  PPLS, \
         RALT,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,      ENT,                      P4,  P5,  P6,        \
         LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,        UP,           P1,  P2,  P3,  PENT, \
         LCTL,LGUI,LALT,               SPC,                FN0, FN1,  FN2,RCTL,   LEFT,DOWN,RGHT,    P0,  PDOT),          \
    /* Layer 1: programming layer 1*/
    KEYMAP(\
          ESC,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        TRNS,TRNS,TRNS,                         \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,SLSH,FN16,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS, \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN17,FN18,FN21,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS, \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN19,FN20,     TRNS,                      TRNS,TRNS,TRNS,      \
         FN31,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN22,     TRNS,        TRNS,         TRNS,TRNS,TRNS,TRNS, \
         TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS),
    /* Layer 2: programming layer 2*/
    KEYMAP(\
          ESC,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        TRNS,TRNS,TRNS,                         \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN23,RBRC,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS, \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN24,FN25,FN28,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS, \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN26,FN27,     TRNS,                      TRNS,TRNS,TRNS,      \
         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NUBS,FN29,FN30,     TRNS,        TRNS,         TRNS,TRNS,TRNS,TRNS, \
         TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS),
    /* Layer 3: media layer */
    KEYMAP(\
          FN3,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,        MPRV,MPLY,MNXT,                         \
           NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,     NO,  NO,VOLU,      NO,  NO,  NO,  NO, \
           NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,     NO,MUTE,VOLD,      NO,  NO,  NO,  NO, \
           NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,       NO,                        NO,  NO,  NO,      \
           NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,       NO,          NO,           NO,  NO,  NO,  NO, \
           NO,  NO,  NO,                 NO,                 NO,  NO,TRNS,  NO,     NO,  NO,  NO,      NO,  NO),
    /* Layer 4: Mouse layer */
    KEYMAP(\
          FN3,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,          NO,  NO,  NO,                         \
           NO,BTN1,BTN2,BTN3,BTN4,BTN5,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,     NO,  NO,  NO,      NO,  NO,  NO,  NO, \
           NO,  NO,BTN4,MS_U,BTN5,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,     NO,  NO,  NO,      NO,  NO,  NO,  NO, \
           NO,  NO,MS_L,MS_D,MS_R,  NO,WH_L,WH_D,WH_U,WH_R,  NO,  NO,     BTN1,                        NO,  NO,  NO,      \
         LSFT,  NO,  NO,  NO,  NO,  NO,  NO,BTN2,BTN3,  NO,  NO,  NO,     RSFT,          NO,           NO,  NO,  NO,  NO, \
         LCTL,  NO,  NO,               BTN1,                FN0,  NO, APP,RCTL,     NO,  NO,  NO,      NO,  NO)

};

static const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TOGGLE(4),
    [1] = ACTION_LAYER_TOGGLE(1),
    [2] = ACTION_LAYER_TAP_KEY(3, KC_APP),
    [3] = ACTION_LAYER_SET_CLEAR(0),
    [16] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
    [17] = ACTION_MODS_KEY(MOD_RALT,KC_8),
    [18] = ACTION_MODS_KEY(MOD_RALT,KC_9),
    [19] = ACTION_MODS_KEY(MOD_LSFT,KC_COMM),
    [20] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),
    [21] = ACTION_MODS_KEY(MOD_RALT, KC_MINS),
    [22] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
    [23] = ACTION_MODS_KEY(MOD_LSFT, KC_SLSH),
    [24] = ACTION_MODS_KEY(MOD_RALT, KC_7),
    [25] = ACTION_MODS_KEY(MOD_RALT, KC_0),
    [26] = ACTION_MODS_KEY(MOD_LSFT, KC_DOT),
    [27] = ACTION_MODS_KEY(MOD_LSFT, KC_2),
    [28] = ACTION_MODS_KEY(MOD_RALT, KC_NUBS),
    [29] = ACTION_MODS_KEY(MOD_LSFT, KC_NUBS),
    [30] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS),
    [31] = ACTION_LAYER_MOMENTARY(2)
};

