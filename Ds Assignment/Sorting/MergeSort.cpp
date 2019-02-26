#include<iostream>
using namespace std;

void merge(int *,int,int,int);
void MergeSort(int *,int ,int);
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
	MergeSort(arr,low,high);

	cout<<"The sorted list is: \n";
	for(int i=0;i<num;i++){
		cout<<arr[i]<<" ";
	}
	delete (arr);
	return 0;
}

void MergeSort(int *arr,int low,int high){
	if(low>=high)
		return;
	int mid=(low+high)/2;
	MergeSort(arr,low,mid);
	MergeSort(arr,mid+1,high);
	merge(arr,low,mid,high);
}

void merge(int *arr,int low,int mid, int high){
	int ptr1=low,ptr2=mid+1,temp_idx=0;
	int *temp_arr=new int[high-low+1];
    //Merging two sorted lists
	while(ptr1<=mid && ptr2<=high){
		if(arr[ptr1]<arr[ptr2]){
			temp_arr[temp_idx++]=arr[ptr1++];
		}
		else{
			temp_arr[temp_idx++]=arr[ptr2++];
		}
	}
	while(ptr1<=mid)
		temp_arr[temp_idx++]=arr[ptr1++];
	while(ptr2<=high)
		temp_arr[temp_idx++]=arr[ptr2++];
	//Copying temp_arr data into arr
	for(int i=low,j=0;i<=high;i++,j++)
		arr[i]=temp_arr[j];
	//deleting temp_arr memory
	delete(temp_arr);

}