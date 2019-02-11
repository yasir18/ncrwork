#include<stdio.h>
#include <stdlib.h>

void countt(FILE *fp) {
	int alphabets = 0, digits = 0, spaces = 0, specialCharacters = 0;
	char ch;
	while (!feof(fp)) {
		ch = fgetc(fp);
		if ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
			alphabets++;
		else if (ch >= '0' && ch <= '9')
			digits++;
		else if (ch == ' ')
			spaces++;
		else if (ch == '\n');
		else
			specialCharacters++;
	}
	//ch = fgetc(fp);
	//if ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	//	alphabets++;
	printf("Number of alphabets are %d\n", alphabets);
	printf("Number of digits are %d\n", digits);
	printf("Number of spaces are %d\n", spaces);
	printf("Number of special charcters are %d\n", specialCharacters);

}