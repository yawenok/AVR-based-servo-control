#include"std.h"
#include"globle.h"
#include"queue.h"
#include"sp027.h"


/*=========================================================*
*                   参数宏定义                            
*=========================================================*/
#define DATA_LENGTH         11

#define SPEED_ONE	  		0x01				 //通信参数
#define SPEED_TWO	  		0x02				 //通信参数
#define SPEED_THREE	  		0x03				 //通信参数

/********************************************************/
/*                      函数声明
/********************************************************/

BOOL DecodeMsg( DATABUF* pdataBuf, UINT8 u8DataSize );
BOOL AddDecodeMsg( DATABUF* pdataBuf, BYTE Data );


BOOL AddDecodeMsg( DATABUF* pdataBuf, BYTE Data )
{
 QueueAdd(pdataBuf, Data );
 if(GetSize(pdataBuf) >= DATA_LENGTH)
 {
  DecodeMsg(pdataBuf,DATA_LENGTH);
 }
 return FALSE;
}
BOOL DecodeMsg( DATABUF* pdataBuf, UINT8 u8DataSize )
{

	
	UINT8 i = 0;
    UINT8 lcv_Parity=0;
    UINT8 lcv_Cmd=0;
    UINT8 lcv_DataLength=0;
	BOOL bSuccessed = FALSE;
	BYTE bySpeed[2] = { 0 };

	if (pdataBuf == NULL )
	{
		return FALSE;
	}

	//判断缓冲区数据长度
	while( pdataBuf->Datasize >= u8DataSize ) 
	{
        //判断帧头
		if( QueueGet(pdataBuf,0) != 0xAA )     
		{   
		    //删除1位
			QueueDel(pdataBuf,1);            
			continue;
		}
		
		//获取数据长度
		lcv_DataLength = QueueGet(pdataBuf,1); 
        //判断获取的数据长度是否大于缓冲区的数据长度
		if( lcv_DataLength > pdataBuf->Datasize) 
		{   
		    //删除
			QueueDel(pdataBuf,pdataBuf->Datasize);
			return bSuccessed;
		}
		if( lcv_DataLength != u8DataSize)
		{
		   //删除
		   QueueDel(pdataBuf,lcv_DataLength);
		   continue; 
		}
        //判断帧尾
		if( QueueGet(pdataBuf,lcv_DataLength-1) !=0x55 ) 
		{
			QueueDel(pdataBuf,u8DataSize);
			continue;
		}
		//数据校验
		for(i = 1;i < lcv_DataLength - 2; i++)
		{
			lcv_Parity ^= QueueGet(pdataBuf,i);
		}
		//获得校验位
	 	if(lcv_Parity != QueueGet(pdataBuf, lcv_DataLength - 2))
		{
			QueueDel(pdataBuf,u8DataSize);
			continue;
		}
		bSuccessed = TRUE;
		//获得命令位
		lcv_Cmd = QueueGet(pdataBuf,2); 
		//判断命令位
		switch(lcv_Cmd)
		{
            case SPEED_ONE:
			    bySpeed[0] = QueueGet(pdataBuf,3);
				bySpeed[1] = QueueGet(pdataBuf,4);
				g_speed.A = *( short* )bySpeed;
				
				bySpeed[0] = QueueGet(pdataBuf,5);
				bySpeed[1] = QueueGet(pdataBuf,6);
				g_speed.B = *( short* )bySpeed;
				
				bySpeed[0] = QueueGet(pdataBuf,7);
				bySpeed[1] = QueueGet(pdataBuf,8);
				g_speed.C = *( short* )bySpeed;
		
			break;
			case SPEED_TWO:
				bySpeed[0] = QueueGet(pdataBuf,3);
				bySpeed[1] = QueueGet(pdataBuf,4);
				g_speed.D = *( short* )bySpeed;
				
				bySpeed[0] = QueueGet(pdataBuf,5);
				bySpeed[1] = QueueGet(pdataBuf,6);
				g_speed.E = *( short* )bySpeed;
				
				bySpeed[0] = QueueGet(pdataBuf,7);
				bySpeed[1] = QueueGet(pdataBuf,8);
				g_speed.F = *( short* )bySpeed;
			break;
			/*
			case SPEED_THREE:
			    bySpeed[0] = QueueGet(pdataBuf,3);
				bySpeed[1] = QueueGet(pdataBuf,4);
				g_speed.A = *( short* )bySpeed;
				
				bySpeed[0] = QueueGet(pdataBuf,5);
				bySpeed[1] = QueueGet(pdataBuf,6);
				g_speed.B = *( short* )bySpeed;
				
				bySpeed[0] = QueueGet(pdataBuf,7);
				bySpeed[1] = QueueGet(pdataBuf,8);
				g_speed.C = *( short* )bySpeed;
			break;
			*/
			default :
				break;
		}
		//删除缓冲区中已读的数据
		QueueDel(pdataBuf,u8DataSize); 
	}
	return bSuccessed;
}

