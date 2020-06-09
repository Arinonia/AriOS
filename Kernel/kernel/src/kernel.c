#include <kernel/kernel.h>
#include <kernel/screen/vga.h>
#include <kernel/logger/kprintf.h>


void init_kernel(void)
{
    vga_clear_buffer();
    kprintf("Hello world, %s \0", "fdp\0");
}