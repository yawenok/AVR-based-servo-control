#ifndef _TYPEMACRO_H
#define _TYPEMACRO_H



/*=========================================================*
*   静态宏定义                                             *
*=========================================================*/
#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef NULL
#define NULL 0
#endif


/*=========================================================*
*   数据类型定义                                           *
*=========================================================*/

typedef unsigned int uint16;
typedef unsigned int UINT;
typedef unsigned int uint;
typedef unsigned int UINT16;
typedef unsigned int WORD;
typedef unsigned int word;
typedef int          int16;
typedef int          INT16;
typedef int          INT;
typedef unsigned long uint32;
typedef unsigned long UINT32;
typedef unsigned long DWORD;
typedef unsigned long dword;
typedef long          int32;
typedef long          INT32;

typedef signed   char int8;
typedef signed   char INT8;
typedef unsigned char byte;
typedef unsigned char BYTE;
typedef unsigned char UINT8;
typedef unsigned char uint8;
typedef unsigned char BOOL;


/*=========================================================*
*                   功能宏定义                            
*=========================================================*/
#define PWM_TOP             1100
#define PWM_BOTTOM          -1100

#define MOTOR_PORT_A	    PORTC
#define MOTOR_PORT_B	    PORTC

#define MOTOR_DDR_A	        DDRC
#define MOTOR_DDR_B	        DDRC

#define MOTOR_BIT_A	        PC0
#define MOTOR_BIT_B	        PC1

#define MOTOR_GO_AHEAD		{MOTOR_PORT_A |= BIT(MOTOR_BIT_A);  MOTOR_PORT_B &= ~BIT(MOTOR_BIT_B);}
#define MOTOR_GO_BACK		{MOTOR_PORT_A &= ~BIT(MOTOR_BIT_A); MOTOR_PORT_B |=  BIT(MOTOR_BIT_B);}
#define MOTOR_STOP			{MOTOR_PORT_A &= ~BIT(MOTOR_BIT_A); MOTOR_PORT_B &= ~BIT(MOTOR_BIT_B);}


#define WORK_LED            {DDRD|=BIT(7);PORTD^=BIT(7);}
#define COLL_LED            {DDRC|=BIT(2);PORTC^=BIT(2);}
//倍频

# define DDR_INT0          DDRD
# define PORT_INT0         PORTD
# define INT0_BIT          PD2 
# define PIN_INT0          PIND 
// 外部中断0的定义

# define DDR_PCINT         DDRD
# define PORT_PCINT        PORTD
# define PCINT_BIT         PD3
# define PIN_PCINT         PIND
//引脚电平变化处的定义

#define INT0_PORT            PD2
#define INT0_PORT_L        ( !(PIND & BIT(INT0_PORT)))
#define INT0_PORT_H        ( PIND & BIT( INT0_PORT))

#define INT1_PORT            PD3
#define INT1_PORT_L        ( !(PIND & BIT(INT1_PORT)))
#define INT1_PORT_H        ( PIND & BIT( INT1_PORT ))

# define CHANGE_INT0_EDGE  ( EICRA ^= BIT( ISC00 ))
/*=========================================================*
*                   参数宏定义                            
*=========================================================*/
#ifndef MAX_SIZE
 #define MAX_SIZE 128
#endif




#define MEASURETIME         4    
#define LEDTIME             500



#define MOTOR_A             0X00
#define MOTOR_B             0X10
#define MOTOR_C             0X70
#define MOTOR_D             0X60
#define MOTOR_E             0X20
#define MOTOR_F             0X40






/*=========================================================*
*   结构体定义                                             *
*=========================================================*/

//PID参数设计						
typedef struct tagPID
{			
	
	 int nSum_Error;         //  误差累计
	 int nSet_Point;         //  设定目标 
	 int nOutput;			 //	 PID运算输出值	
	 					
     double Proportion;      //  比例常数 	 
	 double Integral;        //  积分常数 	 		
     double Derivative;      //  微分常数  
	 
	 int nPrev_Error;        //  当前误差			
     int nLast_Error;        //  上次误差	
}PID,*pPID;

typedef struct tagDataBuf
{
	
	volatile int  BufLength;
	volatile int  BufHead;
	volatile int  Buftail;
	volatile int  Datasize;
	BYTE DataBuf[ MAX_SIZE ];

} DATABUF,*pDATABUF;

typedef struct tagSpeed
{
   short A;
   short B;
   short C;
   short D;
   short E;
   short F;
}SPEED,*pSPEED;
#endif