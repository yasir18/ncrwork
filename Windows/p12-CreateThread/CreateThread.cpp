#include <Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;

DWORD WINAPI thread_func(LPVOID param)
{
	int i = 0;
	char* p[] = { "hi","yasir","affan" };
	for (i = 0; i < 3; i++)
	{
		printf(" %s", p[i]);
		Sleep(1000);
	}
	return 0;
}
int main()
{
	DWORD thID1, thID2;
	HANDLE hThread1, hThread2;
	HANDLE harray[2];
	hThread1 = CreateThread(
		NULL, //default security attributes
		0, // default stak size
		thread_func, //callback thread function 
		NULL,
		0,
		&thID1);
	hThread2 = CreateThread(
		NULL, //default security attributes
		0, // default stak size
		thread_func, //callback thread function 
		NULL,//parameter to callback
		0,//creation flag
		&thID2);//Thread ID
	if (hThread1 == NULL)
	{
		printf("unable to create thread \n");
		getchar();
		return 0;
	}
	CloseHandle(hThread1);
	getchar();

	system("pause");
	return 0;
}