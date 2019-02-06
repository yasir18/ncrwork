#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int num=-1,numOfDigits=0,temp,sum;
    printf("Enter the number:");
    scanf("%d",&num);
    temp=num;
    while(temp>0){
        temp=temp/10;
        numOfDigits++;
    }

    temp=num;
    while(temp>0){       
        sum+=pow(temp%10,numOfDigits);
        temp/=10;
    }

    if(sum==num)
        printf("%d is an amstromg number",num);
    else
        printf("%d is not an amstromg number",num);

        return 0;
}