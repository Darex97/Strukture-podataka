#include "HashTable.h"

void main()
{
	try
	{
		HashTable a(70);
		HashObject o1("while");
		a.insert(o1);
		HashObject o2("while");
		a.insert(o2);
		HashObject o3("throw");
		a.insert(o3);
		HashObject o4("cast");
		a.insert(o4);
		a.withdraw("cast");
		a.display();
	}
	catch (char* s)
	{
		cout << s << endl;
	}
}