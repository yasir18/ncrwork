#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void rotateWord(FILE *fp, FILE *fp2) {
	printf("Enter the word to be rotated");
	char str[20];  /*To scan a word*/
	char token[30]; /*To scan strings from fp*/
	char revstr[20]; /*storing reverse of str word*/
	scanf("%s", str);
	strcpy(revstr,str);
	int l=strlen(str), i = 0,j;
	for(int i=0,j=l-1;i<j;i++,j--){ /*Logic for rotating a word*/
		char c;
		c=revstr[i];
		revstr[i]=revstr[j];
		revstr[j]=c;
	}

	char ch;
	while (!feof(fp)) { /*While end of file*/
		fscanf(fp,"%s",token);
		if(strcmp(str,token)==0){ /*If matches with str, print revstr in fp2*/
			fprintf(fp2, "%s",revstr );
			fputc(' ',fp2);
		}
		else{
			fprintf(fp2, "%s",token ); /*If doesnt matches with str, print token in fp2*/
			fputc(' ',fp2);
		}

	}


}