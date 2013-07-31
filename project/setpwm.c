#include"std.h"

/********************************************************/
/*                      函数声明
/********************************************************/
void Pwm_Port_Init(void);
void Timer1_Init(void);
void Set_M_Pwm(int matchbyte);
void Pwm_Init_Devices(void);

void Pwm_Port_Init(void)
{
  DDRB|=BIT(1);//通道1输出
}
// TIMER1 initialize - prescale:1
// WGM: 14) PWM fast, TOP=ICRn
// desired value: 15KHz
// actual value: 15.010KHz (0.1%)
void Timer1_Init(void)
{
 CLI();
 TCCR1B = 0x00; //stop
 TCNT1H = 0xFB; //setup
 TCNT1L = 0x35; //设置起始值，主要作用是在刚开始的时候
 OCR1AH = 0x00;
 OCR1AL = 0x00;
 ICR1H  = 0x04;//1227
 ICR1L  = 0xCB;
 TCCR1A = 0x82;
 TCCR1B = 0x19; //start Timer
 SEI();
}
void Set_M_Pwm(int matchbyte)
{
 OCR1A = matchbyte;
}
void Pwm_Init_Devices(void)
{
 Pwm_Port_Init();
 Timer1_Init();
}
