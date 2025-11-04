#ifndef INIT_H
#define INIT_H

// Адреса и маски для GPIO (под STM32F4)
#define RCC_GPIOA_EN        (*(volatile uint32_t*)0x40023830)
#define RCC_GPIOB_EN        (*(volatile uint32_t*)0x40023830)
#define RCC_GPIOC_EN        (*(volatile uint32_t*)0x40023830)
#define RCC_GPIOD_EN        (*(volatile uint32_t*)0x40023830)

#define GPIOA_MODER         (*(volatile uint32_t*)0x40020000)
#define GPIOB_MODER         (*(volatile uint32_t*)0x40020400)
#define GPIOC_MODER         (*(volatile uint32_t*)0x40020800)
#define GPIOD_MODER         (*(volatile uint32_t*)0x40020C00)

#define GPIOA_ODR           (*(volatile uint32_t*)0x40020014)
#define GPIOB_ODR           (*(volatile uint32_t*)0x40020414)
#define GPIOD_ODR           (*(volatile uint32_t*)0x40020C14)
#define GPIOC_IDR           (*(volatile uint32_t*)0x40020810)

// Макросы облегчения управления
#define SET_BIT(REG, BIT)   ((REG) |= (BIT))
#define CLR_BIT(REG, BIT)   ((REG) &= ~(BIT))

void GPIO_Init(void);

#endif