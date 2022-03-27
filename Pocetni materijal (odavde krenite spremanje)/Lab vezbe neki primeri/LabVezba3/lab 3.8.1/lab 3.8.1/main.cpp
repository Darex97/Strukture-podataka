#include "Expression.h"
#include "Exception.h"
#include <iostream>

using namespace std;

void main ()
{
	Stack<double> s1(20);
	Expression e;
	try
	{
		cout <<e.postfixCount(s1);
		//cout<<e.postfixCount(e.infix2Postfix(),s1);
	}
	catch(Exception p)
	{
		p.print();
	}
	system("pause");
}
