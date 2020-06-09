#include <kernel/logger/kprintf.h>
#include <kernel/va_list.h>
#include <kernel/types.h>
#include <kernel/utils/string.h>
#include <kernel/screen/vga.h>

static boolean is_flag(const char flag)
{
    return (flag == 'c' || flag == 's');
}

void write(const char *str, int lenght)
{
    for (int i = 0; i < lenght; i++) {
        vga_print_char(str[lenght], WHITE, BLACK);
    }
}

void kprintf(const char *str, ...)
{
    va_list args;

    va_start(args, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%' && is_flag(str[i + 1])) {
            switch (str[i + 1]) {
            case 'c': {
                char ch = va_arg(args, char);
                write(&ch, 1);
                break;
            }
            case 's':{
                char *s = va_arg(args, char *);
                write(s, string_lenght(s));
                break;
            }
            }
        }
        else if (!(str[i - 1] == '%' && is_flag(str[i])))
            write(&str[i], 1);
    }
    va_end(args);
}
