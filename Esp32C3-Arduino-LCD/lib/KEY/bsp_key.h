#ifndef  __BSP_KEY_H
#define __BSP_KEY_H
#include "Arduino.h"

// 4,5,8,9,13
#define KEY_DOWN    13
#define KEY_LEFT    5
#define KEY_UP      8
#define KEY_RIGHT   9
#define KEY_CENTER  4


#define KEY_LEFT_VALUE    digitalRead(KEY_LEFT)
#define KEY_RIGHT_VALUE   digitalRead(KEY_RIGHT)
#define KEY_UP_VALUE      digitalRead(KEY_UP)
#define KEY_DOWN_VALUE    digitalRead(KEY_DOWN)
#define KEY_CENTER_VALUE  digitalRead(KEY_CENTER)
#define KEY_IS_PRESS      (0 == (KEY_LEFT_VALUE&&KEY_RIGHT_VALUE&&KEY_UP_VALUE&&KEY_DOWN_VALUE&&KEY_CENTER_VALUE))
#define KEY_RELEASE       (1 == (KEY_LEFT_VALUE&&KEY_RIGHT_VALUE&&KEY_UP_VALUE&&KEY_DOWN_VALUE&&KEY_CENTER_VALUE))

typedef enum {
  KEY_No_PRESS      = 0u,
  KEY_RIGHT_PRESS   = 1u,
  KEY_DOWN_PRESS    = 2u,
  KEY_UP_PRESS      = 3u,
  KEY_LEFT_PRESS    = 4u,
  KEY_CENTER_PRESS  = 5u
}Key_States;


void  initKeys(void);
uint8_t Key_Scan(bool IsContinuMode);

#endif //__BSP_KEY_H