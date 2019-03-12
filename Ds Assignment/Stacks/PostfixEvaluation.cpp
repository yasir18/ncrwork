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
	string post;
	cout<<"Enter the delimiter: ";
	cin>>del;
	cout<<"Enter the postfix expression with delimiter after every number:";
	cin>>post;
	char del;
	
	//cout<<"Enter the size of Stack: ";
	//cin>>n;
	Stack<int> st(post.length());
	for(int i=0;i<post.length();i++){
		string snum="";
		char ch=post[i];
		int num,a,b;
		if(ch>='0'&&ch<='9'){
			//snum=ch;
			while( i<post.length() && (post[i]!=del)){
				snum+=post[i++];
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
	
	cout<<"The value of expression is "<<st.pop();
		
	return 0;
}