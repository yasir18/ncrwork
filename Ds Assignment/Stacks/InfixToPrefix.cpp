#include<bits/stdc++.h>
#include<string>
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
		//	cout<<"Stack is Empty\n";
		return x;
	}

	~Stack(){
		delete s;
	}
};

int getPrecedence(char c){
	if(c=='+'||c=='-')
		return 2;
	if(c=='*'||c=='/')
		return 3;
	if(c=='('||c=='[')
		return 1;
}

int main(int argc, char const *argv[])
{
	int n;
	string str;
	cout<<"Enter the infix expression :";
	cin>>str;
	reverse(str.begin(),str.end());
	 //a+[b/c-(d*f)]+g-h
	Stack<char> st(str.length());
	string prefix="";

	int flag=0;
	for(int i=0;i<str.length();i++){
		char ch=str[i];
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
			prefix+=ch;
		}
		else if(ch==')')
			st.push(ch);
		else if(ch==']')
			st.push(ch);
		else if(ch=='('){
			char op=st.pop();
			while(op!=')'){
				prefix+=op;
				op=st.pop();
			}
		}
		else if(ch=='['){
			char op=st.pop();
			while(op!=']'){
				prefix+=op;
				op=st.pop();
			}
		}
		else{  
			int preced=getPrecedence(ch);
			int preced2;
			if(!st.IsEmpty()){
				preced2=getPrecedence(st.peek());
			}
			while(preced<preced2 && !st.IsEmpty()  ){
				char op=st.pop();
				preced2=getPrecedence(st.peek());
				prefix+=op;
			}
			st.push(ch);
		}
		//cout<<"\n"<<i<<" "<<prefix<<endl;
	}	
	while(!st.IsEmpty()){
		prefix+=st.pop();
	}
	reverse(prefix.begin(),prefix.end());
	cout<<"The prefix expression is : "<<prefix<<endl;
		
	return 0;
}