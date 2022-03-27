#include "Stek.h"
#include <string>
using namespace std;
Stek::Stek(int x)
{
	velicina=x;
	niz=new char[velicina];
	vrh=-1;
}
Stek::~Stek()
{
	delete [] niz;
}
void Stek::push(char i)
{
	if(velicina==brelemenata())
		throw "Prekoracenje";
	niz[++vrh]=i;
}
char Stek::pop()
{
	if(vrh==-1)
		throw "Potkoracenje";
	char rez=niz[vrh--];
	return rez;
}
void Stek::reverseastack()
{
	Stek tmp1(brelemenata()),tmp2(brelemenata());
	while(!IsEmpty())
		tmp1.push(this->pop());//prepisuje u pomocni stek u obrnuti redosled
	while(!tmp1.IsEmpty())//prepisuje u neki drugi  stek u isti redosled kao u pocetnom steku
		tmp2.push(tmp1.pop());
	while(!tmp2.IsEmpty())//prepisuje u polazni stek u obrnutom redosledu
		this->push(tmp2.pop());
}
void Stek::stampaj()
{
	int tmp=vrh;
	while(vrh!=-1)
	{
		cout<<this->gettop()<<endl;
		vrh--;
	}
	vrh=tmp;
	cout<<"/////"<<endl;
}
