#ifndef _CONSOLE_H
#define _CONSOLE_H

#include <stdint.h>
#include <stddef.h>

// Default values
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

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

static inline uint8_t make_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}

static inline uint16_t make_vgaentry(char ch, uint8_t color) {
	return (uint8_t) ch | (uint8_t) color << 8;
}

uint8_t defaultColor;
uint16_t emptyEntry;
uint16_t blinkingCursor;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

// Terminal function
void intiallizeConsole(void);
void putchar(char ch);
void write_string(const char* data);

#endif