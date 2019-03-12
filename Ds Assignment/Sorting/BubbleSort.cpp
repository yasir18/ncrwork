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
	int temp;
	for(int i=0;i<num;i++){
		for(int j=0;j<num-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

	cout<<"The sorted list is: \n";
	for(int i=0;i<num;i++){
		cout<<arr[i]<<" ";
	}
	delete (arr);
	return 0;
}
