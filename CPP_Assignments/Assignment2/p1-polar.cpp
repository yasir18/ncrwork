#include<iostream>
using namespace std;
class Polar{
	int angle,radius;
public:
	static int count;
	Polar(){
		angle=radius=0;
		count++;
	}
	Polar(int a,int r){
		angle=a;
		radius=r;
		count++;
	}

};
int Polar::count;
int main(){
	Polar p,q;
	Polar r(60,5);
	cout<<Polar::count;
	return 0;
}