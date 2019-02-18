#include<iostream>
using namespace std;
class distance2;
class distance1
{
	int dis_mtr,dis_cm;
	public:
	distance1()
	{
		dis_mtr=dis_cm=0;
	}
	distance1(int dm,int dcm)
	{
		dis_mtr=dm;
		dis_cm=dcm;
	}	 
	void display()
	{
		cout<<"the result is "<<dis_mtr<<" metre,"<<dis_cm<<" centimetres"<<endl;
	}
	friend distance1 sum1(distance1 &, distance2 &);
	friend distance2 sum2(distance1 &, distance2 &);
};
class distance2
{
	int dis_inch,dis_feet;
	public:
	distance2()
	{
		dis_inch=dis_feet=0;
	}
	distance2(int dfeet,int dinch)
	{
		dis_inch=dinch;
		dis_feet=dfeet;	   
	}
	void display()
	{
		cout<<"the result is "<<dis_feet<<" feet,"<<dis_inch<<" inches"<<endl;
	}
	friend distance1 sum1(distance1 &,distance2 &);
	friend distance2 sum2(distance1 &,distance2 &);
};

distance1 sum1(distance1 &d1,distance2 &d2)
{
	distance1 temp;
	int val=0;
	val+=(d1.dis_m)*100+d1.dis_cm;
	val+=(d2.dis_feet)*30.48+(d2.dis_inch)*2.54;
	cout<<val<<endl;
	temp.dis_m=val/100;
	temp.dis_cm=val%100;
	return temp;
}
distance2 sum2(distance1 &d1,distance2 &d2)
{
	distance2 temp;
	int val=0;
	val+=(d2.dis_feet)*12+d2.dis_inch;
	val+=(d1.dis_m)*39.37+(d1.dis_cm)*0.39;
	cout<<val<<endl;
	temp.dis_feet=val/12;
	temp.dis_inch=val%12;
	return temp;
}
int main()
{
	distance1 d1(1,40);
	distance2 d2(1,6);
	distance1 d3;
	distance2 d4;
	cout<<"enter\n1 for sum in metres\n2 for sum in feets\n";
	int val;
	cin>>val;
	if(val==1)
	{
		d3=sum1(d1,d2);
		d3.display();
	} 
	else if(val==2)
	{
		d4=sum2(d1,d2);
		d4.display();	 
	}
	return 0;
}