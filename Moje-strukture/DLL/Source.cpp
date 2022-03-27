#include"Cvor.h"
#include"Lancana.h"
#include<iostream>
using namespace std;
void main()
{
	Lancana a;
	for (int i = 0; i < 10; i++)
		a.dodajnaGlavu(i);

	a.dodajnaRep(7777);
	//a.nadjicvor(5);
	a.print();




}