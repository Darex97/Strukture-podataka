#include "ChainedHashTable.h"
#include <cmath>
using namespace std;
int ChainedHashTable::h(HashObject o)//na osnovu kljuca zadaje index u tablicu
{
	char *tmp=o.gettel();
	int n=strlen(tmp);
	int br=0;
	for(int i=n-3;i<n;i++)
		br=br*10+(tmp[i]-'0');
	return br%1000;
}
ChainedHashTable::ChainedHashTable(int x)
{
	this->n=x;
	this->t=0;
	this->array=new LList[n];
}
ChainedHashTable::~ChainedHashTable()
{
	LList *l;
	for(int i=0;i<n;i++)
	{
		l=&array[i];
		while(!l->IsEmpty())
			l->deletefromhead();
	}
	delete [] array;
}
void ChainedHashTable::insert(HashObject& obj)
{
	array[h(obj)].addtohead(obj.getime(),obj.getprezime(),obj.gettel());
	this->t++;
}
void ChainedHashTable::withdraw(HashObject obj)
{
	array[h(obj)].deleteEl(obj.gettel());
	this->t--;
}
void ChainedHashTable::display()
{
	for(int i=0;i<this->n;i++)
	{
		HashObject *tmp=array[i].gethead();
		while(tmp)
		{
			cout<<"["<<i<<"]"<<"-> ";
			tmp->print();
			tmp=tmp->getnext();
			cout<<" "<<endl;
		}
	}
	cout<<endl;
}