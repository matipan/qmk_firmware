#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include "keymap_german.h"

#include "keymap_nordic.h"

enum custom_keycodes
{
	PLACEHOLDER = SAFE_RANGE, // can always be here
	EPRM,
	VRSN,
	RGB_SLD,
	RGB_0000FF,
	RGB_008000,
	RGB_FFA500,
	RGB_800080,
	RGB_FF0000,
	NEXT_BUFF,
	PREV_BUFF,
	GOLANG,
	TIMON,
	INTERNP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F3   |   1  |   2  |   3  |   4  |   5  |Cmd/V |           | F5   |   6  |   7  |   8  |   9  |   0  |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | `      |   Q  |   W  |   E  |   R  |   T  |Cmd/C |           |  {   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | 3      |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |;     |   '    |
 * |--------+------+------+------+------+------| Esc  |           |  }   |------+------+------+------+------+--------|
 * | F7     |Z     |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |/     |   -    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |CMD SP|Lshift|CmdTab| 2    | 2    |                                       |  1   | 1    | Ctrl |  Cmd | Hyper  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Alt  | Ctrl |       | F9   | F8     |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Cmd  |       | Cmd  |        |      |
 *                                 | Tab  |Backsp|------|       |------| Enter  |Space |
 *                                 | Ctrl |ace   |Shift |       | =    |        |      |
 *                                 `--------------------'       `----------------------'
 */
    [0] = KEYMAP(
		    // Left hand
		    KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_F12,
		    KC_PGDOWN, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_PGUP,
		    MO(3), KC_A, KC_S, KC_D, KC_F, KC_G,
		    KC_F7, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ESCAPE,
		    LGUI(KC_SPACE), LCTL(KC_LALT), LALT(KC_TAB), TG(2), MO(2),
		    ALT_T(KC_NO), KC_LCTL, KC_LGUI, CTL_T(KC_TAB), KC_BSPACE, KC_LSHIFT,
		    // Right hand
		    KC_F5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F11,
		    KC_LCBR, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH,
		    KC_H, KC_J, KC_K, KC_L, KC_SCOLON, LSFT_T(KC_QUOTE),
		    KC_RCBR, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_MINUS,
		    MO(1), TG(1), LCTL(KC_RSHIFT), KC_LGUI, ALL_T(KC_NO),
		    KC_F9, KC_F8, KC_LGUI, KC_EQUAL, KC_ENTER, KC_SPACE),

    [1] = KEYMAP(
		    // Left hand
		    KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRANSPARENT,
		    KC_AUDIO_VOL_UP, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK,
		    KC_AUDIO_VOL_DOWN, KC_TRANSPARENT, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRANSPARENT,
		    KC_AUDIO_MUTE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_MY_COMPUTER, KC_MS_BTN1, KC_MS_BTN2, KC_WWW_REFRESH,
		    // Right hand
		    KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_POWER, KC_PSCREEN, KC_SYSTEM_SLEEP, KC_TRANSPARENT, KC_F15, KC_F14),

    [2] = KEYMAP(
		    // Left hand
		    KC_TRANSPARENT, KC_TRANSPARENT, RGB_0000FF, RGB_008000, RGB_FFA500, RGB_800080, RGB_FF0000,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
		    RGB_MOD, RGB_SLD, KC_TRANSPARENT, RGB_VAD, RGB_VAI, KC_TRANSPARENT,
		    // Right hand
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME, KC_UP, KC_END, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP, KC_TRANSPARENT, KC_PGDOWN, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
		    RGB_TOG, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_HUD, RGB_HUI),

