#include<iostream>
using namespace std;

int main(){
	int num;
	cout<<"Enter the count of numbers";
	cin>>num;
	int *arr=new int [num];
	cout<<"Enter the numbers: ";
	for(int i=0;i<num;i++){
		cin>>arr[i];
	}

	//sorting logic
	int temp,min_idx;
	for(int i=0;i<num;i++){
		min_idx=i;
		for(int j=i+1;j<num;j++){
			if(arr[j]<arr[min_idx])
				min_idx=j;
		}	
			if(arr[i]>arr[min_idx]){
				temp=arr[i];
				arr[i]=arr[min_idx];
				arr[min_idx]=temp;
			}
	}

	cout<<"The sorted list is: \n";
	for(int i=0;i<num;i++){
		cout<<arr[i]<<" ";
	}
	delete(arr);
	return 0;
}