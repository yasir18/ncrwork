#include<stdio.h>
#include <math.h>
int main()
{
	int temp,num=-1,rem,sum=0;
	printf("Enter any number:\n");
	scanf("%d",&num);
	temp=num;
	while(temp>0)
	{	
		rem=temp%10;
		sum=sum+rem;
		temp=temp/10;
	}
	printf("%d is the sum of the digits\n",sum);
	return 0;
}