#include<stdio.h>
#include <math.h>
int main()
{
	char arr[80];
	int noOfElements,i=0,alpha=0,digit=0,blank=0,tab=0,other=0;
	scanf("%[^\n]c",arr);
	noOfElements=sizeof(arr)/sizeof(arr[0]);
//	printf("%d\n",noOfElements);
	for(i=0;arr[i]!='\0';i++)
	{
		if((arr[i]>='A'&&arr[i]<='Z')||(arr[i]>='a'&&arr[i]<='z'))
			alpha++;
		else if(arr[i]>='0'&&arr[i]<='9')
			digit++;
		else if(arr[i]==' ')
			blank++;
		else if (arr[i]=='\t')
			tab++;
		else
			other++;

	}
	printf(" Number of alphabets are %d\n Number of digits are %d\n Number of blanks are  %d\n Number of tabs are %d\n Number of other characters are%d\n",alpha,digit,blank,tab,other);
	
	return 0;
}