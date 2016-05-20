#ifndef _PRINTF_H
#define _PRINTF_H

#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdbool.h>

#include "string.h"

void print(const char* data, size_t data_length);
void printf(const char* restrict format, ...);

#endif