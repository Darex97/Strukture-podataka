#include"HashTable.h"

void main()
{
	try
	{
		HashTable t(11);
		t.insert(1112222, "asd", "dsa");
		t.insert(1112222, "qwe", "ewq");
		t.insert(5553333, "bnm", "mnb");
		t.insert(3335555, "zxc", "cxz");
		t.print();
	}
	catch (char* p)
	{
		cout << "Error:" << p << endl;
	}
	catch (...)
	{
		cout << "Error!!!" << endl;
	}
}