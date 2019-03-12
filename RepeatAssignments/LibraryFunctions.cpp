//#include "stdafx.h"
#include <iostream>
using namespace std;

#include<cstring>
#include<math.h>
#include<stdlib.h>


string strreverse(string str)
{
	
	int start=0,end=str.length()-1;
	while(start<end)
	{
		char temp=str[start];
		str[start]=str[end];
		str[end]=temp;
		start++;
		end--;
	}
	return str;
}

int strcomp(string s1,string s2) //returns 0 if both are same else returns the ascii difference of the unmatching chars
{
	int s1len=s1.length(),s2len=s2.length();
	int i=0;
	while(i<s1len && i<s2len && s1[i]==s2[i])
	{
		i++;
	}
	if(i==s1len){//string1 is smaller and subset of string2
		return (-(int)s2[i]);
	}
	else if(i==s2len){//string2 is smaller and subset of string1
		return ((int)s1[i]);
	}

	return (s1[i]-s2[i]); 
}

char* strconcat(char *src,char *dest)  //ans is dest+src
{
	int i,j;
	for (i = 0; dest[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
    dest[i+j] = '\0';
   return dest;
}

string strconcatstr(string str1,string str2){
	string result;
	for(int i=0;i<str1.length();i++)
		str2+=str1[i];
	return str2;
}

void strcopy(char *str1,char *str2)  // str1<-str2
{
	int i=0;
	while((str1[i]=str2[i])!='\0')
	i++;
	return ;
}

void strcopystr(string &s1,string &s2){
	s1=s2;
	return;
}

int main()
{
	while(1){
			cout<<"Enter the option\n 1)String compare\n2)string reverse \n3)string copy \n4) String Concat\n5)exit\n";
			int option,retValue,len1,len2;
			cin>>option;
			string str1,str2;

			switch(option){

				case 1:					
					printf("Enter the strings to compare\n");
					cin.ignore();
					getline(cin,str1);
					printf("Enter the strings to compare\n");
					getline(cin,str2);					
					retValue=strcomp(str1,str2);
					if(retValue==0)
						cout<<"Strings are same\n";
					else if(retValue>0)
						cout<<"string 1 is lexographically larger\n";
					else
						cout<<"string 2 is lexographically larger\n";
					break;

				case 2:					
					printf("Enter the strings to reverse\n");
					cin.ignore();
					getline(cin,str1);
					cout<<"The reversed string is "<<strreverse(str1)<<endl;
					break;

				// case 3:
				// 	{
				// 		cout<<"Enter the length of the string which is to be overriden: ";
				// 		cin>>len2;
				// 		cout<<"Enter the string which is to be overriden: ";
				// 		char *str2_c=new char[len2]; //dynamically allocating memory
				// 		scanf("%s",str2_c);

				// 		cout<<"Enter the length of string which is to be copied: ";
				// 		cin>>len1;
				// 		cout<<"Enter string which is to be copied: ";
				// 		char *str1_c=new char[len1]; //dynamically allocating memory
				// 		scanf("%s",str1_c);

				// 		strcopy(str2_c,str1_c); //function call

				// 		cout<<"The overriden string is ";
				// 		printf("%s",str2_c);
				// 		cout<<endl;

				// 		delete(str1_c);  //freeing memory
				// 		delete(str2_c);  //freeing memory
				// 		break;
				// 	}

				 case 3:
				 {
				 		cout<<"Enter the string 1 :";
				 		cin>>str1;
				 		cout<<"Enter the string 2: ";
				 		cin>>str2;
				 		strcopystr(str1,str2);
				 		cout<<"The string1 is now "<<str1<<endl;
				 		break;
				 }
				// case 4:
				// 	{
				// 		cout<<"Enter the length of the string 1: ";
				// 		cin>>len1;
				// 		cout<<"Enter string 1:";
				// 		char *str1_c=new char[len1]; //dynamically allocating memory
				// 		scanf("%s",str1_c);

				// 		cout<<"Enter the length of the string 2: ";
				// 		cin>>len2;
				// 		cout<<"Enter string 2:";
				// 		char *str2_c=new char[len2]; //dynamically allocating memory
				// 		scanf("%s",str2_c);

				// 		char *res=strconcat(str1_c,str2_c); //function call

				// 		printf("The Concatenated string is %s\n",res );

				// 		delete(str1_c);  //freeing memory
				// 		delete(str2_c);	 //freeing memory
				// 		break;
				// 	}

					case 4:{
				  	cout<<"Enter string1 :";
				  	cin>>str1;
				  	cout<<"Enter string 2: ";
				  	cin>>str2;
				  	string result=strconcatstr(str1,str2);
				  	cout<<"Concatenated string is "<<result<<endl;
				  	break;
					 }

				case 5:
					return 0;

				default:
					break;

			}
	}

	 return 0;
}	