#include <stdio.h>
#include "addition.c"
#include "subtraction.c"
#include "divison.c"
#include "multiplication.c"
extern int addition(int a,int b);
extern int subtraction(int a,int b);
extern int multiplication(int a,int b);
extern int division(int a,int b);

int main()
{
    int option,op1,op2;
    printf("Choose among the options \n");
    printf("1.ADD 2.SUBTRACT 3.MULTIPLICATION 4.DIVISION \n");
    scanf("%d",&option);
    printf("Enter the operands \n");
    scanf("%d %d",&op1,&op2);
    switch (option){
        case 1:
        printf("Sum is %d",addition(op1,op2));
        break;
        case 2:
        printf("Difference is %d",subtraction(op1,op2));
        break;
        case 3:
        printf("product is  is %d",multiplication(op1,op2));
        break;
        case 4:
        printf("divison is %d",division(op1,op2));
        break;
    }
    
   
    

    return 0;
}