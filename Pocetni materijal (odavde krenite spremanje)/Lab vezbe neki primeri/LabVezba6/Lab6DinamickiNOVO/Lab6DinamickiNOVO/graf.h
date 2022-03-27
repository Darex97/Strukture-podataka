#pragma once

#include "klase.h"
#include "poteg.h"

class dinGraf {

	cvor* start;
	int brCvorova;

public:
	dinGraf ();

	void dodajCvor (double*);
	cvor* nadjiCvor (double*);
	void dodajGranu (int*, double*, double*);
	poteg* nadjiGranu (cvor*, cvor*);
	void stampaj ();

	// 1. Zadatak: Nalazenje cvora sa maksimalnim ulaznim stepenom
	void maxUlazniStepen ();

	// 2. Zadatak: Nalazenje cvora sa maksimalnim izlaznim stepenom
	void maxIzlazniStepen ();

	// 3. Zadatak: Nalazenje cvora sa Izlaznim stepenom 0
	void izlazniStepen ();

	// 4. Zadatak: Nalazenje cvora sa Ulaznim stepenom 0
	void ulazniStepen ();

	// 5. Zadatak: Ispitivanje da li je graf jako povezan.
	void povezanost ();

	// 6. Zadatak: Formiranje matrice susedstva
	void matricaSusedstva ();
};