// Write a program which uses the API “CreateProcess” to create two child processes (say calc.exe and
// notepad.exe).Print handle and process Id of each child process.
#include <Windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;

//int  main()
int _tmain(int argc, TCHAR *argv[], TCHAR *env[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	HANDLE harray[2];
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (argc != 3)
	{
		cout << "no of arguments no given \n";
		getchar();
		return 0;
	}
	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		cout << "Process creation error\n";
		printf("\n the error number is : %d", GetLastError());
		getchar();
		return FALSE;
	}
	printf_s("\n handle of the process is %d ", pi.hProcess);
	printf_s("\n ProcessID of the process is %d ", pi.dwProcessId);
	//  DWORD dwRet = WaitForSingleObject(pi.hProcess, INFINITE);
	//  printf_s("wait  for single object output %d ", dwRet);

	// ---------------second 
	STARTUPINFO si2;
	PROCESS_INFORMATION pi2;
	//handle hProcess;
	ZeroMemory(&si2, sizeof(si2));
	si2.cb = sizeof(si2);
	ZeroMemory(&pi2, sizeof(pi2));

	if (!CreateProcess(NULL, argv[2], NULL, NULL, FALSE, 0, NULL, NULL, &si2, &pi2))
	{
		cout << "Process creation error\n";
		printf("\n the error number is : %d", GetLastError());
		getchar();
		return FALSE;
	}
	printf_s("\n 2-- handle of the process is %d ", pi2.hProcess);
	printf_s("\n 2-- ProcessID of the process is %d ", pi2.dwProcessId);
	//DWORD dwRet2 = WaitForSingleObject(pi2.hProcess, INFINITE);

	harray[0] = pi.hProcess;
	harray[1] = pi2.hProcess;
	DWORD dwEvent = WaitForMultipleObjects(
		2,           // number of objects in array
		harray,     // array of objects
		TRUE,       // wait for any object
		INFINITE);       // five-second wait
	printf_s("wait  for single object output %d ", dwEvent);

	getchar();

	//system("pause");
	//return(0);
	return TRUE;
}
/*
Status = CreateProcess(NULL,//null if the application name is not given using variable but using command line arguments
	argv[1],//application name given as command line argument 
	NULL,//process not inheritable if null
	NULL,//thread not inheritable if null
	FALSE,//handle inheritance not possible
	0,//flags
	NULL,//use parents environment variables
	NULL,//use parents directory
	&StartUpInfo,//startup information
	&ProcessInfo);//process information*/