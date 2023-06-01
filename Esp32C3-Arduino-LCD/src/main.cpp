// #include <Arduino.h>
// #include <TFT_eSPI.h>
// #include <math.h>

// #define PIN_LED1 12
// #define PIN_LED2 13
// TFT_eSPI tft;

// void setup() {
//   Serial.begin(115200);
//   Serial.println("Hello ESP32C3!!");

//   pinMode(PIN_LED1, OUTPUT);
//   pinMode(PIN_LED2, OUTPUT);

//   tft.begin();
//   tft.setRotation(3);
//   tft.setTextFont(2);
//   tft.fillScreen(TFT_BLACK);
//   tft.drawString("   Hello ESP32C3!!",10, 20);
//   tft.drawRect(2, 20, 100, 20, TFT_BROWN);
// }

// void loop() {
//   Serial.println("Hello ESP32C3!!");
//   digitalWrite(PIN_LED1, HIGH);
//   digitalWrite(PIN_LED2, LOW);
//   delay(200);
//   digitalWrite(PIN_LED2, HIGH);
//   digitalWrite(PIN_LED1, LOW);
//   delay(200);
// }
#include "LuatOS_C3.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_wifi.h"
#include "bsp_lcd.h"
#include "bsp_timer.h"

unsigned long lastMs = 0;
long check1s = 0;

void setup() {
  //disableCore0WDT();
  enableCore0WDT();
  Serial.begin(115200);
  Serial.println("Hello ESP32C3!!");
  initTFT();
  initLEDs();
  initKeys();

  Serial.println("Start Config WiFi!");
  autoConfigWifi();
  Serial.println("SWifi Connected!");
  tft.println("Wifi Connected!");
  sprintf(buf, "IP: %s", WiFi.localIP().toString().c_str());
  tft.println(buf);
  configTime(TZ_SEC, DST_SEC, "ntp.ntsc.ac.cn", "ntp1.aliyun.com");
  delay(2000);
  drawBuf.createSprite(TFT_HEIGHT, TFT_WIDTH);
  setupOTAConfig();
  tft.fillScreen(TFT_BLACK);
  
}

void loop() {
  auto ms = millis();
  if(KEY_CENTER_PRESS == Key_Scan(false)){
    LED_Toggle(LED0_PIN);
    LED_Toggle(LED1_PIN);
  }
  
  if (ms - check1s > 1000) {
    check1s = ms;
    showCurrentTime();
    ArduinoOTA.handle();
  }
}