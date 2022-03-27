#pragma once 

#include <iostream>

using namespace std;

class Exception
{
	
public:

	char* message;

	Exception(char* x)
	{
		message = new char;
		message=x;
	}

	~Exception()
	{
		delete [] message;
	}

	void print()
	{
		cout<<message<<endl;
	}

};