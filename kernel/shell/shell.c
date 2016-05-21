#include <shell.h>
#include <console.h>
#include <keyboard.h>

void lsh_loop(void) {
	char *line;
	char **args;
	
	do {
		printf("cfos$ ");
		line = readLine();
		putChar('\n');
	}	while(1);
}