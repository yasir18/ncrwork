#include<stdio.h>
#include <limits.h>
int main()
{
	int num=-1,sum=0,min=INT_MAX,max=INT_MIN,count=0;float avg;
	while(1)
	{
		scanf("%d",&num);
		if(num>0)
		{
			sum+=num;
			min=(num<min)?num:min;
			max=(num>max)?num:max;
			count++;
		}
		else
			break;
	}
	avg=(float)sum/count;
	printf("No of positive Digits Entered:%d\n Minimum Value:%d\n Maximum Value:%d\n Average:%g\n",count,min,max,avg );
	return 0;
}
