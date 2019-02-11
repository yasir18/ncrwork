#include<stdio.h>
#include <stdlib.h>

void removeComments(FILE *fp,FILE *fp2) {
	

	char ch,ch2;
	while (!feof(fp)) { /*While end of file*/
		ch = fgetc(fp);

		if (ch == '/') { /*if a / char is encountered*/

			if (!feof(fp)) { /* Check the next char is not eof */

				ch2 = fgetc(fp);
				if (ch2 == '/')
					while (!feof(fp) && ((ch = fgetc(fp)) != '\n'));/*If we encounter another / ,iterate till u get \n*/
				else if (ch2 == '*') {
					while (!feof(fp) && ((ch = fgetc(fp)) != '*'));/*If we encounter / followed by * ,iterate till * */
					if (!feof(fp) && ((ch = fgetc(fp)) != '*')); /*moves fp next to * char*/
					if (!feof(fp) && ((ch = fgetc(fp)) != '\n')); /* removes new line if existed */
				}	

			}

		}
		else {   /*Print the char if it is not / */
			fputc(ch, fp2);
		}

	}
	fclose(fp);
	fclose(fp2);

}