#include<stdio.h>
int mask(int ,int,int);
int bits(int,int, int);
int main(){
	int hexa,option,flag=0;
	int Compliment;
	printf("Enter the hexa decimal number\n");
	scanf("%x",&hexa);
	while(1){
		printf("Enter the option\n");
		printf("1)Complement of hexa\n2)masking oprtn\n3)Bit shifting\n4)Exit\n");
		scanf("%d",&option);
		switch(option){
			case 1:
				Compliment=~hexa;
				printf("Compliment is %X\n",Compliment );
				break;
			case 2:
				printf("Enter the masking type \n 1)and\n2)xor\n3)or\n");
				int mtype,mhexa,mAns;
				scanf("%d",&mtype);
				printf("Enter the value to mask\n");
				scanf("%x",&mhexa);
				mAns=mask(hexa,mhexa,mtype);
				printf("masking operation is %X\n",mAns );
				break;
			case 3:
				printf("Enter the shifting option\n1)left to right\n2)right to left\n");
				int bShift,numOfBits,bAns;
				scanf("%d",&bShift);
				printf("Enter the number of bits to shift\n");	
				scanf("%d",&numOfBits);
				bAns=bits(hexa,bShift,numOfBits);
				printf("Bit shifting operation is %X\n",bAns);
				break;
			case 4:
				flag=1;
				break;
		}
		if(flag)
			break;
	}
}
int mask(int hexa,int mhexa,int type){
	int ans;
	if(type==1){
		ans=hexa&mhexa;
	}
	else if(type==2){
		ans=hexa|mhexa;
	}
	else{
		ans=hexa^mhexa;
	}
	return ans;
}
int bits(int hexa,int bShift,int num){
	int ans;
	if(bShift==1){
		ans=hexa>>num;
	}
	else{
		ans=hexa<<num;
	}
	return ans;
}