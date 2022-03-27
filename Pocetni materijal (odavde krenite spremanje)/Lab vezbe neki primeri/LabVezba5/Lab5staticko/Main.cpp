#include <iostream>

#include "Tree.h"

using namespace std;

void main()
{
	try
	{
		Tree t(4);

		t.insert(17);
		t.insert(13);
		t.insert(28);
		t.insert(19);
		t.insert(12);
		t.insert(53);
		t.insert(42);

		t.print();

		t.preorder();
		t.inorder();
		t.postorder();

		cout << endl;

		t.print();
		t.balance();
		t.print();

		Tree t1(3);

		t1.insert(3);
		t1.insert(-3);
		t1.insert(7);

		t.print();
		t1.print();

		Tree T(4);
		T.mix(t,t1);
		T.print();

		T.remove(13);
		T.print();

		T.remove(17);
		T.print();

		T.remove(42);
		T.print();

		char end;
		cin >> end;
	}
	catch (exception* e)
	{
		cout << e->what();
	}
}