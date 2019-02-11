#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void deletes2(char *s1,char *s2){
	for(int i=0;i<strlen(s2);i++){
		char c=s2[i];
		int k=0;
		for(int j=0;j<strlen(s1);j++){
			if(c==s1[j])
				continue;
			s1[k++]=s1[j];
		}
		s1[k]='\0';
	}
}

int main()
{
	printf("Enter the string1\n");
	char s1[50],s2[20];
	scanf("%s",s1);
	printf("Enter the string2\n");
	scanf("%s",s2);
	deletes2(s1,s2);

	printf("resultant string is\n");
	printf("%s\n",s1);

	system("pause");
	return 0;
}