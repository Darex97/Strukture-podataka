#include"ChainedHashTable.h"
#include"HashObject.h"
#include"SLList.h"

void main()
{
	try
	{
		ChainedHashTable t(10);
		HashObject o1(10,"for");
		HashObject o2(11,"while");
		HashObject o3(12,"try");
		HashObject o4(21,"include");
		HashObject o5(24,"catch");
		HashObject o6(47,"delete");
		HashObject o7(44,"delete");
		t.insert(o1);
		t.insert(o2);
		t.insert(o3);
		t.insert(o4);
		t.insert(o5);
		t.insert(o6);
		t.insert(o7);

		t.display();
	}
	catch(char *message)
	{
		cout<<message<<endl;
	}
}