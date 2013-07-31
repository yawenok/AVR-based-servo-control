#include"std.h"
#include"pid.h"
#include"globle.h"
#include"timer.h"
#include"SP027.h"
#include"system.h"
#include"queue.h"
void main(void)
{
  G_Var_Init();
  Syetem_Device_Init();
  Inspect_status();
  
  while(TRUE)
  {
   if(Is_Sampling_Time())
   {
     M_Control(&g_speed);
	 //AM_Control(2);
	 //DisplayINTNum_SP027(g_pulse_counter);
   }
   if(IsLEDTime()) WORK_LED;
   WDR();
  }
}