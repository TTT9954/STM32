
#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

typedef uint32_t volatile __vo;
/* TODO: base address of FLASH and SRAM memory */
#define FLASH_BASEADDR           			0x08000000U // base address of Flash memory
#define SRAM1_BASEADDR           			0x20000000U // base address of SRAM1 memory (112KB)
#define SRAM2_BASEADDR           			0x2001C000U // base address of SRAM2 memory (16KB)
#define SRAM_BASEADDR			 			SRAM1_BASEADDR // base address of SRAM memory (system memory)
#define ROM						 			0x1FFF0000U // base address of ROM memory (system memory)

/* TODO: AHBx and APBx peripherals base address */

#define PERIPH_BASEADDR						0x40000000U
#define APB1PERIPH_BASEADDR 				PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR 				0x40010000U
#define AHB1PERIPH_BASEADDR 				0x40020000U
#define AHB2PERIPH_BASEADDR 				0x50000000U
#define AHB3PERIPH_BASEADDR 				0xA0000000U

/*
 * Base address of all peripherals are hanging on AHP1 bus
 * TODO: Complete for all other peripherals
 */

/* GPIO peripherals base address */

#define GPIOA_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR				(AHB1PERIPH_BASEADDR + 0x2000)
#define RCC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x3800)

/*
 * Base address of all peripherals are hanging on APB1 bus
 * TODO: Complete for all other peripherals
 */

#define I2C1_BASEADDR				(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR				(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR				(APB1PERIPH_BASEADDR + 0x5C00)

#define USART2_BASEADDR				(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR				(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR				(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR				(APB1PERIPH_BASEADDR + 0x5000)

#define SPI2_BASEADDR				(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR				(APB1PERIPH_BASEADDR + 0x3C00)

/*
 * Base address of all peripherals are hanging on APB2 bus
 * TODO: Complete for all other peripherals
 */

#define USART1_BASEADDR				(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR				(APB2PERIPH_BASEADDR + 0x1400)
#define ADC1_2_3_BASEADDR			(APB2PERIPH_BASEADDR + 0x2000)
#define SPI1_BASEADDR				(APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR				(APB2PERIPH_BASEADDR + 0x3400)
#define SYSCFG_BASEADDR				(APB2PERIPH_BASEADDR + 0x3800)
#define EXTI_BASEADDR				(APB2PERIPH_BASEADDR + 0x3C00)

/******************** TODO: Reset and clock control register definition structure ********************/

