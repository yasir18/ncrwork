#include<stdio.h>
#include <stdlib.h>

void replace(FILE *fp, FILE *fp2) {


	char ch;
	while (!feof(fp)) {
		ch = fgetc(fp); 
		if (ch == '\t') {
			fputc('\\', fp2);
			fputc('t', fp2);
		}
		else {
			fputc(ch, fp2);
		}

	}
	fclose(fp);
	fclose(fp2);
}