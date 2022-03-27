#pragma once
#include<iostream>//ukljucujem zbog NULL pointera
//on se nalazi u ovoj biblioteci
#include"SLLNode.h"
using namespace std;

template<class T>
class SLList {
protected:
	SLLNode<T> *head, *tail;
public:
	SLList() { head = tail = NULL; }
	~SLList();
	bool isEmpty() { return head == NULL; }//ispituje da li je head jednako NULL
	void addToHead(T el);
	void addToTail(T el);
	T deleteFromHead();
	T deleteFromTail();
	SLLNode<T>* findNodePtr(T el);
	SLLNode<T>* getHead() { return head; }
	SLLNode<T>* getNext(SLLNode<T>* ptr);
	T getHeadEl();
	T getNextEl(T el);
	void printAll();
	bool isInList(T el);
	void deleteEl(T el);
};
//Templejtska klasa pa je definicija funkcija u istom fajlu 
//u kome je i dekleracija.
template<class T>
SLList<T>::~SLList()
{
	while (!isEmpty())
	//Zanimljivo je da ti ovu fju isEmpty mozes da pozoves iz fajla u
	//kome je bila deklarisana bez navodjenja objekta
	//Kao da je globalna za ovaj fajl, ako me razumes.
    //Sta se zapravo desava, ti je pozivas za this.
	{
		T tmp = deleteFromHead();

	}
}
template<class T>
void SLList<T>::printAll() {
	//Obrati paznju kako obilazis listu!
	//Brojac ti je pointer na tip Cvor! JAKO BITNO!
	//Nemoj da te buni ovo SLLNode<T>* to ti je kao int
	//da ti stoji npr. >>> TIP PODATKA <<<
	//Kreces od POKAZIVACA NA GLAVU, odradis sta treba,
	//Pa ti je sledeci pointer onaj koji je sadrzala glava 
	//i tako redom. Lako je i zabavno. :)
	//Kidas. ;)
	for (SLLNode<T>* tmp = head; tmp != NULL;tmp = tmp->next)
		
		cout << tmp->print() << " ";//koristimo fju print iz SLLNode
	//Za pristup funkciji koristis strelicu, a ne tacku, jer imas pointer
	//znam da da znas, samo te podsecam.
}
template<class T>
void SLList<T>::addToHead(T el) {
	head = new SLLNode<T>(el, head);
	if (tail == NULL)
	{
		//Posto imamo jedan element samo smo njegov pokazivac usmerili na glavu. 
				tail = head;
	}
}

template<class T>
void SLList<T>::addToTail(T el) {
	if (!isEmpty())
	//Ako nije prazan:
	{
		//Pokazivac tekuceg repa nije vise NULL
		//vec pokazivac na novi cvor koji u Info
		//delu ima vrednost "el"
		tail->next = new SLLNode<T>(el);
		//a novi rep postaje vrednost repa novog elementa
		//tj. NULL
		tail = tail->next;
	}
	else
		head = tail = new SLLNode<T>(el);
}
//Vracas izbrisani element, jer obicno kad se brise nesto, znaci
//da je taj element procitan. U ovom slucaju je prenos po vrednosti.
//Okinuo bi se Copy-KK, da je potrebno. 
template<class T>
T SLList<T>::deleteFromHead()
{

	if (isEmpty())
		throw "Lista je prazna.";
	//cuvamo vrednost elementa u listi koji ce biti izrisan
	T el = head->info;
    // Pravimo pokazivac tipa Cvor na glavu.
	SLLNode<T>* tmp = head;
	if (head == tail)
		head = tail = NULL;
	else
		//Glava je cvor i mi sad tom cvoru dodeljujemo info i link 
		//prvog narednog elementa
		//strelica verovatno jer je head pointer
		head = head->next;
	//A s obzirom da je tmp pointer tipa cvor na glavu, brisanjem njega
	//brisemo i samu glavu
	delete tmp;
	return el;
}
template<class T>
T SLList<T>::deleteFromTail() {
	
	if (isEmpty())
	{
		throw"Lista je prazna";
	}
	T el = tail->info;
	SLLNode<T>* forDel = tail;
	if (head == tail)
	{
		head = tail = NULL;
	}
	else
	{
		SLLNode<T>* tmp;
		for (tmp = head;tmp->next != tail;tmp = tmp->next);
		//VODI RACUNA GORE TI SE FOR ZAVRSAVA SA TACKA-ZAREZOM
		//Objasnjenje:

		//int i;
		//for (i = 0;i < 10;i++);
		//cout << i;
		
		//Ova petlja stampa 10. Zasto? Zato sto kada se for petlja
		//zavrsava sa ; tada je ona obican brojac, ne postoji telo petlje
		//samo se inkrementira brojac u svakom prolazu.
		//Kada i bude 9, to je manje od 10, pa ce po poslednji put da se inkrementira
		//i izaci ce iz petlje, sto znaci da ce ti istampati 10.

		//Konkretno ova petlja ovde se zavrsava na pretposlednjem elementu.
		tail = tmp;//tail postaje pretposlednji
		tail->next = NULL;//i njegov rep postaje NULL pointer
	}
	delete forDel;
	return el;
}
template<class T>
void SLList<T>::deleteEl(T el) {
	if (isEmpty())
		throw "Lista je prazna.";
	//Uslov koji ispituje da li je element prvi i jedini:
	if (head == tail && head->isEqual(el))
		//u njihovom kodu za drugi uslov stoji:
		// head->info.Equal(el) sto cini sve neispravnim
		//Ovo je i logicno i tacno.
	{
		delete head;
		head = tail = NULL;
	}
	else if (el == head->info)//dal je prvi
	{
		SLLNode<T> *tmp = head;
		head = head->next;
		delete tmp;
	}
	else
		//Na kraju proveravamo da li je ovaj element negde nakon prvog
	{
		SLLNode<T> *pred, *tmp;
		//Posmatraj gde stoji ; to ti odvaja celine
		for (pred = head, tmp = head->next; tmp != NULL && !(tmp->isEqual(el)); pred = pred->next, tmp = tmp->next);
		//Vrtis petlju dok ne dodjes do kraja, ili trazenog elementa
		//i oba pointera uvek pomeras za po jedno mesto
		if (tmp != NULL) //Gledamo da li je doso do poslednjeg elementa, ako 
			//jeste znaci da zadati element nije u listi i nema brisanja.
		{
			//Brisanje:
			pred->next = tmp->next;
			if (tmp == tail)
				tail = pred;
			delete tmp;
		}
	}
}