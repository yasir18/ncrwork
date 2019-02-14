#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	unsigned int num=1;
	char *s=(char *)&num;
	if(*s)
		printf("The processor is little endian\n");
	else
		printf("The processor is Big endian\n");
	// to stop console from closing
	system("pause");
	return 0;
}