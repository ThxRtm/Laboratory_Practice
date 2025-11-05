#include <stdint.h>

void delay(volatile uint32_t count) {
    while(count--) {
        __asm("nop");
    }
}

int main(void) {
    *(volatile uint32_t*)(0x40023800UL + 0x30UL) |= (1 << 0) | (1 << 2); // Включить тактирование GPIOA и GPIOC

    // Настройка PA5 как выход
    uint32_t moder = *(volatile uint32_t*)(0x40020000UL + 0x00UL);
    moder &= ~(3 << (5 * 2));
    moder |=  (1 << (5 * 2));
    *(volatile uint32_t*)(0x40020000UL + 0x00UL) = moder;

    // Настройка PC13 как вход
    moder = *(volatile uint32_t*)(0x40020800UL + 0x00UL);
    moder &= ~(3 << (13 * 2));
    *(volatile uint32_t*)(0x40020800UL + 0x00UL) = moder;

    // Отключаем подтяжки на PA5
    uint32_t pupdr = *(volatile uint32_t*)(0x40020000UL + 0x0CUL);
    pupdr &= ~(3 << (5 * 2));
    *(volatile uint32_t*)(0x40020000UL + 0x0CUL) = pupdr;

    // Включаем подтяжку вверх на PC13
    pupdr = *(volatile uint32_t*)(0x40020800UL + 0x0CUL);
    pupdr &= ~(3 << (13 * 2));
    pupdr |=  (1 << (13 * 2));
    *(volatile uint32_t*)(0x40020800UL + 0x0CUL) = pupdr;

    uint8_t led_state = 0;
    uint8_t last_button_state = 1;
    uint8_t button_released = 1;  // Флаг отпускания кнопки для исключения дребезга

    while(1) {
        uint8_t button_state = (*(volatile uint32_t*)(0x40020800UL + 0x10UL) & (1 << 13)) ? 1 : 0;

        if(button_state == 1) {
            // Кнопка отпущена
            button_released = 1;
        }
        // Только если кнопка была отпущена и теперь нажата - переключаем светодиод
        if(button_released && last_button_state == 1 && button_state == 0) {
            led_state = !led_state;
            button_released = 0;  // Ждём отпускания, чтобы не переключать бесконечно

            if(led_state) {
                *(volatile uint32_t*)(0x40020000UL + 0x18UL) = (1 << 5);
            } else {
                *(volatile uint32_t*)(0x40020000UL + 0x14UL) = (1 << 5);
            }
        }
        last_button_state = button_state;

        delay(300000);
    }

    return 0;
}
