#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;

int main()
{
	int number;
	printf("Enter a number\n");
	scanf("%d",&number);
	int reverse_number=0;
	while(number>0)
	{
		reverse_number=reverse_number*10+(number%10);
		number/=10;
	}
	printf("%d\n",reverse_number );
	//to stop console from closing
	system("pause");
	return 0;
}