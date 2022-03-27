#include "CPolynom.h"
#include <iostream>
using namespace std;

CPolynom::CPolynom()
{
}
CPolynom::~CPolynom()
{
}
CPolynom::CPolynom(int red)
{
	order = red;
	niz = new double[order + 1];
}
void CPolynom::dodaj(int stepen, double koef)
{
	niz[stepen] = koef;
}
void CPolynom::print()
{
	for (int i = order; i>0; i--)
		cout << niz[i] << "X^" << i << " + ";
	cout << niz[0] << endl;
}
CPolynom& CPolynom::saberi(CPolynom& P2)
{
	if (this->order > P2.order)
	{
		CPolynom P(this->order);
		for (int i = 0; i <= P2.order; i++)
		{
			P.niz[i] = this->niz[i] + P2.niz[i];
		}
		for (int i = P2.order + 1; i <= this->order; i++)
			P.niz[i] = this->niz[i];
		return P;
	}
	else
	{
		CPolynom P(P2.order);
		for (int i = 0; i <= this->order; i++)
		{
			P.niz[i] = this->niz[i] + P2.niz[i];
		}
		for (int i = this->order + 1; i <= P2.order; i++)
			P.niz[i] = P2.niz[i];
		return P;
	}

}