## Atmospheric station with 4 sector eight-segment display based on STM32F103 MCU

This project used stm32 which counts time tick and switches eight-segment display also stm32 get pressure and temperature from bme280 sensor.

#### Some explanations on the code

In main.c file:

Converts a number to array:

```c
void float_to_array(float num, uint8_t *arr, uint8_t size)
```

Example: (3.14 -> {3, 1, 4})

Init all pins connected to eight-segment display:

```c
disp_seg_pins_t display = {...}
```

##### For more information view file main.c