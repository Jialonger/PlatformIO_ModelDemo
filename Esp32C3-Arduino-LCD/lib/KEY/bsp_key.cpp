#include "bsp_key.h"

void initKeys() {
    uint8_t PIN_KEYS[] = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, KEY_CENTER};
    for (int i = 0; i < sizeof(PIN_KEYS); i++) {
        pinMode(PIN_KEYS[i], INPUT_PULLUP);
    }
}

uint8_t Key_Scan(bool IsContinuMode){
  uint8_t Key_states = KEY_No_PRESS;
  static bool Key_Isrelease  = true;
  if(1 == IsContinuMode)
  {
      Key_Isrelease = true;
  }

  if(Key_Isrelease && KEY_IS_PRESS){
    delay(10);
    if(KEY_IS_PRESS)
    {
      Key_Isrelease = false; //按键已经按下
      if(0 == KEY_LEFT_VALUE)
        Key_states = KEY_LEFT_PRESS;
      if(0 == KEY_RIGHT_VALUE)
        Key_states = KEY_RIGHT_PRESS;
      if(0 == KEY_DOWN_VALUE)
        Key_states = KEY_DOWN_PRESS;
      if(0 == KEY_CENTER_VALUE)
        Key_states = KEY_CENTER_PRESS;
      if(0 == KEY_UP_VALUE)
        Key_states = KEY_UP_PRESS;
	    Serial.printf("KEY STATE = %d\r\n", Key_states);
    }
  }else if(KEY_RELEASE){
    Key_states = KEY_No_PRESS;
    Key_Isrelease = true;
  }

  return Key_states;

}