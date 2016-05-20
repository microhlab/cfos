#include "string.h"

size_t strlen(char* st) {
	size_t result = 0;
	while (st[result]) result++;
	return result;
}