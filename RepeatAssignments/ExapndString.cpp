#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;
bool inputValidation(string line,int &);

void expand(string s1,char *);


int main(){
	string lineInputString;
	printf("Enter the string without any spaces \n");
	getline(cin,lineInputString);
	int memoryReqd=0;
	if(inputValidation(lineInputString,memoryReqd)==0){
		  return 0;
	}
	//cout<<"memory reqd is  "<<memoryReqd<<endl;
	char *string2=new char[memoryReqd+1];
	expand(lineInputString,string2);
	printf("The expanded string is %s\n",string2 );
	delete(string2);
	return 0;
}



bool inputValidation(string line,int &memory){
	int idx=0;
	while(idx<line.length()){


		if(line[idx]==' '){
			cout<<"Spaces are not allowed in the input \n";
			return 0;
		}


		if(line[idx]=='-'){

				if( (idx==0)){// used '-' at start of the string
					cout<<"Correct usage of expand is 'operand-operand'"<<endl;
					return 0;
				}

				else if( (idx==line.length()-1)){// used '-' at end of the string
					cout<<"Correct usage of expand is 'operand-operand'"<<endl;
					return 0;
				}

				else if(( (idx+1)<line.length() ) && (line[idx+1]=='-')){ //handle a--b case
					cout<<"Correct usage of expand is 'operand-operand'"<<endl;
					return 0;
				}

				else{             //checking the feasability of the expand operation

						char leftChar=line[idx-1],rightChar=line[idx+1];

						if((!isalpha(leftChar) && !isdigit(leftChar)) || (!isalpha(rightChar) && !isdigit(rightChar)) ){
							cout<<"The operands around '-' should be either digits or alphabets only!"<<endl;
							return 0;
						}

						else if( (isalpha(leftChar) && isdigit(rightChar)) || (isdigit(leftChar) && isalpha(rightChar)) ){//both oprnd shud be of same type
							cout<<"Both the operands around '-' should be either digits or alphabets "<<endl;
							return 0;
						}

						else if( isalpha(leftChar) && isalpha(rightChar) ){ //Handling alphabets expansion
							if((leftChar>='a'&& leftChar<='z') && (rightChar>='A'&& rightChar<='Z')  || 
								(leftChar>='A'&& leftChar<='Z') && (rightChar>='a'&& rightChar<='z')  )
							{
								cout<<"Both the operands should either be Caps or Noncaps"<<endl;
								return 0;
							}
							else{   
								if(leftChar > rightChar){
									cout<<"Left operand should be lesser than right operand"<<endl;
									return 0;
								}
							}

						}

						else if( isdigit(leftChar) && isdigit(rightChar)){ //handling digits expansion
								if(leftChar > rightChar){
									cout<<"Left operand should be lesser than right operand"<<endl;
									return 0;
								}
						}

						 //adding memeory required for storing op-op

						memory+=(int)rightChar-(int)leftChar-1;
						
						
				    }

		}
		else{ //incrementing memory for each character
			memory++;
		}
		
		idx++;

	}

	return 1;

}


void expand(string s1,char *s2){

	int length=s1.length(),indexOfS2=-1,p1,p2;
	for(int itr=0;itr<length;itr++){
		if(s1[itr]=='-'){
			p1=itr-1;
			p2=itr+1;
			int diff=s1[p2]-s1[p1]-1;
			if(-1==diff){ //case 5-5
				itr++;
				continue;
			}
			int iterator=1;
			while(iterator<=diff){
				s2[++indexOfS2]=s1[itr-1]+iterator;
				iterator++;
			}
			
		}
		else{
			s2[++indexOfS2]=s1[itr];
		}
	}
	s2[++indexOfS2]='\0';
}

