#include "LLista.h"
LLista::~LLista()
{
	/*Cvor* tmp;
	while (this->head != NULL)
	{
		tmp = this->head;
		this->head = this->head->next;
		delete tmp;
	}*/
}
void LLista::addToHead(int a)
{
	if (this->head == NULL)
	{
		this->head = new Cvor(a, NULL);
		this->tail = this->head;
	}
	else
	{
		this->head = new Cvor(a, this->head);
	}
}
void LLista::Stampaj()
{
	Cvor* tmp = this->head;
	while (tmp != NULL)
	{
		tmp->Stampaj();
		tmp = tmp->next;
	}
	cout << endl;
}
void LLista::bubbleSort()
{
	Cvor *i, *j;
	bool flag, flag1;
	do
	{
		i = this->head;//Ovde hocu da j i j->next menjaju mesta ako treba,
		j = this->head->next;//a ovo i samo cuva prethodni clan, zbog povezivanja u listu.
		flag = false;//Zastavica koja zaustavlja sortiranje ako prodje kroz niz bez ijedne zamene mesta.
		if (j != NULL && i->info > j->info)//Ovo posebno obradjuje slucaj gde prvi element
		{									// menja mesta sa drugim, posto prvi nema prethodni clan. 
			this->head = i->next;
			i->next = i->next->next;
			this->head->next = i;
			j = i;//ovo treba ako se izvrsi zamena mesta, da vrati da i bude prvo
			i = this->head; //a j drugo
		}
		while (j->next!=NULL)
		{
			flag1 = false;
			if (j->info > j->next->info)
			{
				i->next = j->next;
				j->next = j->next->next;
				i->next->next = j;
				flag = true;
				flag1 = true;
			}
			if (flag1==false)//ako se izvrsi zamena mesta, j
				j = j->next;//ce vec da predje na sledeci element
			i = i->next;
		}
	
	} while (flag);




}
Cvor* LLista::vratiPrethodni(Cvor* c)
{
	Cvor* tmp;
	if (c == this->head)
		return NULL;
	else
	{
		tmp = this->head;
		while (tmp->next != NULL && tmp->next != c)
			tmp = tmp->next;
	}
	return tmp;
}
void LLista::nekiSort()
{ 
	Cvor* i = this->head->next, *j;
	bool flag;
	while (i != NULL)
	{
		j = this->vratiPrethodni(i);
		flag = false;
		while (!flag && j != NULL)
		{
			if (i->info < j->info)
				j = this->vratiPrethodni(j);
			else
				flag = true;
		}
		if (j != NULL)
			this->zameniMesta(j->next, i);
		else
			this->zameniMesta(this->head, i);
		i = i->next;
		this->Stampaj();
	}
}
void LLista::zameniMesta(Cvor* c1, Cvor* c2)
{
	Cvor *i = this->vratiPrethodni(c1), *j = this->vratiPrethodni(c2), *pom;
	if (i==NULL)
	{
		pom = c1->next;
		c1->next = c2->next;
		this->head = c2;
		if (j != c1)
		{
			j->next = c1;
			c2->next = pom;
		}
		else
			c2->next = c1;
		if (c2 == this->tail)
			this->tail = c1;
		
	}
	else if (j == NULL)
	{
		pom = c2->next;
		c2->next = c1->next;
		this->head = c1;
		if (i != c2)
		{
			i->next = c2;
			c1->next = pom;
		}
		else
			c1->next = c2;
		if (c1 == this->tail)
			this->tail = c2;
	}
	else
	{
		pom = c1->next;
		c1->next = c2->next;
		i->next = c2;
		if (j != c1)
		{
			j->next = c1;
			c2->next = pom;
		}
		else
			c2->next = c1;
		if (c2 == this->tail)
			this->tail = c1;
	}
	//pom = c1;
	//c1 = c2;
	//c2 = pom;
}
void LLista::insertionSort()
{
	Cvor* i = this->head->next, *j, *pom;
	bool flag;
	while (i != NULL)
	{
		j = this->vratiPrethodni(i);
		flag = false;
		while (!flag && j != NULL)
		{
			if (i->info > j->info)
				flag = true;
			else
				j = this->vratiPrethodni(j);
		}
		if (j == NULL)
		{
			//menjas tekuci sa glavom
			//tacnije ne menjas, nego na prvo mesto ubacujes tekuci element
			//a sve ostalo siftas u desno
			
			pom = this->vratiPrethodni(i);
			pom->next = i->next;
			i->next = this->head;
			this->head = i;
			i = pom->next;
			
		}
		else if (j != this->vratiPrethodni(i))
		{
			//ovaj "pasus" koda, je isti kao prethodni, samo ne menjas sa glavom
			//nego sa nekim od elemenata u nizu
			pom = this->vratiPrethodni(i);
			pom->next = i->next;
			i->next = j->next;
			j->next = i;
			i = pom->next;

		}
		else
			i = i->next;
		this->Stampaj();
	}
}
void LLista::selectionSort()
{
	Cvor* i = this->head, *j, *min;
	while (i != tail)
	{
		min=i;
		j = i->next;
		while (j != NULL)
		{
			if (j->info < min->info)
				min = j;
			j = j->next;
		}
		if (min != i)
		{
			this->zameniMesta(i, min);
			i = min->next;
		}
		else
			i = i->next;
		this->Stampaj();
	}
}
void LLista::insertSorted(LLista listToInsert)
{
	//Kolokvijum 2016, popravni
	Cvor *prvi, *drugi, *umetnik;
	prvi = getHead();
	
	umetnik = listToInsert.getHead();
	//Granicni slucajevi:
	//ako menjam sa glavom:
	if (prvi->info > umetnik->info)
	{
		Cvor* pomocnik = umetnik;
		umetnik = umetnik->next;
		pomocnik->next = prvi;
		head = pomocnik;
		prvi = getHead();
	}

	drugi = prvi->next;
	while(umetnik!=NULL)
	{
		if (drugi->next != NULL)
		{
			if (drugi->info > umetnik->info)
			{
				prvi->next = umetnik;
				umetnik = umetnik->next;
				prvi->next -> next = drugi;
				prvi = prvi->next;
			}
			else
			{
				prvi = prvi->next;
				drugi = drugi->next;
			}
		}
		else
		{
			if (umetnik != NULL)
			{
				drugi->next = umetnik;
				umetnik = NULL;//da izadje iz petlje
			}
		}
	}

	Cvor* samoDaVidimNesto = getHead();
	Cvor* zaBrisanje = listToInsert.getHead();
	zaBrisanje = NULL;
	//Ovo radi, ako nemas destruktor, jer ce on da ti izbrise ovo sto ti preneses po vrednosti, to je listToInsert.
}
void LLista::update(int value, int add)
{
	Cvor* tmp = getHead();
	//Granicni slucaj:
	if (tmp->info = value)
	{
		tmp->info += add;
		head = tmp->next;
		Cvor* prvi, *drugi,*cuvar;
		prvi = tmp;
		cuvar = tmp;
		for (drugi = tmp->next;cuvar->info > drugi->info;drugi = drugi->next, prvi = prvi->next)
		{
			if (drugi->next == NULL)
			{
				//Za slucaj da dodajemo na kraj.
		     	drugi->next = cuvar;
				cuvar->next = NULL;
				return;
			}
		}

			cuvar->next = drugi;
			prvi->next = cuvar;


	}
	else {
		Cvor* pomocni, *pomocniPomocnik, *prethodni, *naredni;
		for (;tmp->info != value;tmp = tmp->next);
		for (pomocniPomocnik = getHead();pomocniPomocnik->next->info != tmp->info;pomocniPomocnik = pomocniPomocnik->next);
		pomocniPomocnik->next = tmp->next;
		naredni = tmp->next;
		prethodni = tmp;
		tmp->info = tmp->info + add;
		while (tmp->info > naredni->info)
		{
			//tmp = tmp->next;
			naredni = naredni->next;
			prethodni = prethodni->next;
		}
		prethodni->next = tmp;
		tmp->next = naredni;
	}
}
//redovni 2014
void LLista::groupDuplicates()
{
	Cvor *cuvar, *prvi, *drugi;
	cuvar = getHead();
	prvi = getHead();
	drugi = prvi->next;
	while (cuvar->next != NULL && drugi!=NULL)
	{
		//while (drugi != NULL)
		{
			while (drugi != NULL &&drugi->info != cuvar->info )
			{
				prvi = drugi;
				drugi = drugi->next;
			}
			if (drugi != NULL)
			{
				prvi->next = drugi->next;
				drugi->next = cuvar->next;
				cuvar->next = drugi;
				//zavrseno ulancavanje
				drugi = prvi->next;
				cuvar = cuvar->next;
			}
			}
		if (drugi == NULL)
		{
			cuvar = cuvar->next;
		}
			prvi = cuvar->next;
			if (prvi != NULL) 
			{
				drugi = prvi->next;
			}
			Stampaj();
		}
	}
