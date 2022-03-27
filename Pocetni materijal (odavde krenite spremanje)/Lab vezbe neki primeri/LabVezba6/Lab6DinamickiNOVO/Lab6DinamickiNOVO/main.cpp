#include "graf.h"
#include "klase.h"
#include "poteg.h"
#include <iostream>

using namespace std;

void main () {

	dinGraf* novi = new dinGraf ();

	/*cout << "Dodaj 5 elemente:\n";
	for (int i = 0; i < 5; i++) {

		double a;
		cin >> a;
		novi->dodajCvor (&a);
	}

	cout << "Dodaj grane:\n";
	for (int i = 0; i < 8; i++) {

		cout << "Tezina: ";
		int a;
		cin >> a;

		cout << "Prvi Cvor: ";
		double prvi;
		cin >> prvi;

		cout << "Drugi Cvor: ";
		double drugi;
		cin >> drugi;

		novi->dodajGranu (&a, &prvi, &drugi);
	}*/


	double a = 3.5, b = 4.5, c = 8.03, d = 1.79, e = 2.33;
	novi->dodajCvor (&a);
	novi->dodajCvor (&b);
	novi->dodajCvor (&c);
	novi->dodajCvor (&d);
	novi->dodajCvor (&e);

	//Grane
	int g1 = 5, g2 = 2, g3 = 10, g4 = 6, g5 = 13, g6 = 2, g7 = 16, g8 = 4;
	novi->dodajGranu (&g1, &a, &b);
	novi->dodajGranu (&g2, &a, &d);
	novi->dodajGranu (&g3, &a, &e);
	novi->dodajGranu (&g4, &b, &e);
	novi->dodajGranu (&g5, &b, &c);
	novi->dodajGranu (&g6, &c, &b);
	novi->dodajGranu (&g7, &e, &c);
	novi->dodajGranu (&g8, &d, &c);

	/*novi->matricaSusedstva ();
	novi->maxUlazniStepen ();
	novi->maxIzlazniStepen ();
	novi->povezanost ();*/
	//novi->ulazniStepen ();
	novi->izlazniStepen ();
	novi->stampaj ();

	int bb;
	cout << "\n\n\nKraj: ";
	cin >>bb;
}