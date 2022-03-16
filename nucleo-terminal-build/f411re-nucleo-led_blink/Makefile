# Put your source files here (*.c)
SRCS=./main.c

# Binaries will be generated with this name (.elf, .bin, .hex)
PROJ_NAME=led_turned_on

# Compiler settings. Only edit CFLAGS to include other header files.
CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

# Compiler flags
CFLAGS  = -g -O2 -Wall -T./LinkerScript.ld
CFLAGS += -DUSE_STDPERIPH_DRIVER
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -I.
CFLAGS += --specs=nosys.specs

# add startup file to build
SRCS += ./startup_stm32.s

.PHONY: proj

# Commands
all: proj

proj: $(PROJ_NAME).elf

$(PROJ_NAME).elf: $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@
	$(OBJCOPY) -O ihex $(PROJ_NAME).elf $(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin

clean:
	rm -f *.o $(PROJ_NAME).elf $(PROJ_NAME).hex $(PROJ_NAME).bin

burn: proj
	st-flash write $(PROJ_NAME).bin 0x8000000
