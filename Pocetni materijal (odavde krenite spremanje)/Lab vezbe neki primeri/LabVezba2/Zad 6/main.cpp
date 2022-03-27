#include "class.h"

int main()
{
	StaticSortList x;
	x.dodaj_na_pocetak(5);
	x.dodaj_na_pocetak(7);
	x.dodaj_na_pocetak(2);
	x.stampaj();
	x.dodaj_na_pocetak(8);
	x.dodaj_na_pocetak(22);
	x.stampaj();
	x.sort(true);
	x.stampaj();
	x.sort(false);
	x.stampaj();
	system("pause");
	return 0;
}
