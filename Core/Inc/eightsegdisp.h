/**
 * @author Alex
 * @date 2024-11-16
 *
 * @file           : eightsegdisp.h
 * @brief          : Header for main.c file.
 *                 This file contains the function and structures for the 7-segments indicator.
 */

#ifndef __EIGHTSEGDISP_H__
#define __EIGHTSEGDISP_H__

#include "main.h"

typedef enum fonts_s
{
    font_hex = 0,
    font_spec = 1
} fonts_t;

typedef struct seg_font_s
{
    fonts_t disp1;
    fonts_t disp2;
    fonts_t disp3;
    fonts_t disp4;
} seg_font_t;

typedef struct pin_s
{
    GPIO_TypeDef *port;
    uint16_t pin;
} pin_t;
/**
 *   @note The picture of segment letters
 *   _____________
 *  |       A     |
 *  | _  _____  _ |
 *  |   |     |   |
 *  | F |     | B |
 *  |   |     |   |
 *  |¯ ¯¯¯ G ¯¯¯ ¯|
 *  | _  _____  _ |
 *  |   |     |   |
 *  | E |     | C |
 *  |   |     |   |
 *  |¯ ¯¯¯¯¯¯¯¯¯ ¯|
 *  |       D     |
 *   ¯¯¯¯¯¯¯¯¯¯¯¯¯  point
 */
typedef struct disp_seg_pins_s
{
    pin_t seg_a;
    pin_t seg_b;
    pin_t seg_c;
    pin_t seg_d;
    pin_t seg_e;
    pin_t seg_f;
    pin_t seg_g;
    pin_t point;
    pin_t disp1;
    pin_t disp2;
    pin_t disp3;
    pin_t disp4;
} disp_seg_pins_t;
/**
 *   Function to light up a sector in the 7-segment with point display.
 *   @param disp_seg: Pointer to the structure containing the GPIO pins for the 7-segment display.
 *   @param num: Number which transmitted in the 7-segment indicator.
 *   @param fon: Font type (hexadecimal or special) (see file "dispfonts.h" for more information).
 *   @param point: Point display state (1 point light up or 0 point not light up).
 *   @param display: Number of sector (1-4).
 *   @return 1 if error, 0 if success.
 */
uint8_t light_up_sector(disp_seg_pins_t *disp_seg, uint8_t number, fonts_t fon, GPIO_PinState point, uint8_t display);
/**
 *   Function to light up all the sectors in the 7-segments indicator.
 *   @param disp_seg: Pointer to the structure containing the GPIO pins for the 7-segment display.
 *   @param world: Array of number in fonts which transmitted in the 7-segment indicator.
 *   @param point: Point display state (1-4 sectors where be used point or 0 point not used).
 *   @param fon: Fonts used for each segment of the display (in order) (see file "dispfonts.h" for more information).
 *   @param frequency: Frequency in hertz for update display (min 1 max 125).
 *   @return 1 if error, 0 if success.
 */
uint8_t disp_print(disp_seg_pins_t *disp_seg, uint8_t world[4], uint8_t point, fonts_t fon[4], uint8_t frequency);

#endif