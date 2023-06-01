#include "bsp_timer.h"
// hw_timer_t *timer1 = NULL;


// void tierm1Interrupt(void)
// {
//     Serial.println("定时器1触发");
//     Serial.println(timerAlarmEnabled(timer1));
// }

// /* 100ms */
// void Tiemr_init(void)
// {
//     timer1 = timerBegin(0, 80, true);
//     timerAttachInterrupt(timer1, tierm1Interrupt, true);
//     timerSetConfig(timer1,0);
//     timerAlarmWrite(timer1, 100000ul, true);
//     timerAlarmEnable(timer1);
// }