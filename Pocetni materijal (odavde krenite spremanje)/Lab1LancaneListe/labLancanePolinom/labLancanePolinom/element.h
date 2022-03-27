#include <iostream>
using namespace std;
class Element
{
public:
	int koef;
	int stepen;
	Element* next;
	Element() :koef(0), stepen(0){ this->next = NULL; }
	Element(int a, int b, Element* c) :koef(a), stepen(b), next(c){}
	//Element(Element& e);
	~Element(){}
	void Stampaj();
};