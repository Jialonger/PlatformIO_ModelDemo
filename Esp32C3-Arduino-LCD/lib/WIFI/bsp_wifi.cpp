#include "bsp_wifi.h"



void setupOTAConfig(void) {
  ArduinoOTA.onStart([] {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_PINK, TFT_BLACK);
    tft.drawCentreString("OTA Update", 80, 10, 2);
    tft.drawRoundRect(30, 40, 100, 10, 2, TFT_ORANGE);
  });
  ArduinoOTA.onProgress([](u32_t pro, u32_t total) {
    tft.setTextColor(TFT_SKYBLUE, TFT_BLACK);
    sprintf(buf, "%d / %d", pro, total);
    tft.drawCentreString(buf, 80, 60, 2);
    int pros = pro * 100 / total;
    tft.fillRoundRect(30, 40, pros, 10, 2, TFT_ORANGE);
  });
  ArduinoOTA.onEnd([] {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.drawCentreString("Update Succeed!!", 80, 20, 2);
    tft.setTextColor(TFT_SKYBLUE, TFT_BLACK);
    tft.drawCentreString("Restarting...", 80, 40, 2);
  });
  ArduinoOTA.onError([](ota_error_t err) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_RED, TFT_BLACK);
    sprintf(buf, "OTA Error [%d]!!", err);
    tft.drawCentreString(buf, 80, 30, 2);
  });
  ArduinoOTA.begin();
}


void  autoConfigWifi(void) {
  WiFi.mode(WIFI_MODE_STA);
  WiFi.begin();
  for (int i = 0; WiFi.status() != WL_CONNECTED && i < 100; i++) {
    delay(100);
  }
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.mode(WIFI_MODE_APSTA);
    WiFi.beginSmartConfig();
    Serial.println("Waiting for smartConfig.");
    while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      Serial.print(".");
    }
    WiFi.stopSmartConfig();
    WiFi.mode(WIFI_MODE_STA);
  }
}