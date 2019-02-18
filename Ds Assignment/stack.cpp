#include<iostream>
using namespace std;

class Stack{
	int top;
	int size;
	int *s;
public:
	Stack(){
		top=-1;
		size=0;
		s=NULL;
	}
	Stack(int n){
		top=-1;
		size=n;
		s=new int[n];
	}
	bool IsEmpty(){
		return (top==-1);
	}
	bool IsFull(){
		return(top==(size-1));
	}
	void push(int ele){
		if(!IsFull()){

			s[++top]=ele;
			cout<<"Pushed successfully\n";
		}
		else
			cout<<"Stack is Full\n";
	}
	int pop(){
		int x=-9999;
		if(!IsEmpty())
			x=s[top--];
		else
			cout<<"Stack is Empty\n";
		return x;
	}
	void display(){
		for(int i=0;i<=top;i++)
			cout<<s[i]<<" ";
		cout<<endl;
	}

	int peek(){
	int x=-9999;
		if(!IsEmpty())
			x=s[top];
		else
			cout<<"Stack is Empty\n";
		return x;
	}

	~Stack(){
		delete s;
	}
};

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the size of Stack: ";
	cin>>n;
	Stack st(n);
	while(1){
		cout<<"Enter the option \n1)push\n2)pop\n3)IsEmpty\n4)IsFull\n5)display\n6)Peek\n7)Exit\n";
		int ch,ele;
		cin>>ch;
		switch(ch){
			case 1:
				cin>>ele;
				st.push(ele);
				break;
			case 2:
				ele=st.pop();
				if(ele!=-9999)
				cout<<ele<<" is the popped element";
				break;
			case 3:
				if(st.IsEmpty())
					cout<<"Empty\n";
				else
					cout<<"Not Empty\n";
				break;
			case 4:
				if(st.IsFull())
					cout<<"Full\n";
				else
					cout<<"Not Full\n";
				break;
			case 5:
				st.display();
				break;
			case 6:
				ele=st.peek();
				if(ele!=-9999)
				cout<<ele<<" is the element present at top\n";
				break;
			case 7:
				return 0;
			default:
				break; 
					
		}
	}
	return 0;
}