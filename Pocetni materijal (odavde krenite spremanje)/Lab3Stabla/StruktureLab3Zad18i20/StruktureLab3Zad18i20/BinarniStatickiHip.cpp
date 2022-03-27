#include"BinarniStatickiHip.h"

BinarniStatickiHip::BinarniStatickiHip(int l)
{
	duzina = l;
	brojElemenata = 0;
	elementi = new int[duzina+1];
	//pozicija sa indeksom 0 je prazna
	for (int i = 0;i < duzina+1;i++)
		elementi[i] = -1;
}
BinarniStatickiHip::BinarniStatickiHip(BinarniStatickiHip& b)
{
	duzina = b.duzina;
	brojElemenata = b.brojElemenata;
	elementi = new int[brojElemenata++];
	for (int i = 0;i < duzina + 1;i++)
		elementi[i] = b.elementi[i];
}
BinarniStatickiHip::~BinarniStatickiHip()
{
	if (elementi != NULL)
		delete[] elementi;
}
void BinarniStatickiHip::ubaci(int element)
{
	if (brojElemenata == duzina) throw "Hip je pun.";
	int i = brojElemenata + 1;
	while (i > 1 && elementi[i / 2] < element)
	{
		//1. uslov proveravamo da li smo stigli do korena
		//2. uslov ako je roditelj manji od deteta, menjamo im mesto
		elementi[i] = elementi[i / 2];
		i /= 2;
	}
	elementi[i] = element;
	brojElemenata++;
}
void BinarniStatickiHip::stampaj()
{
	//bice rasporedjeni tako da je najveci sto blizi pocetku
	//tj. u opadajucem redosledu posto radis sa MaxHipom
	//stampas po nivoima, baj d vej
	for (int i = 0;i < duzina + 1;i++)
		cout << elementi[i] << " ";
	cout << endl;
}
void BinarniStatickiHip::spojiHipove(BinarniStatickiHip& b)
{
	//BinarniStatickiHip rezultat(duzina + b.duzina);
	//for (int i = 1;i < brojElemenata;i++)
		//rezultat.ubaci(elementi[i]);
	for (int i = 1;i < b.brojElemenata;i++)
		this->ubaci(b.elementi[i]);
	return;
}
/*void BinarniStatickiHip::prebaciUMinHip()
{
	BinarniStatickiHip hipPomocnik(*this);//kopiramo treuntni hip
	delete[] elementi;//obrisan tekuci i u njega ubacujemo minheap
	elementi = new int[duzina + 1];
	for (int i = 0;i < duzina + 1;i++)
		elementi[i] = -1;
	brojElemenata = 0;
	for (int i = 1;i < hipPomocnik.brojElemenata;i++)
		ubaci(hipPomocnik.elementi[i]);//za pojedinacne elemente iz pomocnog(kopiranog tekuceg)
	stampaj();
}*/
void BinarniStatickiHip::prebaciUMinHip()
{
	int* a = new int[duzina + 1];
	for (int i = 0;i < duzina + 1;i++)
		a[i] = elementi[i];

	delete[] elementi;
	elementi = new int[duzina+1];
	for (int i = 0;i < duzina+1;i++)
		elementi[i] = -1;
	brojElemenata = 0;
	for (int i = 1;i < duzina;i++)
		ubaciUMin(a[i]);
	delete[] a;
	//stampaj();
}
void BinarniStatickiHip::ubaciUMin(int element)
{
	if (brojElemenata == duzina+1) throw "Hip je pun.";
	int i = brojElemenata + 1;
	while (i > 1 && elementi[i / 2] > element)//RAZLIKA
	{
		//1. uslov proveravamo da li smo stigli do korena
		//2. uslov ako je roditelj manji od deteta, menjamo im mesto
		elementi[i] = elementi[i / 2];
		i /= 2;
	}
	elementi[i] = element;
	brojElemenata++;
}
int BinarniStatickiHip::trazim(int val)
{
	for (int i = 0;i < brojElemenata;i++)
		if (elementi[i] == val)
			return i;
	throw "Trazeni element ne postoji.";
}
void BinarniStatickiHip::update(int val, int add)
{
	int indeks = trazim(val);
	elementi[indeks] += add;
	if (add > 0)
	{
		while (indeks<=brojElemenata+1 && elementi[indeks] > elementi[indeks * 2])
		{
			int pom = elementi[indeks];
			elementi[indeks] = elementi[indeks * 2];
			elementi[indeks * 2] = pom;
			indeks *= 2;
		}
	}
	else if (add < 0)
	{
		while (indeks>0 && elementi[indeks] < elementi[indeks / 2])
		{
			int pom = elementi[indeks];
			elementi[indeks] = elementi[indeks / 2];
			elementi[indeks / 2] = pom;
			indeks /= 2;
		}
	}
}