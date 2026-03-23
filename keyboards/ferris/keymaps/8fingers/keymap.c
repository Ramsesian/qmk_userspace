#include QMK_KEYBOARD_H

//this let's you define custom layer names.
//You have to put down the names as you'd expect them to appear, no layer can be named the same thing.
//That's because secretly it's going first enum: 0, second enum: 1, etc.
enum layer_names {
    _QWERTY,
    _TALON,
    _BOOT,
};


//lets you make shortcuts for keys to make things a bit more readable.
//layer switches
#define BOOT MO(_BOOT)
#define TALONM MO(_TALON)
#define TALONT TG(_TALON)

//shortcuts
#define WINLEFT G(S(KC_LEFT)) //super-shift-left
#define WINRGHT G(S(KC_RIGHT)) //super-shift-right
#define DELEFT C(A(KC_LEFT))
#define DERIGHT C(A(KC_RIGHT))

//alt try combos
//use combos those are far superior

enum combos {
    SD_SPACE,
    DF_ENTER,
    KL_BKSP,
    SV_SUPER
};

// define combo sequences here
/* lets try this again. lets try a vertical combo so I can hit it with one key.
then lets try with one on both side
then lets try replacing an uncommon key with it.
check out the config for it as well
*/
const uint16_t PROGMEM enter_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM space_combo[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM backspace_combo[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM super_combo[] = {KC_S, KC_C, COMBO_END};


// when you hit a combo sequence you output X
combo_t key_combos[] = {
    [SD_SPACE] = COMBO(space_combo, KC_SPACE),
    [DF_ENTER] = COMBO(enter_combo, KC_ENTER),
    [KL_BKSP] = COMBO(backspace_combo, KC_BACKSPACE),
    [SV_SUPER] = COMBO(super_combo, KC_LWIN),
};
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

enum tap_dance_actions {
    QESC,

};

tap_dance_action_t tap_dance_actions[] = {
    [QESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESCAPE)
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_split_3x5_2(
    //,--------+------------+------------+---------+---------.              ,--------+--------+---------------+--------------+---------------.
       TD(QESC),        KC_W,        KC_E,     KC_R,     KC_T,                   KC_Y,    KC_U,           KC_I,          KC_O,           KC_P,
    //|--------+------------+------------+---------+---------|              |--------+--------+---------------+--------------+---------------|
    SFT_T(KC_A),        KC_S,        KC_D,     KC_F,     KC_G,                   KC_H,    KC_J,           KC_K,          KC_L, SFT_T(KC_SCLN),
    //|--------+------------+------------+---------+---------|              |--------+--------+---------------+--------------+---------------|
           KC_B, CTL_T(KC_Z), ALT_T(KC_X),     KC_C,     KC_V,                   KC_N,    KC_M, ALT_T(KC_COMM), CTL_T(KC_DOT),       KC_QUOTE,
    //|--------+------------+------------+---------+---------|              |--------+--------+---------------+--------------+---------------|
                                               BOOT,  XXXXXXX,                  TALONM, TALONT
    //                                   `-------------------'              `-----------------'

    ),

    [_TALON] = LAYOUT_split_3x5_2(
    //,--------+--------+--------+--------+--------.              ,--------+--------+--------+--------+--------.
        XXXXXXX,  DELEFT, DERIGHT, XXXXXXX, XXXXXXX,                XXXXXXX, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_F18, XXXXXXX,
    //|--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------|
      A(KC_TAB), WINLEFT, WINRGHT,  KC_F13, XXXXXXX,                XXXXXXX, KC_ENTER,MS_WHLD, MS_WHLU,  KC_F17, //MS WHLD/WHLU refer to mouse wheel down/up respectively
    //|--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------|
      KC_LALT, S(KC_TAB),  KC_TAB, XXXXXXX, XXXXXXX,                XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    //|--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------|
                                   XXXXXXX, XXXXXXX,                _______, _______
    //                           `-----------------'              `-----------------'
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
