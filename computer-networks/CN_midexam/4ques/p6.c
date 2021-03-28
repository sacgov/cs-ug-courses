#include <stdio.h>
#include <string.h>
int main() {
	char str[1024];
	char buf[100];
	while(1)
	{
		read(0, str, 9);
		printf("str1 %s str2",str);
		strcpy(buf,"P6 :");
		strcat(buf,str);
		write(1,buf,13);
	}
	return 0;
}