#include QMK_KEYBOARD_H


enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
};

#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,          KC_EQL, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,          KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LGUI, KC_LALT, ADJUST,           LOWER,   KC_SPC,           KC_SPC,  RAISE,            KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_LOWER] = LAYOUT(
  KC_TILD, KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_HOME,          KC_PGUP,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_END ,          KC_PGDN,     KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS,
  _______, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_BSPC,          KC_BSPC,     KC_F12,  _______, _______, KC_MUTE, _______, KC_PIPE,
  _______, _______,  _______, _______, _______, KC_BSPC,                                KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY

  ),

  [_RAISE] = LAYOUT(

  KC_ESC,  KC_1,    KC_2,  KC_3,   KC_4,    KC_5,     _______,          _______,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, KC_4,    KC_5,  KC_6,   KC_PLUS, _______,  _______,          _______,   _______,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  KC_ENT,  KC_7,    KC_8,  KC_9,   KC_MINS, _______,  _______,          _______,   _______,   KC_NUHS, KC_NUBS, KC_MUTE, _______, KC_BSLS,
  _______, KC_COMM, KC_0,  KC_DOT, _______, KC_BSPC,                                 KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY

  ),

  [_ADJUST] = LAYOUT(
     TSKMGR,  _______,  _______, _______, _______, _______, _______,         _______,  _______, UG_NEXT, UG_VALU, UG_SATU, UG_HUEU, CALTDEL,
     _______, _______,  _______, _______, _______, _______, _______,         _______,  _______, UG_PREV, UG_VALD, UG_SATD, UG_HUED, UG_TOGG,
     _______, _______,  _______, _______, _______, _______, _______,         _______,  _______, _______, _______, _______, _______, BL_STEP,
     _______, _______, _______, _______,           _______, _______,         _______,  _______,          _______, _______, _______, QK_BOOT
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
