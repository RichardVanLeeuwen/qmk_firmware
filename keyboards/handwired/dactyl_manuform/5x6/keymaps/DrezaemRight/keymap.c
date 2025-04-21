// My personal layout for the Dactyl Manuform 5x6 Keyboard.
// Designed for programming on dvorak.
// Initial flash: `qmk flash -kb handwired/dactyl_manuform/5x6 -km DrezaemRight -bl avrdude-split-right`
// The `-bl avrdude...` part of the command sets the eeprom memory so that the keyboard always knows which half is the right or left side, no matter how or in which order it is plugged in.
// After setting `qmk config user.keyboard=handwired/dactyl_manuform/5x6` this keymap can be compiled with `qmk compile -km DrezaemRight`.
// Use flash instead of compile to compile and immediately reflash the keyboard.

#include QMK_KEYBOARD_H

// Home row mod keys
// left side
#define GUI_A GUI_T(KC_A)
#define ALT_O LALT_T(KC_O)
#define SHI_E LSFT_T(KC_E)
#define CTL_U LCTL_T(KC_U)
// right side
#define CTL_H RCTL_T(KC_H)
#define SHI_T RSFT_T(KC_T)
#define ALT_N LALT_T(KC_N)
#define ALT_R RALT_T(KC_R)
#define GUI_S RGUI_T(KC_S)

#define _DVORAK 0
#define _GAME 1
#define _NAVI 2
#define _MOUSE 3
#define _MEDIA 4
#define _NUMBERS 5
#define _SYMBOLS 6
#define _FUNCTION 7

