#include "Polinom.h"
Polinom::~Polinom()
{
	
		Element* tmp = this->head;
		while (tmp != NULL)
		{
			this->head = this->head->next;
			delete tmp;
			tmp = this->head;
		}
		
}

void Polinom::stampaj()
{
	Element* tmp = this->head;
	while (tmp != NULL)
	{
		tmp->Stampaj();
		tmp = tmp->next;
	}
	cout << endl;
}
Polinom* Polinom::Saberi(Polinom a, Polinom b)
{
	Element *i, *j;
	i = a.head;
	j = b.head;
	while (i != j && i!= NULL&& j!=NULL)
	{
		if (i->stepen == j->stepen)
		{
			this->dodajNaTail(i->koef + j->koef, i->stepen);
			i = i->next;
			j = j->next;
		}
		else if ( i->stepen > j->stepen)
		{
			this->dodajNaTail(i->koef, i->stepen);
			i = i->next;
		}
		else if (j->stepen>i->stepen)
		{
			this->dodajNaTail(j->koef, j->stepen);
			j = j->next;
		}
	}
	if (i == NULL)

	{
		while (j != NULL) {
			this->dodajNaTail(j->koef, j->stepen);
			j = j->next;
		}
	}
	else if (j == NULL)
	{
		while (i != NULL)
		{
			this->dodajNaTail(i->koef, i->stepen);
			i = i->next;
		}
	}
	return this;
}
void Polinom::dodajNaHead(int a, int b)
{
	if (this->head == NULL)
	{
		this->head = this->tail = new Element(a, b, NULL);
	}
	else 
	{
		this->head = new Element(a, b, this->head);
		
	}
}
void Polinom::dodajNaTail(int a, int b)
{
	if (this->head == NULL)
	{
		this->dodajNaHead(a, b);
		this->tail = this->head;
	}
	else
	{
		this->tail->next = new Element(a, b, NULL);
		this->tail = this->tail->next;
	}
}
Polinom::Polinom(Polinom& p)
{
	Element* tmp = p.head;

	//inicijalizujes na nulu head i tail jer
	//tu prepisujes dati polinom
	this->head = NULL;
	this->tail = NULL;
	while (tmp!=NULL)
	{
		this->dodajNaTail(tmp->koef, tmp->stepen);
		tmp = tmp->next;
	}
}
Polinom* Polinom::Pomnozi(Polinom x, Polinom y)
{
	Element *i, *j;
	i = x.head;
	j = y.head;
	while (i != NULL)
	{
		while (j != NULL)
		{
			this->dodaj(i->koef*j->koef, i->stepen + j->stepen);
			j = j->next;
		}
		i = i->next;
		j = y.head;
	}
	return this;
}
void Polinom::dodaj(int k, int e)
{
	Element* pom = this->head;

	bool flag = false;
	//ako ti je prazan polinom ili ti je stepen veci od stepena
	//head-a dodajes ga na pocetak
	if (pom==NULL || e > this->head->stepen)
	{
		this->dodajNaHead(k, e);
		flag = true;
	}
	//ako ti je stepen  koji si prosledio manji od stepena tail-a dodajes 
	//ga na kraj polinoma
	else if (e < this->tail->stepen)
	{
		this->dodajNaTail(k, e);
		flag = true;
	}
	//Najkomplikovanija situacija:

	while (flag == false && pom != NULL)
	{
	//Prosledjeni stepen vec postoji u polinomu
		// samo saberes koeficijente
		if (pom->stepen == e)
		{
			pom->koef += k;
			flag = true;
		}	
		else if (pom->stepen > e&&pom->next->stepen < e)
		{
	//Prethodni stepen je veci, a naredni manji, znaci moras da umetnes ono sto si
			//prosledio
			pom->next = new Element(k, e, pom->next);
			flag = true;
		}
		//inkrementator
		else
			pom = pom->next;
	}

}