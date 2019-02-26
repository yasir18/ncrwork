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
	int temp,curr_ele,j;
	for(int i=1;i<num;i++){
		j=i-1;
		curr_ele=arr[i];
		while(arr[i]<arr[j] && j!=-1){			
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=curr_ele;
	}

	cout<<"The sorted list is: \n";
	for(int i=0;i<num;i++){
		cout<<arr[i]<<" ";
	}
	delete(arr);
	return 0;
}