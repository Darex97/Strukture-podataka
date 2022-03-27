#include"HashTable.h"

void main()
{
	try
	{
		HashTable t(11);
		t.insert(6535853, "Julije", "Kostov");
		t.insert(6535853, "Julije", "Kostov");
		t.insert(6535853, "Julije", "Kostov");
		//t.insert(3333555, "qwe", "ewq");
		//t.insert(5553333, "asd", "dsa");
		t.print();
	}
	catch (char *p)
	{
		cout << "Error:" << p << endl;
	}
	catch (...)
	{
		cout << "Error!!" << endl;
	}
}