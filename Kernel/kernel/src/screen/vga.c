#include <kernel/screen/vga.h>
#include <kernel/types.h>

static uint32_t vga_index;
static uint32_t vga_column;
static uint32_t vga_row;

static uint16_t vga_entry(uint8_t ch, color fore_color, color back_color)
{
    uint16_t ax;
    uint8_t ah;

    ah = back_color;
    ah <<= 4; //décalage de 4 bytes
    ah |= fore_color; //addission logique des bit
    ax = ah;
    ax <<= 8;
    ax |= ch;
    return ax;
}

static void new_line(void)
{
    vga_column = 0;
    vga_row++;
    vga_index = 80 * vga_row;
}

void vga_print_char(const char ch, color fore_color, color back_color)
{
    uint16_t *buffer = (uint16_t *)VGA_ADDRESS;
    
    buffer[vga_index] = vga_entry(ch, fore_color, back_color);
    vga_index++;
    vga_column++;
    if (vga_column > 80)
        new_line();
}

void vga_clear_buffer(void)
{
    uint16_t *buffer = (uint16_t *)VGA_ADDRESS;

    for (uint32_t i = 0; i < 2200; i++)
        buffer[i] = vga_entry(0, WHITE, BLACK);
    vga_index = 0;
    vga_column = 0;
    vga_row = 0;
}