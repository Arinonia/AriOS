#pragma once

#ifndef _VA_LIST_H_
#define _VA_LIST_H_

typedef char *va_list;

#define __va_size(TYPE) (((sizeof(TYPE) + sizeof(int)-1) / sizeof(int)) * sizeof(int))

#ifndef __sparc__
    #define va_start(AP, LASTARG) (AP = ((char *) &(LASTARG) + __va_size(LASTARG)))
#endif

void va_end(va_list);

#define va_end(AP)
#define va_arg(AP, TYPE) (AP += __va_size(TYPE), *((TYPE *) (AP - __va_size(TYPE))))

#endif