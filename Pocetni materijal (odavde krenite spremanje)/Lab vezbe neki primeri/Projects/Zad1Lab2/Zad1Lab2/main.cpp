#pragma once
#include "CPolynom.h"
void main()
{
	CPolynomLL pol1, pol2;
	CPolynomLL* pol3;
	
	
		pol1.Coef(0, 1.3);
		pol1.Coef(1, 2);
		pol1.Coef(2, 3);
		cout << "Prvi polinom: " << endl;
		pol1.print();

		
		pol2.Coef(0, 1.6);
		pol2.Coef(1, 2);
		cout << "Drugi polinom: " << endl;
		pol2.print();
	
		
		cout << "Rezultat sabiranja 2 polinoma je: " << endl;
		pol3 = pol1.add(pol2);
		cout << endl;
		system("pause");
}

