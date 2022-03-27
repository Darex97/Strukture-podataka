#include <iostream>
using namespace std;

class StaticSortDDList
{
	int velicina;
	int* before;
	int* next;
	int* info;
public:
	void konstruktor(int k)
	{
		velicina=k+2;
		before=new int[velicina];
		next=new int[velicina];
		info=new int[velicina];
		for(int i=2;i<velicina-1;i++)
			next[i]=i+1;
		next[velicina-1]=-1;
		for(int i=2;i<velicina;i++)
			before[i]=i-1;
		next[0]=2;
		before[0]=-1;
		before[2]=0;
		next[1]=-1;
		before[1]=-1;
		next[velicina-1]=-1;
	}
	StaticSortDDList()
	{
		konstruktor(20);
	}
	StaticSortDDList(int k)
	{
		konstruktor(k);
	}
	void dodaj_na_pocetak(int k)
	{
		if(next[0]==-1)
			cout<<"Ne moze se dodati novi element"<<endl;
		else
		{
			int temp=next[0];
			info[temp]=k;
			next[1]=temp;
			next[0]=next[temp];
			if(temp==2)
			{
				before[2]=1;
				next[2]=-1;
			}
			else
			{
				before[temp]=1;
				next[temp]=temp-1;
				before[temp-1]=temp;
			}
		}
	}
	void stampaj()
	{
		int i=1;
		while(next[i]!=-1)
		{
			i=next[i];
			cout<<info[i]<<" ";
		}
		cout<<endl;
	}
	void sort(bool rastuci)
	{
		int i=1;
		int k=-1;
		while(next[i]!=-1)
		{
			int j=next[1];
			while(next[j]!=k)
			{
				if(rastuci==true)
				{
					if(info[j]>info[next[j]])
					{
						int pom=info[j];
						info[j]=info[next[j]];
						info[next[j]]=pom;
					}
				}
				else
				{
					if(info[j]<info[next[j]])
					{
						int pom=info[j];
						info[j]=info[next[j]];
						info[next[j]]=pom;
					}
				}
				if(next[j]==k)
					k=j;
				j=next[j];
			}
			i=next[i];
		}
	}
};
