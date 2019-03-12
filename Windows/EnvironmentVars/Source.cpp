
// ExpandEnvironmentStrings

#include <windows.h>
#include<tchar.h>
#include<iostream>
using namespace std;

void DumpEnvironVariables(TCHAR *env[])
{
	int i = 1;
	while (env != NULL)
	{
		cout << i << "  :  ";
		_tprintf(TEXT("%S\n"), *env);
		i++;
		env++;
	}
}


//int  main()
int main(int argc, TCHAR *argv[], TCHAR *env[])
{
	DumpEnvironVariables(env);

	///expanding environment string using ExpandEnvironmentStrings
	TCHAR envVarString[] = TEXT("%windir%");
	TCHAR envVarString2[] = TEXT("%OneDrive%");
	TCHAR buffer[MAX_PATH];
	DWORD dwRet;
	dwRet = ExpandEnvironmentStrings(envVarString, buffer, MAX_PATH);
	if (!dwRet)
	{
		printf("%d \n", GetLastError());
	}
	else
	{
		printf("%S\n", buffer);
	}
	dwRet = ExpandEnvironmentStrings(envVarString2, buffer, MAX_PATH);
	if (!dwRet)
	{
		printf("%d \n", GetLastError());
	}
	else
	{
		printf("%S\n", buffer);
	}
	system("pause");
	return(0);
}
