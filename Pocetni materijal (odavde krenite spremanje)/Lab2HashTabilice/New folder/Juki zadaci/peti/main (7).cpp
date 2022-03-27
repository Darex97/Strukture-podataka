#include"HashTable.h"

void main()
{
	try
	{
		HashTable t(7, 4);
		t.insert("int");
		t.insert("char");
		t.insert("void");
		t.insert("var");
		t.insert("int");
		t.insert("char");
		t.print();
	}
	catch (char* p)
	{
		cout << "Error:" << p << endl;
	}
	catch (...)
	{
		cout << "Error!!!!!" << endl;
	}
}