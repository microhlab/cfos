#include <shell.h>
#include <console.h>
#include <keyboard.h>

void lsh_loop(void) {
	char* cmd;
	char **args;
	
	do {
		printf("cfos$ ");
		cmd = readLine();
		strip(cmd);
		if (stringEqual(cmd, "osname"))
			printf("Simple OS cfos version 1.0 - Chien Tran\n");
		else
		if (stringEqual(cmd, "clear"))
			clrscr();
		else
		if (stringEqual(cmd, "help"))
			printf(commandList);
		else
			printf("Command not found, type ""help"" to view available command\n");
	}	while(1);
}