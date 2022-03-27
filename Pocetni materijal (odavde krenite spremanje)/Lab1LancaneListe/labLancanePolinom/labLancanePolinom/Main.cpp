#include "Polinom.h"
void main()
{
	Polinom p, q, r, s;
	p.dodajNaHead(6, 1);
	p.dodajNaHead(3, 2);
	p.dodajNaHead(2, 3);
	p.stampaj();
	q.dodajNaHead(6, 0);
	q.dodajNaHead(5, 2);
	q.stampaj();
	r.Saberi(p, q);
	r.stampaj();
	s.Pomnozi(p, q);
	s.stampaj();
}