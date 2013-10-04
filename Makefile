#Makefile for CandyOS
#Luke Bullard, October 2013
#-----
CC=i586-elf-gcc
CPP=i586-elf-g++
LD=i586-elf-ld
ASM=nasm

CCFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra -Iinclude
CPPFLAGS=-ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -Iinclude
LDFLAGS=-Tsrc/link.ld
ASFLAGS=-felf
CRTBEGIN_OBJ:=$(shell $(CC) $(CCFLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ:=$(shell $(CC) $(CCFLAGS) -print-file-name=crtend.o)

SOURCES=src/boot.s src/kmain.cpp src/common.cpp src/terminal.cpp src/vga_terminal.cpp
ASMSOURCES=$(SOURCES:.s=.o)
CSOURCES=$(ASMSOURCES:.c=.o)
CPPSOURCES=$(CSOURCES:.cpp=.o)
OBJECTS=$(CPPSOURCES)

all: $(OBJECTS) link

genimage: all
	sh ./genimage.sh

clean:
	rm $(OBJECTS) kernel.bin

link:
	$(LD) $(LDFLAGS) -o kernel.bin $(OBJECTS)

.s.o:
	$(ASM) $(ASFLAGS) $< -o $@

.cpp.o:
	$(CPP) -c $< -o $@ $(CPPFLAGS)

.c.o:
	$(CC) -c $< -o $@ $(CCFLAGS)