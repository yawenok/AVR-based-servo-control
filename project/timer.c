#include"std.h"
#include"globle.h"
/********************************************************/
/*                      函数声明
/********************************************************/

void Timer0_Init(void);
void Timer0_ovf_isr(void);
BOOL Is100ms(void);
BOOL Is_Sampling_Time(void);

// TIMER0 initialize - prescale:256
// WGM: Normal
// desired value: 1000Hz
// actual value: 1002.354Hz (0.2%)
// 定时1ms
void Timer0_Init(void)
{
	TCCR0B = 0x00;  //stop
 	TCNT0 = 0xB9;   //set count
 	TCCR0A = 0x00; 
 	TCCR0B = 0x04;  //start timer
	TIMSK0 |= BIT(1);
}
/********************************************************/
/*                    静态变量声明
/********************************************************/
#pragma interrupt_handler Timer0_ovf_isr:iv_TIM0_OVF
void Timer0_ovf_isr(void)
{ 
  TCNT0 = 0xB9;
  g_LEDms++;
  g_ms++;
  g_MeasureTime++;
}
BOOL IsLEDTime(void)
{
 if(g_LEDms >= LEDTIME) 
 {
  g_LEDms = 0;
  return TRUE;
 }
 return FALSE;
}
BOOL Is_Sampling_Time(void)
{
  if(g_MeasureTime >= MEASURETIME)
  {
   g_MeasureTime = 0;
   return TRUE;
  }
  return FALSE;
}