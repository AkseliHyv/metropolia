#ifndef HEADERS_H_
#define HEADERS_H_
#include <stdint.h>
#include <sys/types.h>
#include <stdbool.h>

typedef enum
{
    OPTO_FALL_EVENT
} events;

#define OPTO_FORK 28
#define MOT_A 2
#define MOT_B 3
#define MOT_C 6
#define MOT_D 13
#define STR_MAX_SIZE 10
#define FIFO_LENGTH 32
#define DEBOUNCE_TIMER 50000

#define CALIB_ROTATIONS 3

void irq(uint gpio, uint32_t event_mask);
void clear_fifo(void);
void status(float calib_steps);
float calibrate(void);
void rotate_n(int n, float calib_steps);
void rotate_step(void);
void init(void);

#endif // HEADERS_H_