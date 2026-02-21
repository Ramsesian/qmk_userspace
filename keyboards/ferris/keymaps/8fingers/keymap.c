#include QMK_KEYBOARD_H

//this let's you define custom layer names.
//You have to put down the names as you'd expect them to appear, no layer can be named the same thing. 
//That's because secretly it's going first enum: 0, second enum: 1, etc.
enum layer_names {
  _TALON,
  _BOOT,
};

//lets you make shortcuts for keys to make things a bit more readable.
#define BOOT MO(_BOOT)

//Pro Micro With The Bootloader ATmega32U4 5V/16MHz Module Controller Mega32U4 Leonardo For Arduino


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_TALON] = LAYOUT_split_3x5_2(
    //,--------+--------+--------+--------+--------.              ,--------+--------+--------+--------+--------.
         KC_F13,  KC_F14,  KC_F15,  KC_F16, XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    //|--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------|
         KC_F17,  KC_F18,  KC_F19,  KC_F20, XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    //|--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------|
         KC_F21,  KC_F22,  KC_F23,  KC_F24, XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    //|--------+--------+--------+--------+--------|              |--------+--------+--------+--------+--------|
                                      BOOT, XXXXXXX,                XXXXXXX, XXXXXXX
    //                           `-----------------'              `-----------------'
    ),

    // ADD SPLIT KEYBOARD TO YOUR RULES.MK BEFORE FLASHING

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
