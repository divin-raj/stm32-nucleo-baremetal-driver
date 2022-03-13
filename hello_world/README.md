# hello world
led_blinking code for stm32f411re

#building project

$ make

#clean the workspace

$ make clean

#burn the controller

$ make burn
 
$ arm-none-eabi-gcc -T./LinkerScript.ld --specs=nosys.specs ./main.c startup_stm32.s -o application.elf


