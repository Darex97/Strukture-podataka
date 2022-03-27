#include "element.h"
class Polinom
{
private:
	Element* head;
	Element* tail;
public:
	Polinom(){ this->head = NULL; this->tail = NULL; }
	Polinom(Polinom& p);
	~Polinom();
	void dodajNaHead(int, int);
	void dodajNaTail(int, int);
	void dodaj(int, int);
	void stampaj();
	Polinom* Saberi(Polinom, Polinom);
	Polinom* Pomnozi(Polinom, Polinom);
};