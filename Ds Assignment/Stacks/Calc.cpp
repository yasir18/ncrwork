 #include<bits/stdc++.h>
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
		}
		else
			cout<<"Stack is Full\n";
	}
	t pop(){
		t x=(t)-99;
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
	t x=(t)-99;
		if(!IsEmpty())
			x=s[top];
		else
			cout<<"Stack is Empty\n";
		return x;
	}

	//string InfixToPostfix(string str);

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

string InfixToPostfix(string str){
	Stack<char> st(str.length());
	string postfix="";

	int flag=0;
	for(int i=0;i<str.length();i++){
		char ch=str[i];
		if(ch>='0'&&ch<='9'){
			while(  (ch>='0'&&ch<='9')){
				postfix+=ch;
				i++;
				if(i<str.length())
					ch=str[i];
				else
					break;
			}
			i--;
			postfix+='@';
		}
		else if(ch=='(')
			st.push(ch);
		else if(ch=='[')
			st.push(ch);
		else if(ch==')'){
			char op=st.pop();
			while(op!='('){
				postfix+=op;
				op=st.pop();
			}
		}
		else if(ch==']'){
			char op=st.pop();
			while(op!='['){
				postfix+=op;
				op=st.pop();
			}
		}
		else{  
			int precedOfCurrent=getPrecedence(ch);
			int precedOfTop;
			if(!st.IsEmpty()){
				precedOfTop=getPrecedence(st.peek());
			}
			while( !st.IsEmpty() && precedOfCurrent<=precedOfTop ){
				char op=st.pop();
				precedOfTop=getPrecedence(st.peek());
				postfix+=op;
			}
			st.push(ch);
		}
		
	}	
	while(!st.IsEmpty()){
		postfix+=st.pop();
	}
	return postfix;

}


long long postfixEvaluation(string postfix){
	Stack<long long> st(postfix.length());
	char del='@';
	for(int i=0;i<postfix.length();i++){
		string snum="";
		char ch=postfix[i];
		long long num,a,b;
		if(ch>='0'&&ch<='9'){
			//snum=ch;
			while( i<postfix.length() && (postfix[i]!=del)){
				snum+=postfix[i++];
			}
			char char_arr[snum.length()];
			strcpy(char_arr,snum.c_str());
			num=atoi(char_arr);
			//cout<<num;
			st.push(num);
		}
		else if(ch=='+'){
			a=st.pop();
			b=st.pop();
			st.push(b+a);
		}
		else if(ch=='-'){
			a=st.pop();
			b=st.pop();
			st.push(b-a);
		}
		else if(ch=='*'){
			a=st.pop();
			b=st.pop();
			st.push(b*a);
		}
		else if(ch=='/'){
			a=st.pop();
			b=st.pop();
			st.push(b/a);
		}
		else
			;

	}
	return st.pop();
}
int main(int argc, char const *argv[])
{
	int n;
	string str;
	cout<<"Enter the input without any spaces :";
	cin>>str;
	
	
	string postfix=InfixToPostfix(str);
	cout<<"The postfix expression is : "<<postfix<<endl;
	

	long long ans=postfixEvaluation(postfix);
	cout<<"Answer is : "<<ans<<endl;	
	return 0;
}