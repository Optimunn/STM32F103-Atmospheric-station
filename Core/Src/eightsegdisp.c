#include "eightsegdisp.h"
#include "dispfonts.h"
#include "main.h"

uint8_t light_up_sector(disp_seg_pins_t *disp_seg, uint8_t number, fonts_t fon, GPIO_PinState point, uint8_t display)
{
    uint8_t sector = 0b0;
    if (fon == font_hex)
        sector = fonts_hex[number];
    else if (fon == font_spec)
        sector = fonts_spec[number];
    HAL_GPIO_WritePin(disp_seg->disp1.port, disp_seg->disp1.pin, display ^ 0b1000);
    HAL_GPIO_WritePin(disp_seg->disp2.port, disp_seg->disp2.pin, display ^ 0b0100);
    HAL_GPIO_WritePin(disp_seg->disp3.port, disp_seg->disp3.pin, display ^ 0b0010);
    HAL_GPIO_WritePin(disp_seg->disp4.port, disp_seg->disp4.pin, display ^ 0b0001);

    HAL_GPIO_WritePin(disp_seg->seg_a.port, disp_seg->seg_a.pin, sector & 0b10000000);
    HAL_GPIO_WritePin(disp_seg->seg_b.port, disp_seg->seg_b.pin, sector & 0b01000000);
    HAL_GPIO_WritePin(disp_seg->seg_c.port, disp_seg->seg_c.pin, sector & 0b00100000);
    HAL_GPIO_WritePin(disp_seg->seg_d.port, disp_seg->seg_d.pin, sector & 0b00010000);
    HAL_GPIO_WritePin(disp_seg->seg_e.port, disp_seg->seg_e.pin, sector & 0b00001000);
    HAL_GPIO_WritePin(disp_seg->seg_f.port, disp_seg->seg_f.pin, sector & 0b00000100);
    HAL_GPIO_WritePin(disp_seg->seg_g.port, disp_seg->seg_g.pin, sector & 0b00000010);
    HAL_GPIO_WritePin(disp_seg->point.port, disp_seg->point.pin, point  & 0b00000001);
    return 0;
}

uint8_t disp_print(disp_seg_pins_t *disp_seg, uint8_t world[4], uint8_t point, fonts_t fon[4], uint8_t frequency)
{
    static uint32_t counter = 1;
    static uint8_t item = 1;
    static uint8_t index = 0;
    if ((HAL_GetTick() - counter) > (uint8_t)(250 / frequency))
    {
        counter = HAL_GetTick();
        uint8_t pnt = 0;
        if (point == index + 1)
            pnt = 1;
        light_up_sector(disp_seg, world[index], fon[index], pnt, item);
        item = item << 1;
        index++;
        if (item > 9)
        {
            item = 1;
            index = 0;
        }
    }
    return 0;
}