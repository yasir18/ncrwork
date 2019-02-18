#include<iostream>
using namespace std;
class Employee
{
	int x,y;
	string name;
	//public section
	public:
		

		Employee()//default constructor
		{
			cout<<"In default constructor"<<endl;
			string s;
			cout<<"enter the name:";
			cin>>s;
			name=s;
		}
		Employee(int a,int b)//parameterized constructor
		{
			cout<<"in parameterized constructor"<<endl;
			x=a;
			y=b;
			string s;
			cout<<"enter the name:";
			cin>>s;
			name=s;
		}
		Employee(const Employee &b)//copy constructor
		{
			cout<<"in copy constructor"<<endl;
			x=b.x;
			y=b.y;
			//string str;
			name=b.name;
		}
		friend void display_byval(Employee e){// call by value;
			cout<<"Call by value " ;
			cout<<e.name<<endl;
		}

		friend void display_byref(Employee &e){// call by reference;
			cout<<"Call by reference ";
			cout<<e.name<<endl;
		}

		~Employee()//destructor
		{
			cout<<"In destructor of \n"<<endl;
			cout<<name<<endl;
		}
};
// void func()// function to see active objects and deleted objects after the execution of function
// {
	
// }
int main()
{
	//func();
	Employee e1,e2(100,200);
	// displaying sizes of objects
	cout<<sizeof(e1)<<" "<<sizeof(e2)<<endl;
	Employee e3(e2);
	Employee e4=e2; //copy constructor is called
	Employee e5;
	e5=e3;   //normal assignment, nothing is called
	cout<<sizeof(e3)<<endl;
	display_byval(e1);  //copy constructor is called
	display_byref(e1);
	
}