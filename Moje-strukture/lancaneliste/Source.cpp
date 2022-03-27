#include"Cvor.h"
#include"Lancana.h"
#include<iostream>
using namespace std;
int main()
{
	Cvor k(5);
	Lancana b;
	for (int i = 1; i <= 9; i++)
	{
	
		b.dodajnaglavu(i);
		
	}
	

	b.deleteel(7);
	b.print();
	return 0;







}