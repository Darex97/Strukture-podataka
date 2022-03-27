#include <iostream.h>
#include "StatDLList.h"

int main(){

	StatDLList lista(5);
	lista.AdHead();
	lista.AdHead();	
	lista.brisi(7);
	lista.AdHead();
	lista.AdHead();
	lista.brisi(-2);
	lista.AdHead();
	lista.prikazi();
	lista.brisi(1);
	lista.brisi(3);
	lista.brisi(4);
	lista.AdHead();
	lista.brisi(0);
	lista.AdHead();
	lista.AdHead();
	lista.AdHead();
	lista.AdHead();
	lista.prikazi();

	return 0;
}


//Ultra fancy lista! Radi s'a 'oces!
