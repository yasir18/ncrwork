 #include<iostream>
#include<string.h>
using namespace std;
template <class t>
class Stack{
	t top;
	t size;
	t *s;
public:
	Stack(){
		top=-1;
		size=0;
		s=NULL;
	}
	Stack(int n){
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
			//cout<<"Pushed successfully\n";
		}
		else
			cout<<"Stack is Full\n";
	}
	t pop(){
		t x=-99;
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
	t x=-99;
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
	string str;
	cout<<"Enter the string :";
	cin>>str;
	//cout<<"Enter the size of Stack: ";
	//cin>>n;
	Stack<char> st(str.length());
	int flag=0;
	for(int i=0;i<str.length();i++){
		char ch=str[i];
		switch(ch){
			case '(':
			case '[':
			case '{':
				st.push(ch);
				break;
			case ')':
			case ']':
			case '}':
				if(!st.IsEmpty()){
					if((ch==')'&&st.peek()=='(')||(ch==']'&&st.peek()=='[')||(ch=='}'&&st.peek()=='{')){
						char temp=st.pop();
					}
				}	
				else{
					flag=1;
					break;
				}
				break;
			default :
			 	break;	
		}
		if(flag)
			break;
	}	
	if(st.IsEmpty()&&flag==0){
		cout<<"matched \n";
	}
	else
		cout<<"UnMatched \n";

		
	return 0;
}