#define DVORAK DF(_DVORAK)
#define GAME DF(_GAME)
#define NAVI LT(_NAVI, KC_ESC)
#define MOUSPC LT(_MOUSE, KC_SPC)
#define MEDIA LT(_MEDIA, KC_ENT)
#define NUMBER LT(_NUMBERS, KC_TAB)
#define FUNCTIO LT(_FUNCTION, KC_DEL)
#define SYMBOLS LT(_SYMBOLS, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_5x6(
      KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSLS,
      KC_TAB ,KC_QUOT,KC_COMM,KC_DOT , KC_P  , KC_Y  ,                         KC_F  , KC_G  , KC_C  , ALT_R , KC_L  ,KC_SLSH,
      KC_CAPS,GUI_A  ,ALT_O  ,SHI_E  , CTL_U , KC_I  ,                         KC_D  , CTL_H ,SHI_T  , ALT_N , GUI_S ,KC_MINS,
      KC_LSFT,KC_SCLN, KC_Q  , KC_J  , KC_K  , KC_X  ,                         KC_B  , KC_M  , KC_W  , KC_V  , KC_Z  ,KC_EQL ,
                      KC_LEFT,KC_RGHT,                                                          KC_UP ,KC_DOWN,
                                      NAVI   ,MOUSPC ,                        SYMBOLS,NUMBER ,
                                      GAME   ,MEDIA  ,                        FUNCTIO,KC_DEL ,
                                      KC_LSFT,KC_LCTL,                        KC_LGUI,KC_LALT
  ),

  [_GAME] = LAYOUT_5x6(
      KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSLS,
      KC_TAB ,KC_QUOT,KC_COMM,KC_DOT , KC_P  , KC_Y  ,                         KC_F  , KC_G  , KC_C  , ALT_R , KC_L  ,KC_SLSH,
      KC_CAPS,KC_A   ,KC_O   ,KC_E   , KC_U  , KC_I  ,                         KC_D  , KC_H  ,KC_T   , KC_N  , KC_S  ,KC_MINS,
      KC_LSFT,KC_SCLN, KC_Q  , KC_J  , KC_K  , KC_X  ,                         KC_B  , KC_M  , KC_W  , KC_V  , KC_Z  ,KC_EQL ,
                      KC_LEFT,KC_RGHT,                                                          KC_UP ,KC_DOWN,
                                      NAVI   ,KC_SPC ,                        SYMBOLS,NUMBER ,
                                      DVORAK ,MEDIA  ,                        FUNCTIO,KC_DEL ,
                                      KC_LSFT,KC_LCTL,                        KC_LGUI,KC_LALT
  ),

  [_NAVI] = LAYOUT_5x6(
    _______,_______,_______,_______,_______,_______,                          _______,_______,_______,_______,_______,_______,
    _______,_______,_______, KC_UP ,_______,_______,                          _______,_______,_______,_______,_______,_______,
    _______,_______,KC_LEFT,KC_DOWN,KC_RGHT,_______,                          _______,_______,_______,_______,_______,_______,
    QK_BOOT,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,_______,                          _______,_______,_______,_______,_______,_______,
                    C(KC_C),C(KC_V),                                                          _______,_______,
                                    _______,_______,                          _______,_______,
                                    _______,_______,                          _______,_______,
                                    _______,_______,                          _______,_______
  ),

  [_MOUSE] = LAYOUT_5x6(
      _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,_______,                        _______,KC_BTN1,KC_MS_U,KC_WH_U,_______,_______,
      _______,_______,_______,_______,_______,_______,                        _______,KC_MS_L,KC_WH_L,KC_MS_R,KC_WH_R,_______,
      _______,_______,_______,_______,_______,_______,                        _______,KC_BTN2,KC_MS_D,KC_WH_D,_______,_______,
                      _______,_______,                                                        _______,_______,
                                      _______,_______,                        KC_BTN1,KC_BTN2,
                                      _______,_______,                        KC_BTN3,_______,
                                      _______,_______,                        _______,_______
  ),

  [_MEDIA] = LAYOUT_5x6(
      _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
      _______,KC_VOLU,KC_MUTE,KC_INS ,_______,_______,                        _______,_______,_______,_______,_______,_______,
      _______,KC_VOLD,KC_MPRV,KC_MPLY,KC_MNXT,_______,                        _______,_______,_______,_______,_______,_______,
      _______,KC_PAUS,KC_SCRL,KC_PSCR,KC_CAPS,QK_BOOT,                        _______,_______,_______,_______,_______,_______,
                      _______,_______,                                                        _______,_______,
                                      _______,_______,                        _______,_______,
                                      _______,_______,                        _______,_______,
                                      _______,_______,                        _______,_______
  ),

  [_NUMBERS] = LAYOUT_5x6(
    _______,_______,_______,_______,_______,_______,                          _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,                          KC_PAST, KC_7  , KC_8  , KC_9  ,KC_PLUS,_______,
    _______,_______,_______,_______,_______,_______,                          KC_PSLS, KC_4  , KC_5  , KC_6  ,KC_MINS,_______,
    QK_BOOT,_______,_______,_______,_______,_______,                           KC_0  , KC_1  , KC_2  , KC_3  ,KC_PEQL,QK_BOOT,
                    _______,_______,                                                          _______,_______,
                                    _______,_______,                          _______,_______,
                                    _______,_______,                          _______,_______,
                                    _______,_______,                          _______,_______
  ),

  [_SYMBOLS] = LAYOUT_5x6(
      _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,_______,                        _______,KC_LCBR,KC_RCBR,KC_EQL ,KC_EXLM,_______,
      _______,_______,_______,_______,_______,_______,                        _______,KC_LPRN,KC_RPRN,KC_SLSH,KC_BSLS,_______,
      _______,_______,_______,_______,_______,_______,                        _______,KC_LBRC,KC_RBRC,KC_MINS,KC_GRV,_______,
                      _______,_______,                                                        _______,_______,
                                      _______,_______,                        _______,_______,
                                      _______,_______,                        _______,_______,
                                      _______,_______,                        _______,_______
  ),

  [_FUNCTION] = LAYOUT_5x6(
    KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                          KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
    _______, KC_F1 , KC_F2 , KC_F3 , KC_F4 ,_______,                          _______,_______,_______,_______,_______,_______,
    _______, KC_F5 , KC_F6 , KC_F7 , KC_F8 ,_______,                          _______,_______,_______,_______,_______,_______,
    QK_BOOT, KC_F9 , KC_F10, KC_F11, KC_F12,_______,                          QK_BOOT,_______,_______,_______,_______,_______,
                    _______,_______,                                                          _______,_______,
                                    _______,_______,                          _______,_______,
                                    _______,_______,                          _______,_______,
                                    _______,_______,                          _______,_______
  ),

};

//   [_LAYER] = LAYOUT_5x6(
//       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
//       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
//       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
//       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
//                       _______,_______,                                                        _______,_______,
//                                       _______,_______,                        _______,_______,
//                                       _______,_______,                        _______,_______,
//                                       _______,_______,                        _______,_______
//   ),

