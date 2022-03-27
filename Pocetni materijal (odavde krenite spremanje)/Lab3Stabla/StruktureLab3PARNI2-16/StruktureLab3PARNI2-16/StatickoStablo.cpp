#include"StatickoStablo.h"

//Mahom je kod identican kao za dinamicko stablo sa razlikom 
//u tome sto je levo dete onamo bilo p->left, a ovde
//p[2*tekuci+1], a desno umesto p->right p[2*tekuci+2]
StatickoStablo::StatickoStablo(int brojNivoa)
{
	t = 0;
	m = 1;
	for (int i = 0;i < brojNivoa;i++)
		m = m * 2;
	m--;//jedna je majka(koren)
	cvorovi = new int*[m];
	for (int i = 0;i < m;i++)
		cvorovi[i] = NULL;
}
StatickoStablo::~StatickoStablo()
{
	//Bunilo te je, pazi:
	//Moras da obrises svaki clan ponaosob zato sto radis
	//sa pointerima,inace bi oni ostali "da vise", da je bio obican niz, dovoljno bi
	//bilo delete [] niz, ali nije takav slucaj. :D
	if (cvorovi != NULL)
	{
		for (int i = 0;i < m;i++)
			if (cvorovi[i] != NULL)
				delete cvorovi[i];
	}
	delete[] cvorovi;
}
void StatickoStablo::ubaci(int el)
{
	if (m == t)
		throw "Nema vise mesta.";
	int tekuci = 0;
	int prethodni;
	while (cvorovi[tekuci] != NULL && tekuci < m)
		//vodimo i racuna o opsegu, za to sluzi ovaj 2. uslov
	{
		prethodni = tekuci;
		if (*cvorovi[tekuci] > el)
			//neophodna nam je zvezdica da pristupimo tome
			//na sta nam ukazuje konkretan pointer
			tekuci = 2 * tekuci + 1;//levi potomak
		else if (*cvorovi[tekuci] < el)
			tekuci = 2 * tekuci + 2;//desni potomak
		else return;//ako su jednaki
	}
	//nasli smo indeks gde cemo da ubacimo element,
	//sad sledi ubacivanje
	if (tekuci >= m)//ne znamo koji nas je uslov izbacio
		return;//pa moramo da proverimo oba
	if (cvorovi[0] == NULL)
	{
		//Postavljamo koren
		//Moramo da zauzemo mesto prvo, to nismo uradili u KK, tamo
		//smo zauzeli mesto za niz pointera, a sad nam treba
		//mesto za konkretan podatak
		cvorovi[0] = new int;
		*cvorovi[0] = el;
		//pristupamo samom mestu(*)i njemu dodeljujemo
		//vrednost el
		t++;
	}
	else if (*cvorovi[prethodni] > el)//kao levi potomak
	{
		//seti se da ti se prethodni azurira pri svakom
		//ulasku u while
		cvorovi[2 * prethodni + 1] = new int;
		*cvorovi[2 * prethodni + 1] = el;
		t++;
	}
	else if (*cvorovi[prethodni] < el)//kao desni potomak
	{
		cvorovi[2 * prethodni + 2] = new int;
		*cvorovi[2 * prethodni + 2] = el;
		t++;
	}
}
void StatickoStablo::prikazi()
	{
		//sve je isto kao u dinamickoj implementaciji
		//prosledjujes koren
		prikazi(0);
		cout << endl;
	}
void StatickoStablo::prikazi(int p)
{
	//Inorder
	if (p < m && cvorovi[p] != NULL)//Do kraja, ili do lista
	{
		prikazi(2 * p + 1);//cepas levo(ides po levoj deci)
		cout << *cvorovi[p] << " ";
		prikazi(2 * p + 2);//cepas desno
	}
}
int StatickoStablo::visina()
	{
		return visina(0);
	}
