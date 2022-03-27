#include "SLLNode.h"

class SLList
{
private:
	SLLNode *head,*tail;
public:
	SLList();//pomocu ovog konstruktora kreiramo praznu listu
	~SLList();//*destruktor obezbedjuje brisanje cele dinamicke liste

	void AddToTail(int el);//*funkcija koja dodaje novi cvor na kraj liste
	void AddToHead(int el);//*funkcija koja dodaje cvor na pocetak liste

	void Print();//*funkcija za stampanje liste

	int DeleteFromTail();//*funkcija koja brise zadnji cvor iz liste
	int DeleteFromHead();//*funkcija za brisanje prvog cvora u listi
	void DeleteElement(int el);//*funkcija za brisanje cvora ciji je info deo jednak zadatom delu

	void IsInList(int el);//*funkcija ispituje da li je neki element u listi

	void DeleteAll();//*funkcija brise sve elemente iz liste

	int NumberOfNodes();//*funkcija vraca broj cvorova u listi


	//void Sort();
};