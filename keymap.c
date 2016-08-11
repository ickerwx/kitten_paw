/*
Copyright 2014 Ralf Schmitt <ralf@bunkertor.net>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "debug.h"
#include "keymap.h"
#include "mousekey.h"
#include "wait.h"

/*
  Matrix col/row mapping
  
  ,----.    ,-------------------. ,-------------------. ,-------------------. ,--------------.
  | J6 |    | I4 | H4 | H2 | H6 | | A7 | E6 | D2 | D4 | | B4 | B7 | B6 | B0 | | C7 | C5 | A5 |
  `----'    `-------------------' `-------------------' `-------------------' `--------------'
  ,-------------------------------------------------------------------------. ,--------------. ,-------------------.
  | J4 | J7 | I7 | H7 | G7 | G4 | F4 | F7 | E7 | D7 | R7 | R4 | E4 |     B2 | | L4 | O4 | Q4 | | K1 | L1 | Q1 | Q0 |
  |-------------------------------------------------------------------------| |--------------| |-------------------|
  | J2   | J5 | I5 | H5 | G5 | G2 | F2 | F5 | E5 | D5 | R5 | R2 | E2 |   B3 | | K4 | O7 | Q7 | | K5 | L5 | Q5 | O5 |
  |-------------------------------------------------------------------------| '--------------' |--------------     |
  | O5    | J3 | I3 | H3 | G3 | G6 | F6 | F3 | E3 | D3 | R3 | R6 |       B1 |                  | K2 | L2 | Q2 |    |
  |-------------------------------------------------------------------------|      ,----.      |-------------------|
  | N2      | J1 | I1 | H1 | G1 | G0 | F0 | F1 | E1 | D1 | R0 |          N3 |      | O6 |      | K3 | L3 | Q3 | O3 |
  |-------------------------------------------------------------------------| ,--------------. |--------------     |
  | A4 | P2 | C6 |                  K6                  | C0 | M3 | D0 | A1 | | O0 | K0 | L0 | | L6      | Q6 |    |
  `-------------------------------------------------------------------------' `--------------' `-------------------'
*/

