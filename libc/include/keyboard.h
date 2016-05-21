#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <sysutils.h>

bool keyPressed[0x40];

void initKeyboard(void);

// Input function
char getChar(void);
char* readLine(void);

#endif