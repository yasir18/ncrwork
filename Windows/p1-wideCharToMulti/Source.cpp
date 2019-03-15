#include<Windows.h>
#include<iostream>
using namespace std;

int main()
{
	WCHAR wc[] = L"Yasir";
	char c[] = "Affan";

	cout << "Wide char string is: ";
	printf("%S\n", wc);

	cout << "ANSI char string is: ";
	cout << " " << c << endl;

	int lenw = wcslen(wc);
	int len = strlen(c);
	cout << lenw << " " << len << endl;

	int sizeOfCharw = sizeof(wc[0]);
	int sizeOfChar = sizeof(c[0]);
	cout << "size of WCHAR :"<<sizeOfCharw << "\nSize of char " << sizeOfChar << endl;

	int sizeReqd = WideCharToMultiByte(CP_UTF8, 0, wc, -1, NULL, 0, NULL, NULL);
	if (0 == sizeReqd )
	{
		cout << "error converting  wide char to multi";
	}
	else
	{
		char *newmul = new char[sizeReqd];
		WideCharToMultiByte(CP_UTF8, 0, wc, -1, newmul, sizeReqd, NULL, NULL);
		cout << "new created mulchar:  " << newmul << endl;
		//To check whether created char array is UNicode or not 
		//Returns 1 on succes and 0 on failure
		if (0 == IsTextUnicode(newmul, sizeof(char)*sizeReqd, NULL)) {
			cout << newmul << " is not Unicode \n\n";
		}
	}


	cout << "--------multi char to wide ------";
	int sizeReqdw = MultiByteToWideChar(CP_UTF8, 0, c, -1, NULL, 0);

	if (0 == sizeReqdw) {
		cout << "error converting  multi to char    "<<endl;
	}
	else
	{
		WCHAR *newWide = new WCHAR[sizeReqdw];
		MultiByteToWideChar(CP_UTF8, 0, c, -1, newWide, sizeReqdw);

		cout << "new Created Wide char : ";
			printf("%S\n", newWide);
			//To check whether created char array is UNicode or not 
			//Returns 1 on succes and 0 on failure
			if (1 == IsTextUnicode(newWide, sizeof(char)*sizeReqd, NULL)) {
				printf("%S", newWide);
				cout  << " is  UNicode \n\n ";
			}
	}

		return 0;
}