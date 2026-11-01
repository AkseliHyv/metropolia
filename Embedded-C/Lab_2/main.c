#include "headers.h"
#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "hardware/irq.h"
#include "pico/stdlib.h"
#include "pico/util/queue.h"
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>

static queue_t fifo;
static button rotary_button = {.pin = ROT_SW, .last_time = 0, .last_value = 0};

int main(void)
{
    init_gpio();
    init_pwm();
    
    const int leds[3] = {LED_1_GPIO, LED_2_GPIO, LED_3_GPIO};
    bool leds_on = false;
    int level = 500;

    queue_init(&fifo, sizeof(int), FIFO_LENGTH);
    gpio_set_irq_enabled_with_callback(ROT_SW, GPIO_IRQ_EDGE_FALL, true, irq);
    gpio_set_irq_enabled(ROT_A, GPIO_IRQ_EDGE_RISE, true);
    

    while (1)
    {
        int event;
        int target_level = 0;
        if (queue_try_remove(&fifo, &event)) {
            if (event == ROTARY_DOWN_EVENT)
            {
                if (!leds_on)
                {
                    target_level = level;
                }
                leds_on = !leds_on;
            }
            else if (event == ROTARY_LEFT_EVENT)
            {
                level--;
                target_level = level;
            }
            else
            {
                level++;
                target_level = level;
            }
        }

        set_led_levels(leds, target_level);
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
    const uint32_t current_time = time_us_32();
    if (current_time - rotary_button.last_time >= DEBOUNCE_TIMER)
    {
        rotary_button.last_time = current_time;

        int event = ROTARY_DOWN_EVENT;
        queue_try_add(&fifo, &event);
    }
}

void handle_rot(void)
{
    if (gpio_get(ROT_B) == 1)
    {
        int event = ROTARY_RIGHT_EVENT;
        queue_try_add(&fifo, &event);
    }
    else
    {
        int event = ROTARY_LEFT_EVENT;
        queue_try_add(&fifo, &event);
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

void set_led_levels(const int *leds, const int level)
{
    for (int i = 0; i < 3; i++)
    {
        pwm_set_gpio_level(leds[i], level);
    }
}

void init_pwm(const int *leds)
{
    for (int i = 0; i < 3; i++)
    {
        const uint slice = pwm_gpio_to_slice_num(leds[i]);
        const uint channel = pwm_gpio_to_channel(leds[i]);

        pwm_set_clkdiv(slice, (float)clock_get_hz(clk_sys) / 1000000);
        pwm_set_wrap(slice, 999);
        pwm_set_chan_level(slice, channel, 0);
        pwm_set_enabled(slice, true);
        gpio_set_function(leds[i], GPIO_FUNC_PWM);
    }
}
