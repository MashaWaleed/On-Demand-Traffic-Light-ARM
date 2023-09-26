/*
 * stm32f103x8.h
 *
 *  Created on: Aug 31, 2023
 *      Author: mw296
 */

#ifndef STM32F103X8_H_
#define STM32F103X8_H_


//----------------------------------------------
//Includes
//----------------------------------------------

#include "stdlib.h"
#include "stdint.h"
#include "BIT_MATH.h"

//==========================================================



//----------------------------------------------------------
//Base Addresses for memory
//----------------------------------------------------------

#define FLASH_Memory_BASE                       0x08000000UL
#define System_Memory_BASE                      0x1FFFF000UL
#define SRAM_Memory_BASE                        0x20000000UL


#define Peripherals_BASE                        0x40000000UL
#define Cortex_M3_Peripherala_BASE              0xE0000000UL

//--------------------------------------
//Base Addresses for Genering cortex m3 peripherals
//--------------------------------------
//NVIC
#define NVIC_BASE                                0xE000E100UL



//--------------------------------------
//Base Addresses for AHB Peripherals
//--------------------------------------
//RCC
#define RCC_BASE                                0x40021000UL


//--------------------------------------
//Base Addresses for APB1 Peripherals
//--------------------------------------



//--------------------------------------
//Base Addresses for APB2 Peripherals
//--------------------------------------

//GPIO
#define GPIOA_BASE                               0x40010800UL
#define GPIOB_BASE                               0x40010C00UL
#define GPIOC_BASE                               0x40011000UL
#define GPIOD_BASE                               0x40011400UL
#define GPIOE_BASE                               0x40011800UL

//EXTI
#define EXTI_BASE                                0x40010400UL

//AFIO
#define AFIO_BASE                                0x40010000UL




//=====================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral registers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*



//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;

}RCC_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-


typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;


}EXTI_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-


typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	uint32_t RESERVED;
	volatile uint32_t MAPR2;


}AFIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: NVIC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct {
    volatile uint32_t ISER[3];   // NVIC_ISER0, NVIC_ISER1, NVIC_ISER2
    uint32_t RESERVED0[29];      // Reserved space (0x00C - 0x07C)
    volatile uint32_t ICER[3];   // NVIC_ICER0, NVIC_ICER1, NVIC_ICER2
    uint32_t RESERVED1[29];      // Reserved space (0x080 - 0x0FC)
    volatile uint32_t ISPR[3];   // NVIC_ISPR0, NVIC_ISPR1, NVIC_ISPR2
    uint32_t RESERVED2[29];      // Reserved space (0x100 - 0x17C)
    volatile uint32_t ICPR[3];   // NVIC_ICPR0, NVIC_ICPR1, NVIC_ICPR2
    uint32_t RESERVED3[29];      // Reserved space (0x180 - 0x1FC)
    volatile uint32_t IABR[3];   // NVIC_IABR0, NVIC_IABR1, NVIC_IABR2
    uint32_t RESERVED4[29];      // Reserved space (0x200 - 0x27C)
    volatile uint32_t IPR[60];   // NVIC_IPR0 - NVIC_IPR59
    uint32_t RESERVED5[644];     // Reserved space (0x280 - 0xFFC)
    volatile uint32_t STIR;      // NVIC_STIR
} NVIC_TypeDef;


//=========================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral instances
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA                                 ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB                                 ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC                                 ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD                                 ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE                                 ((GPIO_TypeDef *)GPIOE_BASE)

#define RCC                                   ((RCC_TypeDef *)RCC_BASE)

#define EXTI                                  ((EXTI_TypeDef *)EXTI_BASE)

#define AFIO                                  ((AFIO_TypeDef *)AFIO_BASE)

#define NVIC                                  ((NVIC_TypeDef *)NVIC_BASE)

//=========================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//quick clock enable macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()                    (RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()                    (RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()                    (RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()                    (RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()                    (RCC->APB2ENR |= 1<<6)

#define RCC_AFIO_CLK_EN()                     (RCC->APB2ENR |= 1<<0)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//quick NVIC enable/disable macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define NVIC_IRQ6_EXTI0_Enable()                (SET_BIT(NVIC->ISER[0], 6))
#define NVIC_IRQ7_EXTI1_Enable()                (SET_BIT(NVIC->ISER[0], 7))
#define NVIC_IRQ8_EXTI2_Enable()                (SET_BIT(NVIC->ISER[0], 8))
#define NVIC_IRQ9_EXTI3_Enable()                (SET_BIT(NVIC->ISER[0], 9))
#define NVIC_IRQ10_EXTI4_Enable()               (SET_BIT(NVIC->ISER[0], 10))
#define NVIC_IRQ23_EXTI5_9_Enable()             (SET_BIT(NVIC->ISER[0], 23))
#define NVIC_IRQ40_EXTI10_15_Enable()           (SET_BIT(NVIC->ISER[1], 8))


#define NVIC_IRQ6_EXTI0_Disable()               (SET_BIT(NVIC->ICER[0], 6))
#define NVIC_IRQ7_EXTI1_Disable()                (SET_BIT(NVIC->ICER[0], 7))
#define NVIC_IRQ8_EXTI2_Disable()                (SET_BIT(NVIC->ICER[0], 8))
#define NVIC_IRQ9_EXTI3_Disable()                (SET_BIT(NVIC->ICER[0], 9))
#define NVIC_IRQ10_EXTI4_Disable()               (SET_BIT(NVIC->ICER[0], 10))
#define NVIC_IRQ23_EXTI5_9_Disable()             (SET_BIT(NVIC->ICER[0], 23))
#define NVIC_IRQ40_EXTI10_15_Disable()           (SET_BIT(NVIC->ICER[1], 8))

//=========================================================================
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//IVT INTERRUPT VECTOR TABLE ONLY EXTI IS INCLUDED
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define EXTI0_IRQ        6
#define EXTI1_IRQ        7
#define EXTI2_IRQ        8
#define EXTI3_IRQ        9
#define EXTI4_IRQ        10
#define EXTI5_IRQ        23
#define EXTI6_IRQ        23
#define EXTI7_IRQ        23
#define EXTI8_IRQ        23
#define EXTI9_IRQ        23
#define EXTI10_IRQ       40
#define EXTI11_IRQ       40
#define EXTI12_IRQ       40
#define EXTI13_IRQ       40
#define EXTI14_IRQ       40
#define EXTI15_IRQ       40


#endif /* STM32F103C8_DRIVERS_STM32F103X8_H_ */
