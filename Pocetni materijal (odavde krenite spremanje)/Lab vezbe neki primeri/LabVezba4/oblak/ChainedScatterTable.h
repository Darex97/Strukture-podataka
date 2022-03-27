#include "ScatterObject.h"
template<class T,class R>
class ChainedScatterTable : public ScatterObject<T,R>
{
protected:
	ChainedScatterObject<T,R>* niz;
public:
	ChainedScatterTable(unsigned int len)
	{
		length=len;
		count=0;
		niz=new ChainedScatterObject<T,R>[len];
		for(int i=0;i<len;i++)
		{
			niz[i]=ChainedScatterObject<T,R>();
			niz[i].free=true;
			niz[i].next=-1;
		}
	}

	~ChainedScatterTable()
	{
		for(int i=0;i<length;i++)
			niz[i].deleteRecord();
		delete [] niz;
	}

	void display()
	{
		for(int i=0;i<length;i++)
			if(!niz[i].free)
			{
				cout<<"["<<i<<"]"<<"|";
				niz[i].print();
				cout<<"|"<<niz[i].next<<endl;
			}
			else
				cout<<"["<<i<<"]"<<endl;
	}

	void insert(ChainedScatterObject<T,R> obj)
	{
		if(count==getLength())
			throw "Tabel is full";
		long probe = h(obj);
		if(!niz[probe].free)
		{
			while(niz[probe]!=-1)
			{
				probe=niz[probe].next;
			}
			long tail=probe;
			probe=g(probe);
			while(!niz[probe].free && probe!=tail)
				probe=g(probe);
			if(probe==tail)
				throw "Poor secondary transformation";
			niz[tail].next=probe;
		}
		niz[probe]=obj;
		niz[probe].free=false;
		niz[probe].next=-1;
		count++;
	}

	void insertAll(ChainedScatterObject<T,R>* nizo,int n)
	{
		for(int i=0;i<n;i++)
		{
			insert(nizo[i]);
		}
	}

};


