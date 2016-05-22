#include <keyboard.h>
#include <console.h>
#include <io.h>

void initKeyboard(void) {
	for (int i=0; i < 0x40; i++) keyPressed[i] = false;
}

// INPUT FUNCTIONS
char getChar(void) {
	do {
		byte c = inb(0x60);
		if (c <= 0x40) keyPressed[c] = true;
			else if (c >= 0x81 && c <= 0xB9) {
				if (keyPressed[c - 0x80]) {						
					keyPressed[c - 0x80] = false;			
					return Character[c - 0x80];
				}
			}
	}	while (1);
}

char* readLine(void) {
	char* buffer;
	memfill(buffer, 100, 0);
	char c;
	word pos = 0;
	while (1) {
		c = getChar();
		if (c == '\b') {
			if (pos > 0) {
				buffer[--pos] = '\0';
				while (*buffer == ' ') buffer++;
				removeChar();
			}
		}	else
		if (c == '\n') {
			buffer[pos] = '\0';
			putChar('\n');
			return buffer;
		}	else {
			buffer[pos++] = c;
			putChar(c);
		}
	}
}