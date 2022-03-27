#include"HashTable.h"

void main()
{
	try
	{
		HashTable t(11);
		t.insert("char");
		t.insert("int");
		t.insert("void");
		t.insert("int");
		t.insert("char");
		t.insert("int");
		t.insert("void");
		t.print();
	}
	catch (char* p)
	{
		cout << "Error: " << p << endl;
	}
	catch (...)
	{
		cout << "!!!" << endl;
	}
}