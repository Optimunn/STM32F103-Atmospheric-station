/**
 * @author Alex
 *
 * @file           : dispfonts.h
 * @brief          : Header for eightsegdisp.c file.
 *                 This file contains the fonts for the 7-segments indicator.
 */

#ifndef __DISPFONTS_H__
#define __DISPFONTS_H__

#include "main.h"

static const uint8_t fonts_hex[17] =
    {
        0b11111100, // 0
        0b01100000, // 1
        0b11011010, // 2
        0b11110010, // 3
        0b01100110, // 4
        0b10110110, // 5
        0b10111110, // 6
        0b11100000, // 7
        0b11111110, // 8
        0b11110110, // 9
        0b11101110, // A
        0b00111111, // B
        0b10011100, // C
        0b01111010, // D
        0b10011110, // E
        0b10001110, // F
};

static const uint8_t fonts_spec[9] =
    {
        0b00000000, // Space
        0b00000010, // minus
        0b11000110, // o in up
        0b00111010, // o in down
        0b00010000, // low dash
        0b10010000, // up and low dash
        0b10010010, // triple horizontal dash
        0b01101100, // double vertical dash
        0b11001110, // leather "P"
};

#endif