
/***********************************************************
*   声明库说明：SP027 段显液晶模块驱动库函数               *
*     			VSS     CLK      DI    VDD                 *
*              电源地  时钟信号  数据  电源正              *
*  注意: 应在写完一次数据后在末尾加上一个时钟跳变沿(Paulse)*
***********************************************************/
/********************
* 头 文 件 配 置 区 *
********************/
# include "std.h"

//端口自定义区：
/***********************************************/
#define   SP027_PORT  	PORTC  		//SP027端  口
#define   CLK         	PC5   		//SP027时钟线
#define   DI          	PC4			//SP027数据线
/***********************************************/
/**********************************************
*  SP027显示模块                              *
*  接口定义：                                 *
*                VSS     CLK      DI    VDD   *
*              电源地  时钟信号  数据  电源正 *
***********************************************/
#define   CLK0        SP027_PORT&=(~(1<<CLK)) 
#define   CLK1        SP027_PORT|=((1<<CLK))
#define   DI0         SP027_PORT&=(~(1<<DI)) 
#define   DI1         SP027_PORT|=((1<<DI))
#define   Wrt1         CLK0;CLK1;DI1;DI0;              //写数据"1"
#define   Wrt0         CLK0;CLK1;DI0;DI1;              //写数据"0" 
#define   Paulse       CLK0;CLK1;                      //一个跳变沿
#define   GO           0x01
#define   Ready        0x02

/********************
*   函 数 声 明 区  *
********************/
void Display_Onechar(unsigned char Data);

/********************
*   模块函数声明区  *
********************/
void CLS(void);
void DisplayINTNum_SP027(long Number);
void DisplayFloatNum_SP027(float Num);

/********************
*   模块变量声明区  *
********************/
const unsigned char DisplayCode[] = {0x09,0xcf,0x91,0x85,0x47,0x25,0x21,0x8f,0x01,0x05,       // signed   char
                         0x03,0x61,0x39,0xc1,0x31,0x33,0x29,0x43,0x7b,0xc9,
						 0x79,0xe1,0x13,0xf3,0x49,0xf7,0xfd,0xff}; 
						 /*{0~F,G,H,I,J,L,O,P,r,U,_,-}*/ 
						 			 
/***********************************************************
*   函数功能：清屏函数                                     *
***********************************************************/
void CLS(void)
{
   unsigned char k = 0; 
   for(k=0;k<41;k++)
   {
      Wrt0;
   }	   
}                       
/***********************************************************
*   函数功能：十进制数据显示函数                           *
*   输    入：要显示的数(long)                             *
***********************************************************/
void DisplayINTNum_SP027(long Number)
{	
	unsigned char lcv_Counter = 0;
    unsigned char cNonce_BIT_Number = 0;
	unsigned char tmpNumber[5] = {0};
	unsigned char isNegative = FALSE;
	if(Number<0)
	{
		isNegative = TRUE;
	}
	Number =fabs(Number);//取绝对值
	CLS();	//清屏
	
	do
	{   
		if(lcv_Counter+isNegative>=5)
		{
			tmpNumber[0] &=~BIT(0);	//误操作
			break;
		}
		tmpNumber[lcv_Counter] = DisplayCode[Number%10];   //计算当前位上的数字Number%10
		Number=Number/10;    //计算比当前位更高位上的数字
		lcv_Counter ++;
	}while(Number);
	if(isNegative)
	{
		tmpNumber[lcv_Counter]=0xF7;	//负号
		lcv_Counter++;
	}
	while(lcv_Counter--)
	{
		Display_Onechar(tmpNumber[lcv_Counter]);	//显示
	}
    Paulse;   
}   
/***********************************************************
*   函数功能：Float数据显示函数                            *
*   输    入：要显示的数(float)                            *
***********************************************************/
void DisplayFloatNum_SP027(float Num)
{
    unsigned char lcv_Counter = 0;
    unsigned char cNonce_BIT_Number = 0;
	unsigned char tmpNumber[5] = {0};
    unsigned long Number = 0;
	unsigned char isNegative = FALSE;
	
	if(Num<0)
	{
		isNegative = TRUE;         //# define TRUE    (!0x00)
	}
	Number =fabs((long)(Num*100));
	CLS();	//清屏
	
	do
	{   
		if(lcv_Counter+isNegative>=5)
		{
			tmpNumber[0] &=~BIT(0);	//误操作
			break;
		}
		tmpNumber[lcv_Counter] = DisplayCode[Number%10];   //计算当前位上的数字Number%10
		Number=Number/10;    //计算比当前位更高位上的数字
		lcv_Counter ++;
	}while(Number||(lcv_Counter<=2));
	tmpNumber[2] &=~BIT(0);	//小数点
	if(isNegative)
	{
		tmpNumber[lcv_Counter]=0xF7;	//负号
		lcv_Counter++;
	}
	while(lcv_Counter--)
	{
		Display_Onechar(tmpNumber[lcv_Counter]);	//显示
	}
    Paulse;
}    

/***********************************************************
*   函数功能：写单个数字                                   *
*   输    入：要显示的数(UINT8)                            *
*   输    出：    无                                       *
* -------------------------------------------------------- *
*  [使用说明]                                              *
***********************************************************/
void Display_Onechar(unsigned char Data)
{
   unsigned char CharLength = 0;
   unsigned char NumTemp = 0;
   
   for (CharLength=0;CharLength<8;CharLength++)
   {
	  NumTemp = (( Data >>(7-CharLength))&0x01);
	  if (NumTemp == 0)
	  {
		Wrt1;
	  }
	  else
	  {
	    Wrt0;
	  }	  
   }         
}
/*********************
 十六进制显示函数附属函数
**********************/
void Display_Onecha(unsigned char Data)
{
   unsigned char CharLength = 0;
   unsigned char NumTemp = 0;
   
   for (CharLength=0;CharLength<8;CharLength++)
   {
	  NumTemp = ((DisplayCode[ Data ]>>(7-CharLength))&0x01);
	  if (NumTemp == 0)
	  {
		Wrt1;
	  }
	  else
	  {
	    Wrt0;
	  }	  
   }         
}
/************************
   十六进制显示函数
***********************/

void HEXDispNum(int Num)
{
   static char i = 0;
   static char TempData[]={0,0,0,0,0};
   
   TempData[4]= Num&0x000f;
   TempData[3]= (Num&0x00f0)>>4;
   TempData[2]= (Num&0x0f00)>>8;
   TempData[1]= (Num&0xf000)>>12;
   for (i=0;i<5;i++)
   {   
      Display_Onecha(TempData[i]);
   }	  
   Paulse;
} 
