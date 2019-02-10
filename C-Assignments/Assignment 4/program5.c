#include<stdio.h>
int main(){
	printf("Enter the string :");
	char s[50];
	scanf("%s",s);
	char *p=s;
	while((*p)!='\0'){
		(*p)^=32;
		p++;
	}
	printf("Now the string is %s",s);
	system("pause");
	return 0;

}