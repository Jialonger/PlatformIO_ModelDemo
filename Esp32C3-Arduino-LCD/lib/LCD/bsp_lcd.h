#ifndef __BSP_LCD_H
#define __BSP_LCD_H
#include "Arduino.h"
#include <TFT_eSPI.h>


#define TZ 8            // 中国时区为8
#define DST_MN 0        // 默认为0
#define TZ_MN ((TZ)*60) //时间换算
#define TZ_SEC ((TZ)*3600)
#define DST_SEC ((DST_MN)*60)

extern TFT_eSPI tft;
extern char buf[];
extern TFT_eSprite drawBuf;

void initTFT(void);
void showCurrentTime(void);

#endif //_BSP_LCD_H