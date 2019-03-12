// Assignmentquestion10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<windows.h>
#include <iostream>
#include<tchar.h>
using namespace std;

int main()
{
	HANDLE hFile = NULL;
	LPCWSTR lpFile = L"new.txt";
	SECURITY_ATTRIBUTES secProcess;
	secProcess.bInheritHandle = TRUE;
	secProcess.lpSecurityDescriptor = NULL;
	secProcess.nLength = sizeof(secProcess);
	hFile = CreateFileW(
		lpFile,
		GENERIC_READ,
		0,
		&secProcess,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (NULL == hFile)
	{
		cout << "error in creating the file with error " << GetLastError() << endl;
		getchar();
		return 0;
	}
	cout << "file created successfully\n";
	cout << "The handle of file is : " << hFile << endl;
	STARTUPINFO siProcess;

	PROCESS_INFORMATION piProcess;
	siProcess.cb = sizeof(siProcess);
	ZeroMemory(&siProcess, sizeof(siProcess));
	ZeroMemory(&piProcess, sizeof(piProcess));
	BOOL bCreateProc = CreateProcess(
		TEXT("C:\\WINDOWS\\system32\\notepad.exe"),
		NULL,
		NULL,
		NULL,
		TRUE,
		0,
		NULL,
		NULL,
		&siProcess,
		&piProcess
	);
	if (0 == bCreateProc)
	{
		cout << "create process failed with error " << GetLastError() << endl;
		getchar();
		return 0;
	}
	cout << "process created with handles inherited\n";
	cout << "Handle of child process is " << piProcess.hProcess;
	getchar();
	return 0;
}

