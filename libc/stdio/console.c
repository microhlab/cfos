#include <console.h>
#include <io.h>
#include <mem.h>

// INITIALIZE FUNCTIONS
void initConsole(void) {
	defaultColor = make_color(CL_BLACK, CL_LIGHT_GREY);
	emptyEntry = make_vgaentry(' ', defaultColor);
	clrscr();
	updateCursor();
}

void clrscr(void) {
	curX = curY = 0;
	for (size_t y = 0; y < SRC_HEIGHT; y++) 
	for (size_t x = 0; x < SRC_WIDTH; x++) {
		src[y*SRC_WIDTH + x] = emptyEntry;
	}
}

void scrollDown(void) {
	for (byte y=0; y < SRC_HEIGHT - 1; y++)
		for (byte x=0; x < SRC_WIDTH; x++)
			src[y*SRC_WIDTH + x] = src[(y+1)*SRC_WIDTH + x];
	curY--;
	for (byte x=0; x < SRC_WIDTH; x++)
		src[curY*SRC_WIDTH + x] = emptyEntry;
}

// OUTPUT FUNCTIONS

void putChar(char ch) {
	if (ch=='\n') {
		curY++; curX = 0;
		if (curY == SRC_HEIGHT) scrollDown();
		return ;
	}
	src[curY * SRC_WIDTH + curX] = make_vgaentry(ch, defaultColor);
	curX++;
	if (curX==SRC_WIDTH) {
		curY++; curX= 0;
		if (curY==SRC_HEIGHT) scrollDown();
	}
	updateCursor();
}

void removeChar(void) {
	if (curX == 0) {
		curX = SRC_WIDTH - 1;
		curY --;
	}	else
		curX--;
	src[curY * SRC_WIDTH + curX] = emptyEntry;
	updateCursor();
}

void print(char* st) {
	word i = 0;
	while (st[i]) {
		putChar(st[i]);
		i++;
	}
}

void printf(const char* restrict format, ...) {
	va_list params;
	va_start(params, format);
	// Process format string
	while (*format != '\0') { // While string not end
		if (*format != '%') { // If is param included
			putChar(*format); // Write char
			format++;
		}	else {
			format++;
			if (*format=='\0') break;
			switch (*format) {
				case 'c': {
					char c = (char) va_arg(params, int);
					putChar(c);
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

void updateCursor(void) {
	word pos = curY * SRC_WIDTH + curX;
	outb(0x3D4, 14);
	outb(0x3D5, (pos >> 8) & 0x00FF);
	outb(0x3D4, 15);
	outb(0X3D5, pos & 0x00FF);
}