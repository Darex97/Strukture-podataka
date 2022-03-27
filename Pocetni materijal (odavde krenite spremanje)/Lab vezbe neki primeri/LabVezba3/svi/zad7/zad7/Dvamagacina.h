#include <iostream>
using namespace std;
class Dvamagacina
{
	int *niz;
	int velicina;
	int vrh1;
	int brel1;
	int vrh2;
	int brel2;
public:
	Dvamagacina(int);
	~Dvamagacina();
	void push1(int);
	void push2(int);
	int pop1();
	int pop2();
	int getinfo1(){return niz[vrh1];};
	int getinfo2(){return niz[vrh2];};
	void stampaj();
};