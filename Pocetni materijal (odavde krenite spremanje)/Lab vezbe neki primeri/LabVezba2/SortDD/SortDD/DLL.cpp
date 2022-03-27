
#include "CStaticSortDList.h"
#include<iostream>
using namespace std;
void CStaticSortDList::AddToHead(int el)
{
	if(lrmp==-1)
		throw("Nema mesta!!!");
	//specijalan slucaj kada je lista prazna
	if(head==-1)
	{
		//indeks prvog slobdnog
		int tmp=lrmp;
		value[tmp]=el;
		//vrednost lrmp se postavlja na indeks narednog slobdnog elementa
		lrmp=next[tmp];
		//nema sledbenika pa je indeks narednog elementa -1
		next[tmp]=-1;
		//nema prethodnika pa je indeks prethodnog elementa -1
		prev[tmp]=-1;
		head=tmp;
		
	}
	else
	{
		//indeks prvog slobdnog
		int tmp=lrmp;
		value[tmp]=el;
		//vrednost lrmp se postavlja na indeks narednog slobdnog elementa
		lrmp=next[tmp];
		//sledbenik novog elementa je indeks elementa na koji ukazuje head
		next[tmp]=head;
		//novi cvor je prvi u listi i on nema prethodnika
		prev[tmp]=-1;
		//prethodnik cvora od malopre ce da bude novi cvor
		prev[head]=tmp;
		head=tmp;

	}
	


	
}

void CStaticSortDList::Sort(bool rastuci)
{
	if(head==-1)
	{
		cout<<"Lista je prazna!"<<endl;
		return;
	}
	
	//odredjivanje indeksa zadnjeg elementa
	int i,j,m,n=0,h;
	int q, p, t;
	for(q=head;q!=-1;q=next[q])
		n++;

	for(i=1,t=head;i<n; t=next[t],i++)
	for(j=0,p=head;j<n-i;p=next[p],j++)
		if((value[p]) > value[next[p]])
		{
			h=value[p];
			value[p]=value[next[p]];
			value[next[p]]=h;
		}


	/*
	int ptr1,ptr2,prev2;

	for(ptr1=tail;ptr1!=head;ptr1=prev2)
	{
		//cout<<"Usli smo!"<<endl;
		prev2=-1;
		for(ptr2=head;ptr2!=ptr1;ptr2=next[ptr2])
		{
			if(value[ptr2]>value[next[ptr2]])
			{
				if(prev2==-1)
				{
					head=next[ptr2];
					next[ptr2]=next[next[ptr2]];
					next[head]=ptr2;
				}
				else
				{
					next[prev2]=next[ptr2];
					next[ptr2]=next[next[ptr2]];
					next[next[prev2]]=ptr2;
				}
				
			}

			prev2=ptr2;
		}
	}

	*/

}


void CStaticSortDList::printList()
{
	if(head==-1)
	{
		cout<<"Lista je prazna!"<<endl;
		return;
	}
	
	int tmp;
	for(tmp=head;next[tmp]!=-1;tmp=next[tmp])
	{
		cout<<"\t "<<value[tmp];
	}
	cout<<"\t "<<value[tmp];
	cout<<endl;

}