typedef struct
{
	__vo RCC_CR;		 /* TODO: RCC clock control register 			      				  - Address offset: 0x00 */
	__vo RCC_PLLCFGR;	 /* TODO: RCC PLL configuration register 			     			  - Address offset: 0x04 */
	__vo RCC_CFGR; 		 /* TODO: RCC clock configuration register 			     			  - Address offset: 0x08 */
	__vo RCC_CIR;	 	 /* TODO: RCC clock interrupt register 			     				  - Address offset: 0x0C */
	__vo RCC_AHB1RSTR; 	 /* TODO: RCC AHB1 peripheral reset register 			     		  - Address offset: 0x10 */
	__vo RCC_AHB2RSTR;	 /* TODO: RCC AHB2 peripheral reset register			     		  - Address offset: 0x14 */
	__vo RCC_AHB3RSTR;	 /* TODO: RCC AHB3 peripheral reset register			     		  - Address offset: 0x18 */
	__vo RESERVED_1; 	 /* TODO: Reserved			     									  - Address offset: 0x1C */
	__vo RCC_APB1RSTR;	 /* TODO: RCC APB1 peripheral reset register 			     		  - Address offset: 0x20 */
	__vo RCC_APB2RSTR;	 /* TODO: RCC APB2 peripheral reset register 			     		  - Address offset: 0x24 */
	__vo RESERVED_2;	 /* TODO: Reserved  			 									  - Address offset: 0x28 */
	__vo RESERVED_3;	 /* TODO: Reserved 			     									  - Address offset: 0x2C */
	__vo RCC_AHB1ENR;	 /* TODO: RCC AHB1 peripheral clock enable register 			      - Address offset: 0x30 */
	__vo RCC_AHB2ENR;	 /* TODO: RCC AHB2 peripheral clock enable register 			      - Address offset: 0x34 */
	__vo RCC_AHB3ENR;	 /* TODO: RCC AHB3 peripheral clock enable register 			      - Address offset: 0x38 */
	__vo RESERVED_4;	 /* TODO: Reserved 			     									  - Address offset: 0x3C */
	__vo RCC_APB1ENR;	 /* TODO: RCC APB1 peripheral clock enable register 			      - Address offset: 0x40 */
	__vo RCC_APB2ENR;	 /* TODO: RCC APB2 peripheral clock enable register 			      - Address offset: 0x44 */
	__vo RESERVED_5;	 /* TODO: Reserved 			     		 							  - Address offset: 0x48 */
	__vo RESERVED_6;     /* TODO: Reserved 			     									  - Address offset: 0x4C */
	__vo RCC_AHB1LPENR;  /* TODO: RCCAHB1 peripheral clock enable in low power mode register  - Address offset: 0x50 */
	__vo RCC_AHB2LPENR;  /* TODO: RCCAHB2 peripheral clock enable in low power mode register  - Address offset: 0x54 */
	__vo RCC_AHB3LPENR;  /* TODO: RCCAHB3 peripheral clock enable in low power mode register  - Address offset: 0x58 */
	__vo RESERVED_7;	 /* TODO: Reserved			     									  - Address offset: 0x5C */
	__vo RCC_APB1LPENR;  /* TODO: RCCAPB1 peripheral clock enabled in low power mode register - Address offset: 0x60 */
	__vo RCC_APB2LPENR;	 /* TODO: RCCAPB2 peripheral clock enabled in low power mode register - Address offset: 0x64 */
	__vo RESERVED_8;	 /* TODO: RCC PLLI2S configuration register 			     		  - Address offset: 0x68 */
	__vo RESERVED_9;	 /* TODO: RCC PLLI2S configuration register 			     	  	  - Address offset: 0x6C */
	__vo RCC_BDCR;		 /* TODO: RCC Backup domain control register 			     	  	  - Address offset: 0x70 */
	__vo RCC_CSR;		 /* TODO: RCC clock control & status register 			     		  - Address offset: 0x74 */
	__vo RESERVED_10;	 /* TODO: Reserved 			     									  - Address offset: 0x78 */
	__vo RESERVED_11;    /* TODO: Reserved 			     									  - Address offset: 0x7C */
	__vo RCC_SSCGR;		 /* TODO: RCC spread spectrum clock generation register 	 		  - Address offset: 0x80 */
	__vo RCC_PLLI2SCFGR; /* TODO: RCC PLLI2S configuration register 			     		  - Address offset: 0x84 */
} RCC_RegDef_t;

/******************** TODO: Peripheral register definition structure ********************/

typedef struct
{
	__vo MODER; 	/* TODO: GPIO port mode register 			      - Address offset: 0x00 */
	__vo OTYPER; 	/* TODO: GPIO port output type register 	      - Address offset: 0x04 */
	__vo OSPEEDR; 	/* TODO: GPIO port output speed register 	      - Address offset: 0x08 */
	__vo PUPDR; 	/* TODO: GPIO port pull-up/pull-down register     - Address offset: 0x0C */
	__vo IDR; 		/* TODO: GPIO port input data register 		      - Address offset: 0x10 */
	__vo ODR; 		/* TODO: GPIO port output data register 		  - Address offset: 0x14 */
	__vo BSRR; 		/* TODO: GPIO port bit set/reset register 	      - Address offset: 0x18 */
	__vo LCKR; 		/* TODO: GPIO port configuration lock register    - Address offset: 0x1C */
	__vo AFRL; 		/* TODO: GPIO alternate function low register     - Address offset: 0x20 */
	__vo AFRH; 		/* TODO: GPIO alternate function high register    - Address offset: 0x24 */

} GPIO_RegDef_t;



/*
 * TODO: Peripheral base address type casting to GPIOx_RegDef_t
 */

#define GPIOA 		((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB 		((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC 		((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD 		((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE 		((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF 		((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG 		((GPIO_RegDef_t *)GPIOG_BASEADDR)
#define GPIOH 		((GPIO_RegDef_t *)GPIOH_BASEADDR)
#define GPIOI 		((GPIO_RegDef_t *)GPIOI_BASEADDR)

