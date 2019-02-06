#include<bits/stdc++.h>
using namespace std;
int main(){
	int num,temp;
	string bin="",hexa="";
	cout<<"Enter the number";
	cin>>num;
	temp=num;
	while(temp>0){
		if(temp&1)
			bin=bin+"1"+'\0';
		else
			bin=bin+"0"+'\0';
		temp=temp>>1;
	}
	reverse(bin.begin(),bin.end());
	cout<<"Binary is "<<bin<<endl;
	temp=num;
	while(temp>0){
		int rem=temp%16;
		if(rem<=9){
			//char c='0'+rem;
			//hexa=hexa+c+'\0';
			hexa+=rem+'0';
		}
		else{
			 switch(rem){
			case 10:
				hexa=hexa+"A"+'\0';
				break;
			case 11:
				hexa=hexa+"B"+'\0';
				break;
			case 12:
				hexa=hexa+"C"+'\0';
				break;
			case 13:
				hexa=hexa+"D"+'\0';
				break;
			case 14:
				hexa=hexa+"E"+'\0';
				break;
			case 15:
				hexa=hexa+"F"+'\0';
				break;				
					
			}
		}
		temp=temp/16;
		
	}
	reverse(hexa.begin(),hexa.end());
	cout<<"Hexa decimal representation is "<<hexa<<endl;
	return 0;
}