//#include "stdafx.h"
#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;


int main()
{
	char s[50];
	printf("Enter the strings\n");
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++)
	{
		printf("%s",s+i);
		for(int j=0;j<i;j++)
			printf("%c",s[j]);
		printf("\n");
	}

	system("pause");
	 return 0;
}	