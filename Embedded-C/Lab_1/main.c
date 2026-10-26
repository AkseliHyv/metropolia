#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "headers.h"
#include "pico/stdlib.h"
#include <sys/types.h>

int main(void)
{
    bool sw1_was_down = false;
    bool leds_on = false;
    int level = 500;
    const int leds[3] = {LED_1_GPIO, LED_2_GPIO, LED_3_GPIO};
    const int buttons[3] = {SW_0_GPIO, SW_1_GPIO, SW_2_GPIO};

    for (int i = 0; i < 3; i++)
    {
        init_pwm(leds[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        init_button(buttons[i]);
    }

    while (1)
    {
        const bool sw1_down = is_down(SW_1_GPIO);

        if (sw1_down && !sw1_was_down)
        {
            int target_level;
            if (level == 0 && leds_on) // LEDs are at 0, put them to 500
            {
                level = 500;
                target_level = level;
            }
            else if (leds_on) // LEDs are on and not at 0, turn them off
            {
                target_level = 0;
                leds_on = false;
            }
            else // LEDs are off, turn them on
            {
                target_level = level;
                leds_on = true;
            }
            set_led_levels(leds, target_level);
        }

        if (!gpio_get(SW_0_GPIO) && leds_on)
        {
            level++;
            if (level > 1000) level = 1000;
            set_led_levels(leds, level);
        }

        if (!gpio_get(SW_2_GPIO) && leds_on)
        {
            level--;
            if (level < 0) level = 0;
            set_led_levels(leds, level);
        }

        sw1_was_down = sw1_down;
        sleep_ms(5);
    }

    return 0;
}

void set_led_levels(const int *leds, const int level)
{
    for (int i = 0; i < 3; i++)
    {
        pwm_set_gpio_level(leds[i], level);
    }
}

void init_pwm(const int pin)
{
    gpio_set_function(pin, GPIO_FUNC_PWM);

    const uint slice = pwm_gpio_to_slice_num(pin);
    const uint channel = pwm_gpio_to_channel(pin);

    pwm_set_clkdiv(slice, (float)clock_get_hz(clk_sys) / 1000000);
    pwm_set_wrap(slice, 999);
    pwm_set_chan_level(slice, channel, 0);
    pwm_set_enabled(slice, true);
}

void init_button(const int pin)
{
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_up(pin);
}

bool is_down(const int pin)
{
    if (!gpio_get(pin))
    {
        sleep_ms(20);
        if (!gpio_get(pin))
        {
            return true;
        }
    }
    return false;
}
