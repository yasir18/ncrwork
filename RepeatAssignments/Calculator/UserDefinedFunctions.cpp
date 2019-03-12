
 int getPrecedence(char c);
 string InfixToPostfix(string str);
 double postfixEvaluation(string postfix);
 bool paranthesisCheck(string str);
 bool inputValidation(string line,string &str);
 bool isPostfixValid(string post);

bool inputValidation(string line,string &str){
	int i=0;
	while(i<line.length()){
		if(line[i]==' '){
			cout<<"Please enter the input without any spaces "<<endl;
			return 0;
		}
		else if((line[i]>='a'&&line[i]<='z') || (line[i]>='A'&&line[i]<='Z')){
			cout<<"Alphabets are not allowed "<<endl;
			return 0;
		}
		else if((line[i]>='0' && line[i]<='9')||line[i]=='+'||line[i]=='-'||line[i]=='*'||line[i]=='/'){//used to copy line content to str content leaving spaces
			str+=line[i];
			i++;
		}
		else if(line[i]=='('||line[i]=='['||line[i]==']'||line[i]==')'||line[i]=='{'||line[i]=='}'){//used to copy line content to str content leaving spaces
			str+=line[i];
			i++;
		}
		else if(line[i]=='.'){
			cout<<"Fractional Numbers are not allowed "<<endl;
			return 0;
		}
		else {  //if entered characters are other special symbols
			cout<<"The allowed characters are + , - , * , / ";
			return 0;
		}
		
	}
	if(0==paranthesisCheck(str)){ //if paranthesis are not balanced
		cout<<"Please check the paranthesis "<<endl;
		return 0;
	}	
	return 1;
}

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
		if(ch>='0'&&ch<='9'){  //if digit is encounterd, append it in postfix
			while(  (ch>='0'&&ch<='9')){
				postfix+=ch;
				i++;
				if(i<str.length()) //checking whether i is less than str length
					ch=str[i];
				else
					break;
			}
			if(ch=='('||ch=='['||ch=='{'||ch=='}'||ch=='('||ch=='['){//handling 56(89) like casesS
				//cout<<"Input is invalid";
				return "INVALID";
				
			}
			i--; // inorder not to skip the ith char
			postfix+='@';
		}
		else if(ch=='(' || ch=='[' || ch=='{') //open braces are pushed
			st.push(ch);
		else if(ch==')' || ch==']' || ch=='}'){ //pop all operators till u encountered closing paran
			char op=st.pop();
			char openBrack;
			if(ch==')')
				openBrack='(';
			else if(ch==']')
				openBrack='[';
			else
				openBrack='{';
			while(op!=openBrack){
				postfix+=op;
				op=st.pop();
			}
		}
		else{   //if operator is encountered
			int precedOfCurrent=getPrecedence(ch);
			int precedOfTop;
			if(!st.IsEmpty()){
				precedOfTop=getPrecedence(st.peek());
			}
			while( !st.IsEmpty() && precedOfCurrent<=precedOfTop ){ //pop all elements untill precedofCurrent > precedOfTop
				char op=st.pop();
				precedOfTop=getPrecedence(st.peek());
				postfix+=op;
			}
			st.push(ch); //push current operator
		}
		
	}	
	while(!st.IsEmpty()){
		postfix+=st.pop();
	}
	return postfix;

}


double postfixEvaluation(string postfix){
	Stack<double> st(postfix.length());
	char del='@';
	for(int i=0;i<postfix.length();i++){
		string snum="";
		char ch=postfix[i];
		double num,a,b;
		if(ch>='0'&&ch<='9'){
			//snum=ch;
			while( i<postfix.length() && (postfix[i]!=del)){ //storing digits in string
				snum+=postfix[i++];
			}
			char *char_arr=new char[snum.length()];
			strcpy(char_arr,snum.c_str());
			num=atoi(char_arr);  //converting string to number
			delete (char_arr);
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
			if(a==0){
				cout<<"Divison by 0 not allowed"<<endl;
				return 0;
			}
			st.push(b/a);
		}
		else
			;

	}
	return st.pop();
}

bool paranthesisCheck(string str){
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
			case ')': //corresponding opening paranthesis is popped
			case ']':
			case '}':
				if(!st.IsEmpty()){
					if((ch==')'&&st.peek()=='(')||(ch==']'&&st.peek()=='[')||(ch=='}'&&st.peek()=='{')){
						char temp=st.pop();
					}
				}	
				else{ // stating element in stack cant be closing paran
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
	if(st.IsEmpty()&&flag==0){ //only if stack is empty and flag is not set, paran are balanced
		return 1;
	}
	else
		return 0;
}

 bool isPostfixValid(string post){
 	if(post==""){  //if no input is given
 		cout<<"Input is empty "<<endl;
 		return 0;
 	}
 	int countOfDigits=0,countOfOperators=0,i=0;
 	while(i<post.length()){  //Counting number of operators and numbers
 		if(post[i]=='+'||post[i]=='-'||post[i]=='*'||post[i]=='/')
 			countOfOperators++;
 		else if(post[i]>='0'&&post[i]<='9')
 		{
 			countOfDigits++;
 			while(i<post.length() && (post[i]>='0'&&post[i]<='9')){
 				i++;
 			}
 			i--;
 		}
 		i++;//incrementing iterator
 	}
 	if(countOfDigits==countOfOperators+1){ //In postfix expr, count of numbers are 1 greater then count of oprtrs
 		
 		return 1;
 	}
 	cout<<"Input invalid!"<<endl;
 	return 0;
 }

