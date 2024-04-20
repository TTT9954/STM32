
#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include "stm32f407xx.h"

/*
 * TODO: This is a configuration pin structure for GPIO pin
 */
typedef struct
{
	uint8_t GPIO_PinNumber;			/* possible value from @GPIO_PIN_NUMBERS */
	uint8_t GPIO_PinMode; 			/* possible value from @GPIO_PIN_MODES */
	uint8_t GPIO_PinSpeed;			/* possible value from @GPIO_OUTPUT_SPEED */
	uint8_t GPIO_PinPuPdControl;	/* possible value from @GPIO_PUPD */
	uint8_t GPIO_PinOPType;			/* possible value from @GPIO_OUTPUT_TYPE */
	uint8_t GPIO_PinAltFunc;		/* possible value from @GPIO_ALTF */
} GPIO_PinConfig_t;

/*
 * TODO: This is a handle structure for a GPUIO pin
 */
typedef struct
{
	GPIO_RegDef_t *GPIOx_Base_Addr;   /*!< Pointer to hold base address of GPIO peripherals >*/
	GPIO_PinConfig_t GPIO_Pin_Config; /* Hold configuration pin structure */
} GPIO_Handle_t;

/*
 * @GPIO_PIN_MODES
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0			0
#define GPIO_PIN_NO_1			1
#define GPIO_PIN_NO_2			2
#define GPIO_PIN_NO_3			3
#define GPIO_PIN_NO_4			4
#define GPIO_PIN_NO_5			5
#define GPIO_PIN_NO_6			6
#define GPIO_PIN_NO_7			7
#define GPIO_PIN_NO_8			8
#define GPIO_PIN_NO_9			9
#define GPIO_PIN_NO_10			10
#define GPIO_PIN_NO_11			11
#define GPIO_PIN_NO_12			12
#define GPIO_PIN_NO_13			13
#define GPIO_PIN_NO_14			14
#define GPIO_PIN_NO_15			15
/*
 * @GPIO_PIN_MODES
 * The possible modes of GPIO pin
 */
#define GPIO_INPUT_MODE 		0
#define GPIO_OUTPUT_MODE 		1
#define GPIO_ALTF_MODE 			2
#define GPIO_ANALOG_MODE 		3
#define GPIO_IT_FT				4 // Interrupt falling trigger detection on corresponding pin
#define GPIO_IT_RT				5 // Interrupt trigger detection on corresponding pin
#define GPIO_IT_RFT				6 // Interrupt Falling and Rising detection on corresponding pin

/*
 * * @GPIO_OUTPUT_TYPE
 * The GPIO output types of GPIO pin
 */
#define GPIO_OP_TYPE_PP 		0
#define GPIO_OP_TYPE_OD			1

/*
 * @GPIO_OUTPUT_SPEED
 * The output speed of GPIO pin
 */
#define GPIO_LOW_SPEED			0
#define GPIO_MED_SPEED			1
#define GPIO_HIGH_SPEED			2
#define GPIO_VERY_HIGH_SPEED	3

/*
 * @GPIO_PUPD
 * The pull-up/pull-down of GPIO pin
 */
#define GPIO_NO_PUPD			0
#define GPIO_PU					1
#define GPIO_PD					2

/*
 * @GPIO_ALTF
 * The Alternate functions of GPIO pin
 */
#define GPIO_PIN_AF0			0
#define GPIO_PIN_AF1			1
#define GPIO_PIN_AF2			2
#define GPIO_PIN_AF3			3
#define GPIO_PIN_AF4			4
#define GPIO_PIN_AF5			5
#define GPIO_PIN_AF6			6
#define GPIO_PIN_AF7			7
#define GPIO_PIN_AF8			8
#define GPIO_PIN_AF9			9
#define GPIO_PIN_AF10			10
#define GPIO_PIN_AF11			11
#define GPIO_PIN_AF12			12
#define GPIO_PIN_AF13			13
#define GPIO_PIN_AF14			14
#define GPIO_PIN_AF15			15


/***********************************************************************************************
 * 										APIs supported by this driver
 * 						For more informations about the APIs check function definitions
 ***********************************************************************************************/
/*
 * Peripherals Clock setup
 */
void GPIO_PeripheralClock_Init(GPIO_RegDef_t *GPIOx, uint8_t EnOrDis);


void GPIO_Init(GPIO_Handle_t *GPIOx);

void GPIO_Deinit(GPIO_RegDef_t *GPIOx, uint8_t EnOrDis);

/*
 * Data READ/WRITE
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *GPIOx, uint8_t PinNumber);
//uint8_t GPIO_ReadFromInputPin(GPIO_Handle_t *GPIOx);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *GPIOx);

void GPIO_WriteToOutputPin(GPIO_RegDef_t *GPIOx, uint8_t PinNumber, uint8_t state);

void GPIO_WriteToOutputPort(GPIO_RegDef_t *GPIOx, uint16_t value);

void GPIO_WriteToTogglePin(GPIO_RegDef_t *GPIOx, uint8_t PinNumber);

/*
 * TODO: IRQ Configuration and ISR handling
 */

uint8_t GPIO_EXTI_PortCode(GPIO_RegDef_t *GPIOx);

void GPIO_IRQ_Config(uint8_t IRQNumber, uint8_t EnOrDis);

void GPIO_IRQPriority_Config(uint8_t IRQNumber, uint32_t IRQPriority);


void GPIO_IRQHandle(uint8_t PinNumber);

#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
