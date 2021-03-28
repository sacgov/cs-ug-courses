#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
	char str[1024];
	sleep(20);
	strcpy(str,"FRM_PROG5");
	printf("%s", str);
	return 0;
}