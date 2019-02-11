#include<stdio.h>
#include <stdlib.h>
#include<string.h>

void rotateWord(FILE *fp, FILE *fp2) {
	printf("Enter the word to be rotated");
	char str[20];
	char token[30];
	char revstr[20];
	scanf("%s", str);
	strcpy(revstr,str);
	int l=strlen(str), i = 0,j;
	for(int i=0,j=l-1;i<j;i++,j--){
		char c;
		c=revstr[i];
		revstr[i]=revstr[j];
		revstr[j]=c;
	}

	char ch;
	while (!feof(fp)) {
		fscanf(fp,"%s",token);
		if(strcmp(str,token)==0){
			fprintf(fp2, "%s",revstr );
			fputc(' ',fp2);
		}
		else{
			fprintf(fp2, "%s",token );
			fputc(' ',fp2);
		}

	}


}