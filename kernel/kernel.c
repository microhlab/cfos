#include "shell.h"

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
|                                                                              |\
|                                                                              |\
--------------------------------------------------------------------------------";

void kernel_main(void) {
	lsh_loop();
}