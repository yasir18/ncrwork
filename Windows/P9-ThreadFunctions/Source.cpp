// Write a program to create a child process. Use GetCurrentProcessId, GetCurrentThreadId, 
// GetProcessId, GetThreadId, GetProcessIdOfThread to print process and 
//thread information in each of the process.

#include <Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;

int main()
{

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	WCHAR name[50] = L"calc.exe";

	if (!CreateProcess(NULL, name, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		cout << "Process creation error\n";
		printf("\n the error number is : %d", GetLastError());
		getchar();
		return FALSE;
	}
	printf_s("\n handle of the process is %d ", pi.hProcess);
	printf_s("\n ProcessID of the process is %d ", pi.dwProcessId);

	printf_s("\n using GetProcessId : ProcessId is %d \n", GetProcessId(pi.hProcess));
	printf_s("\n using GetThreadId : ThreadId is %d \n", GetThreadId(pi.hProcess));


	printf_s("\n using GetCurrentProcessId gets processid of calling process(MAIN) \n :  CurrentProcessId is %d \n", GetCurrentProcessId());
	printf_s("\n using GetCurrentThreadId gets handleid of calling process(MAIN) \n :  GetCurrentThreadId is %d \n", GetCurrentThreadId());



	DWORD dwRet = WaitForSingleObject(pi.hProcess, INFINITE);
	printf_s("wait  for single object output %d ", dwRet);
	getchar();

	//system("pause");
	//return(0);
	return 0;
}