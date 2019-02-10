#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;

int main()
{
	cout<<"Enter the two numbers ";
	int n1,n2; cin>>n1>>n2;

	for(int i=n1;i<=n2;i++)
	{
		int p=i,r=sqrt(i),j; //check till sqrt(i)
		for(j=2;j<=r;j++)
		{
			if(p%j==0)
			{
				break;
			}
		}
		if(j==r+1)
			cout<<p<<" ";
	}

	system("pause");
	return 0;
}