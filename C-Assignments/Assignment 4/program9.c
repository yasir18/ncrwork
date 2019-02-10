#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int search(char a[],char b[]){
	int index;
	for(int i=0;i<strlen(a);i++){
		if(a[i]==b[0]){
			int j;
			index=i;
			for(j=0;j<strlen(b)&&i<strlen(a);i++,j++){
				if(a[i]!=b[j])
					break;
			}
			if(j==strlen(b))
				return index;
		}
	}
}
int main(){
	char s1[100],s2[40];
	printf("Enter the strings in s1:\n");
	scanf("%[^\n]s",s1);
	printf("Enter the string to be searched\n");
	scanf("%s",s2);

	int idx=search(s1,s2);
	if(idx==-1)
		printf("Not found\n");
	else
		printf("Found at index %d\n",idx );

	return 0;
}