#include "printf.h"

void print(const char* data, size_t data_length) {
	for (size_t i = 0; i < data_length; i++)
		putchar(data[i]);
}

void printf(const char* restrict format, ...) {
	va_list params;
	va_start(params, format);
	size_t amount;

	while (*format != '\0') {
		if (*format != '%') {
			putchar(*format, 1);
			format++;
		}	else {
			format++;
			if (*format=='\0') break;
			switch (*format) {
				case 'c': {
					char c = (char) va_arg(params, int);
					print(&c, 1);
				};	break;
				case 's': {
					char* st = va_arg(params, char*);
					print(st, strlen(st));
				};	break;
				
			}
			format++;
		}
	}
	va_end(params);
}