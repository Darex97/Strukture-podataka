#include"Lancana.h"
#include<iostream>
using namespace std;
void Lancana::print()
{
	for (Cvor* tmp = head; tmp != NULL; tmp = tmp->sl)
		cout << tmp->print()<<" ";
}
void Lancana::dodajnaGlavu(int el)
{
	if (!prazna()) {
		head = new Cvor(el, NULL, head);
		head->sl->pr = head;
	}
	else head = tail = new Cvor(el);

}
void Lancana::dodajnaRep(int el)
{
	if (!prazna())
	{
		tail = new Cvor(el, tail, NULL);
		tail->pr->sl = tail;
	}
	else head = tail = new Cvor(el);
}
Lancana::~Lancana()
{
	while (!prazna())
		int tmp = DeleteGlava();
}
int Lancana::DeleteGlava()
{
	if (prazna())
		throw exception("prazna");
	int k = head->info;
	Cvor* tmp = head;
	if (head == tail)
		head = tail = NULL;
	else
		head = head->sl;
	delete tmp;
	return k;
}
int Lancana::DeleteREp()
{
	if (prazna())
		throw exception("prazna");
	int k = tail->info;
	Cvor* brisanje = tail;
	if (head == tail)
		head = tail = NULL;
	else
	{
		Cvor* tmp;
		for (tmp = head; tmp->sl != tail; tmp = tmp->sl);
		tail = tmp;
		tail->sl = NULL;
	}
	delete brisanje;
	return k;

}
bool Lancana::ulisti(int el)
{
	Cvor* tmp;
	for ( tmp = head; tmp != NULL && !(tmp->jednak(el)); tmp = tmp->sl);
		if (tmp == NULL) {
			cout << "nema ga";
			return false;
		}
		else {
			cout << "tu je";
			return true;
		}
}
int Lancana::getNextEl(int el)
{
	Cvor* trazi, * sledeci;
	for (trazi = head, sledeci = head->sl;sledeci!=NULL && trazi != NULL && !(trazi->jednak(el)); trazi = trazi->sl, sledeci = sledeci->sl);
	if ( sledeci==NULL || trazi == NULL)
		cout << "nema ga";
	else {
		cout << sledeci->print();
		return sledeci->info;
	}

}
Cvor* Lancana::nadjicvor(int el)
{
	Cvor* trazi;
	for (trazi = head; trazi != NULL && !(trazi->jednak(el)); trazi = trazi->sl);
	if (trazi == NULL)
		cout << "nema ga samo treba da se baci exception";
	else
	{	
		cout << trazi->info;
		trazi->sl->info = 777;
		return trazi;

	}
}
void Lancana::deleteEl(int el)
{
	if (prazna())
		cout << "prazna";
	 if (head == tail && head->jednak(el))
	{
		delete head;
		head = tail = NULL;
	}
	 else if (el == head->info)
	 {
		 Cvor* tmp = head;
		 head = head->sl;
		 head->pr = NULL;
		 delete tmp;
	 }
	else
	{
		Cvor* tmp;
		for (tmp = head; tmp != NULL && !(tmp->jednak(el)); tmp = tmp->sl);
		if (tmp != NULL)
		{
			tmp->pr->sl = tmp->sl;
			if (tmp->sl)
				tmp->sl->pr = tmp->pr;
			if (tmp == tail)
				tail = tmp->pr;
			delete tmp;
		}

	}
	}

