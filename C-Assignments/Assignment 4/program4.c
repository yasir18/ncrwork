#include<stdio.h>
int replace(char *);
int main(){
	char cat[]="The cat sat";
	printf("Number of spaces are %d",replace(cat));
	printf("\n%s",cat);

	return 0;
}
int replace(char *p){
	int count=0;
	while(*p!='\0'){
		if(*p==' '){
			count++;
			*p='-';
		}
		p++;
	}
	return count; 
}