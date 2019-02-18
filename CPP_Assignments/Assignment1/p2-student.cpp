#include<bits/stdc++.h>
using namespace std;

class Student{
	char *studentName;
	char *grade;
	int marks1,marks2,marks3;
public:
	void set_Data(char *studentname,int a,int b,int c){
		int len=strlen(studentname);
		studentName=(char*)malloc((len+1)*sizeof(char));
		strcpy(studentName,studentname);
		marks1=a;
		marks2=b;
		marks3=c;

	}

	float average(){
		float ans;
		ans=((float)marks1+marks2+marks3)/((float)3);
		return ans;
	}

	void ComputeGrade(){
		float avg=this->average();
		if(avg>60){
			grade="First";
		}
		else if(avg>=50&&avg<=60)
			grade="Second";
		else if(avg>=40&&avg<=50)
			grade="Third";
		else
			grade="Fail";
	}
	void display(){
		cout<<"Student name is "<<studentName<<"\nMarks1="<<marks1<<"\nMarks2="<<marks2<<"\nMarks3="<<marks3;
		cout<<"Grade is "<<grade;
	}
};
int main(){
	Student s1;
	char name[20];
	int m1,m2,m3;
	cout<<"Enter the name ";
	cin>>name;
	cout<<"Enter the marks: ";
	cin>>m1>>m2>>m3;
	s1.set_Data(name,m1,m2,m3);
	float avg=s1.average();
	s1.ComputeGrade();
	s1.display();
	cout<<"Average is "<<avg;
	return 0;

}