#define RCC			((RCC_RegDef_t *)RCC_BASEADDR)

             /*********************	TODO: ENABLING CLOCK *********************/

/*
 * TODO: Make Macros for enabling GPIOx Peripheral clock
 */
#define GPIOA_PERIPH_CLOCK_EN()		(RCC->RCC_AHB1ENR |= (1 << 0));
#define GPIOB_PERIPH_CLOCK_EN()		(RCC->RCC_AHB1ENR |= (1 << 1));
#define GPIOC_PERIPH_CLOCK_EN()		(RCC->RCC_AHB1ENR |= (1 << 2));
#define GPIOD_PERIPH_CLOCK_EN()		(RCC->RCC_AHB1ENR |= (1 << 3));
#define GPIOE_PERIPH_CLOCK_EN()		(RCC->RCC_AHB1ENR |= (1 << 4));
#define GPIOF_PERIPH_CLOCK_EN()		(RCC->RCC_AHB1ENR |= (1 << 5));
#define GPIOG_PERIPH_CLOCK_EN()		(RCC->RCC_AHB1ENR |= (1 << 6));
#define GPIOH_PERIPH_CLOCK_EN()		(RCC->RCC_AHB1ENR |= (1 << 7));
#define GPIOI_PERIPH_CLOCK_EN()		(RCC->RCC_AHB1ENR |= (1 << 8));

/*
 * TODO: Make Macros for enabling I2Cx Peripheral clock
 */
#define I2C1_PERIPH_CLOCK_EN()		(RCC->RCC_APB1ENR |= (1 << 21));
#define I2C2_PERIPH_CLOCK_EN()		(RCC->RCC_APB1ENR |= (1 << 22));
#define I2C3_PERIPH_CLOCK_EN()		(RCC->RCC_APB1ENR |= (1 << 23));

/*
 * TODO: Make Macros for enabling SPIx Peripheral clock
 */
#define SPI1_PERIPH_CLOCK_EN()		(RCC->RCC_APB2ENR |= (1 << 12));
#define SPI2_PERIPH_CLOCK_EN()		(RCC->RCC_APB1ENR |= (1 << 14));
#define SPI3_PERIPH_CLOCK_EN()		(RCC->RCC_APB1ENR |= (1 << 15));

/*
 * TODO: Make Macros for enabling USARTx/UARTx Peripheral clock
 */
#define USART1_PERIPH_CLOCK_EN()	(RCC->RCC_APB2ENR |= (1 << 4));
#define USART2_PERIPH_CLOCK_EN()	(RCC->RCC_APB1ENR |= (1 << 17));
#define USART3_PERIPH_CLOCK_EN()	(RCC->RCC_APB1ENR |= (1 << 18));
#define USART6_PERIPH_CLOCK_EN()	(RCC->RCC_APB2ENR |= (1 << 5));
#define UART4_PERIPH_CLOCK_EN()		(RCC->RCC_APB1ENR |= (1 << 19));
#define UART5_PERIPH_CLOCK_EN()		(RCC->RCC_APB1ENR |= (1 << 20));

/*
 * TODO: Make Macros for enabling System configuration clock (SYSCFG)
 */
#define SYSCFG_CLOCK_EN()			(RCC->RCC_APB2ENR |= (1 << 14));


/*********************	TODO: DISABLING CLOCK *********************/
/*
 * TODO: Make Macros for disabling GPIOx Peripheral clock
 */

