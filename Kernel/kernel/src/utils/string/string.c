#include <kernel/utils/string.h>
#include <kernel/types.h>

int string_lenght(char *str)
{
    int lenght = 0;

    while (str[lenght]) 
        lenght++;
    return lenght;
}
