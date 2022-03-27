#include"Cvor.h"
#include<iostream>
using namespace std;
class Lancana
{
protected:
	Cvor* head, * tail;
public:
	Lancana() { head = tail = NULL; }
	~Lancana();
	bool prazno() { return head == NULL; }
	void dodajnaglavu(int el);
	void dodajnarep(int el);
	int deletehead();
	int deletetail();
	void deleteel(int el);
	Cvor* nadjicvor(int el);
	Cvor* uzmiglavu() {
		//cout << head->info;
		return head;
	}
	Cvor* uzmisledeci(Cvor ptr);
	int uzmielglava() { return head->info; }
	//int uzmislel();
	//bool ulistije(int el);
	void Exchange(Lancana& list, int value, int lenght);

	void print();
	Cvor* FormList(int* niz);
	void UpdateNode(int key, int value);




};
