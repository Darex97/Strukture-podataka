#include <iostream>
using namespace std;
class Stek
{
	char *niz;
	int velicina;
	int vrh;
public:
	Stek(int);
	~Stek();
	void push(char);
	char pop();
	char gettop(){return niz[vrh];};
	bool IsEmpty(){return vrh==-1;};
	int brelemenata(){return vrh+1;};
	void reverseastack();
	void stampaj();
};