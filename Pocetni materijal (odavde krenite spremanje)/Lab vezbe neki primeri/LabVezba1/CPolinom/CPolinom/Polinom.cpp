#include "Polinom.h"
#include <iostream>
using namespace std;

CPolinom::CPolinom(int order)
{
	redPol=order;
	koeficijenti=new double[redPol+1];
	for (int i=redPol; i>=0; i--)
		koeficijenti[i]=0;
}

CPolinom::CPolinom(CPolinom& p)
{
	redPol = p.redPol;
	koeficijenti=new double[redPol+1];
	for (int i=redPol; i>=0; i--)
		koeficijenti[i] = p.koeficijenti[i];
}

CPolinom::~CPolinom(void)
{
	delete [] koeficijenti;
	
}
void CPolinom::Coef(int exp, double coef)
{
	koeficijenti[exp]=coef;
}

CPolinom CPolinom::Add(CPolinom poly1, CPolinom poly2)
{
	if (poly1.redPol>poly2.redPol)
	{
		CPolinom rez(poly1);

		for(int i = 0; i <= poly2.redPol; i++)
		{
			rez.koeficijenti[i] += poly2.koeficijenti[i];
		}

		return rez;
	}
	else 
	{
		CPolinom rez(poly2);

		for(int i = 0; i <= poly1.redPol; i++)
		{
			rez.koeficijenti[i] += poly1.koeficijenti[i];
		}

		return rez;
	}
}
void CPolinom::print()
{
	for (int i=redPol; i>=0; i--)
		if (i>0)
		cout << koeficijenti[i] << "x^" <<i<< "+";
		else cout << koeficijenti[i]<< endl;
}