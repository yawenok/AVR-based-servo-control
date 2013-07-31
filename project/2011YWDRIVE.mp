NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   0034   0020 =     32. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0034  __lit_start
       0054  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   0100 =    256. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       0154  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0154   1B32 =   6962. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00AA  __start
       00AA  __text_start
       00CB  _exit
       00CC  _main
       00E4  _CLS
       00EE  _DisplayINTNum_SP027
       0173  _DisplayFloatNum_SP027
       020F  _Display_Onechar
       0228  _Display_Onecha
       0247  _HEXDispNum
       028A  _QueueInit
       02AD  _QueueAdd
       02DF  _QueueDel
       0303  _QueueGet
       031D  _GetSize
       0321  _AddDecodeMsg
       0332  _DecodeMsg
       0454  _G_Var_Init
       04AA  _Timer0_Init
       04B7  _Timer0_ovf_isr
       051E  _IsLEDTime
       053C  _Is_Sampling_Time
       055A  _Port_Init
       056F  _Motor_Port_Init
       0574  _Watchdog_init
       057E  _Syetem_Device_Init
       059F  _AM_Control
       05F1  _BM_Control
       063E  _CM_Control
       068F  _DM_Control
       06DC  _EM_Control
       0732  _FM_Control
       077F  _Inspect_status
       07D3  _M_Control
       0814  _PID_Init
       0841  _PID_Calculate
       08EE  _PID_Output
       091A  _LimitValue
       096D  _Uart_Port_Init
       0971  _Uart0_Init
       0984  _Uart0_rx_isr
       09B6  _Communicate_Init
       09B8  _Int0_Init
       09C3  _Int0_isr
       0A5E  _CollectData_Init
       0A5F  _Read_M_Rate
       0A6F  _Pwm_Port_Init
       0A71  _Timer1_Init
       0A8D  _Set_M_Pwm
       0A92  _Pwm_Init_Devices
       0A94  push_arg4
       0A96  push_arg2
       0A99  mod16s
       0A9D  div16s
       0AB6  mod16u
       0AB8  div16u
       0AB9  xdiv16u
       0AD2  div32u
       0AD4  mod32u
       0AD8  div32s
       0ADA  mod32s
       0B05  long_div_prolog
       0B18  long_div_epilog
       0B27  tst_R16_R19
       0B2C  tst_R24_R27
       0B31  neg_R24_R27
       0B3A  pop_xgset003C
       0B3F  pop_xgset00FC
       0B46  pop_xgsetF0FC
       0B51  push_xgsetF0FC
       0B53  push_xgset30FC
       0B55  push_xgset00FC
       0B57  push_xgset003C
       0B5C  push_xgset300C
       0B61  pop_xgset300C
       0B66  push_xgsetF00C
       0B6D  pop_xgsetF00C
       0B74  neg32
       0B7D  lpm32
       0B91  lsr16
       0B98  lsr8
       0B9E  asgnblk
       0BB6  fpsub
       0BB8  fpadd
       0BB9  fpadd_alt
       0C17  fpadd2
       0C21  fpint
       0C51  uint2fp
       0C53  int2fp
       0C5C  ulong2fp
       0C5E  long2fp
       0C73  fpdiv1
       0C7C  fpdiv2
       0C86  fpdiv1x
       0C92  fpdiv2x
       0D07  unpacks
       0D0E  tstR16_R19
       0D16  unpacku
       0D2F  normalize_and_pack
       0D64  pack
       0D74  saveFPRegs
       0D83  restoreFPRegs
       0D92  fpmule
       0DE0  fpmule1
       0DE9  fpmule1x
       0DF5  fpcmp
       0E00  fpcmp2
       0E0B  fpneg
       0E12  fpneg2
       0E18  _fabsf
       0E43  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   0100 =    256. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       0100  _DisplayCode
       0126  SP027.c:i
       0127  SP027.c:TempData
       012E  _g_pulse_counter
       0132  _g_all_pulse
       0136  _g_LEDms
       013A  _g_ms
       013E  _g_MeasureTime
       0142  _g_PID
       0158  _g_databuf
       01E0  _g_speed
       01EC  pid.c:bIsFrist
       01ED  pid.c:Collectdata
       01EF  pid.c:bIsFrist:1
       01F0  pid.c:Collectdata:1
       01F2  pid.c:bIsFrist:2
       01F3  pid.c:Collectdata:2
       01F5  pid.c:bIsFrist:3
       01F6  pid.c:Collectdata:3
       01F8  pid.c:bIsFrist:4
       01F9  pid.c:Collectdata:4
       01FB  pid.c:bIsFrist:5
       01FC  pid.c:Collectdata:5
       01FE  pid.c:g_ID
       0200  __data_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0026 =     38. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\PROGRA~1\ICCAVR~1.22\lib\crtAVR.o	[ crtavr.s ]
main.o	[ main.c ]
SP027.o	[ SP027.c ]
queue.o	[ queue.c ]
decode.o	[ decode.c ]
globle.o	[ globle.c ]
timer.o	[ timer.c ]
system.o	[ system.c ]
pid.o	[ pid.c ]
communicate.o	[ communicate.c ]
collectdata.o	[ collectdata.c ]
setpwm.o	[ setpwm.c ]
<library>	[ asave.s, div16s.s, div16u.s, div32.s, gpop2.s, gpop3.s, gpop5.s, gpush.s, gpushx.s, gpushz.s, lneg.s ]
[ lpm32.s, lsr16.s, lsr8.s, struct.s, fpadd.s, fpadd2.s, fpint.s, int2fp.s, fpdiv_new.s, fputil.s, fpmule.s ]
[ fpmule1.s, fpmule1x.s, fpcmp.s, fpcmp2.s, fpneg.s, fpneg2.s, fabsf.s ]

User Global Definitions

ram_end = 0x4ff
hwstk_size = 0x40

User Base Address Definitions

func_lit = 0x34
data = 0x100
eeprom:0.512

