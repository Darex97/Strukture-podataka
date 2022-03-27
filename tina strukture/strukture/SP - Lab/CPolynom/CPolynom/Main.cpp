#include <iostream>

using namespace std;

#include "CPolynom.h"
#include "DSException.h"

int main()
{
	CPolynom* poly1 = new CPolynom(3);
	CPolynom* poly2 = new CPolynom(2);

	try
	{
		poly1->Coef(3, 6.0);
		poly1->Coef(2, 10.0);
		poly1->Coef(0, 5.0);

		poly2->Coef(2, 4.0);
		poly2->Coef(1, 2.0);
		poly2->Coef(0, 1.0);

		CPolynom resultPoly1 = CPolynom::Add(*poly1, *poly2);

		cout << "resultPoly1 = ";
		resultPoly1.Print();
		cout << endl;

		CPolynom resultPoly2;

		resultPoly2 = CPolynom::Mul(*poly1, *poly2);

		cout << "resultPoly2 = ";
		resultPoly2.Print();
		cout << endl;
	}
	catch (const DSException& ex)
	{
		cout << "Error Message: " << ex.GetMessage() << endl;
	}
	catch (const exception& ex)
	{
		cout << "Error Message: " << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Caught unknown exception." << endl;
	}

	delete poly2;
	delete poly1;

	return 0;
}