#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
	char str[1024];
	strcpy(str,"FRM_PROG3");
	printf("%s", str);
	return 0;
}