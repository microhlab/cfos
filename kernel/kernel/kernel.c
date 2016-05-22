#include <shell.h>
#include <console.h>

const char* welcome = 
"--------------------------------------------------------------------------------\
|                                                                              |\
|                                                                              |\
|                                                                              |\
|                  Simple 32 bit OS 1.0                                        |\
|                  Written by : Chien Tran                                     |\
|                  Email : yeulaptrinh98@gmail.com                             |\
|                  Source code : git - cfos                                    |\
|                                                                              |\
|                  Supported function : printf, strlen                         |\
|                                                                              |\
|                                                                              |\
|                                                                              |\
--------------------------------------------------------------------------------";


char* stt = "HelloGirl";

void kernel_main(void) {
	stt = "OhYeahfucking";
	initConsole();
	initKeyboard();
	print(welcome);
	lsh_loop();
}