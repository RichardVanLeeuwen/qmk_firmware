/* My personal layout for the Dactyl Manuform 5x6 Keyboard */
// Designed for gaming
// qmk compile -km DrezaemLeft
// qmk flash -kb handwired/dactyl_manuform/5x6 -km DrezaemLeft -bl avrdude-split-left

#include QMK_KEYBOARD_H

// Function that returns the desired tapping term for each key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case LSFT_T(KC_E):
        case RSFT_T(KC_T):
            return 160;
        default:
            return TAPPING_TERM;
    }
}

// Home row mod keys for qwerty
// left side
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SHI_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)
// right side
#define CTL_J RCTL_T(KC_J)
#define SHI_K RSFT_T(KC_K)
#define ALT_L RALT_T(KC_L)
#define GUI_SC RGUI_T(KC_SCLN)

// The space/shift key
#define SHISPC LSFT_T(KC_SPC)

#define _QWERTY 0
#define _GUILDW 1
#define _MACROL 2
#define _NAVI 3
#define _MOUSE 4
#define _MEDIA 5
#define _NUMBERS 6
#define _SYMBOLS 7
#define _FUNCTION 8

#define QWERTY TO(_QWERTY)
#define GUILDW TO(_GUILDW)
#define HOMEMOD TG(_HOMEMOD)
#define MACROL MO(_MACROL)
#define NAVI LT(_NAVI, KC_ESC)
#define MOUSPC LT(_MOUSE, KC_SPC)
#define MEDIA LT(_MEDIA, KC_ENT)
#define NUMBER LT(_NUMBERS, KC_TAB)
#define FUNCTIO LT(_FUNCTION, KC_DEL)
#define SYMBOLS LT(_SYMBOLS, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
      KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
      KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
      MACROL ,GUI_A  ,ALT_S  ,SHI_D  , CTL_F , KC_G  ,                         KC_H  , CTL_J ,SHI_K  ,ALT_L  ,GUI_SC ,KC_QUOT,
      KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
                      KC_LEFT,KC_RGHT,                                                         KC_UP ,KC_DOWN,
                                      NAVI   ,MOUSPC ,                        SYMBOLS,NUMBER ,
                                      KC_LSFT,MEDIA  ,                        FUNCTIO,KC_DEL ,
                                      KC_LALT,GUILDW ,                        KC_LGUI,KC_LALT
  ),

  [_GUILDW] = LAYOUT_5x6(
      KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
      KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
      MACROL , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
      KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
                      _______,_______,                                                        _______,_______,
                                      KC_SPC ,KC_LCTL,                        KC_BSPC,KC_TAB ,
                                      KC_ENT ,KC_LSFT,                        KC_DEL ,_______,
                                      _______,QWERTY ,                        _______,_______
  ),

  [_MACROL] = LAYOUT_5x6(
      _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
      _______,KC_CAPS,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
      _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                      QWERTY ,_______,                                                        _______,_______,
                                      _______,_______,                        _______,_______,
                                      _______,_______,                        _______,_______,
                                      _______,_______,                        _______,_______
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
      _______,KC_PAUS,KC_SCRL,KC_PSCR,KC_CAPS,_______,                        _______,_______,_______,_______,_______,_______,
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
    QK_BOOT, KC_F9 , KC_F10, KC_F11, KC_F12,_______,                          _______,_______,_______,_______,_______,_______,
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

