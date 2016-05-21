#ifndef _CONSOLE_H
#define _CONSOLE_H

#include <stdarg.h>
#include <string.h>
#include <sysutils.h>
#include <mem.h>

// Default values
// VGA Colors
enum vga_color {
	CL_BLACK = 0,
	CL_BLUE = 1,
	CL_GREEN = 2, 
	CL_CYAN = 3,
	CL_RED = 4,
	CL_MAGENTA = 5,
	CL_BROWN = 6,
	CL_LIGHT_GREY = 7,
	CL_DRAK_GREY = 8,
	CL_LIGHT_BLUE = 9,
	CL_LIGHT_GREEN = 10,
	CL_LIGHT_CYAN = 11,
	CL_LIGHT_RED = 12,
	CL_LIGHT_MAGENTA = 13,
	CL_LIGHT_BROWN = 14,
	CL_WHITE = 15,
};

// Default VGA Screen 80 columns and 25 rows
#define SRC_WIDTH 80
#define SRC_HEIGHT 25

// Default function
static inline word make_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}

static inline uint16_t make_vgaentry(char ch, byte color) {
	return (byte) ch | (byte) color << 8;
}

// Common values
byte defaultColor, curX, curY;
word emptyEntry;
static word* const src = (word*) 0xB8000;

// Initialize function
void initConsole(void);
void clrscr(void);
// Output function
void putChar(char ch);
void removeChar(void);
void print(char* st);
void printf(const char* restrict format, ...);
void updateCursor(void);
// Input function
char getChar(void);
char* readLine(void);

#endif