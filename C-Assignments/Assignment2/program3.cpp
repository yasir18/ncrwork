
#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;

long long int fact(int number)
{
	if(number<=1)
		return 1;
	return number*fact(number-1);
}
int main()
{
	int number;
	printf("Enter a number\n");
	scanf("%d",&number);
	long long int ans=fact(number);
	printf("%ld\n", ans);
	//to stop console from closing
	system("pause");
	return 0;
}