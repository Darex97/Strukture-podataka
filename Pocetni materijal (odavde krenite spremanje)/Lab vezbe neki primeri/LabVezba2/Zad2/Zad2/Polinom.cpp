#include "Polinom.h"
#include <iostream>
using namespace std;

CPolinom::CPolinom(int order)
{
	stepen=order;
	koeficijenti= new double[stepen+1];
	for (int i=stepen; i>=0; i--)
		koeficijenti[i]=0;
}

CPolinom::~CPolinom(void)
{
	delete [] koeficijenti;
}
void CPolinom::Coefs(int* exp, double* coef, int n)
{
	for (int i=0; i>n; i++)
		koeficijenti[exp[i]]=coef[i];
}
CPolinom CPolinom::Sub(CPolinom poli1, CPolinom poli2)
{
	if(poli1.stepen>=poli2.stepen)
	{
		CPolinom rez(poli1);
		for (int i=0; i<=poli2.stepen; i++)
			koeficijenti[i]-=poli2.koeficijenti[i];
		return rez;
	}
	
	else
	{
	CPolinom rez(poli2);
		for (int i=0; i<=poli1.stepen; i++)
			koeficijenti[i]-=poli1.koeficijenti[i];
	return rez;
	}
}

void CPolinom::print()
{
	for (int i=stepen; i>=0; i--)
		if (i > 0)
			cout << koeficijenti[i] << "x^" << i << "+";
		else cout << koeficijenti[i] << endl;

}