#!/usr/bin/env bash

LD=$1
LD_FLAGS=$2

$LD $LD_FLAGS -T ld/kernel.ld $(find -name '*.o' | tr '\n' ' ') -o kernel.bin -nostdlib
grub-file --is-x86-multiboot kernel.bin