#ifndef HEADERS_H_
#define HEADERS_H_
#include <sys/types.h>
#include <stdbool.h>

enum events
{
    ROTARY_DOWN_EVENT,
    ROTARY_LEFT_EVENT,
    ROTARY_RIGHT_EVENT
};

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
#define DEBOUNCE_TIMER 1000000

void irq(uint gpio, uint32_t event_mask);
void handle_sw(void);
void handle_rot(void);
void init_button(int pin, bool button);

#endif // HEADERS_H_
