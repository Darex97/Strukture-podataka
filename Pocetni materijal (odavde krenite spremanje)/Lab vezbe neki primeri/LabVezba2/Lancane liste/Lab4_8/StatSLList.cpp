// StatSLList.cpp: implementation of the StatSLList class.
//
//////////////////////////////////////////////////////////////////////

#include "StatSLList.h"
#include <iostream.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StatSLList::StatSLList(int n){
	info = new int[n];
	link = new int[n];
	for (int i=0;i<n-1;i++)
		link[i]=i+1;
	link[n-1]=-1;
	header = -1;
	lrmp = 0;
	brup = 0;
	maxvel = n;

}

StatSLList::~StatSLList(){
	delete [] info;
	delete [] link;
}

void StatSLList::adHead(int a)
{
	if(brup<maxvel)
	{
		info[lrmp]=a;
		link[lrmp]=header;
		lrmp++;
		header++;
		brup++;
	}
	else cout<<"Nema vise mesta!"<<endl;
}

void StatSLList::prikazi()
{
	if (brup != 0)
	{
		int pom;
		pom = header;
		cout<<"StatSLLista : \n"<<endl;
		cout<<"HEAD-->"<<info[pom]<<"-->";
		pom = link[pom];
		while (pom != -1){
			cout<<info[pom]<<"-->";
			pom = link[pom];
		}
		cout<<"END\n"<<endl;
	}
	else cout<<"Lista je prazna!"<<endl;
}

void StatSLList::bubbleSort()
{
	int trn,trn1,pom,pom1,pom2;
	//cout<<header<<endl;
	for (trn=header;link[trn]!= -1;trn=link[trn])
		for (trn1=link[trn];trn1!= -1;trn1=link[trn1])
			if (info[trn]>info[trn1])
			{
				if(trn==header)
					header=trn1;
				pom=link[trn];
				link[trn]=link[trn1];
				link[trn1]=pom;
				pom=0;
				pom1=0;
				while (link[pom]!=trn)
					pom++;
				while (link[pom1]!=trn1)
					pom1++;
				pom2=link[pom];
				link[pom]=link[pom1];
				link[pom1]=pom2;
			}
}