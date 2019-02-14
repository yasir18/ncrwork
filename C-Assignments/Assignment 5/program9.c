#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char s[60];
	scanf("%[^\n]s",s);
	FILE *fp;
	fp=fopen("file2.txt","w");
	int len=strlen(s),pos;
	for(int i=0;i<len;i++){
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
			char c=(char)(s[i]^32);
			fputc(c,fp);
			pos=ftell(fp);
			fprintf(fp," Current position is %d\n",pos );
		}
		else{
			char c=s[i];
			fputc(c,fp);
			pos=ftell(fp);
			fprintf(fp," Current position is %d\n",pos );
		}
		
	}
	printf("\n\n Changing pointer using fseek \n ");
	int ret=fseek(fp,0,SEEK_SET);
	if(ret==0){
		printf("Now the current position is %d\n",ftell(fp));
	}
	else{
		printf("Please check the offset of fseek");
	}
	
	fclose(fp);
}