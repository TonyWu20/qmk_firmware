#include QMK_KEYBOARD_H
#include "keymap_steno.h"
enum dactyl_layers
{
    MALTRON,
    SYMBOLS,
    NUMPADS,
    FUNCTIONS,
    PLOVER
};
enum custom_keycodes
{
    COPY,
    PASTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MALTRON] = LAYOUT(
        KC_Q, KC_P, KC_Y, KC_C, KC_B,                  KC_V, KC_M, KC_U, KC_Z, KC_L, /* row 1 */
        LGUI_T(KC_A), LALT_T(KC_N), LSFT_T(KC_I), LCTL_T(KC_S),  KC_F, KC_D, RCTL_T(KC_T), RSFT_T(KC_H), RALT_T(KC_O), RGUI_T(KC_R), /* row 2 */
        KC_COMM, KC_DOT, KC_J, KC_G, KC_SLSH,          KC_SCLN, KC_W, KC_K, KC_MINS, KC_X,                   /* row 3 */
						       KC_J, KC_K,             KC_H, KC_L, // row 4
				LT(SYMBOLS, KC_ESC), KC_E, KC_LSFT,    KC_BSPC, LT(NUMPADS, KC_SPC), RSFT_T(KC_ENT), // upper thumb //clang-format off
				COPY, PASTE, KC_TAB, KC_CAPS, TO(PLOVER), LT(FUNCTIONS, KC_NO)// lower thumb //clang-format off
        ),
    [SYMBOLS] = LAYOUT(
        KC_AMPR, KC_AT,   KC_PERC, KC_TILD, KC_CIRC,   KC_DLR, KC_BSLS, KC_MINS, KC_SLSH, KC_HASH,
		KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_EQL,    KC_ASTR, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM,
		LSFT(KC_COMM), LSFT(KC_DOT),KC_QUES, KC_COLON, KC_GRAVE,  KC_QUOT, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT,
								   KC_UP,   KC_DOWN,   KC_LEFT, KC_RGHT,
						  KC_TRNS, KC_TRNS, KC_LSFT,   KC_BTN2, KC_TRNS, KC_RSFT,//clang-format off
						  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS),//clang-format off
    [NUMPADS] = LAYOUT(
        KC_SLEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PPLS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_PAST, KC_P4, KC_P5, KC_P6, KC_PCMM, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_PMNS, KC_P1, KC_P2, KC_P3, KC_PEQL,
		                           KC_VOLU, KC_VOLD,  KC_P0,   KC_PDOT, 
						  KC_MPLY, KC_MNXT, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
						  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS),
    [FUNCTIONS] = LAYOUT(
		KC_F10, KC_F7, KC_F8, KC_F9, RESET,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, // row 1
	    KC_F11, KC_F4, KC_F5, KC_F6, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, // row 2
		KC_F12, KC_F1, KC_F2, KC_F3, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          // row 3
						      KC_VOLU, KC_VOLD,    KC_TRNS, KC_TRNS, // row 4
                     KC_MPLY, KC_MNXT, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, 
					 KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS),
    [PLOVER] = LAYOUT(
        STN_N1, STN_N2, STN_N3, STN_N4, STN_N5,    STN_N6, STN_N7, STN_N8, STN_N9, STN_NA, 
		STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1,   STN_FR, STN_PR, STN_LR, STN_TR, STN_DR, 
		STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2,   STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,
								KC_NO,  KC_NO,     KC_NO, KC_NO, 
						STN_A,  STN_A,  STN_O,     STN_E, STN_U, STN_U, 
						STN_O,  KC_NO,  KC_NO,     KC_NO, TO(MALTRON),STN_E)};


bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case COPY:
        if (record->event.pressed)
        {
            register_code(KC_LGUI);
            register_code(KC_C);
            unregister_code(KC_LGUI);
            unregister_code(KC_C);
        }
        break;
    case PASTE:
        if (record->event.pressed)
        {
            register_code(KC_LGUI);
            register_code(KC_V);
            unregister_code(KC_LGUI);
            unregister_code(KC_V);
        }
    }
    return true;
};
