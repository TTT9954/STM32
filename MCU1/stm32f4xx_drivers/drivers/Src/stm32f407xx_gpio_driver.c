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
 * TODO: Peripherals Clock setup
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
	//1. Configure the mode of GPIO pin
	if(GPIOx_Handle->GPIO_Pin_Config.GPIO_PinMode <= GPIO_ANALOG_MODE)
	{
		temp |= (GPIOx_Handle->GPIO_Pin_Config.GPIO_PinMode << (2 * GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber));
		GPIOx_Handle->GPIOx_Base_Addr->MODER &= ~(0x3 << (2 * GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber));
		GPIOx_Handle->GPIOx_Base_Addr->MODER |= temp;
	}
	else
	{
		// later
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
		temp1 = (GPIOx_Handle->GPIO_Pin_Config.GPIO_PinAltFunc << (4 * GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber));
		GPIOx_Handle->GPIOx_Base_Addr->AFRL |= temp1;
	}
	else
	{
		temp1 = (GPIOx_Handle->GPIO_Pin_Config.GPIO_PinAltFunc << ((4 * (GPIOx_Handle->GPIO_Pin_Config.GPIO_PinNumber%8))));
		GPIOx_Handle->GPIOx_Base_Addr->AFRH |= temp1;
	}
	temp1 = 0;
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

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *GPIOx);

void GPIO_WriteToOutputPin(GPIO_RegDef_t *GPIOx, uint8_t PinNumber, uint8_t Set_Reset)
{
	if(Set_Reset == SET)
	{
		GPIOx->ODR |= (Set_Reset << PinNumber);
	}
	else
	{
		GPIOx->ODR &= (Set_Reset << PinNumber);
	}
}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *GPIOx, uint8_t Set_Reset);

void GPIO_WriteToTogglePin(GPIO_RegDef_t *GPIOx, uint8_t PinNumber);

/*
 * TODO: IRQ Configuration and ISR handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnOrDis);

void GPIO_IRQHandle(uint8_t PinNumber);

