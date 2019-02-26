#include<iostream>
using namespace std;

void Heapify(int *arr,int idx,int num ){
	int large=idx;
	int left=2*idx+1;
	int right=2*idx+2;
	if(left<num && arr[left]>=arr[large] )
		large=left;
	if(right<num && arr[right]>=arr[large])
		large=right;
	if(large!=idx){
		swap(arr[idx],arr[large]);
		Heapify(arr,large,num);
	}
}


void HeapSort(int *arr,int num){
	for(int i=num/2-1;i>=0;i--){
		Heapify(arr,i,num);
	}

	for(int i=num-1;i>=0;i--){
		swap(arr[i],arr[0]);
		Heapify(arr,0,i);
	}

}


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
	
	HeapSort(arr,num);

	cout<<"The sorted list is: \n";
	for(int i=0;i<num;i++){
		cout<<arr[i]<<" ";
	}
	delete (arr);
	return 0;
}
