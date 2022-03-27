#include "HashTable.h"

HashTable::HashTable(int x)
{
	n=x;
	t=0;
	a=new HashObject[n];
}
HashTable::~HashTable()
{
	if(t>0)
	{
		for(int i=0;i<n;i++)
			if(!a[i].get_free())
				a[i].deleterecord();
		delete [] a;
	}
}
int HashTable::h(HashObject obj)
{
	char *tmp=obj.get_tel();
	int n=strlen(tmp);
	int br=0;
	for(int i=n-3;i<n;i++)
		br=br*10+(tmp[i]-'0');
	return br%1000;
}
void HashTable::insert(HashObject& obj)
{
	if(t==n-1)
		throw "Tablica puna.";
	int probe=h(obj);
	if(!this->a[probe].get_free())//prvo ulancamo
	{
		while(a[probe].get_next()!=-1)
			probe=a[probe].get_next();
		int tail=probe;
		probe=(probe+1)%n;
		while(!a[probe].get_free() && probe!=tail)
			probe=(probe+1)%n;
		if(probe==tail)
			throw "Lose si izveo ponovno ulancavanje.";
		a[tail].set_next(probe);
	}
	a[probe]=obj;//pa tek onda unesemo vrednost u objekat
	a[probe].set_next(-1);
	t++;
}
void HashTable::withdraw(char* key)
{
	if(t==0)
		throw "Tabla je prazna";
	HashObject tmp("","",key);
	int probe=h(tmp);
	int prev=-1;
	while(probe!=-1 && strcmp(a[probe].get_tel(),key))
	{
		prev=probe;
		probe=a[probe].get_next();
	}
	if(probe==-1)
		throw "Element nije nadjen.";
	if(prev!=-1)
	{
		a[prev].set_next(a[probe].get_next());
		a[probe].deleterecord();
	}
	else
	{
		if(a[probe].get_next()==-1)
		{
			a[probe].deleterecord();
		}
		else
		{
			int nextel=a[probe].get_next();
			a[probe].deleterecord();
			a[probe]=a[nextel];
			a[nextel].deleterecord();
			a[nextel].set_next(-1);
		}
	}
	t--;
}
void HashTable::display()
{
	for(int i=0;i<n;i++)
		if(!a[i].get_free())
		{
			cout<<"["<<i<<"]"<<"-> ";
			a[i].print();
			cout<<"next->"<<a[i].get_next()<<endl;
		}
	cout<<"//////////"<<endl;
}