#pragma once
#include "CPolynomLL.h"
void main()
{
	CPolynomLL pol1, pol2;
	CPolynomLL* pol3;
	for (int i = 0; i<8; i++)
	{
		pol1.Coef(i, i*1.3);
		pol2.Coef(i + 2, i*1.6);
	}
	pol1.print();
	pol2.print();
	pol3 = pol1.add(pol2);
	//pol3->print();
	system("pause");
}

