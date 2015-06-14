#include <LPC17xx.h>
#include "lcd.h"
#include "uart.h"
#include <math.h>
extern unsigned char data[];
extern  unsigned char RxData[19202];
extern uint32_t Rxlen;
void Delay(uint32_t Time)
{
		uint32_t i;
		i=0;
		while(Time--)
		{
			 for(i=0;i<5000;i++);
		}
}
int main(void)
{
		int i;
		unsigned short color;
		unsigned char pos=0;
		unsigned char sum=0;
		SystemInit();
		
		LCD_Init();
	//	LCD_Clear(White);
//	 LCD_Bmp(0,180,320,60,data);
		UART0_Init();
	/*	while(1)
		{
				while(Rxlen<2);
				color=(unsigned short)RxData[0]<<8|(unsigned short)RxData[1];
				Rxlen=0;
				LCD_Clear(color);
		}*/
		while(1)
		{
				while(pos!=8)
				{
						while(Rxlen<19202);
						Rxlen=0;
			//			for(i=0;i<19200;i++)
			//				sum+=RxData[i];
			//			pos=RxData[19201];
			//			if(abs(sum-RxData[19200])>50)
			//			{
			//					UART0_SendByte(pos);
		//						continue;
		//				}
						LCD_Bmp(0,210-(unsigned char)pos*30,320,30,RxData);
						//++pos;
						UART0_SendByte(++pos);
				}
				pos=0;
		}
//		while(Rxlen<19200);
//		LCD_Bmp(0,210,320,30,RxData);
}		
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
