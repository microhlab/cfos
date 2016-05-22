#ifndef _SHELL_H
#define _SHELL_H

static const char* commandList = "List of available commands:\n\
+ clear : clear screen\n\
+ osname : view full name of the operating system\n";

void lsh_loop(void);

#endif