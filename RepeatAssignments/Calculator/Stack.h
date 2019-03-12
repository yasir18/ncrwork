// #include<bits/stdc++.h>
// #include<string.h>
// using namespace std;
template <class t>
class Stack{
	int top;
	int size;
	t *s;
public:
	Stack(){  //default constructor
		top=-1;
		size=0;
		s=NULL;
	}
	Stack(int n){ //parameterised constructor
		top=-1;
		size=n;
		s=new t[n];
	}
	bool IsEmpty(){
		return (top==-1);
	}
	bool IsFull(){
		return(top==(size-1));
	}
	void push(t ele){
		if(!IsFull()){
			s[++top]=ele;
		}
		else
			cout<<"Stack is Full\n";
	}
	t pop(){
		t x=(t)-999;
		if(!IsEmpty())
			x=s[top--];
		else
			//cout<<"Stack is Empty\n";
		return x;
	}
	void display(){
		for(int i=0;i<=top;i++)
			cout<<s[i]<<" ";
		cout<<endl;
	}

	int peek(){
	t x=(t)-999;
		if(!IsEmpty())
			x=s[top];
		else
			//cout<<"Stack is Empty\n";
		return x;
	}

   
	~Stack(){ //destructor
		delete s;
	}
};
