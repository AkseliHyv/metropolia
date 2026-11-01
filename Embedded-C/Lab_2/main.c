#include "headers.h"
#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "hardware/irq.h"
#include "pico/stdlib.h"
#include <sys/types.h>

static int fifo[FIFO_LENGTH];
static button rotary_button = {.pin = ROT_SW, .last_time = 0, .last_value = 0};

int main(void)
{
    init_gpio();

    gpio_set_irq_enabled_with_callback(ROT_SW, GPIO_IRQ_EDGE_FALL, true, irq);
    gpio_set_irq_enabled(ROT_A, GPIO_IRQ_EDGE_RISE, true);

    while (1)
    {
        // Handle fifo
    }
}

void irq(uint gpio, uint32_t event_mask)
{
    if (gpio == ROT_SW)
    {
        handle_sw();
    }
    else if (gpio == ROT_A)
    {
        handle_rot();
    }
}

void handle_sw(void)
{
    const int current_time = time_us_32();
    if (current_time - rotary_button.last_time >= DEBOUNCE_TIMER)
    {
        rotary_button.last_time = current_time;
        // Add event to fifo
    }
}

void handle_rot(void)
{
    if (gpio_get(ROT_B) == 1)
    {
        // Add event to fifo
    }
    else
    {
        // Add event to fifo
    }
}

void init_gpio(void)
{
    gpio_init(ROT_SW);
    gpio_init(ROT_A);
    gpio_init(ROT_B);

    gpio_set_dir(ROT_SW, GPIO_IN);
    gpio_set_dir(ROT_A, GPIO_IN);
    gpio_set_dir(ROT_B, GPIO_IN);

    gpio_pull_up(ROT_SW);
}