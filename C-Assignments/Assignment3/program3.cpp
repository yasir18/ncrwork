#include<iostream>
using namespace std;
int main(){
	int num,count=0;
	cout<<"Enter the number";
	cin>>num;
	for(int i=0;i<8;i++){
		count+=num&1;
		num=num>>1;
	}
	cout<<"Number of 1s in 8 bit number are "<<count; 


	return 0;
}