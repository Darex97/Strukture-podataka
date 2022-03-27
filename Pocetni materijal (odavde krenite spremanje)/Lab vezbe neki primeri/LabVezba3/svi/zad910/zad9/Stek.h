#include "Queue.h"
#include <iostream>
using namespace std;
class Stek
{
	int *niz;
	int velicina;
	int vrh;
public:
	Stek(int);
	~Stek();
	void push(int);
	int pop();
	int gettop(){return niz[vrh];};
	bool IsEmpty(){return vrh==-1;};
	int brelemenata(){return vrh+1;};
	void reverseastack();
	void reverseaqueue();
	void stampaj();
	void copyStack(Stek&);
};