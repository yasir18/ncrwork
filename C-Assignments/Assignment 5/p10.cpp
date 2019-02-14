// Write a program that will generate a data file containing a list of
// countries and their corresponding capitals. Write interactive code which
// will access the above created data file to perform the following
// operations
// a) Determine the capital of a specified country
// b) Determine the country whose capital is specified
// c) Terminate the programme


#include<iostream>
#include<cstring>
using namespace std;

struct cc
{
	char country[20];
	char city[20];
}c[5],input;

int main()
{

	cout<<"enter the 5 countries and there capital : \n";	
	char co[20];
	char ci[20];
	FILE *fp=fopen("file2.dat","w+");
	if (fp == NULL) 
    { 
        fprintf(stderr, "\nError opend file\n"); 
        exit (1); 
    }
	for(int i=0;i<5;i++)
	{
		cout<<"enter for country and city ["<<i+1<<"] : ";
		cin>>co>>ci;
		strcpy(c[i].country,co);
		strcpy(c[i].city,ci);
		fwrite (&c[i], sizeof(struct cc), 1, fp);
		// if(fwrite != 0)  
  //       	printf("contents to file written successfully !\n"); 
  //   	else 
  //       	printf("error writing file !\n");  
	}
	 fclose (fp);
	

	 FILE *wr=fopen("file2.dat","r"); 
	if (wr == NULL) 
    { 
        fprintf(stderr, "\nError opend file\n"); 
        exit (1); 
    }

    cout<< "-----------table ----------------\n";
    while(fread(&input, sizeof(struct cc), 1, wr)) 
	    {
	    	  printf ("country = %s \t city = %s \n", input.country, input.city);

	    }
	 cout<< "----------------- ----------------\n";   


while(1)
{
    cout<<"enter choice \n 1. to search country's capital \n 2. to search capital of country\n 3. exit \n: input :";
    int n; cin>>n;
    if(n==1)
    {
    	char s[20]; 
    	cout<<"enter country: "; cin>>s;
    	int flag=0;

    	fseek(wr,0,SEEK_SET);
	    while(fread(&input, sizeof(struct cc), 1, wr)) 
	    {
	    	  // printf ("country = %s city = %s \n", input.country, input.city);
	    	if(strcmp(s,input.country)==0)
	    	{
	    		flag=1;
	    		cout<<"\n found capital ="<<input.city<<endl;
	    	}
	    }
	    if(flag==0)
	    	cout<<" not found \n";
    }
    else if(n==2)
    {
    	char s[20]; 
    	cout<<"enter capital: "; cin>>s;
    	int flag=0;
    	
    	fseek(wr,0,SEEK_SET);
	    while(fread(&input, sizeof(struct cc), 1, wr)) 
	    {
	    	if(strcmp(s,input.city)==0)
	    	{
	    		flag=1;
	    		cout<<"\n found capital ="<<input.country<<endl;
	    	}
	    }
	    if(flag==0)
	    	cout<<" not found \n";

    }
    else
    {
    	cout<<"exit"<<endl;
    	exit(0);
    }
 }     
  
    // close file 
    fclose (wr); 


	return 0;
}