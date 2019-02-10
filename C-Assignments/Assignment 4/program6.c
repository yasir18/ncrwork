#include<stdio.h>
#include<string.h>
void rev(char *,int,int);
int main(){
	printf("Enter the string \n");
	char s[50];
	scanf("%s",s);
	rev(s,0,strlen(s)-1);
	printf("%s\n",s );
	return 0;
}
void rev(char *p,int low,int high){
	if(low>=high)
		return ;
	char t;
	t=p[low];
	p[low]=p[high];
	p[high]=t;
	low++;
	high--;
	rev(p,low,high);
	return;
}