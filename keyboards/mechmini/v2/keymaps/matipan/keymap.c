#include QMK_KEYBOARD_H

// Helpful defines
#define _______ KC_TRNS

enum custom_keycodes {
	SUPER_UP = SAFE_RANGE,
	SUPER_DOWN
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch(keycode) {
			case SUPER_UP:
				SEND_STRING(SS_DOWN(X_HOME)SS_TAP(X_UP)SS_UP(X_HOME));
				return false;
			case SUPER_DOWN:
				SEND_STRING(SS_DOWN(X_HOME)SS_TAP(X_DOWN)SS_UP(X_HOME));
				return false;
		}
	}
	return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
			   KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
			   KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
			   SUPER_UP, KC_NO, KC_NO, KC_LCTL, MO(1), KC_ENT, KC_SPC, MO(2), KC_RGUI, KC_LALT, KC_RCTL, SUPER_DOWN),
	[1] = LAYOUT_ortho(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
			   KC_NO, KC_MPLY, KC_MNXT, KC_VOLU, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
			   KC_NO, KC_NO, KC_MSTP, KC_MPRV, KC_VOLD, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,
			   KC_PWR, KC_NO, KC_NO, KC_MUTE, KC_TRNS, KC_PSTE, KC_COPY, KC_NO, KC_LEFT, KC_RGHT, KC_UP, KC_DOWN),
	[2] = LAYOUT_ortho(KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, RGB_M_X,
			   KC_BSLS, KC_MINS, KC_EQL, KC_LCBR, KC_RCBR, KC_NO, BL_TOGG, RGB_TOG, RGB_HUI, RGB_VAI, RGB_SAI, RGB_M_K,
			   KC_NO, KC_LT, KC_GT, KC_LBRC, KC_RBRC, KC_NO, BL_STEP, RGB_MOD, RGB_HUD, RGB_VAD, RGB_SAD, RGB_M_SN,
		           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_M_G, KC_TRNS, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW)
};
