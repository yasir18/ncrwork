#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int rotate_right(int ,int);
int main() 
{
    int n,b;
    scanf("%d %d",&n,&b);
    int temp=rotate_right(n,b);
    printf("%d",temp);
    return 0;
}

int rotate_right(int n,int b){
	return n>>b;
}