#include "init.h"

// Сдвиг цветов в режиме
const uint8_t led_map[3][3] = {
    {0, 1, 2}, // Базовый: зелёный, синий, красный
    {2, 0, 1}, // 1-й сдвиг: красный, зелёный, синий
    {1, 2, 0}  // 2-й сдвиг: синий, красный, зелёный
};

void set_led(int color, int state)
{
    switch (color) {
        case 0: // green
            if (state) SET_BIT(GPIOB_ODR, (1 << 0));
            else CLR_BIT(GPIOB_ODR, (1 << 0));
            break;
        case 1: // blue
            if (state) SET_BIT(GPIOB_ODR, (1 << 7));
            else CLR_BIT(GPIOB_ODR, (1 << 7));
            break;
        case 2: // red
            if (state) SET_BIT(GPIOB_ODR, (1 << 14));
            else CLR_BIT(GPIOB_ODR, (1 << 14));
            break;
    }
}

int main(void)
{
    GPIO_Init();

    int mode = 0;
    int last_btn4 = 1;
    while (1)
    {
        int btn1 = !(GPIOC_IDR & (1 << 13));
        int btn2 = !(GPIOA_ODR & (1 << 8));
        int btn3 = !(GPIOB_ODR & (1 << 6));
        int btn4 = !(GPIOD_ODR & (1 << 3));

        // Управление тройкой светодиодов по текущему режиму
        set_led(led_map[mode][0], btn1);
        set_led(led_map[mode][1], btn2);
        set_led(led_map[mode][2], btn3);

        // Смена режима по фронту кнопки 4
        if (last_btn4 == 1 && btn4 == 0) {
            mode = (mode + 1) % 3;
        }
        last_btn4 = btn4;
    }
}