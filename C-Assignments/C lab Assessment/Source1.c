#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countt(FILE*);
void removeComments(FILE*, FILE* );
void replace(FILE*, FILE*);
void rotateWord(FILE *,FILE*);


int main() {
	printf("Enter the option to perform a function\n");
	printf("1)Count the number of alphabets,digits,spaces and special characters\n");
	printf("2)remove comments from a file\n");
	printf("3)find and replace the word in a file\n");
	printf("4)replace all tabs with  \n");
	printf("5)Exit\n");
	int choice;

	FILE *fp,*fp2,*fp3,*fp4;
	 fopen_s(&fp , "file.txt", "r");
	 fopen_s(&fp2, "write.txt", "w");
	 fopen_s(&fp3, "rotate.txt", "w");
	 fopen_s(&fp4, "replacetabs.txt", "w");
	scanf_s("%d", &choice);
	switch(choice){
		case 1:
			countt(fp);
			break;
		case 2:
			removeComments(fp,fp2);
			break;
			
		case 3:
			rotateWord(fp, fp3);
			break;
			
		case 4:
			replace(fp,fp4);
			break;
		case 5:
			return 0;
			break;

		default:
			printf("Please enter a valid option\n");
			break;
				

	}

	return 0;


}
