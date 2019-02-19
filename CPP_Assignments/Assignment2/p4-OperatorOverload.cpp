#include<iostream>
using namespace std;
class complex
{
	
	public://public section
		int real,imag;
		complex()//default constructor
		{
		}
		complex(int r,int i)//parameterized constructor
		{
			real=r;
			imag=i;
		}
		complex(const complex &c)//copy constructor
		{
			real=c.real;
			imag=c.imag;
		}
		~complex()//destructor
		{
		}
		complex operator+(complex a);
		complex operator-(complex a);
		complex operator-();
		complex operator++();
		complex operator++(int x);
		complex operator=(complex b);
		complex operator,(complex b);
		complex& operator[](int index);
		friend ostream& operator<<(ostream& out,complex a);
		friend istream& operator>>(istream& cin,complex &a);
		complex operator->();
};
complex complex::operator+(complex a)
{
	complex res;
	res.real=a.real+real;
	res.imag=a.imag+imag;
	return res;
}
complex complex::operator-(complex a)
{
	complex res;
	res.real=a.real-real;
	res.imag=a.imag-imag;
	return res;
}
complex complex::operator-()
{
	return complex(-real,-imag);
}
complex complex::operator++()
{
	complex res;
	res.real=++real;
	res.imag=++imag;
	return res;
}
complex complex::operator++(int x)
{
	complex res;
	res.real=real;
	res.imag=imag;
	real++;
	imag++;
	return res;
}
complex complex::operator=(complex b)
{
	//cout<<"here";
	real=b.real;
	imag=b.imag;
	return *this;
}
complex complex::operator,(complex b)
{
	return b;
}
complex& complex::operator[](int index)
{
	//cout<<"overloaded \n";
	return *this;
}
ostream& operator<<(ostream& out,complex a)
{
	out<<"real = "<<a.real<<endl;
	out<<"imaginary value = "<<a.imag<<endl;
	return out;
}
istream& operator>>(istream& cin,complex &a)
{
	cout<<"real: ";
	cin>>a.real;
	cout<<"img: ";
	cin>>a.imag;
	return cin;
}
complex complex::operator->()
{
	return *this;
}
int main()
{
	complex samp,arr[3],a1,a2,a3,a4,*ptr;
	for(int i=0;i<3;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<3;i++)
		cout<<arr[i];
	ptr=&arr[0];
	a1=arr[0]+arr[1];
	cout<<"a1 "<<a1<<endl;
	a2=-arr[1];
	cout<<" a2 "<<a2<<endl;
	a3=arr[0];
	//a3=arr[0]++;
	a4=++arr[1];
	cout<<" a4 ";
	cout<<a4<<endl;
	cout<<a3<<endl<<endl;
	samp=(a1,a2,a3);
	cout<<samp<<endl;
	for(int i=0;i<3;i++)
		cout<<arr[i];
	cout<<ptr->real<<endl;
	// to stop console from closing
	system("pause");
	return 0;
}