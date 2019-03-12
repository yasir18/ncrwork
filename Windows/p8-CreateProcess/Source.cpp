// Write a program to use Create Procees API
#include <Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;

int main() //without cmdline
{
	HANDLE hhProcess;

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	//without cmdline
	//TCHAR *p = TEXT("calc.exe");
	WCHAR name[50] = L"calc.exe";
	//TCHAR path[] = TEXT("C:\\Users\\yasir\\Documents\\Visual Studio 2015\\Projects\\Windows\\p8-CreateProcess\\a.exe");

	if (!CreateProcess(NULL,name , NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		cout << "Process creation error\n";
		printf("\n the error number is : %d", GetLastError());
		getchar();
		return FALSE;
	}
	printf_s("\n handle of the process is %d ", pi.hProcess);
	printf_s("\n ProcessID of the process is %d ", pi.dwProcessId);
	//Sleep(5000);
	DWORD dwRet = WaitForSingleObject(pi.hProcess, 5000);
	cout << GetLastError();
	printf_s("wait  for single object output %d ", dwRet);
	getchar();

	//system("pause");
	//return(0);
	return 0;
}