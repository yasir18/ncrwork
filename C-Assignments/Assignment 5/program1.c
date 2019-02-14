#include<stdio.h>
struct time{
	int hrs;
	int min;
	int sec;
};
int main(){
	struct time value;
	printf("Enter the hrs mins and seconds :");
	scanf("%d %d %d",&value.hrs,&value.min,&value.sec);
	printf("Entered time is %d:%d:%d\n",value.hrs,value.min,value.sec );
	return 0;
}