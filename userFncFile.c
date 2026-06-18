#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "inc/userFncFile.h"
#include "inc/systemTimer.h"
#include "inc/led_Status.h"
#include "inc/led_Led2.h"
#include "inc/led_Led3.h"
#include "inc/led_Led4.h"
#include "inc/led_Led5.h"
#include "inc/timer_api1.h"
#include "inc/Digital.h"
#include "inc/Counter_Cnt1.h"
#include "inc/Counter_Cnt2.h"
#include "inc/Counter_Cnt3.h"
#include "inc/Counter_Cnt4.h"
#include "inc/conversionFunctions.h"
#include "inc/EMICBus.h"

/* User Variables */
uint32_t rpm = 0;
uint32_t pos = 0;

void onReset()
{
    LEDs_Led2_blink(100, 200, 5);
    pos = 0;
    Counter_Cnt1_setEdge(1);
    Counter_Cnt1_setTimeBase(2000, 'A');
    LEDs_Status_state(1);
}


void Counter_Cnt1_onTimeBase(uint32_t count)
{
    LEDs_Led2_blink(100, 101, 1);
    rpm = 30 * count;
}



