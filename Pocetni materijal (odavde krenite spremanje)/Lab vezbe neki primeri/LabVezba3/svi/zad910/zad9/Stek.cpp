#include "Stek.h"

Stek::Stek(int x)
{
	velicina=x;
	niz=new int[velicina];
	vrh=-1;
}
Stek::~Stek()
{
	delete [] niz;
}
void Stek::push(int i)
{
	if(velicina==brelemenata())
		throw "Prekoracenje";
	niz[++vrh]=i;
}
int Stek::pop()
{
	if(vrh==-1)
		throw "Potkoracenje";
	int rez=niz[vrh--];
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
void Stek::reverseaqueue()
{
	Queue tmp(brelemenata());
	while(!IsEmpty())
		tmp.enqueue(this->pop());//stek->red(prepisujem iz steka u red)
	while(!tmp.IsEmpty())//red->stek(sad posto ide od pocetka u stek ce se elementi upisivati u suprotan redosled)
		this->push(tmp.dequeue());
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
void Stek::copyStack(Stek& tmp)//mora preko reference zboh zbog dinamickog niza (*niz)
{
	delete [] niz;
	velicina=tmp.velicina;
	niz=new int[velicina];
	vrh=-1;
	//rezervisan novi prostor
	Stek tmp1(tmp.brelemenata());
	while(!tmp.IsEmpty())
		tmp1.push(tmp.pop());//u tmp1 su elementi iz tmp u obrnuti redosled
	while(!tmp1.IsEmpty())
		this->push(tmp1.pop());
}