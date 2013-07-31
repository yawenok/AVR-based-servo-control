#ifndef _PID_H
#define _PID_H



extern void Inspect_status(void);
extern void AM_Control(short target);
extern void BM_Control(short target);
extern void CM_Control(short target);
extern void DM_Control(short target);
extern void EM_Control(short target);
extern void FM_Control(short target);
extern void PID_Init(PID *pPIDDATA,double P,double I,double D);
extern void M_Control(SPEED *pspeed);








#endif