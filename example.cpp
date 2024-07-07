#include <stdio.h>
#include "stm32g4xx_hal.h"
#include "DHT11.h"

UART_HandleTypeDef hlpuart1;

/*IMPORTANT: INSTANCE OF A TIMER TO COUNT 1us*/
TIM_HandleTypeDef htim1;

/*Microcontroller specific functions*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_LPUART1_UART_Init(void);

/*IMPORTANT: FUNCTION TO INITIALIZE A TIMER TO COUNT 1us*/
static void MX_TIM1_Init(void);

int __io_putchar(int ch) {
    /*PUT YOUR UART CODE*/
}

int main(void) {
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_LPUART1_UART_Init();

	MX_TIM1_Init(); //initializes the timer

	DHT11_InitTypeDef dht;
	DHT11_StatusTypeDef err;
	HAL_DHT11_Init(&dht, GPIOC, GPIO_PIN_10, &htim1);

	while(1) {
        HAL_Delay(1000);
        err = HAL_DHT11_ReadData(&dht);
        
        if(err != DHT11_OK) {
            printf("Failed to read data: %s", HAL_DHT11_GetErrorMsg(err));
            continue;
        }

        printf("T=%.2fC || RH=%.2f%%\n", dht.Temperature, dht.Humidity);
        printf("T=%.2fF\n", HAL_DHT11_ReadTemperatureF(&dht));
	}

	HAL_DHT11_DeInit(&dht); //deinitialses DHT11 driver
    return 0;
}

static void MX_TIM1_Init(void) {

}
