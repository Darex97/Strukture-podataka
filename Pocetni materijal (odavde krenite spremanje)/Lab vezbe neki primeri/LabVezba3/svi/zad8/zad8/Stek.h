#include "Node.h"
class Stek
{
	Node* vrh;
public:
	Stek();
	~Stek();
	bool IsEmpty(){return vrh==NULL;};
	void deletefromhead();
	void push(int);
	int pop();
	int gettop(){return vrh->getinfo();};
	void stampaj();
};