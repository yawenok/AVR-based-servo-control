#include"std.h"
#include"collectdata.h"
#include"globle.h"
#include"decode.h"
/********************************************************/
/*                      º¯ÊýÉùÃ÷
/********************************************************/
void Communicate_Init(void);
void Uart_Port_Init(void);
void Uart0_Init(void);
void Uart0_rx_isr(void);


void Uart_Port_Init(void)
{
  DDRD|=BIT(1);
  DDRD&=~BIT(0);
  PORTD|=BIT(0);
}

//UART0 initialize
// desired baud rate: 38400
// actual: baud rate:39025 (1.6%)
// char size: 8 bit
// parity: Disabled
void Uart0_Init(void)
{
 CLI();
 UCSR0B = 0x00; //disable while setting baud rate
 UCSR0A = 0x00;
 UCSR0C = 0x06;
 UBRR0L = 0x1D; //set baud rate lo
 UBRR0H = 0x00; //set baud rate hi
 UCSR0B = 0x98;
 SEI();
}
#pragma interrupt_handler Uart0_rx_isr:iv_USART0_RXC
void Uart0_rx_isr(void)
{
   AddDecodeMsg(&g_databuf,UDR0);
}

void Communicate_Init(void)
{
 Uart_Port_Init();
 Uart0_Init();
}