#include <iostream>
using namespace std;
class Cvor
{
public:
	int info;
	Cvor* next;
	
	Cvor(){ next = NULL; info = 0; }
	Cvor(int a, Cvor* c){ this->info = a; this->next = c; }
	~Cvor(){}
	void Stampaj();
};