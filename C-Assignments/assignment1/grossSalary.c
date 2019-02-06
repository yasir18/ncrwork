#include <stdio.h>
int main(void) {
	int userSal;
	float grossSal=0;
	printf("Enter the salary :");
	scanf("%d",&userSal);
	if(userSal<=4000){
		grossSal=userSal*(1+(float)10/100+(float)50/100);
	}
	else if(userSal<=8000)
		grossSal=userSal*(1+(float)20/100+(float)60/100);
	else if(userSal<12000)
		grossSal=userSal*(1+(float)25/100+(float)70/100);
	else	
		grossSal=userSal*(1+(float)30/100+(float)80/100);
	
	printf("Total salary is %g",grossSal);	

	return 0;
}
