#include<iostream>
using namespace std;

class Student{
	string name;
	int rollno,m1,m2,m3,total;
	char grade;
public:
	// string name;
	// int rollno,m1,m2,m3,total;
	// char grade;
	friend ostream& operator<<(ostream& out,Student s);
	friend istream& operator>>(istream& in,Student &s);// it is compulsary to pass reference here
	friend void generate_results(Student[],int );
};
	istream& operator>>(istream& in,Student &s){
		cout<<"Enter the name ";
		in>>s.name;
		//cout<<s.name;
		cout<<"Enter the rollno:";
		in>>s.rollno;
		//cout<<s.rollno;
		cout<<"Enter the marks: ";
		in>>s.m1>>s.m2>>s.m3;
		s.total=s.m1+s.m2+s.m3;
		float avg=s.total/3;
		if(avg>60){
			s.grade='A';
		}
		else if(avg>=50&&avg<=60)
			s.grade='B';
		else if(avg>=40&&avg<=50)
			s.grade='C';
		else
			s.grade='F';
		return in;
	}

	ostream& operator<<(ostream& out,Student s){
		cout<<"The name is : "<<s.name<<"\nrollno: "<<s.rollno;;
		
		out<<"\nthe marks: "<<s.m1<<" "<<s.m2<<" "<<s.m3;
		out<<"\nTotal is:";
		out<<s.total;
		out<<"\n Grade is :";
		out<<s.grade;
		//return out;
	}
	void generate_results(Student s[],int n){
		for(int i=0;i<n;i++){
			cout<<s[i]<<endl;
		}
	}

	int main(){
			Student s[3];
			for(int i=0;i<3;i++)
				cin>>s[i];
			//cin>>s[0]>>s[1]>>s[2];
			//cout<<s;
			generate_results(s,3);
		return 0;
	}