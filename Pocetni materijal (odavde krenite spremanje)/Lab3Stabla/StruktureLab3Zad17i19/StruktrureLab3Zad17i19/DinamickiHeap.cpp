#include"DinamickiHeap.h"

DinamickiHeap::DinamickiHeap()
{
	koren = NULL;
	brojElemenata = 0;
}
DinamickiHeap::~DinamickiHeap()
{
	obrisiHeap(koren);
}
void DinamickiHeap::obrisiHeap(HeapElement* p)
{
	if (p != NULL)
	{
		obrisiHeap(p->levi);
		obrisiHeap(p->desni);
		delete p;
	}
}
void DinamickiHeap::ubaci(int element)
{
	if (brojElemenata == 0)
	{
		koren = new HeapElement(element, NULL);
		brojElemenata++;
		return;
	}
	HeapElement* p = koren;
	HeapElement* q;
	int b = brojElemenata + 1;
	char put[30];
	int i = 0;
	while (b > 3)
		//Ideja: Kreces od trenutnog lista
		//i odredjujes da li ce da se nalazi tvoj cvor sa leve
		//ili desne strane i penjes se ka korenu konstantno
		//odredjuci strane
		//Jer kad nacrtas heap, primecujes da element levo od 
		//roditelja je paran po redosledu dodavanja, a levo neparan
		//tako se penjes ka vrhu, a posle spustas sa vrha
	{
		if (b % 2 == 0)
			put[i++] = 'l';
		else put[i++] = 'd';
		b /= 2;
	}
	//ovo je da odredis dal je levo, ili desno od samog korena
	if (b % 2 == 0)
		put[i] = 'l';
	else put[i] = 'd';
	while (i > 0) 
	{
		if (put[i] == 'l')
			p = p->levi;
		else p = p->desni;
		i--;
	}
	//Doso si do lista, dodajes novi element.
	if (put[i] == 'l')
	{
		p->levi = new HeapElement(element, p);
		q = p->levi;
	}
	else
	{
		p->desni = new HeapElement(element, p);
		q = p->desni;
	}
	brojElemenata++;
	//Dodali smo element sad treba da ga metnemo gde treba
	while (p != NULL)
	{
		//q je dete
		//p je roditelj
		if (q->info > p->info)
		{
			//Ako je dete vece od roditelja
			//menjamo im mesta, jer radimo sa MaxHeap-om
			int pom = q->info;
			q->info = p->info;
			p->info = pom;
		}
		else 
			return;//ako nije
		//probaj sa retrun;
		p = p->roditelj;
		q = q->roditelj;
	}
}
void DinamickiHeap::inorderPrikaz()
{
	inorderPrikaz(koren);
	cout << endl;
}
void DinamickiHeap::inorderPrikaz(HeapElement* p)
{
	if (p != NULL)
	{
		inorderPrikaz(p->levi);
		cout << p->info << " ";
		inorderPrikaz(p->desni);
	}
}
void DinamickiHeap::spojiHipove(DinamickiHeap& d)
{
	ubaciElemente(d.koren);
}
void DinamickiHeap::ubaciElemente(HeapElement* p)
{
	//Nista posebno, samo obilazis novo stablo
	//u inordredu i njegove elemente klasicno ubacujes
	if (p != NULL)
	{
		ubaciElemente(p->levi);
		this->ubaci(p->info);
		ubaciElemente(p->desni);
	}
}
void DinamickiHeap::prebaciUMinHeap()
{
	int b = brojElemenata;
	int *a = new int[b];
	prebaciUPolje(a, koren);
	obrisiHeap(koren);
	brojElemenata = 0;
	koren = NULL;
	for (int i = 0;i < b;i++)
		ubaciUMinHeap(a[i]);
	delete [] a;
}
void DinamickiHeap::prebaciUPolje(int* a, HeapElement* p)
{
	static int i;//jedino ovako mozemo da regulisemo da ne setuje
	//svaki put i na nulu, nego da koristi JEDNU ISTU vrednost 
	//za sve rekurzije
	if (p != NULL)
	{
		prebaciUPolje(a, p->levi);
			a[i++] = p->info;
			prebaciUPolje(a, p->desni);
	}
}
void DinamickiHeap::ubaciUMinHeap(int element)
{
	if (brojElemenata == 0)
	{
		koren = new HeapElement(element, NULL);
		brojElemenata++;
		return;
	}
	HeapElement* p = koren;
	HeapElement* q;
	int b = brojElemenata + 1;
	char put[30];
	int i = 0;
	while (b > 3)
	{
		if (b % 2 == 0)
			put[i++] = 'l';
		else put[i++] = 'd';
		b /= 2;
	}

	if (b % 2 == 0)
		put[i] = 'l';
	else put[i] = 'd';
	while (i > 0)
	{
		if (put[i] == 'l')
			p = p->levi;
		else p = p->desni;
		i--;
	}

	if (put[i] == 'l')
	{
		p->levi = new HeapElement(element, p);
		q = p->levi;
	}
	else
	{
		p->desni = new HeapElement(element, p);
		q = p->desni;
	}
	brojElemenata++;
	while (p != NULL)
	{
		//q je dete
		//p je roditelj
		if (q->info < p->info)//RAZLIKA
		{
			
			int pom = q->info;
			q->info = p->info;
			p->info = pom;
		}
		else
			return;
		p = p->roditelj;
		q = q->roditelj;
	}
}
/*void DinamickiHeap::update(int val, int add)
{
	HeapElement* p = koren;
	while (p->info != val)
	{
		if(p->info>val)
	}
}*/
/*HeapElement** DinamickiHeap::trazim(int v, HeapElement*p)
{
	HeapElement** pp=new HeapElement*();
	if (p != NULL)
	{
		trazim(v, p->levi);
		if (p->info == v)
			*pp = p;
		trazim(v, p->desni);
	}
	return pp;
}*/



//Dare radio naknadno:
/*
Pogledaj projekat StrukturePt2 za detaljnije informacije:
Smestanje elemenata:

void DinamickiHeap::ubaciMaxHeap(int elem)
{
if (koren == NULL)
{
koren = new HeapElement(elem, NULL);
brojElemenata++;
return;
}
int b = brojElemenata;
HeapElement* pok = koren;
//	HeapElement* previous= koren;
queue<HeapElement*> mojRed;
mojRed.push(pok);
while (pok->desni != NULL && pok->levi != NULL)
{
//   previous=pok;
mojRed.push(pok->levi);
mojRed.push(pok->desni);
pok = mojRed.front();
mojRed.pop();
}
if (pok->levi == NULL)
{
pok->levi = new HeapElement(elem, pok);
brojElemenata++;
rasporediMax(pok->levi);
}
else
{
pok->desni = new HeapElement(elem, pok);
brojElemenata++;
rasporediMax(pok->desni);
}
}
void DinamickiHeap::rasporediMax(HeapElement* p)
{
while (p->roditelj!=NULL && p->roditelj->info < p->info)
{
int pom = p->info;
p->info = p->roditelj->info;
p->roditelj->info = pom;
p = p->roditelj;
}

}
*/