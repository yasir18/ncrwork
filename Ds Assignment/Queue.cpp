#include<iostream>
using namespace std;

template<class T>
class Queue{
	int r;
	int f;
	int size;
	T *q;
public:
	Queue(){
		r=f=-1;
		size=0;
		q=NULL;
	}
	Queue(int n){
		size=n;
		r=f=-1;
		q= new T[n];
	}
	void Enqueue(T ele){
		if(!isOverFlow()){
			if(isUnderFlow()){
			r=r+1;
			f=f+1;
			q[r]=ele;
			}
			else{
				q[++r]=ele;
			}
		}
		else{
			cout<<"Queue is Full\n";
		}		
	}
	T Dequeue(){
		T x=(T)-99;
		if(!isUnderFlow()){
			if(f==r){
				x=q[f];
				f=r=-1;
			}
			else{
				x=q[f++];
			}
			return x;
		}
		else{
			cout<<"Queue is Empty\n";
			return x;
		}
	}
	bool isUnderFlow(){
		if(r==f && r==-1)
			return true;
		return false;
	}
	bool isOverFlow(){
		return (r==(size-1));
	}
	void display(){
		int i;
		if(!isUnderFlow()){
			for(i=f;i<=r;i++){
			cout<<q[i]<<" ";
			}	
		}
		else{
			cout<<"Empty\n";
		}
		
		
	}
	~Queue(){
		delete q;
	}
};
int main(){
	int n;
	cout<<"Enter the size:";
	cin>>n;
	Queue<int> que(n);
	while(1){
		cout<<"Enter the option \n1)Enqueue\n2)Dequeue\n3)isUnderFlow\n4)isOverFlow\n5)display\n6)Exit\n";
		int ch,ele;
		cin>>ch;
		switch(ch){
			case 1:
				cin>>ele;
				que.Enqueue(ele);
				break;
			case 2:
				ele=que.Dequeue();
				if(ele!=-99)
				cout<<ele<<" is the popped element";
				break;
			case 3:
				if(que.isUnderFlow())
					cout<<"Empty\n";
				else
					cout<<"Not Empty\n";
				break;
			case 4:
				if(que.isOverFlow())
					cout<<"Full\n";
				else
					cout<<"Not Full\n";
				break;
			case 5:
				que.display();
				break;
			case 6:
				return 0;
			default:
				break; 
					
		}
	}
	return 0;
}