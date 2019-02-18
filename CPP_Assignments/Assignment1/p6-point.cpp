#include<bits/stdc++.h>
// #include<math.h>
using namespace std;
class pointt
{
	int xc,yc;
	public:
	pointt()
	{
		xc=yc=0;
	}
	pointt(int a,int b)
	{
		xc=a;
		yc=b;
	}
	void display()
	{
		cout<<"x ; "<<xc<<endl;
		cout<<"y : "<<yc<<endl;
	}
	friend double distancee(pointt a ,pointt b);
};

double distancee(pointt p1,pointt p2)
{
	double res=0;
	res+=(p2.xc-p1.xc)*(p2.xc-p1.xc);
	res+=(p2.yc-p1.yc)*(p2.yc-p1.yc);
	res=sqrt(res);
	return res;
}

int main()
{
	pointt p1(3,5),p2(5,7);
	cout<<"the distance between points is :";
	double ans=distancee(p1,p2);
	cout<<ans<<endl;	
	return 0;
}
