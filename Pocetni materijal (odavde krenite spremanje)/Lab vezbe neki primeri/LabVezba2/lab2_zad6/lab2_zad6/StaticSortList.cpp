#include "StaticSortList.h"
#include <iostream>
using namespace std;

CStaticSortList::CStaticSortList(int s)
{
	size = s;
	info=new int[size];
	next=new int[size];
	for(int i=2; i<size;i++)
		next[i]=i+1;
	next[0]=2; //LRMP
	next[1]=-1; //head
	next[size-1]=-1; //poslednji u nizu, ukazuje na null
}

CStaticSortList::~CStaticSortList(void)
{
	delete [] info;
	delete [] next;
}

void CStaticSortList::addToHead(int el)
{
	if(next[0]==-1)
		throw "Nema mesta!";
	int tmp=next[0]; // tmp = new node;
	info[tmp]=el; // tmp->info=el;
	next[0]=next[tmp]; // lrmp=tmp->link, tmp se brise iz LRMP
	next[tmp]=next[1]; // 
	next[1]=tmp;
}

void CStaticSortList::print()
{
	for(int i=next[1]; i!=-1; i=next[i])
		cout << info[i] << endl;
}

void CStaticSortList::bubbleSort(bool rastuci)
{
	for(int i=next[1]; i!=-1; i=next[i])
		for(int j=next[i]; j!=-1; j=next[j])
		{
			if(rastuci)
			{
				if (info[i]>info[j])
				{
					int tmp=info[i]; // treba da se uradi zamena pokazivaca, a ne vrednosti
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