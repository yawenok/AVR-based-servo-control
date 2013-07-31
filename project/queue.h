#ifndef _USE_QUEUE_H_
#define _USE_QUEUE_H_
#include"TypeMacro.h"



extern BOOL QueueInit(DATABUF* pDataBuf,INT16 size);
extern BOOL QueueAdd(DATABUF* pDataBuf,UINT8 data);
extern BOOL QueueDel(DATABUF* pDataBuf,INT16 DelNum);
extern BYTE QueueGet(DATABUF* pDataBuf,INT16 place);
extern int  GetSize(DATABUF* DataBuf);


#endif