#define GPIOA_PERIPH_CLOCK_DIS()		(RCC->RCC_AHB1ENR &= ~(1 << 0));
#define GPIOB_PERIPH_CLOCK_DIS()		(RCC->RCC_AHB1ENR &= ~(1 << 1));
#define GPIOC_PERIPH_CLOCK_DIS()		(RCC->RCC_AHB1ENR &= ~(1 << 2));
#define GPIOD_PERIPH_CLOCK_DIS()		(RCC->RCC_AHB1ENR &= ~(1 << 3));
#define GPIOE_PERIPH_CLOCK_DIS()		(RCC->RCC_AHB1ENR &= ~(1 << 4));
#define GPIOF_PERIPH_CLOCK_DIS()		(RCC->RCC_AHB1ENR &= ~(1 << 5));
#define GPIOG_PERIPH_CLOCK_DIS()		(RCC->RCC_AHB1ENR &= ~(1 << 6));
#define GPIOH_PERIPH_CLOCK_DIS()		(RCC->RCC_AHB1ENR &= ~(1 << 7));
#define GPIOI_PERIPH_CLOCK_DIS()		(RCC->RCC_AHB1ENR &= ~(1 << 8));

/*
 * TODO: Make Macros for disabling I2Cx Peripheral clock
 */

#define I2C1_PERIPH_CLOCK_DIS()			(RCC->RCC_APB1ENR &= ~(1 << 21));
#define I2C2_PERIPH_CLOCK_DIS()			(RCC->RCC_APB1ENR &= ~(1 << 22));
#define I2C3_PERIPH_CLOCK_DIS()			(RCC->RCC_APB1ENR &= ~(1 << 23));

/*
 * TODO: Make Macros for disabling SPIx Peripheral clock
 */
#define SPI1_PERIPH_CLOCK_DIS()			(RCC->RCC_APB2ENR &= ~(1 << 12));
#define SPI2_PERIPH_CLOCK_DIS()			(RCC->RCC_APB1ENR &= ~(1 << 14));
#define SPI3_PERIPH_CLOCK_DIS()			(RCC->RCC_APB1ENR &= ~(1 << 15));

/*
 * TODO: Make Macros for enabling USARTx/UARTx Peripheral clock
 */
#define USART1_PERIPH_CLOCK_DIS()		(RCC->RCC_APB2ENR &= ~(1 << 4));
#define USART2_PERIPH_CLOCK_DIS()		(RCC->RCC_APB1ENR &= ~(1 << 17));
#define USART3_PERIPH_CLOCK_DIS()		(RCC->RCC_APB1ENR &= ~(1 << 18));
#define USART6_PERIPH_CLOCK_DIS()		(RCC->RCC_APB2ENR &= ~(1 << 5));
#define UART4_PERIPH_CLOCK_DIS()		(RCC->RCC_APB1ENR &= ~(1 << 19));
#define UART5_PERIPH_CLOCK_DIS()		(RCC->RCC_APB1ENR &= ~(1 << 20));

/*
 * TODO: Make Macros for enabling System configuration clock (SYSCFG)
 */
#define SYSCFG_CLOCK_DIS()				(RCC->RCC_APB2ENR &= ~(1 << 14));

/*
 * TODO: Make Macros to reset GPIO peripherals clock
 */
#define GPIOA_PERIPH_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1 << 0); RCC->RCC_AHB1RSTR &= ~(1 << 0);}while(0);
#define GPIOB_PERIPH_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1 << 1); RCC->RCC_AHB1RSTR &= ~(1 << 1);}while(0);
#define GPIOC_PERIPH_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1 << 2); RCC->RCC_AHB1RSTR &= ~(1 << 2);}while(0);
#define GPIOD_PERIPH_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1 << 3); RCC->RCC_AHB1RSTR &= ~(1 << 3);}while(0);
#define GPIOE_PERIPH_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1 << 4); RCC->RCC_AHB1RSTR &= ~(1 << 4);}while(0);
#define GPIOF_PERIPH_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1 << 5); RCC->RCC_AHB1RSTR &= ~(1 << 5);}while(0);
#define GPIOG_PERIPH_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1 << 6); RCC->RCC_AHB1RSTR &= ~(1 << 6);}while(0);
#define GPIOH_PERIPH_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1 << 7); RCC->RCC_AHB1RSTR &= ~(1 << 7);}while(0);
#define GPIOI_PERIPH_CLOCK_RESET()		do{RCC->RCC_AHB1RSTR |= (1 << 8); RCC->RCC_AHB1RSTR &= ~(1 << 8);}while(0);

/*
 * TODO: Some other Macros
 */

#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define GPIO_PIN_SET SET
#define GPIO_PIN_RESET RESET

#endif /* INC_STM32F407XX_H_ */
