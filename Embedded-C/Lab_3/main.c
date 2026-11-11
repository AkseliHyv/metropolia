#include "headers.h"
#include "pico/stdlib.h"
#include "pico/util/queue.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int motor_pins[4] = {MOT_A, MOT_B, MOT_C, MOT_D};

static const uint8_t motor_steps[8][4] = {
    {1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0},
    {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {1, 0, 0, 1},
};
static int current_step = 0;
static float leftover_steps = 0;
static queue_t fifo;
static uint32_t last_opto_time = 0;

int main()
{
    char str[STR_MAX_SIZE] = "";
    float calib_steps = -1;
    init();

    while (1)
    {
        char command[STR_MAX_SIZE] = "";
        int n = 8;

        printf(
            "\nchoose option\n'status': show calibration state and steps per revolution\n'calib': "
            "measure steps per revolution\n'run N': run N/8 of a revolution, default 8\n");
        if (!fgets(str, STR_MAX_SIZE, stdin))
        {
            return EXIT_FAILURE;
        }

        sscanf(str, "%s %d", command, &n);

        if (!strcmp(command, "calib"))
        {
            calib_steps = calibrate();
        }
        else if (!strcmp(command, "status"))
        {
            status(calib_steps);
        }
        else if (calib_steps < 0)
        {
            printf("not calibrated, run 'calib' first\n");
        }
        else if (!strcmp(command, "run"))
        {
            rotate_n(n, calib_steps);
        }
        else
        {
            printf("unknown command\n");
        }
    }
}

void status(float calib_steps)
{
    if (calib_steps < 0)
    {
        printf("not calibrated, steps per revolution: not available\n");
    }
    else
    {
        printf("calibrated, steps per revolution: %.2f\n", calib_steps);
    }
}

float calibrate()
{
    float steps = 0;
    int event;
    leftover_steps = 0;

    clear_fifo();

    for (int i = 0; i <= CALIB_ROTATIONS; i++)
    {
        while (!queue_try_remove(&fifo, &event))
        {
            if (i > 0)
            {
                steps++;
            }
            rotate_step();
        }
    }

    steps = steps / CALIB_ROTATIONS;
    return steps;
}

void rotate_n(const int n, const float calib_steps)
{
    const float steps = n * calib_steps / 8 + leftover_steps;

    for (int i = 0; i < (int)steps; i++)
    {
        rotate_step();
    }
    leftover_steps = steps - (int)steps;
}

void rotate_step()
{
    current_step = (current_step + 1) % 8;
    for (int i = 0; i < 4; i++)
    {
        gpio_put(motor_pins[i], motor_steps[current_step][i]);
    }
    sleep_ms(2);
}

void clear_fifo()
{
    int event;
    while (queue_try_remove(&fifo, &event))
    {
    }
}

void irq(const uint gpio, const uint32_t event_mask)
{
    if (gpio == OPTO_FORK)
    {
        const uint32_t current_time = time_us_32();
        if (current_time - last_opto_time >= DEBOUNCE_TIMER)
        {
            last_opto_time = current_time;
            const int event = OPTO_FALL_EVENT;
            queue_try_add(&fifo, &event);
        }
    }
}

void init()
{
    stdio_init_all();

    for (int pin = 0; pin < 4; pin++)
    {
        gpio_init(motor_pins[pin]);
        gpio_set_dir(motor_pins[pin], GPIO_OUT);
    }

    gpio_init(OPTO_FORK);
    gpio_set_dir(OPTO_FORK, GPIO_IN);
    gpio_pull_up(OPTO_FORK);

    queue_init(&fifo, sizeof(int), FIFO_LENGTH);
    gpio_set_irq_enabled_with_callback(OPTO_FORK, GPIO_IRQ_EDGE_FALL, true, irq);
}