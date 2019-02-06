#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int num,p,b,temp;
	cin>>num>>p>>b;
	temp=pow(2,b)-1;
	temp=temp<<(p-b+1);
	cout<<(num^temp);
	return 0;
}
