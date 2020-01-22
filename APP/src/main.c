#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#include "cmsis_os.h"
   //task1
#define TASK1_STK_SIZE		512
void task1(void *pdata);
osThreadDef(task1, osPriorityNormal, 1, TASK1_STK_SIZE);

//task2
#define TASK2_STK_SIZE		512
void task2(void *pdata);
osThreadDef(task2, osPriorityNormal, 1, TASK2_STK_SIZE);

void task1(void *pdata)
{
    int count = 1;
    while(1)
    {
        printf("\r\nHello world!\r\n###This is task1 ,count is %d \r\n", count++);
        LED_G_ON();
        osDelay(500);
        LED_G_OFF();
        osDelay(500);
    }
}
void task2(void *pdata)
{
    int count = 1;
    while(1)
    {
        printf("\r\nHello TencentOS !\r\n***This is task2 ,count is %d \r\n", count++);
        osDelay(1000);
    }
}


int main(void)
{
	bsp_init();
	led_init();
	uart_init();
	uart_rx_t.status = 0;
	static float float_num = 0.00f;
    osKernelInitialize(); //TOS Tiny kernel initialize
    osThreadCreate(osThread(task1), NULL);// Create task1
    osThreadCreate(osThread(task2), NULL);// Create task2
    osKernelStart();//Start TOS Tiny
	while(1)
	{
		// LED_G_ON();
		// DEBUG_PRINT("LED_G_ON\r\n");
		// float_num += 1.01f;
		// printf("float_num: %f\r\n", float_num);
		// delay_ms(500);

		// LED_G_OFF();
		// DEBUG_PRINT("LED_G_OFF\r\n");
		// float_num += 1.01f;
		// printf("float_num: %f\r\n", float_num);
		// delay_ms(500);

	}
}


void UART_COM_CPLT_Callback(UART_RXD_TypeDef *uart)
{
	uint8_t len = uart->status & RX_BUF_LEN_MASK;
	// printf("Input:\r\n");
	// printf("%.*s\r\n", len, uart->buffer);
	//HAL_UART_Transmit(&uart_com_t,uart->buffer,len,1000);
}




