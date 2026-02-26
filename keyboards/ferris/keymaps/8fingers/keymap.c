#include QMK_KEYBOARD_H

//this let's you define custom layer names.
//You have to put down the names as you'd expect them to appear, no layer can be named the same thing. 
//That's because secretly it's going first enum: 0, second enum: 1, etc.
enum layer_names {
  _TALON,
  _QWERTY,
  _BOOT,
};

//lets you make shortcuts for keys to make things a bit more readable.
//layer switches
#define BOOT MO(_BOOT)
#define QWERTY TG(_QWERTY)


//shortcuts
#define WINLEFT G(S(KC_LEFT)) //super-shift-left
#define WINRGHT G(S(KC_RIGHT)) //super-shift-right
#define DELEFT C(A(KC_LEFT))
#define DERIGHT C(A(KC_RIGHT))

//alt try combos
//use combos those are far superior




//Pro Micro With The Bootloader ATmega32U4 5V/16MHz Module Controller Mega32U4 Leonardo For Arduino

/*
How to use tap dance in your keyboard
enum tap_dance_actions {
    TAP_DANCE_NAME
};

tap_dance_action_t tap_dance_actions[] = { 
    [TAP_DANCE_NAME] = ACTION_TAP_DANCE_DOUBLE(key code one, key code two)
};

in your keyboard you use TD(TAP_DANCE_NAME)
*/



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_TALON] = LAYOUT_split_3x5_2(
    //,--------+--------+--------+--------+--------.              ,--------+--------+--------+--------+--------.
        XXXXXXX,  DELEFT, DERIGHT,  KC_F16, XXXXXXX,                XXXXXXX, XXXXXXX, KC_F17, KC_F18, XXXXXXX, 
    //|--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------|
      A(KC_TAB), WINLEFT, WINRGHT,  KC_F13, XXXXXXX,                XXXXXXX, MS_WHLU, MS_WHLD, KC_ENTER, KC_F19, //MS WHLD/WHLU refer to mouse wheel down/up respectively
    //|--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------|
      KC_LALT, S(KC_TAB),  KC_TAB,  KC_F24, XXXXXXX,                XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, 
    //|--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------|
                                      BOOT, XXXXXXX,                QWERTY, XXXXXXX 
    //                           `-----------------'              `-----------------'
    ),

    [_QWERTY] = LAYOUT_split_3x5_2(
    //,--------+------------+------------+---------+---------.              ,--------+--------+---------------+--------------+---------------.
           KC_Q,        KC_W,        KC_E,     KC_R,     KC_T,                   KC_Y,    KC_U,           KC_I,          KC_O,           KC_P, 
    //|--------+------------+------------+---------+---------|              |--------+--------+---------------+--------------+---------------|
    SFT_T(KC_A),        KC_S,        KC_D,     KC_F,     KC_G,                   KC_H,    KC_J,           KC_K,          KC_L, SFT_T(KC_SCLN), 
    //|--------+------------+------------+---------+---------|              |--------+--------+---------------+--------------+---------------|
           KC_Z, CTL_T(KC_X), ALT_T(KC_C),     KC_V,     KC_B,                   KC_N,    KC_M, ALT_T(KC_COMM), CTL_T(KC_DOT),       KC_QUOTE, 
    //|--------+------------+------------+---------+---------|              |--------+--------+---------------+--------------+---------------|
                                           KC_SPACE, KC_ENTER,                _______, KC_BACKSPACE
    //                                   `-------------------'              `-----------------'

    ),

    [_BOOT] = LAYOUT_split_3x5_2(
    //,--------+--------+--------+--------+--------.              ,--------+--------+--------+--------+--------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    //|--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    //|--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    //|--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------|
                                   _______, XXXXXXX,                XXXXXXX, XXXXXXX
    //                           `-----------------'              `-----------------'
    )
};