int StatickoStablo::visina(int p)
{
	//ili smo premasili opseg, ili je stablo prazno
	if (p >= m || cvorovi[p] == NULL)
		return 0;
	//Ako element nema potomaka
	//Isti je uslov kao za dinamicko stablo, samo je razlika
	//sto ovde vodis racuna i da ne prekoracis opseg
	if ((2 * p + 1 > m || cvorovi[2 * p + 1] == NULL) && (2 * p + 2 >= m || cvorovi[2 * p + 2] == NULL))
		return 1;
	//Provali ovo: sad nemas * ispred cvorova, ali poredis sa pointerom pa nema ni potrebe
	return 1 + max(visina(2 * p + 1), visina(2 * p + 2));
}
int StatickoStablo::max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int StatickoStablo::moment()
{
	return t;
}
int StatickoStablo::tezina()
{
	int tezina = 0;
	for (int i = 0;i < m;i++)
	{
		if (cvorovi[i] != NULL)
		{
			//Moguci slucajevi:
			//Da premasimo opseg, to znaci da smo kod lista,
			//ili, 2. slucaj, da JESTE u opsegu, ali da nema decu
			//sto ponoovo znaci da je u pitanju list.
			if (2 * i + 1 >= m)//tezina u dinamcikom je 1+rekurzija
				tezina++;
			else if (cvorovi[2 * i + 1] == NULL && cvorovi[2 * i + 2] == NULL)
				tezina++;
		}
	}
	return tezina;
}
void StatickoStablo::brisanjeListova()
{
	//aspolutno identicna logika kao malopre, trazis listove
	//postoje 2 mogucnosti sa njima
	for (int i = 0;i < m;i++)
	{
		if (cvorovi[i] != NULL)
		{
			if (2 * i + 1 >= m)
			{
				delete cvorovi[i];
				cvorovi[i] = NULL;//oznacavamo da je to mesto sada prazno
			}
			else if (cvorovi[2 * i + 1] == NULL && cvorovi[2 * i + 2] == NULL)
			{
				delete cvorovi[i];
				cvorovi[i] = NULL;
			}
		}
	}
}
void StatickoStablo::mirrorKopija()
{
	//celjavo malo
	int **pom = new int*[m];//pomocni niz pointera
	int i = m - 1;//poslednji element
	int shift = (m + 1) / 2;//roditelj poslednjeg
	int max = m;
	//Ideja: Prepisujemo svaki nivo unazad.
	//2. Povlacimo sve prepisane elemente tako da poslednji element koji smo
	//prepisali bude na kraju nivoa (ogledalo-efekat)
	while (shift >= 1)
	{
		for (int k = 0;k < shift;k++)
		{
			pom[k] = cvorovi[i];//s desna u levo do shifta
			i--;
		}
		for (int k = 0;k < shift;k++)
		{
			pom[max - 1 - k] = pom[max - k - shift];
		}
		max = max - shift;
		shift /= 2;
	}
	for (int k = 0;k < m;k++)//kopiranje u polazni niz
		cvorovi[k] = pom[k];
	delete[] pom;
}
void StatickoStablo::spajanjeStabala(StatickoStablo& ss)
{
	for (int i = 0;i < ss.m;i++)
		if (ss.cvorovi[i] != NULL)
			this->ubaci(*ss.cvorovi[i]);//Obrati paznju gde ide * ovde
	//ubaci u tekuci
}
int StatickoStablo::nivoSaNajviseCvorova()
{
	int bmax=0;
	int b = 0;
	int k = 2;//k je indikator kada predjemo u naredni nivo
	for (int i = 0;i < m;i++)
	{
		if (((i + 1) % k )!= 0)
		{
			if (cvorovi[i] != NULL)
				b++;
		}
		else//ako udjes u else-granu zavrsio si sa nivoom
		{
			if (b > bmax)
				bmax = b;
			b = 0;//reinicijalizacija
			k *= 2;//naredni nivo je dva puta veci uvek
			if (cvorovi[i] != NULL)//provera prvog elementa u nivou
			//jer gore kreces od i+1
				b++;
		}
	}
	return bmax;
}