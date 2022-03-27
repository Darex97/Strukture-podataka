#include "CSparseMatrix.h"
#include <iostream>
using namespace std;


void main()

{
	CSparseMatrix<int> mat(3, 3);
	mat.SetAt(9, 3, 3);
	mat.print();
	cout << endl;

	mat.SetAt(7, 3, 1);
	mat.print();
	cout << endl;

	mat.SetAt(8, 3, 2);
	mat.print();
	cout << endl;

	mat.SetAt(5, 2, 2);
	mat.print();
	cout << endl;

	mat.SetAt(4, 2, 1);
	mat.print();
	cout << endl;

	mat.SetAt(6, 2, 3);
	mat.print();
	cout << endl;

	mat.SetAt(3, 1, 3);
	mat.print();
	cout << endl;

	mat.SetAt(2, 1, 2);
	mat.print();
	cout << endl;

	mat.SetAt(1, 1, 1);
	mat.print();
	cout << endl;


}