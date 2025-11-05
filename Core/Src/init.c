/*#include "init.h"
void GPIO_Init(void)
{
    // Включение тактирования портов
    SET_BIT(RCC_GPIOA_EN, (1 << 0));
    SET_BIT(RCC_GPIOB_EN, (1 << 1));
    SET_BIT(RCC_GPIOC_EN, (1 << 2));
    SET_BIT(RCC_GPIOD_EN, (1 << 3));
    // Светодиоды (Output)
    SET_BIT(GPIOB_MODER, (1 << (0 * 2)));     // PB0  - зелёный
    SET_BIT(GPIOB_MODER, (1 << (7 * 2)));     // PB7  - синий
    SET_BIT(GPIOB_MODER, (1 << (14 * 2)));    // PB14 - красный
    SET_BIT(GPIOA_MODER, (1 << (5 * 2)));     // PA5  - LD4
    SET_BIT(GPIOD_MODER, (1 << (1 * 2)));     // PD1  - LD5
    SET_BIT(GPIOD_MODER, (1 << (2 * 2)));     // PD2  - LD6
    // Кнопки (Input, по умолчанию уже)
    CLR_BIT(GPIOC_MODER, (3 << (13 * 2)));    // PC13
    CLR_BIT(GPIOA_MODER, (3 << (8 * 2)));     // PA8
    CLR_BIT(GPIOB_MODER, (3 << (6 * 2)));     // PB6
    CLR_BIT(GPIOD_MODER, (3 << (3 * 2)));     // PD3
}
*/