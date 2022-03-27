#include <iostream>
using namespace std;

class StaticSortList
{
	int velicina;
	int* info;
	int* link;
public:
	void konstruktor(int k)
	{
		velicina=k+2;
		link=new int[velicina];
		for(int i=2;i<velicina-1;i++)
			link[i]=i+1;
		link[0]=2;
		link[1]=-1;
		link[velicina-1]=-1;
		info=new int[velicina];
	}
	StaticSortList()
		{
			konstruktor(20);
		}
		StaticSortList(int k)
		{
			konstruktor(k);
		}
		~StaticSortList()
		{
			delete [] info;
			delete [] link;
		}
	void dodaj_na_pocetak(int k)
	{
		if(this->link[0]==-1)
			cout<<"Nema mesta."<<endl;
		else
			{
				int temp=link[0];
				info[temp]=k;
				link[0]=link[temp];
				link[temp]=link[1];
				link[1]=temp;
			}
	}
	void stampaj()
	{
		for(int i=link[1];i!=-1;i=link[i])
			cout<<info[i]<<" ";
		cout<<endl;
	}
	void sort(bool rastuci)
	{
		for(int i=link[1]; i!=-1; i=link[i])
			for(int j=link[i]; j!=-1; j=link[j])
		{
			if(rastuci)
			{
				if (info[i]>info[j])
				{
					int tmp=info[i];
					info[i]=info[j];
					info[j]=tmp;
				}
			}
			else if (info[i]<info[j])
				{
					int tmp=info[i];
					info[i]=info[j];
					info[j]=tmp;
				}
		}

}
};