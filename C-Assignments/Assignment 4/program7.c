#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
 
	
	printf("Enter the number of strings :\n");
	int n;
	scanf("%d",&n);
	char *arr[n];
	for(int i=0;i<n;i++){
		
		char name[50];
		//printf("Enter the string :");
		scanf("%s",name);
		int len=strlen(name);
		arr[i]=(char *)malloc((len+1)*sizeof(char));
		if(arr[i]==NULL){
			for(int j=i-1;j>=0;j--)
				free(arr[j]);
			return -1;
		}
		strcpy(arr[i],name);

	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(strcmp(arr[j],arr[j+1])>0){
				char *p;
				p=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=p;
				// char s[50];
				// strcpy(s,arr[j]);
				// strcpy(arr[j],arr[j+1]);
				// strcpy(arr[j+1],s);
			}
		}
	}

	printf("The sorted strings are:\n");
	for(int i=0;i<n;i++){
		printf("%s\n",arr[i] );
	}
	
	for(int i=n-1;i>=0;i--){
		free(arr[i]);
	}

	return 0;
}
