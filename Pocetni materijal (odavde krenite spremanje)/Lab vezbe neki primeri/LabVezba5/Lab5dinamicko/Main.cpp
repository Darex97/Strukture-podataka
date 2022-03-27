#include "Tree.h"

void main()
{
	Tree T;
	T.insert(5);
	T.insert(2);
	T.insert(4);
	T.insert(7);
	T.insert(6);
	T.insert(9);
	T.insert(8);

	T.preorder();
	cout << endl;
	T.postorder();
	cout << endl;

	int temp = T.differentNodes();

	cout << temp;
	cout << endl;
	
	temp = T.height();

	cout << temp;
	cout << endl;

	temp = T.numberOfLeaves();

	cout << temp;
	cout << endl;

	temp = T.levelWithMostNodes();

	cout << temp;
	cout << endl;

	T.deleteLeaves();

	T.preorder();
	cout << endl;
	T.postorder();
	cout << endl;

	T.deleteByMerging(5);

	T.preorder();
	cout << endl;
	T.postorder();
	cout << endl;

	Tree T1;
	T1.insert(1);
	T1.insert(5);

	T1.preorder();
	cout << endl;
	T1.postorder();
	cout << endl;

	Tree mix;

	mix.mix(T,T1);

	mix.preorder();
	cout << endl;
	mix.postorder();
	cout << endl;

	mix.mirror();

	mix.preorder();
	cout << endl;
	mix.postorder();
	cout << endl;

	mix.balance();

	mix.preorder();
	cout << endl;
	mix.postorder();
	cout << endl;

	char test;
	cin >> test;
}