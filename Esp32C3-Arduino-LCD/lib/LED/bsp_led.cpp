#include "bsp_led.h"

uint8_t PIN_LED[LED_NUNBLE] = {LED0_PIN,LED1_PIN};
uint8_t KEY_VALUE[14];

void initLEDs(void) {
  KEY_VALUE[0] = 12;
  KEY_VALUE[12] = 0;
  KEY_VALUE[1] = 13;
  KEY_VALUE[13] = 1;
  pinMode(PIN_LED[0], OUTPUT);
  pinMode(PIN_LED[1], OUTPUT);
  digitalWrite(PIN_LED[0], LOW);
  digitalWrite(PIN_LED[1], LOW);
}

void LED_Toggle(uint8_t pin)
{
  static bool states_led[LED_NUNBLE] = {false,false};
  if((pin == LED1_PIN)||(pin == LED0_PIN))
  {
    states_led[KEY_VALUE[pin]] = !states_led[KEY_VALUE[pin]];
    digitalWrite(pin,states_led[KEY_VALUE[pin]]);
  }
}