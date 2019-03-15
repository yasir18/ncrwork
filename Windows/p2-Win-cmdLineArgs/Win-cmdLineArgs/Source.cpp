#include <windows.h>
#include <stdio.h>
#include <shellapi.h>

int  main()
{
	LPWSTR *Arglist;
	int nArgs;
	int i;

	Arglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
	if (NULL == Arglist)
	{
		wprintf(L"CommandLineToArgvW failed\n");
		return 0;
	}
	else 
		for (i = 0; i<nArgs; i++) 
			printf("%d: %ws\n", i, Arglist[i]);


	// Free memory allocated for CommandLineToArgvW arguments.
	LocalFree(Arglist);
	system("pause");
	return(0);
}