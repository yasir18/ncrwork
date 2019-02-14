#include<stdio.h>
#include<string.h>
struct st
{
	int x;
	char y;
};
union un
{
	int x;
	char y;
};
int main()
{
	struct st st1;
	union un un1;
	un1.y='A';
	un1.x=15;
	printf("The size of structure is %d\n",sizeof(st1));
	printf("The size of union is %d\n",sizeof(un1));
	printf("%d %c",un1.x,un1.y);
	
	return 0;
}