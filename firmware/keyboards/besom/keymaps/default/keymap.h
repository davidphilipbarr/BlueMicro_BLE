/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include <stdint.h>
#include "hid_keycodes.h"
#include "keyboard_config.h"
#include "advanced_keycodes.h"
#include "Key.h"
#include <array>

#ifndef KEYMAP_H
#define KEYMAP_H



#define _QWERTY 0
#define _L1  1
#define _L2  2

#define _PRESS 0
#define _MT_TAP 1
#define _MT_HOLD 2
#define _DT_TAP 3
#define _DT_DOUBLETAP 4

#define KC_CAP_D MOD(MOD_LSHIFT, KC_D)
#define KC_CAP_Z MOD(MOD_LSHIFT, KC_Z)
#define KC_SAVE MOD(MOD_LCTRL, KC_S)


// Shift
#define SFT_ENT       XXXXXXX
#define SFT_ENT_TAP   KC_ENT
#define SFT_ENT_HOLD  (KC_RSHIFT)

#define SFT_R       XXXXXXX
#define SFT_R_TAP   KC_DOT
#define SFT_R_HOLD  (KC_RSHIFT)

#define SFT_Z       XXXXXXX
#define SFT_Z_TAP   KC_Z
#define SFT_Z_HOLD  (KC_LSHIFT)

// hOME MODSish

#define ALT_S       XXXXXXX
#define ALT_S_TAP   KC_S
#define ALT_S_HOLD  (KC_RALT)

#define CTRL_D      XXXXXXX
#define CTRL_D_TAP   KC_D
#define CTRL_D_HOLD  (KC_LCTL)

#define GUI_F      XXXXXXX
#define GUI_F_TAP   KC_F
#define GUI_F_HOLD  (KC_LGUI)



void setupKeymap();
extern std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix;

#endif /* KEYMAP_H */
