#include "Lancana.h"
#include"Cvor.h"
#include<iostream>
using namespace std;
void Lancana::print()
{
	for (Cvor* tmp = head; tmp != NULL; tmp = tmp->next)
		cout << tmp->print() << " ";
}
void Lancana::dodajnaglavu(int el)
{
	head = new Cvor(el, head);
	if (tail == NULL)
		tail = head;
}
void::Lancana::dodajnarep(int el)
{
	if (!prazno())
	{
		tail->next = new Cvor(el);
		tail = tail->next;
	}
	else
		head = tail = new Cvor(el);
}


int Lancana::deletehead()
{
	if (prazno())
		throw exception("Lista prazna!");
	int el = head->info;
	Cvor* tmp = head;
	if (head == tail)
		head = tail = NULL;
	else
		head = head->next;
	delete tmp;
	return el;

}
Lancana::~Lancana()
{
	while (!prazno())
		int tmp = deletehead(); // da li da brisem sa glave ili i sa glave i sa repa//BRISES UVEK SA GLVAE OVAKO AKO NIJE TRAZENO SA REPA
}
int Lancana::deletetail()
{
	if (prazno())
		throw exception("Praznaaaa");
	int el = tail->info;
	Cvor* zabrisanje = tail;
	if (head == tail)
		head = tail = NULL;
	else
	{
		Cvor* tmp;
		for (tmp = head; tmp->next != tail ;  tmp = tmp->next);
		tail = tmp;
		tail->next = NULL;
	}
	delete zabrisanje;
	return el;
}
void Lancana::deleteel(int el)
{
	if (prazno())
		throw exception("Praznaskrskr");

	if (head == tail && head->jednak(el)) // mala ispravka
	{
		delete head;
		head = tail = NULL;
	}
	else if (el == head->info)
	{
		Cvor* tmp = head;
		head = head->next;
		delete tmp;
	}
	else {
		Cvor* pred, * tmp;
		for (pred = head, tmp = head->next; tmp != NULL && !(tmp->jednak(el)); pred = pred->next, tmp = tmp->next);
		if (tmp != NULL)
		{

			pred->next = tmp->next;

			if (tmp == tail)
				tail = pred;
			delete tmp;
		}
	}
}
Cvor* Lancana::nadjicvor(int el)
{
	Cvor* vrati;
	for (vrati = head; vrati->next != NULL && !(vrati->next->jednak(el)); vrati = vrati->next);

	cout << vrati->info; // ovo je kod za vracanje prethodnog elementa
	return vrati;



}
Cvor* Lancana::uzmisledeci(Cvor ptr)
{
 
		Cvor * trazi;
		for (trazi = head; trazi != NULL && !(trazi->info == ptr.info); trazi = trazi->next);
			//for (trazi = head->next, vrati = head; trazi != NULL && !(trazi->info == ptr.info); trazi = trazi->next, vrati = vrati->next);
		
		cout <<trazi->next->info;
		return trazi->next;
	
}
void Lancana::Exchange(Lancana& list, int value, int lenght)
{
	int b = lenght;
	int i = 1;
	Cvor* pomocni,*original;
	Lancana* k;
	k = &list;
	pomocni = k->head;
	original = head;
	for (original,pomocni; original != NULL && !(original->info == value); original = original->next, pomocni=pomocni->next);
	
	while (b != 0)
	{
		original->info = pomocni->info;
		original = original->next;
		pomocni = pomocni->next;

		b--;
	}
	
	

	
}
Cvor* Lancana::FormList(int* niz)
{
	Lancana k;
	int* pomN;
	int* s = niz;
	Cvor* pomocni;
	pomocni = k.head;
	
	int pom = 0;
	int l = 0;//za for
	int i = 0;//broj elementa
	while (*s!=7777)
	{
		
		pom++;
		s++;
		k.dodajnaglavu(s[i]);
	}
	
	k.print();

	return pomocni;


}
void Lancana::UpdateNode(int key, int value)
{
	Cvor* original, * pomocni,*provera=head, * provera2 = head->next;
	int k = key;
	int v = value;
	if (provera->info == k)
		provera->info += v;
	if (provera2->info == k)
	{
		provera2->info += v;
		head = provera2;
		delete provera;
	}
	for (pomocni = head, original = head->next->next; original != NULL && !(original->jednak(k)); pomocni = pomocni->next, original = original->next);
	if (original!=NULL && original->jednak(k)) {
		original->info += v;
		provera = pomocni->next;
		
		pomocni->next = original;
		provera->next = original->next;
		original->next = provera;
		
	}
	else this->dodajnaglavu(v);
}