#include <iostream>
//#include <cstdio>

//#include "div.cpp"
using namespace std;
 int add(int, int);
 int sub(int, int);
 int mul(int, int);
 int divf(int, int);

int main()
{
	int a, b, op;
	cout<<"1)Addition \n 2)Subtraction \n 3)Multiplication \n 4)Division\n";
	cout << "Choose the option:";
	cin >> op;
	cout << "Enter the two numbers:";
	//hghg
	cin >> a >> b;
	switch (op) {
	case 1:
		cout<<add(a, b)<<endl;
		break;
	case 2:
		cout << sub(a, b) << endl;
		break;
	case 3:
		cout << mul(a, b) << endl;
		break;
	case 4:
		cout << divf(a, b) << endl;
		break;
	}

	system("pause");
	return 0;
}
