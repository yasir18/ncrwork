#include <Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;

int main()
{

	HANDLE hevent = CreateEvent(
		NULL,
		FALSE,
		FALSE,
		TEXT("myEvent")
	);


	system("pause");
	return 0;
}