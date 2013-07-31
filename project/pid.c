#include"std.h"
#include"setpwm.h"
#include"globle.h"
#include"collectdata.h"
#include"decode.h"
/********************************************************/
/*                      函数声明
/********************************************************/


short LimitValue(long nLimitValue,long nMax);
void  Inspect_status(void);
void  PID_Output(short output);
void  AM_Control(short target);
void  BM_Control(short target);
void  CM_Control(short target);
void  DM_Control(short target);
void  EM_Control(short target);
void  FM_Control(short target);
void  M_Control(SPEED *pspeed);

void  PID_Init(PID *pPIDDATA,double P,double I,double D);
//PID小组老算法
void  PID_Calculate(PID *pPIDDATA,int goal,int feedback);


void AM_Control(short target)
{
  static BOOL bIsFrist = TRUE;
  static int  Collectdata = 0;
  if(bIsFrist)
  { 
    PID_Init(&g_PID,1.5f,0.25f,0.5f);
	bIsFrist = FALSE;
  } 
  Collectdata = -Read_M_Rate();
  //将调节范围进行限制 防止超调
  g_PID.nOutput = LimitValue(g_PID.nOutput,PWM_TOP);
  PID_Calculate(&g_PID,target,Collectdata);
  PID_Output(g_PID.nOutput);
}
void BM_Control(short target)
{
  static BOOL bIsFrist = TRUE;
  static int  Collectdata = 0;
  if(bIsFrist)
  { 
    PID_Init(&g_PID,1.5f,0.25f,0.5f);
	bIsFrist = FALSE;
  } 
  Collectdata = Read_M_Rate();
  //将调节范围进行限制 防止超调
  g_PID.nOutput = LimitValue(g_PID.nOutput,PWM_TOP);
  PID_Calculate(&g_PID,target,Collectdata);
  PID_Output(g_PID.nOutput);
}
void CM_Control(short target)
{
  static BOOL bIsFrist = TRUE;
  static int  Collectdata = 0;
  if(bIsFrist)
  { 
    PID_Init(&g_PID,1.5f,0.25f,0.5f);
	bIsFrist = FALSE;
  } 
  Collectdata = Read_M_Rate();
  //将调节范围进行限制 防止超调
  g_PID.nOutput = LimitValue(g_PID.nOutput,PWM_TOP);
  PID_Calculate(&g_PID,target,Collectdata);
  PID_Output(-g_PID.nOutput);
}
void DM_Control(short target)
{
  static BOOL bIsFrist = TRUE;
  static int  Collectdata = 0;
  if(bIsFrist)
  { 
    PID_Init(&g_PID,1.5f,0.25f,0.5f);
	bIsFrist = FALSE;
  } 
  Collectdata = Read_M_Rate();
  //将调节范围进行限制 防止超调
  g_PID.nOutput = LimitValue(g_PID.nOutput,PWM_TOP);
  PID_Calculate(&g_PID,target,Collectdata);
  PID_Output(g_PID.nOutput);
}
void EM_Control(short target)
{
  static BOOL bIsFrist = TRUE;
  static int  Collectdata = 0;
  if(bIsFrist)
  { 
    PID_Init(&g_PID,1.5f,0.25f,0.5f);
	bIsFrist = FALSE;
  } 
  Collectdata = -Read_M_Rate();
  //将调节范围进行限制 防止超调
  g_PID.nOutput = LimitValue(g_PID.nOutput,PWM_TOP);
  PID_Calculate(&g_PID,target,Collectdata);
  PID_Output(-g_PID.nOutput);
}
void FM_Control(short target)
{
  static BOOL bIsFrist = TRUE;
  static int  Collectdata = 0;
  if(bIsFrist)
  { 
    PID_Init(&g_PID,1.5f,0.25f,0.5f);
	bIsFrist = FALSE;
  } 
  Collectdata = Read_M_Rate();
  //将调节范围进行限制 防止超调
  g_PID.nOutput = LimitValue(g_PID.nOutput,PWM_TOP);
  PID_Calculate(&g_PID,target,Collectdata);
  PID_Output(g_PID.nOutput);
}



