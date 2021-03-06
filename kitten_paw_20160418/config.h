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


#define CONFIG_H

/* max value on report descriptor */
#define MOUSEKEY_MOVE_MAX       127
#define MOUSEKEY_WHEEL_MAX      110
#define MOUSEKEY_MOVE_DELTA     5
#define MOUSEKEY_WHEEL_DELTA    1
#define MOUSEKEY_DELAY 50
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_MAX_SPEED 4
#define MOUSEKEY_TIME_TO_MAX 30
#define MOUSEKEY_WHEEL_MAX_SPEED 3
#define MOUSEKEY_WHEEL_TIME_TO_MAX 1000

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xFACE
#define DEVICE_VER      0x0104
#define MANUFACTURER    Bathroom Epiphanies
#define PRODUCT         Kitten Paw Majestouch

/* message strings */
#define DESCRIPTION     t.m.k. keyboard firmware for Majestouch

/* matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 18

/* Set 0 if need no debouncing */
#define DEBOUNCE    5

// use a custom key handler in custom/keymap.c core
#define CUSTOM_KEY_HANDLING

#define ONESHOT_TIMEOUT 500

#define TAPPING_TOGGLE 2

/* key combination for command */
#define IS_COMMAND() (keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))

