#include<iostream>
using namespace std;

template<class T>
class CQueue{
	int r;
	int f;
	int size;
	T *cq;
public:
	CQueue(){
		r=f=-1;
		size=0;
		cq=NULL;
	}
	CQueue(int n){
		size=n;
		r=f=-1;
		cq= new T[n];
	}
	void Enqueue(T ele){
		if(!isOverFlow()){
			if(isUnderFlow()){
			r=r+1;
			f=f+1;
			cq[r]=ele;
			}
			else{
				r=(r+1)%size;
				cq[r]=ele;
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
				x=cq[f];
				f=r=-1;
			}
			else{
				
				x=cq[f];
				f=(f+1)%size;
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
		return (f==((r+1)%size));
	}
	void display(){
		int i;
		for(i=f;i!=r;i=(i+1)%size){
			cout<<cq[i]<<" ";
		}
		cout<<cq[i]<<endl;
	}
	~CQueue(){
		delete cq;
	}
};
int main(){
	int n;
	cout<<"Enter the size:";
	cin>>n;
	CQueue<int> cque(n);
	while(1){
		cout<<"Enter the option \n1)Enqueue\n2)Dequeue\n3)isUnderFlow\n4)isOverFlow\n5)display\n6)Exit\n";
		int ch,ele;
		cin>>ch;
		switch(ch){
			case 1:
				cin>>ele;
				cque.Enqueue(ele);
				break;
			case 2:
				ele=cque.Dequeue();
				if(ele!=-99)
				cout<<ele<<" is the popped element";
				break;
			case 3:
				if(cque.isUnderFlow())
					cout<<"Empty\n";
				else
					cout<<"Not Empty\n";
				break;
			case 4:
				if(cque.isOverFlow())
					cout<<"Full\n";
				else
					cout<<"Not Full\n";
				break;
			case 5:
				cque.display();
				break;
			case 6:
				return 0;
			default:
				break; 
					
		}
	}
	return 0;
}