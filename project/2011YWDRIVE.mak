CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -D_EE_EXTIO -DATMega88  -l -g -MHasMul -MEnhanced -Wa-W 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x2000 -Wl-W -bfunc_lit:0x34.0x2000 -dram_end:0x4ff -bdata:0x100.0x4ff -dhwstk_size:64 -beeprom:0.512 -fihx_coff -S2
FILES = main.o SP027.o queue.o decode.o globle.o timer.o system.o pid.o communicate.o collectdata.o setpwm.o 

2011YWDRIVE:	$(FILES)
	$(CC) -o 2011YWDRIVE $(LFLAGS) @2011YWDRIVE.lk  
main.o: .\std.h D:\PROGRA~1\ICCAVR~1.22\include\iom88v.h D:\PROGRA~1\ICCAVR~1.22\include\_iom88to328v.h D:\PROGRA~1\ICCAVR~1.22\include\macros.h D:\PROGRA~1\ICCAVR~1.22\include\AVRdef.h D:\PROGRA~1\ICCAVR~1.22\include\math.h .\TypeMacro.h .\pid.h .\globle.h .\timer.h .\SP027.h .\system.h .\queue.h
main.o:	main.c
	$(CC) -c $(CFLAGS) main.c
SP027.o: .\std.h D:\PROGRA~1\ICCAVR~1.22\include\iom88v.h D:\PROGRA~1\ICCAVR~1.22\include\_iom88to328v.h D:\PROGRA~1\ICCAVR~1.22\include\macros.h D:\PROGRA~1\ICCAVR~1.22\include\AVRdef.h D:\PROGRA~1\ICCAVR~1.22\include\math.h .\TypeMacro.h
SP027.o:	SP027.c
	$(CC) -c $(CFLAGS) SP027.c
queue.o: .\queue.h .\TypeMacro.h
queue.o:	queue.c
	$(CC) -c $(CFLAGS) queue.c
decode.o: .\std.h D:\PROGRA~1\ICCAVR~1.22\include\iom88v.h D:\PROGRA~1\ICCAVR~1.22\include\_iom88to328v.h D:\PROGRA~1\ICCAVR~1.22\include\macros.h D:\PROGRA~1\ICCAVR~1.22\include\AVRdef.h D:\PROGRA~1\ICCAVR~1.22\include\math.h .\TypeMacro.h .\globle.h .\queue.h .\sp027.h
decode.o:	decode.c
	$(CC) -c $(CFLAGS) decode.c
globle.o: .\std.h D:\PROGRA~1\ICCAVR~1.22\include\iom88v.h D:\PROGRA~1\ICCAVR~1.22\include\_iom88to328v.h D:\PROGRA~1\ICCAVR~1.22\include\macros.h D:\PROGRA~1\ICCAVR~1.22\include\AVRdef.h D:\PROGRA~1\ICCAVR~1.22\include\math.h .\TypeMacro.h .\queue.h
globle.o:	globle.c
	$(CC) -c $(CFLAGS) globle.c
timer.o: .\std.h D:\PROGRA~1\ICCAVR~1.22\include\iom88v.h D:\PROGRA~1\ICCAVR~1.22\include\_iom88to328v.h D:\PROGRA~1\ICCAVR~1.22\include\macros.h D:\PROGRA~1\ICCAVR~1.22\include\AVRdef.h D:\PROGRA~1\ICCAVR~1.22\include\math.h .\TypeMacro.h .\globle.h
timer.o:	timer.c
	$(CC) -c $(CFLAGS) timer.c
system.o: .\std.h D:\PROGRA~1\ICCAVR~1.22\include\iom88v.h D:\PROGRA~1\ICCAVR~1.22\include\_iom88to328v.h D:\PROGRA~1\ICCAVR~1.22\include\macros.h D:\PROGRA~1\ICCAVR~1.22\include\AVRdef.h D:\PROGRA~1\ICCAVR~1.22\include\math.h .\TypeMacro.h .\timer.h .\pid.h .\setpwm.h .\communicate.h .\collectdata.h .\globle.h
system.o:	system.c
	$(CC) -c $(CFLAGS) system.c
pid.o: .\std.h D:\PROGRA~1\ICCAVR~1.22\include\iom88v.h D:\PROGRA~1\ICCAVR~1.22\include\_iom88to328v.h D:\PROGRA~1\ICCAVR~1.22\include\macros.h D:\PROGRA~1\ICCAVR~1.22\include\AVRdef.h D:\PROGRA~1\ICCAVR~1.22\include\math.h .\TypeMacro.h .\setpwm.h .\globle.h .\collectdata.h .\decode.h
pid.o:	pid.c
	$(CC) -c $(CFLAGS) pid.c
communicate.o: .\std.h D:\PROGRA~1\ICCAVR~1.22\include\iom88v.h D:\PROGRA~1\ICCAVR~1.22\include\_iom88to328v.h D:\PROGRA~1\ICCAVR~1.22\include\macros.h D:\PROGRA~1\ICCAVR~1.22\include\AVRdef.h D:\PROGRA~1\ICCAVR~1.22\include\math.h .\TypeMacro.h .\collectdata.h .\globle.h .\decode.h
communicate.o:	communicate.c
	$(CC) -c $(CFLAGS) communicate.c
collectdata.o: .\std.h D:\PROGRA~1\ICCAVR~1.22\include\iom88v.h D:\PROGRA~1\ICCAVR~1.22\include\_iom88to328v.h D:\PROGRA~1\ICCAVR~1.22\include\macros.h D:\PROGRA~1\ICCAVR~1.22\include\AVRdef.h D:\PROGRA~1\ICCAVR~1.22\include\math.h .\TypeMacro.h .\globle.h
collectdata.o:	collectdata.c
	$(CC) -c $(CFLAGS) collectdata.c
setpwm.o: .\std.h D:\PROGRA~1\ICCAVR~1.22\include\iom88v.h D:\PROGRA~1\ICCAVR~1.22\include\_iom88to328v.h D:\PROGRA~1\ICCAVR~1.22\include\macros.h D:\PROGRA~1\ICCAVR~1.22\include\AVRdef.h D:\PROGRA~1\ICCAVR~1.22\include\math.h .\TypeMacro.h
setpwm.o:	setpwm.c
	$(CC) -c $(CFLAGS) setpwm.c