    [3] = KEYMAP(
		    // Left hand
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, HYPR(KC_KP_1), HYPR(KC_KP_2), HYPR(KC_3), KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, HYPR(KC_4), HYPR(KC_5), HYPR(KC_6), KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, HYPR(KC_7), HYPR(KC_8), HYPR(KC_9), KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
		    // Right hand
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, INTERNP, GOLANG,
		    PREV_BUFF, KC_LABK, KC_AT, KC_LPRN, KC_RPRN, KC_HASH, TIMON,
		    KC_RABK, KC_EQUAL, KC_LBRACKET, KC_RBRACKET, KC_DLR, LGUI(KC_UP),
		    NEXT_BUFF, KC_TILD, KC_GRAVE, KC_LCBR, KC_RCBR, KC_PIPE, LGUI(KC_DOWN),
		    KC_KP_PLUS, KC_KP_MINUS, KC_KP_ASTERISK, KC_KP_SLASH, KC_TRANSPARENT,
		    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(1)};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	switch (id)
	{
	case 0:
		if (record->event.pressed)
		{
			SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
		}
		break;
	}
	return MACRO_NONE;
};

void matrix_init_user(void)
{
#ifdef RGBLIGHT_COLOR_LAYER_0
	rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode)
	{
	// dynamically generate these.
	case EPRM:
		if (record->event.pressed)
		{
			eeconfig_init();
		}
		return false;
		break;
	case VRSN:
		if (record->event.pressed)
		{
			SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
		}
		return false;
		break;
	case RGB_SLD:
		if (record->event.pressed)
		{
			rgblight_mode(1);
		}
		return false;
		break;

	case RGB_0000FF:
		if (record->event.pressed)
		{
#ifdef RGBLIGHT_ENABLE
			rgblight_enable();
			rgblight_mode(1);
			rgblight_setrgb(0x00, 0x00, 0xff);
#endif
		}
		return false;
		break;

	case RGB_008000:
		if (record->event.pressed)
		{
#ifdef RGBLIGHT_ENABLE
			rgblight_enable();
			rgblight_mode(1);
			rgblight_setrgb(0x00, 0x80, 0x00);
#endif
		}
		return false;
		break;

	case RGB_FFA500:
		if (record->event.pressed)
		{
#ifdef RGBLIGHT_ENABLE
			rgblight_enable();
			rgblight_mode(1);
			rgblight_setrgb(0xff, 0xa5, 0x00);
#endif
		}
		return false;
		break;

	case RGB_800080:
		if (record->event.pressed)
		{
#ifdef RGBLIGHT_ENABLE
			rgblight_enable();
			rgblight_mode(1);
			rgblight_setrgb(0x80, 0x00, 0x80);
#endif
		}
		return false;
		break;

	case RGB_FF0000:
		if (record->event.pressed)
		{
#ifdef RGBLIGHT_ENABLE
			rgblight_enable();
			rgblight_mode(1);
			rgblight_setrgb(0xff, 0x00, 0x00);
#endif
		}
		return false;
		break;
	case NEXT_BUFF:
		/* SEND_STRING(SS_DOWN(X_RIGHT_CURLY_BRACE) SS_TAP(X_B) SS_UP(X_RIGHT_CURLY_BRACE)); */
		return false;
		break;
	case PREV_BUFF:
		/* SEND_STRING(SS_DOWN(X_LEFT_CURLY_BRACE) SS_TAP(X_B) SS_UP(X_LEFT_CURLY_BRACE)); */
		return false;
		break;
	case GOLANG:
		if (record->event.pressed) {
			SEND_STRING("golang");
		}
		return false;
		break;
	case INTERNP:
		if (record->event.pressed) {
			SEND_STRING("I5international.26");
		}
		return false;
		break;
	case TIMON:
		if (record->event.pressed) {
			SEND_STRING("Timon.1234");
		}
		return false;
		break;
	}
	return true;
}

uint32_t layer_state_set_user(uint32_t state)
{

	uint8_t layer = biton32(state);

	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
	switch (layer)
	{
	case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
		rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
		break;
	case 1:
		ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
		rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
		break;
	case 2:
		ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
		rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
		break;
	case 3:
		ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
		rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
		break;
	case 4:
		ergodox_right_led_1_on();
		ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
		rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
		break;
	case 5:
		ergodox_right_led_1_on();
		ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
		rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
		break;
	case 6:
		ergodox_right_led_2_on();
		ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
		rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
		break;
	case 7:
		ergodox_right_led_1_on();
		ergodox_right_led_2_on();
		ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
		rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
		break;
	default:
		break;
	}
	return state;
};
