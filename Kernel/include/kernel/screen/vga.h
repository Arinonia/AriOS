#pragma once

#ifndef _VGA_H_
#define _VGA_H_

#define VGA_ADDRESS 0xB8000 //adresse pour print avec le driver de base

typedef enum Color color;
enum Color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_MAGENTA,
    YELLOW,
    WHITE
};

void vga_print_char(const char ch, color fore_color, color back_color);
void vga_clear_buffer(void);

#endif