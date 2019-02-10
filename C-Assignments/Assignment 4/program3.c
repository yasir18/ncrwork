#include<stdio.h>
#include<string.h>

int main(){

	char * s [ ] = {
					"we will teach you how to " ,
					"Move a mountain " ,
					"Level a building " ,
					"Erase the past ",
					"Make a million " };
					
	int count=0,len;
	for(int i=0;i<5;i++){
		len=strlen(s[i]);
		for(int j=0;j<len;j++){
			if(s[i][j]=='e')
				count++;
		}
	}				

	printf("Number of e's in the aray are %d\n",count );

	return 0;
}