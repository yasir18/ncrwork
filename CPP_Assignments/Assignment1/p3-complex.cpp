#include<iostream>
using namespace std;

class Complex{
	int real,img;
	public:
		Complex(){
			real=img=0;
		}
		Complex(int x){
			real=img=x;
		}
		Complex(int x,int y){
			real=x;img=y;
		}
		 void add(Complex &c1,Complex &c2){
			real=c1.real+c2.real;
			img=c1.img+c2.img;
		}
		friend Complex multiply(Complex &,Complex &);
		void display(){
			cout<<real<<"+i("<<img<<")";
		}
};

Complex multiply(Complex &c,Complex &c2 ){
	Complex temp;
	temp.real= c2.real*c.real - c2.img*c.img;
	temp.img= c2.real*c.img + c2.img*c.real;
	return temp;
}

int main(){
	Complex c1,c5,c2(6),c3(8,3),c4;
	c4.add(c2,c3);
	c5=multiply(c2,c3);
	cout<<"Sum is ";
	c4.display();
	cout<<"Product is";
	c5.display();
	return 0;
}