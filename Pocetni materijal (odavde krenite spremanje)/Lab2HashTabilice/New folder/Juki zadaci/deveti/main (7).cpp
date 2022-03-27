#include"HashTable.h"

void main()
{
	try
	{
		HashTable t(11);
		t.insert("int");
		t.insert("int");
		t.insert("int");
		t.insert("int");
		t.print();
	}
	catch (char* p)
	{
		cout << "Error:" << p << endl;
	}
	catch (...)
	{
		cout << "Error!!!!" << endl;
	}
}