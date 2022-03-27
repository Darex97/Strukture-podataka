#include "HashTable.h"

HashTable::HashTable(int x)
{
	m=x;
	n=2*m;
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
int HashTable::f(char* b)
{
	int res=0;
	int a=7;
	for(int i=0;b[i]!=0;i++)
		res=res<<a^b[i];
	return res;
}
int HashTable::h(HashObject obj)
{
	return (f(obj.get_keyword())%m);
}
void HashTable::insert(HashObject& obj)
{
	if(t==n-1)
		throw "Tablica puna.";
	int probe1=h(obj);
	int probe=m;
	if(!this->a[probe1].get_free())//prvo ulancamo
	{
		while(a[probe].get_next()!=-1)
			probe=a[probe].get_next();
		int tail=probe;
		probe=(probe+1)%n;
		if(probe==n)
			probe=m;
		while(!a[probe].get_free() && probe!=tail)
			probe=(probe+1)%n;
		if(probe==tail)
			throw "Lose si izveo ponovno ulancavanje.";
		a[probe1].set_next(probe);
		a[probe]=obj;
		a[probe].set_next(-1);
		t++;
	}
	else
	{
		a[probe1]=obj;
		a[probe1].set_next(-1);
		t++;
	}
}
void HashTable::withdraw(char* key)
{
	if(t==0)
		throw "Tabla je prazna";
	int probe=f(key)%m;
	int prev=-1;
	while(probe!=-1 && strcmp(a[probe].get_keyword(),key))
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
			cout<<"["<<i<<"]"<<"->";
			a[i].print();
			cout<<"next->"<<a[i].get_next()<<endl;
		}
		else
			cout<<"["<<i<<"]"<<endl;
	cout<<"//////////"<<endl;
}