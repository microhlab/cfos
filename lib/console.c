#include "console.h"

void initConsole(void) {
	defaultColor = make_color(CL_WHITE, CL_BLACK);
	emptyEntry = make_vgaentry(' ', defaultColor);
	clrscr();
}

void clrscr(void) {
	curX = curY = 0;
	for (size_t y = 0; y < SRC_HEIGHT; y++) 
	for (size_t x = 0; x < SRC_WIDTH; x++) {
		src[y*SRC_WIDTH + x] = emptyEntry;
	}
}

void putchar(char ch) {
	src[curY * SRC_WIDTH + curX] = make_vgaentry(ch, defaultColor);
	curX++;
	if (curX==SRC_WIDTH) {
		curY++; curX= 0;
		if (curY==SRC_HEIGHT) curY=0;
	}
}

void print(char* st) {
	longword i = 0;
	while (st[i]) putchar(st[i++]);
}

void printf(const char* restrict format, ...) {
	va_list params;
	va_start(params, format);
	// Process format string
	while (*format != '\0') { // While string not end
		if (*format != '%') { // If is param included
			putchar(*format); // Write char
			format++;
		}	else {
			format++;
			if (*format=='\0') break;
			switch (*format) {
				case 'c': {
					char c = (char) va_arg(params, int);
					putchar(c);
				};	break;
				case 's': {
					char* st = va_arg(params, char*);
					print(st);
				};	break;
				
			}
			format++;
		}
	}
	va_end(params);
}