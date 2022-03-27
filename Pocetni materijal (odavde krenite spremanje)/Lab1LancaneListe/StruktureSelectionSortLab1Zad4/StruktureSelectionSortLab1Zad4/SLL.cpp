#include"SLL.h"
#include"CvorListe.h"
#include<iostream>
using namespace std;

SLL::~SLL()
{
	while (!isEmpty())
	{
		deleteFromHead();
		//ekvivaletno zapisu: this->deleteFromHead
	}
}
void SLL :: addToHead(int element) {
	if (head != NULL)
		head = new CvorListe(element, head);
	else
		tail = head = new CvorListe(element);
}
void SLL::addToTail(int element) {
	if (!isEmpty()) {
		tail->next = new CvorListe(element, NULL);
		//onaj koji bude posle trenutnog tail-a dobice navedenu vrednost
		tail = tail->next;
	}
	else
	{
		head = tail = new CvorListe(element);
	}
}
int SLL::deleteFromHead() {

	if (!isEmpty())
	{
		int el = head->info;
		//da mozemo da vratimo vrednost koju 
		//cemo da izbrisemo
		CvorListe* tmp = head;
		//tmp pravimo da ne bismo pisali posle
		//delete head, jer nam je head nesto drugo
		//pa brisemo tmp;
		if (head == tail)
			head = tail = NULL;
		else
			head = head->next;
		delete tmp;
		return el;
	}
}
int SLL::deleteFromTail() {
	if (!isEmpty())
	{
		int vracamInfo;
		CvorListe* zaBrisanje;
		CvorListe* tmp;
		vracamInfo = tail->info;
		//cuvamo vrednost koju ce da vrati fja
		if (head == tail)
	  //proveravamo da li je nasa lista sacinjena od
			//1 elementa
		{
			head = tail = NULL;
		}
		else
		{
			for (tmp=head;tmp->next != NULL;tmp = tmp->next);
			//vracamInfo = tmp->next->info;
			tail = tmp;
			//novi tejl nam je pretposlednji
			tmp->next = NULL;
			//poslednji brisemo
		}
		delete zaBrisanje;
		return vracamInfo;
		}
}
void SLL::printAll() {
	for (CvorListe* tmp=head;tmp!= NULL;tmp = tmp->next)
		tmp->print();
}
void SLL::SelectionSort() {
	CvorListe* i;
	i = head;
	while(i->next!=NULL)
	//ovde sam stavio while zbog fora koji je na kraju while-a
	{
		int pomocniBrojac = 0;

		CvorListe* min = i;
		for (CvorListe* j = i->next;j != NULL;j = j->next)
		
			
			if (min->info > j->info)
			{
				min = j;
			}

			zameniMesta(i,min);
	//Ovo radi da menjas samo info delove:
			//	CvorListe* min= new CvorListe(j->info);
			//if (i->info > j->info)
			//{
				//min->info = i->info;
				//i->info = j->info;
				//j->info = min->info;
			//}
			glavniBrojac++;
			//Da znamo od kog narednog elementa da podjemo.
			for (i = head;pomocniBrojac != glavniBrojac;i = i->next)
			{
				pomocniBrojac++;
			}
	}
}
void SLL::zameniMesta(CvorListe* i, CvorListe* j) {
	CvorListe* pomocni = new CvorListe(i->info, i->next);
	//sad nam je u privremenom tekuci
	CvorListe* m, *l;
	for (m = head;m->next->info != j->info;m = m->next);
	//vozis do onog koji prethodi minimalnom
	if (m->info == i->info)
	{
		//Poseban slucaj ako su i-ti i prethodni minimalnom
		//isti. Izbegavas upadanje u beskonacnu petlju.
		for (l = head;l->next->info != m->info;l = l->next);
		l->next = j;
		m->next = j->next;
		j->next = m;
	}
	else {
		m->next = i;
		i->next = j->next;
		j->next = pomocni->next;
	}
	if (glavniBrojac == 0)
	{
		head = j;
	}
	else if (m->next != NULL)
	{
		for (m = head;m->next->info != i->info;m = m->next);
		m->next = j;
	}
	printAll();
	cout << endl;
}
void SLL::BubbleSort() {
	int pomocniBubbleBrojac;
	CvorListe *i, *j,*m;
	//Ideja:
	/*
	Prebrojis koliko imas elemenata, za to sluzi prvi for.
	I svaki put obilazis jedan element manje, jer ce na kraj
	niza uvek da ti "ispliva" najveci.
	*/

	for (i = head;i->next != NULL;i = i->next)
	{
		glavniBubbleBrojac++;
	}

	while(glavniBubbleBrojac!=0)
	{
		
		pomocniBubbleBrojac =0;
		j = head;

		while (pomocniBubbleBrojac<glavniBubbleBrojac-1)
			//kao da ides od 0 do n-1
		{
			int flag = 0;
			if (j->info > j->next->info)
			{
				//Ako je levi veci od desnog, zamenis im mesta
				CvorListe* tmp = new CvorListe(j->next->info,j->next->next);
				j->next = j->next->next;
				tmp->next = j;
				if (j->info == head->info)
				{
					//Granicni slucaj ako menjas sa glavom lancane liste.
					//Ovo je granicni slucaj jer glava nema prethodni
					//element koji ukazuje na nju.
					//Sto jeste slucaj sa ostalim elementima.
					head = tmp;
				}
				else
				{
					//a ovo je slucaj za sve ostale vrednosti
					for ( m = head;m->next->info != j->info;m=m->next);
					m->next = tmp;

					
				}
				flag = 1;
			}
			if (flag == 0)
			{
				//ako nista nisi zamenio ipak moras da se pomeris 
				//za jedan element u desno
				j = j->next;
			}
			cout << endl;
			printAll();
			pomocniBubbleBrojac++;
		}
		glavniBubbleBrojac--;
		//svaki put obilazimo jedan element manje
		//jer je poslednji uvek najveci, tj. vec sortiran
	}
}
