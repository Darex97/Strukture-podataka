#pragma once

#include "klase.h"
#include "graf.h"
#include "poteg.h"
#include <iostream>

using namespace std;

//-------------------------------------------------------------
//				Inicijalizacija cvora
//-------------------------------------------------------------
cvor::cvor () {

	this->pokCvor = NULL;
	this->pokPoteg = NULL;
	this->status = -1;
}

cvor::cvor (double el) {

	this->kljuc = el;
	this->pokCvor = NULL;
	this->pokPoteg = NULL;
	this->status = -1;
}

cvor::cvor (double el, cvor* pCvor) {

	this->kljuc = el;
	this->pokCvor = pCvor;
	this->pokPoteg = NULL;
	this->status = -1;
}

//-------------------------------------------------------------
//				Inicijalizacija potega
//-------------------------------------------------------------
poteg::poteg () {

	this->dest = NULL;
	this->pokPoteg = NULL;
}

//poteg::poteg (int* tez, cvor* destinacija, poteg* naredni) {
//
//	this->tezina = *tez;
//	this->dest = destinacija;
//	this->pokPoteg = naredni;
//}


//-------------------------------------------------------------
//				Inicijalizacija grafa
//-------------------------------------------------------------
dinGraf::dinGraf () {

	this->start = NULL;
	this->brCvorova = 0;
}

void dinGraf::dodajCvor (double* el) {

	cvor* novi = new cvor (*el, this->start);
	this->start = novi;

	this->brCvorova++;
}

cvor* dinGraf::nadjiCvor (double* a) {

	cvor* pointer = this->start;

	while (pointer != NULL)

		if (pointer->kljuc == *a)
			return pointer;
		
		else
			pointer = pointer->pokCvor;

	return pointer;
}

void dinGraf::dodajGranu (int* tez, double* a, double* b) {

	cvor* prvi = this->nadjiCvor (a);
	cvor* drugi = this->nadjiCvor (b);

	if (prvi != NULL && drugi != NULL) {

		poteg* novi = new poteg (tez, drugi, prvi->pokPoteg);
		prvi->pokPoteg = novi;

		cout << "Grana je dodata!\n";
	}

	else
		cout << "Cvorovi sa datim elementima nisu pronadjeni!\n";

}

poteg* dinGraf::nadjiGranu (cvor* prvi, cvor* drugi) {

	poteg* novi = prvi->pokPoteg;

	while (novi) {

		if (novi->dest->kljuc == drugi->kljuc)
			return novi;

		novi = novi->pokPoteg;
	}

	return novi;
}

void dinGraf::maxIzlazniStepen () {

	cvor* maxPtr = NULL;
	cvor* ptr = this->start;
	int max = 0;

	while (ptr != NULL) {

		int br = 0;

		poteg* potezi = ptr->pokPoteg;

		while (potezi != NULL) {

			br++;
			potezi = potezi->pokPoteg;
		}

		if (br > max) {

			maxPtr = ptr;
			max = br;
		}

		ptr = ptr->pokCvor;
	}

	if (maxPtr)
		cout << "Cvor sa elementom " << maxPtr->kljuc << " ima najvise izlaznih potega, i to " << max << " potega!" << endl;

	else
		cout << "Ni jedan cvor nema izlaznih potega!\n";
}

void dinGraf::maxUlazniStepen () {

	cvor* ptrTrazenog = this->start;
	cvor* maxPtr = NULL;
	int max = 0;

	while (ptrTrazenog) {

		int br = 0;
		
		cvor* ptr = this->start;

		while (ptr) {
			
			poteg* potezi = ptr->pokPoteg;

			while (potezi) {

				if (potezi->dest->kljuc == ptrTrazenog->kljuc)
					br++;

				potezi = potezi->pokPoteg;
			}

			ptr = ptr->pokCvor;

		}

		if (br > max) {

			max = br;
			maxPtr = ptrTrazenog;
		}

		ptrTrazenog = ptrTrazenog->pokCvor;
	}

	if (maxPtr) {

		cout << "Cvor sa maksimalnim brojem ulaznih potega ima vrednost: " << maxPtr->kljuc;
		cout << ". On ima " << max << " ulaznih potega.\n";
	}

	else
		cout << "Ni jedan cvor nema ulaznih potega!\n";
}

void dinGraf::stampaj () {

	cvor* novi = this->start;

	while (novi != NULL) {

		cout << endl << novi->kljuc << "->";

		poteg* potezi = novi->pokPoteg;

		while (potezi) {

			cout << potezi->dest->kljuc << "->";
			potezi = potezi->pokPoteg;
		}

		novi = novi->pokCvor;
	}
}

void dinGraf::izlazniStepen () {

	//Ova funkcija nalazi sve cvorove koji nemaju izlazni stepen. Prvo je napravljen prazan
	//niz pokazivaca na cvorove. U njemu ce se kasnije smestaju cvorove koji nemaju izlazni
	//poteg. Jednostavno se krece od pocetka liste sa cvorovima. Ako je pokazivac na listu potega
	//unutar datog cvora jednako NULL, onda se smesti pokazivac na njega u niz i inkerementira se 
	//brojac i. Na kraju se niz pokazivaca, ako postoji, prikazuje na ekran.

	int n = this->brCvorova;
	cvor** niz = new cvor* [this->brCvorova];
	int i = 0;

	for (;i < this->brCvorova; i++)
		niz [i] = NULL;

	i = 0;

	cvor* novi = this->start;

	while (novi) {

		if (!novi->pokPoteg) {

			niz [i] = novi;
			i++;
		}

		novi = novi->pokCvor;
	}

	i = 0;

	if (!niz [0])
		cout << "Svi cvorovi imaju izlazni stepen!\n";

	else {
		
	cout << "Cvorovi sa izlaznim stepenu 0 imaju elemente:\n";

		while (!niz [i]) {

			cout << i + 1 << ".\t" << niz[i]->kljuc << endl;
			i++;
		}
	}
}

