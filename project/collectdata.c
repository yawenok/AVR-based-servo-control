#include"std.h"
#include"globle.h"

void Int0_Init(void);
void Int0_isr(void);
void CollectData_Init(void);
int  Read_M_Rate(void);

void Int0_Init(void)
{
  EICRA|=BIT(ISC01);
  EIMSK|=BIT(INT0);
  
  DDR_INT0&=~BIT(INT0_BIT);
  PORT_INT0|=BIT(INT0_BIT); 
  
  DDR_PCINT&=~BIT(PCINT_BIT);
  PORT_PCINT|=BIT(PCINT_BIT);
}

#pragma interrupt_handler Int0_isr:iv_INT0
void Int0_isr(void)
{	
    CLI();
	COLL_LED;
	CHANGE_INT0_EDGE;
	if( (INT0_PORT_L && INT1_PORT_H) ||(INT0_PORT_H && INT1_PORT_L))
	{
	 g_pulse_counter++;
	 g_all_pulse++;
	}
	else
	{
	 g_pulse_counter--;
	 g_all_pulse--;
	}
	SEI();
}
void CollectData_Init(void)
{
  Int0_Init();
}
int Read_M_Rate(void)
{ 
  int nMRate = 0;
  CLI();
  nMRate = g_pulse_counter;
  g_pulse_counter = 0;
  SEI();
  return nMRate;
}