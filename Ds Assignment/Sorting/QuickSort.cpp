#include<iostream>
using namespace std;

int partition(int *,int,int);
void QuickSort(int *,int,int );
void swap(int &x,int &y){
	int temp;
	temp=x;
	x=y;
	y=temp;
}
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
	int low=0,high=num-1;
	QuickSort(arr,low,high);

	cout<<"The sorted list is: \n";
	for(int i=0;i<num;i++){
		cout<<arr[i]<<" ";
	}
	delete (arr);
	return 0;
}

void QuickSort(int *arr,int low,int high){
	if(low>=high)
		return;
	int pivot=partition(arr,low,high);
	QuickSort(arr,low,pivot-1);
	QuickSort(arr,pivot+1,high);
}

int partition(int *arr,int low,int high){
	int pivot=arr[high];
	int low_idx=low-1;
	for(int i=low;i<high;i++){
		if(arr[i]<pivot){
			//swapping arr[i] and arr[low_idx]
			low_idx++;
			swap(arr[i],arr[low_idx]);
		}
	}
	low_idx++;
	swap(arr[high],arr[low_idx]);
	return low_idx;
}