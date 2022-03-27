#include <iostream>
using namespace std;
#include "Polinom.h"

void main()
{
	CPolinom p1(4);
	CPolinom p2(2);

	int broj;
	cout<< "Unesite broj" << endl;
	cin>> broj;
	int* nizSt = new int[broj];
	cout<< "unesite stepene" << endl;
	for (int i=0; i<broj; i++)
		cin >> nizSt[i];
	double* nizKoef= new double[broj];
	cout<< "unesite koeficijente" << endl;
	for (int i=0; i<broj; i++)
		cin >> nizKoef[i];

	p1.Coefs(nizSt, nizKoef, broj);
	p1.print();
	p2.print();
	
}