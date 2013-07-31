#include"std.h"
#include"queue.h"
long g_pulse_counter = 0;
long g_all_pulse = 0;
long g_LEDms = 0;
long g_ms = 0;
long g_MeasureTime = 0;

PID     g_PID = {0};
DATABUF g_databuf = {0};
SPEED   g_speed = {0,0,0,0,0,0};

void   G_Var_Init(void)
{
 g_PID.nSum_Error = 0;
 g_PID.nSet_Point = 0;
 g_PID.nOutput = 0;
 
 g_PID.Proportion = 0.0f;
 g_PID.Integral = 0.0f;
 g_PID.Derivative = 0.0f;
 
 g_PID.nPrev_Error = 0;
 g_PID.nLast_Error = 0;
	
 g_speed.A = 0;
 g_speed.B = 0;
 g_speed.C = 0;
 g_speed.D = 0;
 g_speed.E = 0;
 g_speed.F = 0;
 QueueInit(&g_databuf,MAX_SIZE);
 
}