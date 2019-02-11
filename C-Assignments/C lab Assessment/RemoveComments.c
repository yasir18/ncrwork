#include<stdio.h>
#include <stdlib.h>

void removeComments(FILE *fp,FILE *fp2) {
	

	char ch,ch2;
	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch == '/') {
			if (!feof(fp)) {
				ch2 = fgetc(fp);
				if (ch2 == '/')
					while (!feof(fp) && ((ch = fgetc(fp)) != '\n'));
				else if (ch2 == '*') {
					while (!feof(fp) && ((ch = fgetc(fp)) != '*'));
					if (!feof(fp) && ((ch = fgetc(fp)) != '*'));
					if (!feof(fp) && ((ch = fgetc(fp)) != '\n'));
				}										
			}

		}
		else {
			fputc(ch, fp2);
		}

	}
	fclose(fp);
	fclose(fp2);

}