cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico_w)
include(pico_sdk_import.cmake)
project(Lab_2 C CXX ASM)

pico_sdk_init()

add_executable(Lab_2
        headers.h
        main.c
        main.c
)

target_link_libraries(Lab_2
        pico_stdlib
        hardware_pwm
        hardware_irq
)

pico_enable_stdio_uart(Lab_2 1)
pico_enable_stdio_usb(Lab_2 0)

pico_add_extra_outputs(Lab_2)
