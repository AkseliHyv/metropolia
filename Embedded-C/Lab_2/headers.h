#ifndef HEADERS_H_
#define HEADERS_H_
#include <stdint.h>
#include <sys/types.h>
#include <stdbool.h>

typedef enum
{
    ROTARY_DOWN_EVENT,
    ROTARY_LEFT_EVENT,
    ROTARY_RIGHT_EVENT
} events;

typedef struct
{
    int pin;
    int64_t last_time;
    int last_value;
} button;

#define ROT_A 10
#define ROT_B 11
#define ROT_SW 12
#define LED_1_GPIO 20
#define LED_2_GPIO 21
#define LED_3_GPIO 22
#define FIFO_LENGTH 32
#define DEBOUNCE_TIMER 50000
#define STEP_SIZE 50

void irq(uint gpio, uint32_t event_mask);
void handle_sw(uint32_t mask);
void handle_rot(void);
void init_gpio(void);
void init_pwm(void);
void set_led_levels(int level);

#endif // HEADERS_H_
