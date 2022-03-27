#pragma once
#include "Graf.h"
void main()
{

	Graf g(7);
	g.dodajCvor(1);
	g.dodajCvor(2);
	g.dodajCvor(3);
	g.dodajCvor(4);
	for (int i = 1; i < 5; i++)
	{
		g.dodajVezu(i,(i+1)%4);
	}
	g.dodajVezu(1,1);
	g.stampajGraf();
	system("pause");
}