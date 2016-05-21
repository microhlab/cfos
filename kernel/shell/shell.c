#include <shell.h>
#include <console.h>

void lsh_loop(void) {
	char *line;
	char **args;
	initConsole();
	
	do {
		printf("cfos$ ");
		line = readLine();
		putChar('\n');
	}	while(1);
}