#include<iostream>
using namespace std;
class employee
{
	
	string name;
	int empno;
	float salary;
public:
	
	//member function declarations
	friend istream& operator>>(istream &cin,employee &s);
	friend ostream& operator<<(ostream& out,employee s);
};
ostream& operator<<(ostream& cout,employee s)
{
	cout<<"employee name is "<<s.name<<endl;
	cout<<"employee number is "<<s.empno<<endl;
	cout<<"employee salary is "<<s.salary<<endl;
}
istream& operator>>(istream &cin,employee &s)
{
	cin>>s.name>>s.empno>>s.salary;
	return cin;
}
int main()
{
	employee e[5];//creating an array of 5 objects
	for(int i=0;i<5;i++)
		cin>>e[i];
	for(int i=0;i<5;i++)
		cout<<e[i]<<endl;
	
	return 0;
}