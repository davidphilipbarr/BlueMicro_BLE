/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"


#if KEYBOARD_SIDE == SINGLE
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
            KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                                     KC_4,    KC_5,    KC_6
    )};

void setupKeymap() {

   // no layers for SINGLE keymap
   // this is a keymap that's used for testing that each key is responding properly to key presses
   // flash this keymap to both left and right to test whether each half works properly.
   // once tested, you can flash the left and right to their respective halves.

}
#endif


#if KEYBOARD_SIDE == LEFT

/* Qwerty
 * ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |
 * |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |
 * |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |
 * |------+------+------+------+------+------|
 * |      |      |      |  GUI | L(1) |Space |
 * `-----------------------------------------'
 */

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
        KC_Q,    KC_W,    KC_E,    KC_R,     KC_T, 
        KC_A,    ALT_S,    CTRL_D ,    GUI_F,     KC_G,
        SFT_Z,    KC_X,    KC_C,    KC_V,     KC_B,
                                         KC_LGUI, LAYER_1, KC_LCTL \
    )};

 
void setupKeymap() {


//------------------------------------------------------------------------------
//LAYER 0 ----------------------------------------------------------------------
//------------------------------------------------------------------------------

 uint32_t layer0_tap[MATRIX_ROWS][MATRIX_COLS] =
       KEYMAP( \
                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,\
               XXXXXXX,ALT_S_TAP,CTRL_D_TAP , GUI_F_TAP,XXXXXXX, \
              SFT_Z_TAP,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX, \
             				XXXXXXX, XXXXXXX,XXXXXXX \
        );



 uint32_t layer0_hold[MATRIX_ROWS][MATRIX_COLS] =
       KEYMAP( \
                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,\
               XXXXXXX,ALT_S_HOLD,    CTRL_D_HOLD ,    GUI_F_HOLD,XXXXXXX, \
              SFT_Z_HOLD,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, \
             				XXXXXXX, XXXXXXX,XXXXXXX \
        );


/* Layer 1 (Raise)
 * ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------+------|
 * | CTRL |      |      |      |      |      |
 * |------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |
 * |------+------+------+------+------+------|
 * |      |      |      |  GUI | L(1) |Space |
 * `-----------------------------------------'
 */
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
                 KC_1, KC_2, KC_3, KC_4, KC_5, \
                KC_TAB, KC_SAVE, KC_DQUO, KC_PIPE, KC_NUPI,\
                KC_ESC, KC_TILD, KC_NUBS,   KC_NUHS,  KC_NONUS_HASH, \
                                         KC_LGUI, LAYER_1, KC_RGUI \
        );

    /* Layer 2 (lower)
 * ,-----------------------------------------.
 * |  Esc |   !  |   @  |   #  |   $  |   %  |
 * |------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |
 * |------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |
 * |------+------+------+------+------+------|
 * |      |      |      | GUI  | L(1) |Space |
 * `-----------------------------------------'
 */
    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
              KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC, \
              KC_HASH, KC_QUES, KC_SLSH, KC_COLN, KC_SCLN,  \
              KC_CAP_Z ,  KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, \
                                        KC_LGUI, LAYER_1, KC_SPC \
        );
    /*
     * add the other layers on the regular presses.
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
        }
    }

    // if you want to add Tap/Hold or Tap/Doubletap activations, then you add them below.

}

#endif  // left



#if KEYBOARD_SIDE == RIGHT

/* Qwerty
 * ,-----------------------------------------.
 * |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+-------------|
 * |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------|------|
 * |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------|
 * | Space| L(2) | Left | Down |  Up  |Right |
 * `-----------------------------------------'
 */

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      
           KC_H,     KC_J,     KC_K,     KC_L,  KC_QUOT,
            KC_N,    KC_M,    KC_COMMA, KC_DOT, KC_ENT,  
            KC_SPC ,  LAYER_2, KC_RSFT
    )};

void setupKeymap() {

/* Layer 1 (Raise)
 * ,-----------------------------------------.
 * |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+-------------|
 * |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------|------|
 * |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------|
 * | Space| L(2) | Left |      |      |      |
 * `-----------------------------------------'
 */
    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
           KC_6,    KC_7,    KC_8,    KC_9, KC_0,  
             KC_HASH, KC_MINS,   KC_EQL,  KC_LCBR, KC_DEL,
              KC_MINS, KC_GRV, KC_LBRC, KC_RBRC, KC_BSPC,
              KC_SPC,  LAYER_2, KC_RALT  \
        );

    /* Layer 2 (lower)
 * ,-----------------------------------------.
 * |   ^  |   &  |   *  |   (  |   )  | Bspc |
 * |------+------+------+------+-------------|
 * |   -  |   =  |   {  |   }  |   |  |  `   |
 * |------+------+------+------+------|------|
 * |   _  |   +  |   [  |   ]  |   \  |  ~   |
 * |------+------+------+------+------+------|
 * | Space| L(2) |  Alt |      |      |      |
 * `-----------------------------------------'
 */
    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
                KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  \
                KC_MINS,   KC_EQL,  KC_LCBR,  KC_RCBR, KC_BSPC,  \
                KC_UNDS,  KC_LEFT, KC_DOWN, KC_UP,KC_RGHT, \
                KC_ENT,   LAYER_2, KC_RALT  \
        );
    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
        }
    }

}

#endif

