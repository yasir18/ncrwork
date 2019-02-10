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
		printf("%s\n",arr[i] );
	}
	
	for(int i=n-1;i>=0;i--){
		free(arr[i]);
	}

	// //************************************************************************
	// printf("Enter the number of strings:\n");
	// char **p=NULL;
	// int n;
	// scanf("%d",&n);
	// p=(char **)(n*sizeof(char*));
	// if(p==NULL)
	// 	return -1;
	// for(int i=0;i<n;i++){
	// 	char name[50];
	// 	scanf("%s",name);
	// 	int len=strlen(name);
	// 	p[i]=(char *)malloc((len+1)*sizeof(char));
	// 	if(p[i]==NULL){
	// 		for(int j=i-1;j>=0;j--)
	// 			free(p[j]);
	// 		return -1;
	// 	}
	// 	strcpy(p[i],name);
	// }

	// for(int i=0;i<n;i++){
	//  	printf("%s\n",p[i] );
	//  }

	// for(int i=n-1;i>=0;i--){
	// 	free(p[i]);
	// }
	// free(p);

	return 0;
}
