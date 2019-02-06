#include<iostream>
using namespace std;
int main(){
	int n,sum,tempsum,l=0,i,h=0;
	cout<<"Enter the value of n";
	cin>>n;
	int arr[n];
	cout<<"Enter the values :";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Enter the value of sum";
	cin>>sum;
	tempsum=0;
	int flag=0;
	for(i=0;i<n;i++){
		if(tempsum<sum){
			tempsum+=arr[i];
		}
		if(tempsum>sum){
			while(tempsum>sum){
				tempsum-=arr[l];				
				l++;
			}
		}
		if(tempsum==sum){
			if(i==l){ 
				if(arr[i]!=sum)//handling case of sum=0
				{
					l++;
					continue;
				}	
			}
					flag=1;
					break;
		}
				cout<<"temp"<<tempsum<<" sum "<<sum<<endl;
	}

	if(flag){
		cout<<"indices are "<<l<<" "<<i;
	}
	else{
		cout<<"Not found";
	}
}