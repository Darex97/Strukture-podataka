#include"HashTable.h"
void main()
{
	try
	{
		HashTable t(10);
		
		HashObject o1(123456, "Darko");
		HashObject o2(2345890, "Milutin");
		HashObject o3(1234543, "Pera");
		HashObject o4(123456, "Darko");
		t.insert(o1);
		t.insert(o2);
		t.insert(o3);
		t.insert(o4);

		t.printAll();


	}
	catch (char* izuzetak)
	{
		cout << izuzetak << endl;
	}
}