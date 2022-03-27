#include"HashTable.h"

void main()
{
	try
	{
		HashTable t(11);
		t.insert("int");
		t.insert("char");
		t.insert("for");
		cout << t.find("void") << endl << t.find("for") << endl;
		t.print();
	}
	catch (char *p)
	{
		cout << "Error:" << p << endl;
	}
	catch (...)
	{
		cout << "Error!" << endl;
	}
}