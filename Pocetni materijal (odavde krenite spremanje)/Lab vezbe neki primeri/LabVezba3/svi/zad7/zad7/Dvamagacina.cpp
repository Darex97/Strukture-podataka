#include "Dvamagacina.h"

Dvamagacina::Dvamagacina(int n)
{
	velicina=n;
	niz=new int[velicina];
	vrh1=-1;
	vrh2=velicina;
	brel1=brel2=0;
}
Dvamagacina::~Dvamagacina()
{
	delete [] niz;
}
void Dvamagacina::push1(int x)
{
	if((brel1+brel2)==velicina)
		throw "Polje sa magacinima je puno";
	niz[++vrh1]=x;
	brel1++;
}
void Dvamagacina::push2(int x)
{
	if((brel1+brel2)==velicina)
		throw "Polje sa magacinima je puno";
	niz[--vrh2]=x;
	brel2++;
}
int Dvamagacina::pop1()
{
	if(brel1==0)
		throw "Magacin1 je prazan";
	int rez=niz[vrh1--];
	brel1--;
	return rez;
}
int Dvamagacina::pop2()
{
	if(brel2==0)
		throw "Magacin2 je prazan";
	int rez=niz[vrh2++];
	brel2--;
	return rez;
}
void Dvamagacina::stampaj()
{
	cout<<"Mag1: ";
	for(int i=0;i<=vrh1;i++)
		cout<<niz[i]<<" ";
	cout<<endl;
	cout<<"Mag2: ";
	for(int i=vrh2;i<velicina;i++)
		cout<<niz[i]<<" ";
	cout<<endl<<"//////////"<<endl;
}