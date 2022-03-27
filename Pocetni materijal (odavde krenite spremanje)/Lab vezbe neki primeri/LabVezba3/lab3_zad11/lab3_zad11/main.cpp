#include "Stack.h"
#include <cstring>
#include <iostream>
using namespace std;

void main()
{
	try
	{
	Stack stek(10);
	char txt[100];
	gets(txt);
	stek.uPostfix(txt);
	}
	catch(char* s)
	{
		cout << s << endl;
	}
}

// ((