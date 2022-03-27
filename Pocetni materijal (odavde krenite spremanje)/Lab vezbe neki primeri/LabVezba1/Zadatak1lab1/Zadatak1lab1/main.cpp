#include"Polinom.h"
#include<iostream>
using namespace std;

void main()
{
	Polinom P1(3);
	Polinom P2(2);
	
	P1.dodaj(0,7);
	P1.dodaj(1,3);
	P1.dodaj(2,1);
	P1.dodaj(3,5);

	P2.dodaj(0,5);
	P2.dodaj(1,1);
	P2.dodaj(2,2);

	P1.stampaj();
	P2.stampaj();

	Polinom P3;
	P3=P1.saberi(P2);
	P3.stampaj();
}