#include "Cvor.h"
class LLista
{
private:
	Cvor* head, *tail;
public:
	LLista(){ this->head = NULL; this->head = NULL; }
	~LLista();
	Cvor* getHead() { return head; }
	Cvor* getTail() { return tail; }
	void addToHead(int);
	void Stampaj();
	void bubbleSort();
	void insertionSort();
	void nekiSort();
	Cvor* vratiPrethodni(Cvor*);
	void zameniMesta(Cvor*, Cvor*);
	void selectionSort();
	void insertSorted(LLista listToInsert);//popravni 2016
	void update(int value, int add);//redovni 2015
	void groupDuplicates();//popravni 2016
};