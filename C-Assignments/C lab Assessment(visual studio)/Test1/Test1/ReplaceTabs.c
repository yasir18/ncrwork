#include<stdio.h>
#include <stdlib.h>

void replace(FILE *fp, FILE *fp2) {


	char ch;
	while (!feof(fp)) { /*While end of file*/
		ch = fgetc(fp); 
		if (ch == '\t') { /*If tab is enontered replace it with '/'t*/
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