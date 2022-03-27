#include"Cvor.h"
#include"Lancana.h"
#include<iostream>
using namespace std;
void main()
{
	
	Cvor* n;
	Lancana b,a;
	int k[] = { 11,22,33,44,7777 };
	for (int i = 1; i <= 9; i++)
	{
		
		b.dodajnarep(i);
		a.dodajnaglavu(i);

	}
	

	
	
	b.UpdateNode(3,77);
	b.print();

	
	
	//







}