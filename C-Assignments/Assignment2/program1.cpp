#include <iostream>
#include<cstring>
#include<math.h>
using namespace std;
 
int main()
{
    int choice;
    cout<<"Enter the choice\n1)binToDec\n2)DecToBin\n";
    cin>>choice;
    if(choice==1){
            char s[32];
            printf("Enter a binary number(1s and 0s) \n");
            scanf("%s", s); 

            int l=strlen(s);
            cout<<"length ="<<l<<" "<<endl;

            int n=0;
            for(int i=l-1;i>=0;i--)
            {
                if(s[i]=='1')
                {
                    n+= pow(2,l-1-i);
                }
            }

            printf("The Binary number is = %s \n", s);
            printf("Its decimal equivalent is = %d \n", n);
    }
    else{
        
        printf("Enter the decimal number\n");
        int num,k; 
        cin>>num;
        k=num;
        int bl=log2(k)+1;  cout<<bl<<endl;
        char bs[bl+1];
        for(int i=bl-1;i>=0;i--)
        {
            if( (k) & 1)
                bs[i]='1';
            else
                bs[i]='0';
            k=k>>1;
        }
        bs[bl]='\0';
        printf("Its decimal equivalent is = %d \n", num);
         printf("The Binary number is = %s \n", bs);
    }
    

  
    

    

    system("pause");
}