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

int main()
{
    int event;
    const int leds[3] = {LED_1_GPIO, LED_2_GPIO, LED_3_GPIO};
    bool leds_on = false;
    int level = 500;

    init_gpio();
    init_pwm(leds);

    queue_init(&fifo, sizeof(int), FIFO_LENGTH);
    gpio_set_irq_enabled_with_callback(ROT_SW, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, irq);
    gpio_set_irq_enabled(ROT_A, GPIO_IRQ_EDGE_RISE, true);
    

    while (1)
    {
        if (queue_try_remove(&fifo, &event)) {
            int target_level = 0;
            if (event == ROTARY_DOWN_EVENT)
            {
                printf("Rotary switch event");
                if (!leds_on)
                {
                    target_level = level;
                }
                else if (level == 0)
                {
                    level = 500;
                    target_level = level;
                    leds_on = !leds_on; // Reverse the change that happens at the end of the conditional
                }
                leds_on = !leds_on;
            }
            else if (event == ROTARY_RIGHT_EVENT && leds_on)
            {
                level -= STEP_SIZE;
                if (level < 0) level = 0;
                target_level = level;
            }
            else if (leds_on)
            {
                level += STEP_SIZE;
                if (level > 1000) level = 1000;
                target_level = level;
            }
            set_led_levels(leds, target_level);
        }
    }
}

void irq(const uint gpio, const uint32_t event_mask)
{
    if (gpio == ROT_SW)
    {
        handle_sw(event_mask);
    }
    else if (gpio == ROT_A)
    {
        handle_rot();
    }
}

void handle_sw(const uint32_t mask)
{
    const uint32_t current_time = time_us_32();
    if (current_time - rotary_button.last_time >= DEBOUNCE_TIMER)
    {
        rotary_button.last_time = current_time;

        if (mask == GPIO_IRQ_EDGE_FALL)
        {
            const int event = ROTARY_DOWN_EVENT;
            queue_try_add(&fifo, &event);
        }
    }
}

void handle_rot()
{
    if (gpio_get(ROT_B) == 1)
    {
        const int event = ROTARY_RIGHT_EVENT;
        queue_try_add(&fifo, &event);
    }
    else
    {
        const int event = ROTARY_LEFT_EVENT;
        queue_try_add(&fifo, &event);
    }
}

void init_gpio()
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
