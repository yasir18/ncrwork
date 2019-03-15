//------------------------read file--------------------------------
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>
using namespace std;
#define BUFFERSIZE 100

void  _tmain(int argc, TCHAR *argv[])
{
	printf("reading file -------------\n");
	HANDLE hFile;
	TCHAR buffer[BUFFERSIZE];

	printf("\n");
	if (argc != 2)
	{
		printf("Usage Error: Incorrect number of arguments\n\n");
		_tprintf(TEXT("Usage:\n\t%s <text_file_name>\n"), argv[0]);
		return;
	}

	hFile = CreateFile(argv[1],               // file to open
		GENERIC_READ,          // open for reading
		0,             // share for reading
		NULL,                  // default security
		OPEN_EXISTING,         // existing file only
		FILE_ATTRIBUTE_NORMAL, // normal file
		NULL);                 // no attr. template

	if (hFile == INVALID_HANDLE_VALUE)
	{
		_tprintf(TEXT("Terminal failure: unable to open file \"%s\" for read.\n"), argv[1]);
		DWORD err=GetLastError();
		printf("%u",err);
		getchar();
		return;
	}
	else
	{
		/*LPDWORD lpFileSizeHigh = 0;
		 GetFileSize(
			  hFile,
			 lpFileSizeHigh
		);*/
		int noOfBytes = 0;
		ZeroMemory(buffer, BUFFERSIZE);
		bool bRet = ReadFile(hFile, buffer, BUFFERSIZE, NULL, NULL);
		if (0 == bRet)
		{
			_tprintf(TEXT("cannot open file : errorno : %d"), GetLastError);
		}
		else
		{
			for (int i = 0; i < _tcslen(buffer); i++)
			{
				printf("%c", buffer[i]);
			}
			_tprintf(TEXT("\n"));
		}
	}
	getchar();
	system("pause");
}