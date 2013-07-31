#include"std.h"
#include"timer.h"
#include"pid.h"
#include"setpwm.h"
#include"communicate.h"
#include"collectdata.h"
#include"globle.h"
void Port_Init(void)
{
  DDRC |= BIT( PC2 );//BLED1
  PORTC |= BIT( PC2 );
  DDRD |= BIT( PD7 );//BLED2
  PORTD |= BIT( PD7 );
  //usart
  DDRD |= BIT( PD1 );//TX output

  //外部中断引脚配置，用于采集码盘反馈信息
  //INT0 Falling INT
  DDRD  &= ~BIT( PD2 );
  PORTD |=  BIT( PD2 );
  //PWM 通道1
  DDRB|=BIT(1);//通道1输出
  //SP027
  DDRC |= BIT( PC4 )|BIT( PC5 );
  //Motor port init
  DDRC |= BIT( PC0 )|BIT( PC1 );
  //Motor ID Pin
  DDRD &= ~BIT( 4 ) ;
  DDRD &= ~BIT( 5 ) ;
  DDRD &= ~BIT( 6 ) ;
  PORTD |= BIT( 4 )|BIT( 5 )|BIT( 6 );
}
void Motor_Port_Init(void)
{
 MOTOR_DDR_A |= BIT(MOTOR_BIT_A);//DDRC|=BIT(PC0);
 MOTOR_DDR_B |= BIT(MOTOR_BIT_B);//DDRC|=BIT(PC1);
 //STOP
 MOTOR_PORT_A &= ~BIT(MOTOR_BIT_A); 
 MOTOR_PORT_B &= ~BIT(MOTOR_BIT_B);
}
//Watchdog initialize
// prescale: 1024K
void Watchdog_init(void)
{
 WDR (); //this prevents a timeout on enabling
 WDTCSR |= (1<<WDCE) | (1<<WDE);/* 30-Oct-2006 Umesh*/  
 WDTCSR = 0x2D; //WATCHDOG ENABLED - dont forget to issue WDRs
}

void Syetem_Device_Init(void)
{
 CLI();
 Port_Init();
 Motor_Port_Init(); 
 CollectData_Init();
 Pwm_Init_Devices();
 Communicate_Init();
 Timer0_Init();
 Watchdog_init();
 
 MCUCR = 0x00;
 EICRA = 0x02; //extended ext ints [ INT0 Falling int ]
 EIMSK = 0x01;
 TIMSK0 = 0x01; //timer 0 interrupt sources
 TIMSK1 = 0x00; //timer 1 interrupt sources
 TIMSK2 = 0x00; //timer 2 interrupt sources
 PCMSK0 = 0x00; //pin change mask 0 
 PCMSK1 = 0x00; //pin change mask 1 
 PCMSK2 = 0x00; //pin change mask 2
 PCICR = 0x00;  //pin change enable 
 PRR = 0x00;    //power controller
 
 SEI();
}
