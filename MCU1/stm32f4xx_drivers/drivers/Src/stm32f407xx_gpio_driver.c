#include "stm32f407xx.h"
#include "stm32f407xx_gpio_driver.h"

/*
 * TODO: Peripherals Clock setup
 */
/*
 * @fn					- GPIO_PeripheralClock_Init
 *
 * @brief				- This function about enabling or disabling clock of given GPIO
 *
 * @param[in]			- GPIO_RegDef_t *GPIOx: Base address of the GPIO Peripheral
 * @param[in]			- uint8_t EnOrDis: ENABLE or DISABLE macros
 * @param[in]			-
 *
 * return				- none
 *
 * @Note				- none
 */
void GPIO_PeripheralClock_Init(GPIO_RegDef_t *GPIOx, uint8_t EnOrDis)
{
	if(EnOrDis == ENABLE)
	{
		if(GPIOx == GPIOA)
		{
			GPIOA_PERIPH_CLOCK_EN();
		}
		if(GPIOx == GPIOB)
		{
			GPIOB_PERIPH_CLOCK_EN();
		}
		if(GPIOx == GPIOC)
		{
			GPIOC_PERIPH_CLOCK_EN();
		}
		if(GPIOx == GPIOD)
		{
			GPIOD_PERIPH_CLOCK_EN();
		}
		if(GPIOx == GPIOE)
		{
			GPIOE_PERIPH_CLOCK_EN();
		}
		if(GPIOx == GPIOF)
		{
			GPIOF_PERIPH_CLOCK_EN();
		}
		if(GPIOx == GPIOG)
		{
			GPIOG_PERIPH_CLOCK_EN();
		}
		if(GPIOx == GPIOH)
		{
			GPIOH_PERIPH_CLOCK_EN();
		}
		if(GPIOx == GPIOI)
		{
			GPIOI_PERIPH_CLOCK_EN();
		}

	}
	else
	{
		if(GPIOx == GPIOA)
		{
			GPIOA_PERIPH_CLOCK_DIS();
		}
		if(GPIOx == GPIOB)
		{
			GPIOB_PERIPH_CLOCK_DIS();
		}
		if(GPIOx == GPIOC)
		{
			GPIOC_PERIPH_CLOCK_DIS();
		}
		if(GPIOx == GPIOD)
		{
			GPIOD_PERIPH_CLOCK_DIS();
		}
		if(GPIOx == GPIOE)
		{
			GPIOE_PERIPH_CLOCK_DIS();
		}
		if(GPIOx == GPIOF)
		{
			GPIOF_PERIPH_CLOCK_DIS();
		}
		if(GPIOx == GPIOG)
		{
			GPIOG_PERIPH_CLOCK_EN();
		}
		if(GPIOx == GPIOH)
		{
			GPIOH_PERIPH_CLOCK_DIS();
		}
		if(GPIOx == GPIOI)
		{
			GPIOI_PERIPH_CLOCK_DIS();
		}

	}
}

/*
 * TODO: Initialize GPIO
 */
/*
 * @fn					- GPIO_Init
 *
 * @brief				- This function about initializing given GPIO
 *
 * @param[in]			- GPIO_Handle_t *GPIOx: Base address of the GPIO Peripheral
 * @param[in]			-
 * @param[in]			-
 *
 * return				- none
 *
 * @Note				- none
 */

void GPIO_Init(GPIO_Handle_t *GPIOx_Handle)
{
	uint32_t temp = 0;
	uint32_t temp1 = 0;
	uint32_t temp2 = 0;

	GPIO_PeripheralClock_Init(GPIOx_Handle->GPIOx_Base_Addr, ENABLE);
	//1. Configure the mode of GPIO pin
	if(GPIOx_Handle->GPIO_Pin_Config.GPIO_PinMode <= GPIO_ANALOG_MODE)
	{
		temp |= (GPIOx_Handle->GPIO_Pin_Config.GPIO_PinMode << (2 * GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber));
		GPIOx_Handle->GPIOx_Base_Addr->MODER &= ~(0x3 << (2 * GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber));
		GPIOx_Handle->GPIOx_Base_Addr->MODER |= temp;
	}
	else
	{
		if(GPIOx_Handle->GPIO_Pin_Config.GPIO_PinMode == GPIO_IT_FT)
		{
			// Configure the FTSR - falling trigger
			EXTI->FTSR |= (1 << GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber);
			EXTI->RTSR &= ~(1 << GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber);

		}
		if(GPIOx_Handle->GPIO_Pin_Config.GPIO_PinMode == GPIO_IT_RT)
		{
			// Configure the RTSR - rising trigger
			EXTI->RTSR |= (1 << GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber);
			EXTI->FTSR &= ~(1 << GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber);

		}
		if(GPIOx_Handle->GPIO_Pin_Config.GPIO_PinMode == GPIO_IT_RFT)
		{
			// Configure both of rising and falling trigger
			EXTI->FTSR |= (1 << GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber);
			EXTI->RTSR |= (1 << GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber);
		}

		SYSCFG_CLOCK_EN();
		temp1 = GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber/4;
		SYSCFG->EXTICR[temp1] |= EXTI_PORTCODE(GPIOx_Handle->GPIOx_Base_Addr) << (4 * (GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber%4));

		// 3. Enable IMR with appropriate pin
		EXTI->IMR |= (1 << GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber);
	}
	temp = 0;
	//2. Configure the speed of GPIO pin
	temp |= (GPIOx_Handle->GPIO_Pin_Config.GPIO_PinSpeed) << (2 * GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber);
	GPIOx_Handle->GPIOx_Base_Addr->OSPEEDR |= temp;
	//3. Configure the PUPD of GPIO pin
	temp = 0;
	temp |= (GPIOx_Handle->GPIO_Pin_Config.GPIO_PinPuPdControl) << (2 * GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber);
	GPIOx_Handle->GPIOx_Base_Addr->PUPDR |= temp;
	//4. Configure the output type of GPIO pin
	temp = 0;
	temp |= (GPIOx_Handle->GPIO_Pin_Config.GPIO_PinOPType) << (GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber);
	GPIOx_Handle->GPIOx_Base_Addr->OTYPER |= temp;

	//5. Configure alternate function of GPIO pin
	if(GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber <= GPIO_PIN_NO_8)
	{
		temp2 = (GPIOx_Handle->GPIO_Pin_Config.GPIO_PinAltFunc << (4 * GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber));
		GPIOx_Handle->GPIOx_Base_Addr->AFRL |= temp2;
	}
	else
	{
		temp2 = (GPIOx_Handle->GPIO_Pin_Config.GPIO_PinAltFunc << ((4 * (GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber%8))));
		GPIOx_Handle->GPIOx_Base_Addr->AFRH |= temp2;
	}
	temp2 = 0;
}

