//#include "stdafx.h"
#include <iostream>
using namespace std;

#include<cstring>
#include<math.h>
#include<stdlib.h>

char rev[100];
char* strev(char s[50])
{
	
	int i=0,j=strlen(s)-1;
	while(i<strlen(s))
	{
		rev[i++]=s[j--];
	}
	return rev;
}

int strcomp(char s[50],char t[50])
{
	int i=0;
	while(s[i]==t[i])
	{
		if(s[i]=='\0')
			return 0;
		i++;
	}
	return (s[i]-t[i]);
}

char* strconcat(char *src,char *dest)
{
	int i,j;
	for (i = 0; dest[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
    dest[i+j] = '\0';
    return dest;
}
void strcopy(char *a,char *b)
{
	int i=0;
	while((a[i]=b[i])!='\0')
	i++;
	return ;
}

int main()
{
	char s[50],t[50],*cat;
	printf("Enter the strings to compare\n");
	scanf("%s",s);
	scanf("%s",t);
	if(strcomp(s,t)==0)
	{
		printf("The strings are equal\n");
	}
	else
	{
		printf("The strings are unequal\n");
	}
	char *rev=strev(s);
	printf("\n reverse of string %s is: ", s);
	printf("%s\n", rev);
	cat=strconcat(s,t);
	printf("\nConcatenated string is :");
	printf("%s\n", cat);
	char st[]="Added string";
	strcopy(cat,st);
	printf("\ncopied string is : ");
	printf("%s\n", cat);
	
	system("pause");
	 return 0;
}	