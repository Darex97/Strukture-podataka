#pragma once

#include "poteg.h"

class poteg ;

class cvor {

public:
	double kljuc;
	cvor* pokCvor;
	poteg* pokPoteg;
	int status;
	
public:
	cvor ();
	cvor (double);
	cvor (double, cvor*);
	~cvor () { delete pokCvor; delete pokPoteg; }
};