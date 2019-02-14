#include<stdio.h>
#define makestr(s) #s  //stringizing operator = makes s as a quoted string
#define print(a,b)  a##b //concatenation operator

#define MAC 0
#define TEST 0
int main()
{
	int ab=1000;
	#ifdef MAC
		#if TEST==0
			printf("the value of %s is %d\n",makestr(ab),print (a,b));
		#else
			printf("TEST is not defined\n");
		#endif
	#endif	

	return 0;
}

// #ifdef MACRO
//     controlled text
// #endif