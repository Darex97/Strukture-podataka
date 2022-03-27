#include"Graf.h"
void main()
{
	Graf g(10);
	int a = 1, b = 2, c = 3, d = 4;
	int e = 7, f = 8;
	g.dodajCvor(a);
	g.dodajCvor(b);
	g.dodajCvor(c);
	g.dodajCvor(d);
	g.dodajCvor(e);
	g.dodajCvor(f);
	g.dodajVezu(a,b);
	g.dodajVezu(a,c);
	g.dodajVezu(a,d);
	g.dodajVezu(b,a);
	g.dodajVezu(c,a);
	g.dodajVezu(d,a);
	g.dodajVezu(d, b);
	cout << "Cvor 7 je na indeksu: " << g.nadjiCvor(e) << endl;
	g.stampajGraf();

	g.maxUlazni();
	g.maxIzlazni();
	g.nulaUlazni();
	g.nulaIzlazni();
}