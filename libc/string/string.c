#include <string.h>
#include <console.h>

size_t strlen(char* st) {
	size_t result = 0;
	while (st[result]) result++;
	return result;
}

void strip(char* data) {
	while (*data != ' ') data++;
	*data = '\0';
}

bool stringEqual(char* s1, char* s2) {
	if (strlen(s1) != strlen(s2)) return false;
	word size = strlen(s1);
	for (word i=0; i < size; i++)
		if (s1[i] != s2[i])
			return false;
	return true;
}