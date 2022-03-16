/*
   @File        : main.c

   @Author      : Divin Raj

   @Description : Sample stm-nucleo led blinking application. 

   @Target      : STM32F411RE
   */



#include <stdint.h>

#define GPIOA_BASE          ((uint32_t)0x40020000)                               /* GPIOA Base address */
#define GPIOA_ODR           (GPIOA_BASE + 0x14)                                  /* Output data register */
#define GPIOA_MOD           (GPIOA_BASE)                                         /* Output mode Register */
#define RCC_BASE            ((uint32_t)0x40023830)                               /* RCC_AHB1 Base address */

#define GPIOA_CLKEN(val)    ((*(volatile uint32_t *)RCC_BASE)  |= (1u << val))   /* Enabling GPIOA CLK */
#define GPIOA_ODR_TG(pin)   ((*(volatile uint32_t *)GPIOA_ODR) ^= (1u << 5))     /* Writing Output Data Register */
#define GPIOA_MOD_WR(pin)   ((*(volatile uint32_t *)GPIOA_MOD) |= (1u << 2*pin)) /* Setting Output Mode */

int main()
{
	int idx = 0;
	GPIOA_CLKEN(0);  /* 0 - GPIOA CLOCK ENABLE PIN  */  
	GPIOA_MOD_WR(5u); /* 5 - PIN NUMBER FOR USER LED */
	while(1)
	{
		for(idx = 0; idx < 500000; idx++);
		GPIOA_ODR_TG(5u);
	}
	return 0;
} 
