#include <mem.h>

void memfill(char* buffer, word size, byte value) {
	for (byte i=0; i < size; i++)
		buffer[i] = value;
}