#include<iostream>
using namespace std;
class Time{
	int hrs,mins,secs;
public:
	Time(){
		hrs=mins=secs=0;
	}
	Time(int hr,int min,int sec){
		hrs=hr;
		mins=min;
		secs=sec;
	}
	void print(){
		cout<<"The time is "<<hrs<<":"<<mins<<":"<<secs<<endl;
	}
	Time add(Time t){
		Time temp;
		temp.secs=(secs+t.secs);
		temp.mins=(mins+t.mins);
		temp.hrs=(hrs+t.hrs);
		if(temp.secs>=60){
			temp.mins++;
			temp.secs=temp.secs%60;
		}
		if(temp.mins>=60){
			temp.hrs++;
			temp.mins=temp.mins%60;
		}
		if(temp.hrs>=24)
			temp.hrs=temp.hrs%24;
		return temp;
	}
};

int main(){
	Time t3;
	cout<<"Enter the time 1:";
	int a,b,c;
	cin>>a>>b>>c;
	Time t1(a,b,c);
	cout<<"Enter the time 2:";
	cin>>a>>b>>c;
	Time t2(a,b,c);
	t3=t1.add(t2);
	t3.print();
	return 0;
}