void dinGraf::ulazniStepen () {

	//Ova funkcija nalazi sve cvorove koji nemaju ulazni poteg. Prvo se kreira niz pokazivaca na
	//cvorove, u koga ce se kasnije smestaju pokazivaci na cvorove bez ulaznih potega. Pokazivac
	//ptrTrazenog se referencira na prvi cvor, i na dalje se krece po listi cvorova i za svaki
	//cvor se ispita da li ima poteg ka trazenom cvoru (ptrTrazenog). Ako ima, onda se brojac
	//br inkrementira i izlazi se iz petlje. ptrTrazenog se referencira na naredni cvor i trazi
	//se potezi ka tom cvoru. Glavna petlja se vrti sve dok je ptrTrazenog razlicit od nule.
	//Na kraju se niz pokazivaca, ako postoji, prikazuje na ekran.

	cvor* ptrTrazenog = this->start;
	cvor** niz = new cvor* [this->brCvorova];
	int i = 0;

	for (; i < this->brCvorova; i++)
		niz [i] = NULL;

	i = 0;

	while (ptrTrazenog) {

		int br = 0;
		
		cvor* ptr = this->start;

		while (ptr && !br) {
			
			poteg* potezi = ptr->pokPoteg;

			while (potezi && !br) {

				if (potezi->dest->kljuc == ptrTrazenog->kljuc)
					br++;

				potezi = potezi->pokPoteg;
			}

			ptr = ptr->pokCvor;

		}

		if (!br) {

			niz [i] = ptrTrazenog;
			i++;
		}

		ptrTrazenog = ptrTrazenog->pokCvor;
	}

	i = 0;

	if (!niz [0])
		cout << "Svi cvorovi imaju ulazni stepen!\n";

	else {

		cout << "Cvorovi koji nemaju ulazne potege:\n";

		while (niz [i]) {

			cout << i + 1 << ".\t" << niz[i]->kljuc << endl;
			i++;
		}
	}
}

void dinGraf::matricaSusedstva () {

	//Ova funkcija generise matricu susedstva i prikazuje je na ekran. Prvo se kreira niz
	//pokazivaca na cvorove i u njemu se smestaju pokazivaci na sve cvorove grafa. Ovaj 
	//niz ce se kasnije koristiti za trazenje grane izmedju dva cvorova. U while petlji 
	// trazimo grane, tj poteze tako sto proveravamo da li ima poteg izmedju tekuceg cvora
	//(novi) i svih ostalih cvorova, ciji se pokazivaci nalaze u nizu. Svuda gde funkcija
	//'nadjiGranu' vraca pokazivac na tu granu, u matricu se smesta jedinica, u suprotnom
	//se smesta 0.

	cvor** niz = new cvor* [this->brCvorova];
	cvor* novi = this->start;
	int i = 0;

	while (novi) {

		niz [i] = novi;
		i++;
		novi = novi->pokCvor;
	}

	int **matSusedstva = new int* [this->brCvorova];
	for (i = 0; i < this->brCvorova; i++)
		matSusedstva [i] = new int [this->brCvorova];

	novi = this->start;


	i = 0;

	while (novi) {

		for (int j = 0; j < this->brCvorova; j++) {

			if (this->nadjiGranu (novi, niz [j]))
				matSusedstva [i][j] = 1;

			else
				matSusedstva [i][j] = 0;
		}

		novi = novi->pokCvor;
		i++;
	}

	cout << "Matrica susedstva:\n";

	for (int i = 0; i < this->brCvorova; i++) {

		for (int j = 0; j < this->brCvorova; j++)
			cout << matSusedstva [i][j];

		cout << endl;
	}

	cout << endl << endl;
}

void dinGraf::povezanost () {

	//Ova f-ja trazi da li je orijentisani graf jako povezan, tj da li je svaki cvor sa svakim
	//povezan. Generise se niz pokazivaca na cvorove u koga se smestaju svi cvorovi. U drugoj 
	//while petlji se proverava za tekuci cvor (novi) da li postoji poteg ka svakom cvoru, tj 
	//svakom pokazivacu u nizu. Ako bar jedan poteg ne postoji, onda izlazi se iz petlje.

	cvor* niz [10];
	cvor* novi = this->start;
	int i = 0;

	while (novi) {

		niz [i] = novi;
		i++;
		novi = novi->pokCvor;
	}

	novi = this->start;
	bool p = true;

	while (novi && p) {

		for (int j = 0; j < 10 && p; j++) 
			if (!this->nadjiGranu (novi, niz [j]))
				p = false;

		novi = novi->pokCvor;
	}

	if (p)
		cout << "Graf je jako povezan!";

	else
		cout << "Graf je slabo povezan!";
}