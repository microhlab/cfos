#ifndef _STRING_H
#define _STRING_H

#include <stddef.h>
#include <sysutils.h>

size_t strlen(char* st);
void strip(char* data);
bool stringEqual(char* s1, char* s2);

#endif