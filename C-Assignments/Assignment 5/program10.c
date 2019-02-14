#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list
{
	char country[20];
	char capital[20];
	
}item,item2;

int main(int argc, char const *argv[])
{
	int n;
	FILE *fp,*fp2;
	fp=fopen("CountriesNCapials.dat","w+");

	//printf("Enter the number of countries :\n");
	//scanf("%d",&n);
	//for(int i=0;i<n;i++){
		//char count[20],cap[20];
		//struct list item,item2;
		printf("Enter the country name:");
		scanf("%s",&item.country);
		printf("Enter the capital name:");
		scanf("%s",&item.capital);
		printf("size is %d\n",sizeof(struct list) );
		int fwr=fwrite(&item,sizeof(struct list),1,fp);
		//rewind(fp);
		//int fwr2=fread(&item2,sizeof(struct list),1,fp);
		//printf("%s\n",item.country );
		

		if(fwr!=0)
			printf("Success\n");
		else
			printf("Failure\n");
	//}
	fclose(fp);
	fp=fopen("CountriesNCapials.dat","r");
	int fwr2=fread(&item2,sizeof(struct list),1,fp);

	if(fwr2!=0)
			printf("Success\n");
		else
			printf("Failure\n");

	printf("%s\n",item2.country );
	printf("%s\n",item2.capital );


	fclose(fp2);

	return 0;
}