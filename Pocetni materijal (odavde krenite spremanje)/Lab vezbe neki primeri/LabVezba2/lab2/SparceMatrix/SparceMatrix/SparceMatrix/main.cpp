#include "SparseMatrix.h"

void main()
{
	SparseMatrix sm(5, 5);

	sm.addElement(3, 1, 5);
	sm.addElement(1, 0, 3);
	sm.addElement(2, 1, 4);
	sm.addElement(4, 1, 7);
	sm.addElement(4, 4, 5);

	cout << "Element 4,1: " << sm.getElement(4, 1) << endl;
	cout << "Element 3,3: " << sm.getElement(3, 3) << endl;

	sm.print();

	int x;
	cin >> x;
}