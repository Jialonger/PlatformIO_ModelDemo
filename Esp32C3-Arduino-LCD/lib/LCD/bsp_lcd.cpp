#include "bsp_lcd.h"

char buf[32] = {0};
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite drawBuf(&tft);

void inline setLCDBrightness(int bri) { ledcWrite(0, bri); }

void initTFT(void) {
  tft.begin();
  tft.setRotation(3);
  tft.setTextFont(2);
  tft.fillScreen(TFT_BLACK);
  pinMode(TFT_BL, OUTPUT);
  ledcSetup(0, 1000, 10);
  ledcAttachPin(TFT_BL, 0);
  setLCDBrightness(100);
}

void showCurrentTime(void) {
  struct tm info;
  getLocalTime(&info);
  strftime(buf, 32, "%T", &info);
  drawBuf.fillRect(0, 0, TFT_HEIGHT, TFT_WIDTH, TFT_BLACK);
  drawBuf.setTextColor(TFT_CYAN);
  drawBuf.setFreeFont(&FreeSerifBold18pt7b);
  drawBuf.drawCentreString(buf, 80, 10, 1);
  strftime(buf, 32, "%F", &info);
  drawBuf.setTextColor(TFT_GREEN);
  drawBuf.setFreeFont(&FreeSerifBold12pt7b);
  drawBuf.drawCentreString(buf, 80, 50, 1);
  drawBuf.pushSprite(0, 0);
}