#include <stdio.h>

int main(void) {
	int i,j,k;
	for(i=0;i<5;i++){
			k=i;
			for(j=0;j<5;j++){
					if((i+j)==4)
						printf("%d",5-j);
					else if((i+j)>4){
						printf("%d",k);
						k--;
					}
					else
						printf(" ");
			}
			
			k=2;
			for(j=3;j>=0;j--){
					if((i+j)==4)
						printf("%d",5-j);
					else if((i+j)>4){
					printf("%d",k);
					k++;
					}
					else
						printf(" ");
			}
			printf("\n");
	}
	// your code goes here
	return 0;
}
