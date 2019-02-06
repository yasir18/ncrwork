#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int num=-1;
	while(1){
		cin>>num;
		if(num<1||num>31){
		//	return 0;		
			break;
		}
		else{
			int l=log2(num);
			int arr[l+1]={0};
			for(int i=0;i<=l;i++){
				arr[i]=num&1;
				num=num>>1;
			}
			for(int i=l;i>=0;i--){
				cout<<arr[i];
			}
			cout<<endl;
			
		}
	}
	// your code goes here
	return 0;
}
