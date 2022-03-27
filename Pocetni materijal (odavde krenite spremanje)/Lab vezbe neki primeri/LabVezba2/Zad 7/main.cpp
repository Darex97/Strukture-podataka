#include "class.h"

int main()
{
	StaticSortDDList x(5);
	x.dodaj_na_pocetak(15);
	x.dodaj_na_pocetak(6);
	x.dodaj_na_pocetak(11);
	x.stampaj();
	x.dodaj_na_pocetak(32);
	x.dodaj_na_pocetak(24);
	x.stampaj();
	x.dodaj_na_pocetak(5);
	x.stampaj();
	x.sort(true);
	x.stampaj();
	x.sort(false);
	x.stampaj();
	system("pause");
	return 0;
}
