#include <stdint.h>
#include "stm32f407xx_gpio_driver.h"

void delay()
{
	for(uint32_t i = 0; i < 100000; i++);
}
int main(void)
{
	uint8_t button_state = 1;
	GPIO_PeripheralClock_Init(GPIOA, ENABLE);
	GPIO_PeripheralClock_Init(GPIOD, ENABLE);

	GPIO_Handle_t GPIOD_Handle, GPIOA_Handle;
	GPIOA_Handle.GPIOx_Base_Addr = GPIOA;
	GPIOD_Handle.GPIOx_Base_Addr = GPIOD;

	// button pin configuration
	GPIOA_Handle.GPIO_Pin_Config.GPIO_PinMode = GPIO_INPUT_MODE;
	GPIOA_Handle.GPIO_Pin_Config.GPIO_PinNumber = GPIO_PIN_NO_4;
	GPIO_Init(&GPIOA_Handle);

	// led pin configuration
	GPIOD_Handle.GPIO_Pin_Config.GPIO_PinMode = GPIO_OUTPUT_MODE;
	GPIOD_Handle.GPIO_Pin_Config.GPIO_PinNumber = 12;
	GPIOD_Handle.GPIO_Pin_Config.GPIO_PinSpeed  = GPIO_HIGH_SPEED;
	GPIOD_Handle.GPIO_Pin_Config.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOD_Handle.GPIO_Pin_Config.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&GPIOD_Handle);
	GPIOD_Handle.GPIO_Pin_Config.GPIO_PinMode = GPIO_OUTPUT_MODE;
	GPIOD_Handle.GPIO_Pin_Config.GPIO_PinNumber = 13;
	GPIO_Init(&GPIOD_Handle);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA, 4) == button_state)
		{
			delay();
			while(GPIO_ReadFromInputPin(GPIOA, 4) == button_state);
			delay();
			GPIO_WriteToTogglePin(GPIOD, 12);
			GPIO_WriteToTogglePin(GPIOD, 13);
		}



	}

}


