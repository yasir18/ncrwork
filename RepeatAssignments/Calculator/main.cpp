#include<iostream>
#include<string>

#include<cstdlib>
#include<string.h>
using namespace std;
#include "Stack.h"
#include "UserDefinedFunctions.cpp"



int main(int argc, char const *argv[])
{
	int n;
	string str,line;
	cout<<"Enter the input without any spaces :";
	getline(cin,line);
	if(inputValidation(line,str)==0){
		return 0;
	}

	string postfix=InfixToPostfix(str);

	//cout<<"The postfix expression is : "<<postfix<<endl;
	if(postfix=="INVALID"){
		cout<<"Input entered is invalid "<<endl;
		return 0;
	}
	if(isPostfixValid(postfix)==0){//if postfix expression is not valid
		return 0;
	}
	double ans=postfixEvaluation(postfix);
	cout<<"Answer is : "<<ans<<endl;	
	return 0;
}

