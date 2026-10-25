#ifndef HEADERS_H_
#define HEADERS_H_
#include <sys/types.h>
#include <stdbool.h>

#define SW_0_GPIO 7
#define SW_1_GPIO 8
#define SW_2_GPIO 9

#define LED_1_GPIO 20
#define LED_2_GPIO 21
#define LED_3_GPIO 22

void init_pwm(int pin);
void init_button(int pin);
bool is_down(int pin);

#endif // HEADERS_H_
