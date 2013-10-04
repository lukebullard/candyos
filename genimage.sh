#!/bin/bash
#CandyOS CD Image Generation Script
#Luke Bullard, 2013
mkdir -p isodir
mkdir -p isodir/boot
cp kernel.bin isodir/boot/kernel.bin
mkdir -p isodir/boot/grub
cp config/grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o build/CandyOS-0.0.0.iso isodir
rm -rf isodir