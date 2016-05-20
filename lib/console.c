#include "console.h"

size_t curX = 0, curY = 0;

void initiallizeConsole(void) {
	defaultColor = make_color(CL_WHITE, CL_BLACK);
	emptyEntry = make_vgaentry(' ', defaultColor);
	blinkingCursor = make_vgaentry('_', defaultColor);
	for (size_t y = 0; y < VGA_HEIGHT; y++) 
	for (size_t x = 0; x < VGA_WIDTH; x++) {
		VGA_MEMORY[y*VGA_WIDTH + x] = emptyEntry;
	}
}

void putchar(char ch) {
	VGA_MEMORY[curY * VGA_WIDTH + curX] = make_vgaentry(ch, defaultColor);
	curX++;
	if (curX==VGA_WIDTH) {
		curY++; curX= 0;
		if (curY==VGA_HEIGHT) curY=0;
	}
	VGA_MEMORY[curY*VGA_WIDTH + curX] = blinkingCursor;
}

void write_string(const char* data) {
	size_t i = 0;
	while (data[i]) {
		putchar(data[i]);
		i++;
	}
}