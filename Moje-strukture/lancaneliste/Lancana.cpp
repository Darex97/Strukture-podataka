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

Lancana::~Lancana()
{
	while (!prazno())
		int tmp = deletehead(); // da li da brisem sa glave ili i sa glave i sa repa//BRISES UVEK SA GLVAE OVAKO AKO NIJE TRAZENO SA REPA
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
		for (tmp = head; tmp->next != tail ; tmp = tmp->next);
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
	Cvor* vrati,*trazi;
	for (vrati = head, trazi = head->next; trazi != NULL && !(trazi->jednak(el)); vrati = vrati->next, trazi = trazi->next);
	
	cout << vrati->info; // ovo je kod za vracanje prethodnog elementa
	return vrati;
	


}
Cvor* Lancana::uzmisledeci(Cvor ptr)
{
	Cvor* vrati, * trazi;
	for (trazi = head->next, vrati = head; trazi != NULL && !(trazi->info == ptr.info); trazi = trazi->next, vrati = vrati->next);
	cout << vrati->info;
	return vrati;

}