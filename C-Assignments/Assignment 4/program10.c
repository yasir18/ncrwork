#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void delete(char s[],char c){
	int k=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]==c)
			continue;
		s[k++]=s[i];
	}
	s[k]='\0';
}
int main()
{
	printf("Enter the string and the character\n");
	char s[50],c;
	scanf("%s %c",s,&c);
	delete(s,c);
	printf("resultant string is\n");
	printf("%s\n",s);

	system("pause");
	return 0;
}