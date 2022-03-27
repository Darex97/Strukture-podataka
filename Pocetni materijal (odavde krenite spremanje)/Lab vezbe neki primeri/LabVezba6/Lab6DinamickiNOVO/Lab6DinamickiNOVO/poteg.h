#pragma once

#include "klase.h"

class cvor;

class poteg {

public:
	int tezina;
	cvor* dest;
	poteg* pokPoteg;

public:
	poteg ();
	poteg (int* tez, cvor* destinacija, poteg* naredni) {

		this->tezina = *tez;
		this->dest = destinacija;
		this->pokPoteg = naredni;
	}
	~poteg () { delete dest; delete pokPoteg; }
};