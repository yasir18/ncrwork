#include<stdio.h>
#include<string.h>
void expand(char s1[],char s2[]){

	int l=strlen(s1),k=0,p1,p2;
	for(int i=0;i<l;i++){
		if(s1[i]=='-'){
			p1=i-1;
			p2=i+1;
			char c=s1[p1];
			while(c!=s1[p2]){
				s2[k++]=c+1;
				c=c+1;
			}
			k--;
		}
		else{
			s2[k++]=s1[i];
		}
	}
	s2[k]='\0';
}
int main(){
	char s1[30],s2[100];
	printf("Enter the string to be expanded\n");
	scanf("%s",s1);
	
	expand(s1,s2);
	printf("The new string is %s\n",s2 );
	return 0;
}
