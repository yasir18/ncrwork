#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

//#define BUFFERSIZE 5
DWORD g_BytesTransferred = 0;

void  main(int argc, char *argv[])
{

	HANDLE hFile;
	char DataBuffer[] = "Writing data to file.";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;
	BOOL bErrorFlag = FALSE;

	printf("\n");
	if (argc != 2)
	{
		printf("Usage Error:\tIncorrect number of arguments\n\n");
		_tprintf(TEXT("%s <file_name>\n"), argv[0]);
		return;
	}

	hFile = CreateFileA(
		argv[1],                // name of the file
		GENERIC_WRITE,          // open for writing
		0,                      // do not share
		NULL,                   // default security
		CREATE_NEW,             // create new file only
		FILE_ATTRIBUTE_NORMAL,  // normal file
		NULL);                  // no attr. template

	if (hFile == INVALID_HANDLE_VALUE)
	{

		_tprintf(TEXT("Terminal failure: Unable to open file \"%s\" for write.\n"), argv[1]);
		return;
	}

	_tprintf(TEXT("Writing %d bytes to %S.\n"), dwBytesToWrite, argv[1]);

	bErrorFlag = WriteFile(
		hFile,           // open file handle
		DataBuffer,      // start of data to write
		dwBytesToWrite,  // number of bytes to write
		&dwBytesWritten, // number of bytes that were written
		NULL);            // no overlapped structure

	if (FALSE == bErrorFlag)
	{

		printf("Terminal failure: Unable to write to file.\n");
	}
	else
	{
		if (dwBytesWritten != dwBytesToWrite)
		{
			// This is an error because a synchronous write that results in
			// success (WriteFile returns TRUE) should write all data as
			// requested. This would not necessarily be the case for
			// asynchronous writes.
			printf("Error: dwBytesWritten != dwBytesToWrite\n");
		}
		else
		{
			_tprintf(TEXT("Wrote %d bytes to %S successfully.\n"), dwBytesWritten, argv[1]);

		}
	}
	getchar();
	system("pause");

	CloseHandle(hFile);


	return;
}