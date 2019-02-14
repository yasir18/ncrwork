#include<stdio.h>
#include<string.h>
struct complex{
	float real,img;
};

enum operations{Addition=1,Subtraction,Multiplication,Division};

struct complex add(struct complex a,struct complex b){
	//printf("sadasd\n");
	struct complex res;
	res.real=a.real+b.real;
	res.img=a.img+b.img;
	
	return res;
}

struct complex sub(struct complex a,struct complex b){
	struct complex res;
	res.real=a.real-b.real;
	res.img=a.img-b.img;
	return res;
}
struct complex mul(struct complex a,struct complex b){
	struct complex res;
	res.real=a.real*b.real-(a.img*b.img);
	res.img=a.real*b.img+a.img*b.real;
	return res;
}

struct complex div(struct complex a,struct complex b){
	struct complex res;
	float x=a.real*b.real+(a.img*b.img);
	float y=a.img*b.real-a.real*b.img;
	float deno=b.real*b.real+b.img*b.img;
	res.real=x/deno;
	res.img=y/deno;
	return res;
}

void print(struct complex res){
	printf("The result is %f +i(%f)",res.real,res.img);
}


int main(){
	struct complex c1,c2,result;
	printf("Enter the real and imag part of complex number 1 :");
	scanf("%f %f",&c1.real,&c1.img);
	printf("Enter the real and imag part of complex number 2 :");
	scanf("%f %f",&c2.real,&c2.img);
	printf("%f %f\n",c2.real,c2.img );
	printf("Enter the operation \n1)Addition\n2)Subtraction\n3)Multiplication\n4)Division\n");
	char choice[15];
	enum operations op;
	int ch;
	scanf("%d",&ch);
	// printf("%d",Addition);
	// scanf("%s",choice);
	// if(strcmp("Addition",choice)==0)
	// 	op=Addition;
	// if(strcmp("Subtraction",choice)==0)
	// 	op=Subtraction;
	// if(strcmp("Multiplication",choice)==0)
	// 	op=Multiplication;
	// if(strcmp("Division",choice)==0)
	// 	op=Division;
	//printf("%d\n",op );
	switch(ch){
		case Addition:
			result=add(c1,c2);
			print(result);
			break;
		case Subtraction:
			result=sub(c1,c2);
			print(result);
			break;
		case Multiplication:
			result=mul(c1,c2);
			print(result);
			break;
		case Division:
			result=div(c1,c2);
			print(result);
			break;			

	}

}