#include"Cpolynom.h"
#include <iostream>
using namespace std;
void main()
{
	Cpolynom Polinom(4);
	Polinom.Coef(0,3);
	Polinom.Coef(1,2);
	Polinom.Coef(2,4);
	Polinom.Coef(3,5);
	Polinom.Coef(4,1);
	Polinom.stampaj();
	Cpolynom Izvedeni;
	Izvedeni=Polinom.Derivate(1);
	Izvedeni.stampaj();
}