#define KEYMAP( \
  KJ6,      KI4, KH4, KH2, KH6, KA7, KE6, KD2, KD4, KB4, KB7, KB6, KB0,   KC7, KC5, KA5,                       \
  KJ4, KJ7, KI7, KH7, KG7, KG4, KF4, KF7, KE7, KD7, KR7, KR4, KE4, KB2,   KL4, KO4, KQ4,   KK1, KL1, KQ1, KQ0, \
  KJ2, KJ5, KI5, KH5, KG5, KG2, KF2, KF5, KE5, KD5, KR5, KR2, KE2, KB3,   KK4, KO7, KQ7,   KK5, KL5, KQ5, KO5, \
  KI2, KJ3, KI3, KH3, KG3, KG6, KF6, KF3, KE3, KD3, KR3, KR6,      KB1,                    KK2, KL2, KQ2,      \
  KN2, KI6, KJ1, KI1, KH1, KG1, KG0, KF0, KF1, KE1, KD1, KR0,      KN3,        KO6,        KK3, KL3, KQ3, KO3, \
  KA4, KP2, KC6,                KK6,                KC0, KM3, KD0, KA1,   KO0, KK0, KL0,   KL6,      KQ6       \
) \
{ \
  /* 0       1         2         3         4         5         6         7               */ \
  {KC_NO,    KC_##KA1, KC_NO,    KC_NO,    KC_##KA4, KC_##KA5, KC_NO,    KC_##KA7}, /* A */ \
  {KC_##KB0, KC_##KB1, KC_##KB2, KC_##KB3, KC_##KB4, KC_NO,    KC_##KB6, KC_##KB7}, /* B */ \
  {KC_##KC0, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_##KC5, KC_##KC6, KC_##KC7}, /* C */ \
  {KC_##KD0, KC_##KD1, KC_##KD2, KC_##KD3, KC_##KD4, KC_##KD5, KC_NO,    KC_##KD7}, /* D */ \
  {KC_NO,    KC_##KE1, KC_##KE2, KC_##KE3, KC_##KE4, KC_##KE5, KC_##KE6, KC_##KE7}, /* E */ \
  {KC_##KF0, KC_##KF1, KC_##KF2, KC_##KF3, KC_##KF4, KC_##KF5, KC_##KF6, KC_##KF7}, /* F */ \
  {KC_##KG0, KC_##KG1, KC_##KG2, KC_##KG3, KC_##KG4, KC_##KG5, KC_##KG6, KC_##KG7}, /* G */ \
  {KC_NO,    KC_##KH1, KC_##KH2, KC_##KH3, KC_##KH4, KC_##KH5, KC_##KH6, KC_##KH7}, /* H */ \
  {KC_NO,    KC_##KI1, KC_##KI2, KC_##KI3, KC_##KI4, KC_##KI5, KC_##KI6, KC_##KI7}, /* I */ \
  {KC_NO,    KC_##KJ1, KC_##KJ2, KC_##KJ3, KC_##KJ4, KC_##KJ5, KC_##KJ6, KC_##KJ7}, /* J */ \
  {KC_##KK0, KC_##KK1, KC_##KK2, KC_##KK3, KC_##KK4, KC_##KK5, KC_##KK6, KC_NO   }, /* K */ \
  {KC_##KL0, KC_##KL1, KC_##KL2, KC_##KL3, KC_##KL4, KC_##KL5, KC_##KL6, KC_NO   }, /* L */ \
  {KC_NO,    KC_NO,    KC_NO,    KC_##KM3, KC_NO,    KC_NO,    KC_NO,    KC_NO   }, /* M */ \
  {KC_NO,    KC_NO,    KC_##KN2, KC_##KN3, KC_NO,    KC_NO,    KC_NO,    KC_NO   }, /* N */ \
  {KC_##KO0, KC_NO,    KC_NO,    KC_##KO3, KC_##KO4, KC_##KO5, KC_##KO6, KC_##KO7}, /* O */ \
  {KC_NO,    KC_NO,    KC_##KP2, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO   }, /* P */ \
  {KC_##KQ0, KC_##KQ1, KC_##KQ2, KC_##KQ3, KC_##KQ4, KC_##KQ5, KC_##KQ6, KC_##KQ7}, /* Q */ \
  {KC_##KR0, KC_NO,    KC_##KR2, KC_##KR3, KC_##KR4, KC_##KR5, KC_##KR6, KC_##KR7}  /* R */ \
}

#include "keymap_rwx.h"
#include "led.h"

#define KEYMAPS_SIZE    (sizeof(keymaps) / sizeof(keymaps[0]))
#define FN_ACTIONS_SIZE (sizeof(fn_actions) / sizeof(fn_actions[0]))

/* translates key to keycode */
uint16_t keymap_key_to_keycode(uint8_t layer, keypos_t key) {
  if (layer < KEYMAPS_SIZE)
    return pgm_read_word(&keymaps[(layer)][(key.col)][(key.row)]);
  else
    return pgm_read_word(&keymaps[0][(key.col)][(key.row)]);
}

/*
When using my programming layer, the left shift key is used as an FN key.
This has the side-effect that I can't use it to get capital letters or secondary
characters. So I could either define every key as FN key, or I can use this
function to return a macro for each keypress.
*/
action_t handle_programming_layer_2_shift(uint16_t keycode) {
  action_t action;
  action.code = ACTION_NO;
  if (keycode >= KC_A && keycode <= KC_EXSEL && \
     !(  // do not send LSFT + these keycodes, they are needed for emulating the US layout
         keycode == KC_NONUS_BSLASH ||
         keycode == KC_RBRC ||
         keycode == KC_BSLS ||
         keycode == KC_GRV
    )) {
    action.code = ACTION_MODS_KEY(MOD_LSFT, keycode);
  }
  return action;
}

/* do custom key handling, will be called from action_for_key in common/keymap.c 

To use this, define CUSTOM_KEY_HANDLING in config.h
This will make sure that this function is called from actio_for_key.
In here, you can define much more fine-grained action handling.
*/
action_t custom_key_handler(uint8_t layer, uint16_t keycode) {
  action_t action;
  action.code = ACTION_NO;
  if (keycode >= KC_FN0 && keycode <= FN_MAX) {
    // do not handle FN keys here
    return action;
  }
  if (layer == 2) {
    /* every key that is not aN FN key will be handled here
    it will return a macro LSFT + key
    */
    return handle_programming_layer_2_shift(keycode);
  }
  return action;
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint16_t keycode) {
  action_t action;
  if (FN_INDEX(keycode) < FN_ACTIONS_SIZE)
    action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
  else
    action.code = ACTION_NO;
  return action;
}


void tap_helper(keyrecord_t *record, uint16_t orig_mod, uint16_t macro_mod, uint16_t macro_kc ) {
  if (record->event.pressed) {
      if (record->tap.count > 0 && !record->tap.interrupted) {
          if (record->tap.interrupted) {
              dprint("tap interrupted\n");
              register_mods(MOD_BIT(orig_mod));
          }
      } else {
          register_mods(MOD_BIT(orig_mod));
      }
  } else {
      if (record->tap.count > 0 && !(record->tap.interrupted)) {
          add_weak_mods(MOD_BIT(macro_mod));
          send_keyboard_report();
          register_code(macro_kc);
          unregister_code(macro_kc);
          del_weak_mods(MOD_BIT(macro_mod));
          send_keyboard_report();
          record->tap.count = 0;  // ad hoc: cancel tap
      } else {
          unregister_mods(MOD_BIT(orig_mod));
      }
  }
}
/* if LCTRL is tabbed, print (, or ) if RCTRL is tabbed, same for LALT/RALT and [/] */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    // The code is copied from keymap_hasu.c in the tmk keyboards hhkb folder
    // Debug output
    if (record->event.pressed) dprint("P"); else dprint("R");
    dprintf("%d", record->tap.count);
    if (record->tap.interrupted) dprint("i");
    dprint("\n");

    switch (id) {
        case LCTRL_PAREN:
            tap_helper(record, KC_LCTL, KC_LSHIFT, KC_8);
            break;
        case RCTRL_PAREN:
            tap_helper(record, KC_RCTL, KC_LSHIFT, KC_9);
            break;
        case LALT_BRACKET:
            tap_helper(record, KC_LALT, KC_RALT, KC_8);
            break;
        case RALT_BRACKET:
            tap_helper(record, KC_RALT, KC_RALT, KC_9);
            break;
        case CTRL_CLICK:
            if (record->event.pressed) {
                mousekey_clear();
                register_mods(MOD_BIT(KC_LCTL));
                send_keyboard_report();
                wait_ms(50);
                mousekey_on(KC_BTN1);
                mousekey_send();
                wait_ms(100);
                mousekey_off(KC_BTN1);
                mousekey_send();
                wait_ms(50);
                unregister_mods(MOD_BIT(KC_LCTL));
                send_keyboard_report();
            }
            break;
    }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case GRV: // macro to print accent grave
            return (record->event.pressed ?
                    MACRO( D(LSFT), T(EQL), U(RALT), T(SPC), END) :
                    MACRO_NONE );
        case CFLEX: // print accent circonflex
            return (record->event.pressed ?
                    MACRO( T(GRV), T(SPC), END ) :
                    MACRO_NONE );
    }
    return MACRO_NONE;
}

void hook_layer_change(uint32_t layer_state) {
  // this hook sets the keyboard indicator LEDs
  // I use the caps lock LED to signal use of the programming layer and
  // the scroll lock LED to show the use of the mouse layer
  uint8_t highest_layer;
  highest_layer = biton32(layer_state);
  // first disable layer indicators
  led_set(host_keyboard_leds() & ~(1<<USB_LED_CAPS_LOCK));
  led_set(host_keyboard_leds() & ~(1<<USB_LED_SCROLL_LOCK));
  if (highest_layer == MOUSE) {
    led_set(host_keyboard_leds() | (1<<USB_LED_SCROLL_LOCK));
  } else if (highest_layer == PROG1 || highest_layer == PROG2) {
    led_set(host_keyboard_leds() | (1<<USB_LED_CAPS_LOCK));
  }
}