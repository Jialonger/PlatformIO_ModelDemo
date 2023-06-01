#ifndef __BSP_LED_h
#define __BSP_LED_h
#include <Arduino.h>

typedef enum{
    LED0_PIN = 12,
    LED1_PIN = 13,
    LED_NUNBLE = 2
}LEDx_PIN;

void initLEDs(void);
void LED_Toggle(uint8_t pin);

#endif //_BSP_LED_h