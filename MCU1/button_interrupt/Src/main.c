#include <stdint.h>
#include <stdio.h>

#define RCC_BASE_ADDRESS 0x40023800
#define EXTI_BASE_ADDRESS 0x40013C00 // External interrupt/event controller base address
#define SYSCFG_BASE_ADDRESS 0x40013800 // System configuration controller base address
#define GPIOA_BASE_ADDRESS 0x40020000 // GPIOA base address

#define RCC_APB2ENR_OFFSET 0x44
#define EXTI_IMR_OFFSET 0x00
#define	EXTI_RTSR_OFFSET 0x08
#define EXTI_PR_OFFSET 0x14
#define SYSCFG_EXTICR1_OFFSET 0x08
#define GPIOA_MODER_OFFSET 0x00
#define GPIOA_AFRL_OFFSET 0x20

void button_init();

void led_blink();

uint32_t volatile button_state = 0;
uint32_t volatile button_count = 0;
uint32_t last_button_state;

uint32_t volatile *pRccAhb1Enr = (uint32_t *) (RCC_BASE_ADDRESS + 0x30);
uint32_t volatile *pRccApb2Enr = (uint32_t *) (RCC_BASE_ADDRESS + 0x44);

uint32_t volatile *pSysCfr = (uint32_t *) (SYSCFG_BASE_ADDRESS + 0x08);
uint32_t volatile *pSysCfr1 = (uint32_t *) (SYSCFG_BASE_ADDRESS + 0x0C);

uint32_t volatile *pExtiImr = (uint32_t *) (0x40013C00 + 0x00);
uint32_t volatile *pExtiFtsr = (uint32_t *) (0x40013C00 + 0x04);
uint32_t volatile *pExtiRtsr = (uint32_t *) (0x40013C00 + 0x08);
uint32_t volatile *pExtiPr = (uint32_t *) (0x40013C00 + 0x14);

uint32_t volatile *pGpioaModer = (uint32_t *) (0x40020000 + 0x00);
uint32_t volatile *pGpiobModer = (uint32_t *) 0x40020400;
uint32_t volatile *pGpioDModer = (uint32_t *) (0x40020C00 + 0x00);

uint32_t volatile *pGpiodPUPD = (uint32_t *) (0x40020C00 + 0x0C);

uint32_t volatile *pGpioaOutput = (uint32_t *) (0x40020000 + 0x14);
uint32_t volatile *pGpiobInput = (uint32_t *) (0x40020400 + 0x10);
uint32_t volatile *pGpiodOutput = (uint32_t *) (0x40020C00 + 0x14);

uint32_t volatile *pNVICIRQEnReg = (uint32_t *) 0xE000E100;


int main(void)
{
	button_init();

	while(1)
	{
		// Disable interrupt
		//*pExtiImr &= ~(1 << 0);
		*pExtiImr &= ~(1 << 5);

		if(button_state != last_button_state)
		{
			last_button_state = button_state;
			if(button_state == 1)
			{

				for(uint32_t volatile i = 0; i < 20000; i++);
				while(!last_button_state);
				*pGpiodOutput ^= (1 << 12);
			}

//			*pGpioaOutput &= ~(1 << 1);
//			button_count++;
//			printf("Button is pressed : %lu\n", button_count);

		}
		button_state = 0;
		//*pExtiImr |= (1 << 0);
		*pExtiImr |= (1 << 5);
		//*pGpioaOutput &= ~(1 << 1);

	}

	return 0;
}

//void led_blink()
//{
//	*pGpioaOutput ^= (1 << 1);
//	for(uint32_t volatile i = 0; i < 1157000; i++);
//}
void button_init()
{
	*pRccAhb1Enr |= (1 << 0) | (1 << 1) | (1 << 3); // Enable clock for GPIOA, GPIOB, GPIOD
	*pRccApb2Enr |= (1 << 14); // Enable clock for System configuration controller clock

	*pSysCfr |= (0x01 << 0);
	*pSysCfr1 |= (0x3 << 4);
	*pExtiImr |= (1 << 5) | (1 << 0); // EXTI interrupt enable
	*pExtiRtsr |= (1 << 5);
	//pExtiFtsr |= (1 << 0);

	*pGpioaModer |= (0x1 << 2);
	*pGpioDModer |= (0x1 << 24);
	//*pGpioDModer &= ~(0x1 << 10);
	*pGpiobModer &= ~(1 << 0);


	//*pGpiodPUPD |= (1 << 10);
	*pNVICIRQEnReg |= (1 << 23) | (1 << 6); // IRQ number 6 so must use NVIC_ISER0 register (0-31 IRQ number )

	last_button_state = button_state;
}

void EXTI9_5_IRQHandler()
{
	// Make this flag SET if button is pressed
	*pGpiodOutput ^= (1 << 12);

	// Clearing of EXTI interrupt pending bit
	*pExtiPr |= (1 << 5);
}
