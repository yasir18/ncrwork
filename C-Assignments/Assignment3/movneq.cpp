#include<iostream>
using namespace std;
void swap(int&,int&);
int main(){
	int n;
	cout<<"Enter the value of n";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int i=0,j=n-1;
	while(i<=j){
		while(arr[i]<=0)
			i++;
		while(arr[j]>0)
			j--;
		if(i<j){
			swap(arr[i],arr[j]);
			i++;
			j--;
		}	
	}

//Handling cases with zeroes
	int negidx2=0,negidx1=0;
	while(arr[negidx2]<=0)
		negidx2++;
	negidx2--;
	while(negidx1<=negidx2){
		while(arr[negidx1]<0)
			negidx1++;
		while(arr[negidx2]==0)
			negidx2--;
		if(negidx1<negidx2){
			swap(arr[negidx1],arr[negidx2]);
			negidx1++;
			negidx1--;
		}
		
	}


	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";


	return 0;
}

void swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}