static int g_ID = 0;
void Inspect_status(void)
{
  DDRD&=~BIT(4);
  DDRD&=~BIT(5);
  DDRD&=~BIT(6);
  PORTD|=BIT(4)|BIT(5)|BIT(6);
  if((PIND&BIT(4))&&(!(PIND&BIT(5)))&&(!(PIND&BIT(6))))
  {
   g_ID=2;
  }
  else if((!(PIND&BIT(4)))&&(PIND&BIT(5))&&(PIND&BIT(6)))
  {
   g_ID=4;      
  }
  else if((PIND&BIT(4))&&(PIND&BIT(5))&&(PIND&BIT(6)))
  {
   g_ID=3;
  }
  else if((!(PIND&BIT(4)))&&(!(PIND&BIT(5)))&&(!(PIND&BIT(6))))
  {
   g_ID=1;      
  } 
  else if((!(PIND&BIT(4)))&&(PIND&BIT(5))&&(!(PIND&BIT(6))))
  {
   g_ID=5;
  }
  else if((!(PIND&BIT(4)))&&(!(PIND&BIT(5)))&&(PIND&BIT(6)))
  {
   g_ID=6;
  }  
}
void M_Control(SPEED *pspeed)
{
   switch(g_ID)
   {
    case 1:
	 AM_Control(pspeed->A);
	 break;
	case 2:
	 BM_Control(pspeed->B);
	 break;
	case 3:
	CM_Control(pspeed->C);
	 break;
    case 4:
     DM_Control(pspeed->D);
	 break;
	case 5:
	 EM_Control(pspeed->E);
	 break;
    case 6:
	 FM_Control(pspeed->F);
	 break;
	default:
	 break;
   }
}

void PID_Init(PID *pPIDDATA,double P,double I,double D)
{
 pPIDDATA->nSet_Point = 0; 	
 pPIDDATA->nOutput = 0;					
 pPIDDATA->nPrev_Error = 0;		
 pPIDDATA->nLast_Error = 0; 
 
 pPIDDATA->Proportion = P; 
 pPIDDATA->Integral = I; 		
 pPIDDATA->Derivative = D;
}
//小组PID老算法
void PID_Calculate(PID *pPIDDATA,int goal,int feedback)
{
  pPIDDATA->nSet_Point = goal;
  //误差传递，即保存当前时刻误差，所以随时都保存有两个误差值：当前、上一个时刻
  pPIDDATA->nLast_Error = pPIDDATA->nPrev_Error;
  //计算当前值于指令值的误差
  pPIDDATA->nPrev_Error = pPIDDATA->nSet_Point-feedback;
  if((pPIDDATA->Proportion) < 0.0f)
  {
    //根据当前误差及时增减输出量
	pPIDDATA->nOutput += pPIDDATA->nPrev_Error/(-(pPIDDATA->Proportion));
  }
  else
  {  
    //根据当前误差及时增减输出量
	pPIDDATA->nOutput += pPIDDATA->nPrev_Error*(pPIDDATA->Proportion);                      
  }												
  if((pPIDDATA->Derivative) < 0.0f)
  { 
    //根据两个时刻的误差作比较的结果可以看出调节效果，并再次作出补偿调节
	pPIDDATA->nOutput += (pPIDDATA->nPrev_Error- pPIDDATA->nLast_Error) / (-(pPIDDATA->Derivative));
  }
  else
  {  
    //根据两个时刻的误差作比较的结果可以看出调节效果，并再次作出补偿调节
	pPIDDATA->nOutput += (pPIDDATA->nPrev_Error - pPIDDATA->nLast_Error) *(pPIDDATA->Derivative);
  }
}
void PID_Output(short output)
{
 if(output < 0)	
 {
  if(output < PWM_BOTTOM) output = PWM_BOTTOM;
  MOTOR_GO_BACK;
  Set_M_Pwm(-output);		
 }	
 else if(output > 0)
 {
  if(output > PWM_TOP) output = PWM_TOP;
  MOTOR_GO_AHEAD;
  Set_M_Pwm(output);	
 }
 else MOTOR_STOP;
}
short  LimitValue(long nLimitValue,long nMax)
{
  nLimitValue = fabs( nLimitValue ) < nMax ? nLimitValue 
  	                   : (nLimitValue < 0 ? -nMax : nMax ) ;
  				 
  return (short)nLimitValue;
}