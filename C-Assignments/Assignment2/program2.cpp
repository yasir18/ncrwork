#include<bits/stdc++.h>
using namespace std;
 int main()
{

    int choice;
    cout<<"Enter the choice\n1)binToHexa\n2)hexaToBin\n";
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
            char h[10];
            int i=0;
            while (n>0) {
                int r = n % 16;
                h[i++] = (r < 10) ? (r + '0') : (r - 10 + 'A');
                n = n / 16;
            }
            h[i] = '\0';
            reverse(h,h+i);
            printf(" hexadecimal number  is : %s \n",h);
            printf("\n");
    }
    else{
             printf("Enter Hexadecimal value in the form of string\n");
            char hex[10];
            scanf("%s",hex);

            for(int i=0;i<strlen(hex);i++)
            {
                switch(hex[i])
                {
                    case '0':
                    printf("0000");
                    break;
                    case '1':
                    printf("0001");
                    break;
                    case '2':
                    printf("0010");
                    break;
                    case '3':
                    printf("0011");
                    break;
                    case '4':
                    printf("0100");
                    break;
                    case '5':
                    printf("0101");
                    break;
                    case '6':
                    printf("0110");
                    break;
                    case '7':
                    printf("0111");
                    break;
                    case '8':
                    printf("1000");
                    break;
                    case '9':
                    printf("1001");
                    break;

                    case 'A':
                    case 'a':
                    printf("1010");
                    break;

                    case 'B':
                    case 'b':
                    printf("1011");
                    break;

                    case 'c':
                    case 'C':
                    printf("1100");
                    break;

                    case 'D':
                    case 'd':
                    printf("1101");
                    break;

                    case 'e':
                    case 'E':
                    printf("1110");
                    break;

                    case 'f':
                    case 'F':
                    printf("1111");
                    break;

                    default:
                    printf("invalid input for hexadecimal number \n");
                     return -1;
                }
            }
    }

    printf("\n");	
	 system("pause");
	 return 0;
}