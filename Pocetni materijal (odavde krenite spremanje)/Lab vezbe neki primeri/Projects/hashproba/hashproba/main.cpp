#include "HashTable.h"
#include <iostream>
using namespace std;

void main()
{
	try
	{
		HashTable c(10);
		HashObject a1("foreach");
		c.insert(a1);
		HashObject a2("float");
		c.insert(a2);
		HashObject a3("while");
		c.insert(a3);
		HashObject a4("cast");
		c.insert(a4);
		HashObject a5("throw");
		c.display();
		double b = c.FP();
		cout << "Faktor popunjenosti iznosi: " << b << endl;
		cout << endl;
		c.withdraw(a1);
		c.display();
		c.withdraw(a5);
	}
	catch (char* e)
	{
		cout << e << endl;
	}
}