void GPIO_Deinit(GPIO_RegDef_t *GPIOx, uint8_t EnOrDis)
{
	if(EnOrDis == ENABLE)
	{
		if(GPIOx == GPIOA)
		{
			GPIOA_PERIPH_CLOCK_RESET();
		}
		if(GPIOx == GPIOB)
		{
			GPIOB_PERIPH_CLOCK_RESET();
		}
		if(GPIOx == GPIOC)
		{
			GPIOC_PERIPH_CLOCK_RESET();
		}
		if(GPIOx == GPIOD)
		{
			GPIOD_PERIPH_CLOCK_RESET();
		}
		if(GPIOx == GPIOE)
		{
			GPIOE_PERIPH_CLOCK_RESET();
		}
		if(GPIOx == GPIOF)
		{
			GPIOF_PERIPH_CLOCK_RESET();
		}
		if(GPIOx == GPIOG)
		{
			GPIOG_PERIPH_CLOCK_RESET();
		}
		if(GPIOx == GPIOH)
		{
			GPIOH_PERIPH_CLOCK_RESET();
		}
		if(GPIOx == GPIOI)
		{
			GPIOI_PERIPH_CLOCK_RESET();
		}

	}
}

/*
 * TODO: Data READ/WRITE
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *GPIOx, uint8_t PinNumber)
{
	uint8_t state = 0;
	state = (uint8_t)(GPIOx->IDR >> PinNumber) & 0x1;
	return state;
}

//uint8_t GPIO_ReadFromInputPin(GPIO_Handle_t *GPIOx)
//{
//	uint8_t state = 0;
//	state = (uint8_t)(GPIOx->GPIOx_Base_Addr->IDR >> GPIOx->GPIO_Pin_Config.GPIO_PinNumber) & 0x1;
//	return state;
//}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *GPIOx)
{
	uint16_t temp = 0;
	temp = (uint16_t)GPIOx->IDR;
	return temp;
}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *GPIOx, uint8_t PinNumber, uint8_t state)
{
	if(state == SET)
	{
		GPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		GPIOx->ODR &= ~(1 << PinNumber);
	}
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *GPIOx, uint16_t value)
{
	GPIOx->ODR = value;
}

void GPIO_WriteToTogglePin(GPIO_RegDef_t *GPIOx, uint8_t PinNumber)
{
	GPIOx->ODR ^= (1 << PinNumber);
}

/*
 * TODO: IRQ Configuration and ISR handling
 */
void GPIO_IRQ_Config(uint8_t IRQNumber, uint8_t EnOrDis)
{
	if(EnOrDis == ENABLE)
	{
		if(IRQNumber >= 0 && IRQNumber <= 31)
		{
			*NVIC_ISER0 |= (1 << IRQNumber);
		}
		if(IRQNumber >= 32 && IRQNumber <= 63)
		{
			*NVIC_ISER1 |= (1 << (IRQNumber%32));
		}
		if(IRQNumber >= 64 && IRQNumber <= 95)
		{
			*NVIC_ISER2 |= (1 << (IRQNumber%64));
		}
		if(IRQNumber >= 96 && IRQNumber <= 127)
		{
			*NVIC_ISER3 |= (1 << (IRQNumber%96));
		}
	}
//	else
//	{
//		if(IRQNumber >= 0 && IRQNumber <= 31)
//		{
//			*NVIC_ICER0 |= (1 << IRQNumber);
//		}
//		if(IRQNumber >= 32 && IRQNumber <= 63)
//		{
//			*NVIC_ICER1 |= (1 << (IRQNumber%32));
//		}
//		if(IRQNumber >= 64 && IRQNumber <= 95)
//		{
//			*NVIC_ICER2 |= (1 << (IRQNumber%64));
//		}
//		if(IRQNumber >= 96 && IRQNumber <= 127)
//		{
//			*NVIC_ICER3 |= (1 << (IRQNumber%96));
//		}
//	}
}

void GPIO_IRQPriority_Config(uint8_t IRQNumber, uint32_t IRQPriority)
{
	uint8_t temp  = IRQNumber/4;
	uint8_t temp2 = IRQNumber%4;
	uint32_t IRQPriority_avaible = (IRQPriority & 0xF) << 4;
	*(NVIC_IPR_BASEADDR + (temp)) |=  IRQPriority_avaible << 8*temp2;
}

void GPIO_IRQHandle(uint8_t PinNumber)
{
	if((EXTI->PR) & ((1 << PinNumber)))
	{
		EXTI->PR |= (1 << PinNumber);
	}

}

