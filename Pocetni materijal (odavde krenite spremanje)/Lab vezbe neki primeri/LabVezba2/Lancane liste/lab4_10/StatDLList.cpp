// StatDLList.cpp: implementation of the StatDLList class.
//
//////////////////////////////////////////////////////////////////////

#include "StatDLList.h"
#include <iostream.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StatDLList::StatDLList(int n){
	info = new int[n];
	dlink = new int[n];
	llink = new int[n];
	for (int i=0;i<n-1;i++)
		dlink[i]=i+1;
	for (i=1;i<n;i++)
		llink[i]=i-1;
	for (i=0;i<n;i++)
		info[i]=-1;
	llink[0]=-1;
	dlink[n-1]=-1;
	HEAD = -1;
	LRMP = 0;
	brup = 0;
	maxv = n;
}


StatDLList::~StatDLList(){
	delete [] info;
	delete [] llink;
	delete [] dlink;
}

void StatDLList::AdHead(){
	int pom;
	if(brup<maxv){
		int x=0;
		cout<<"Unesite element: ";
		cin>>pom;
		cout<<endl;
		info[LRMP]=pom;
		llink[LRMP]=-1;
		dlink[LRMP]=HEAD;
		if(brup != 0)
			llink[HEAD]=LRMP;
		HEAD=LRMP;
		while (info[x] != -1 && x<maxv)
			x++;
		LRMP=x;
		brup++;
	}
	else cout<<"Nema vise mesta!"<<endl;
}

void StatDLList::prikazi(){
	if (brup != 0){
		int pom;
		pom = HEAD;
		cout<<"IZGLED StatDLListe : \n"<<endl;
		cout<<"B-->"<<info[pom]<<"["<<pom<<"]-->";
		pom = dlink[pom];
		while (pom != -1){
			cout<<info[pom]<<"["<<pom<<"]-->";
			pom = dlink[pom];
		}
		cout<<"E\n"<<endl;
	}
	else cout<<"Lista je prazna!"<<endl;
}

void StatDLList::brisi(int ind){   //Radi!!!
	int x=0;
	if (info[ind]==-1 || ind>=maxv){
		cout<<"Overflow!"<<endl;
		return;
	}
	if (ind <0){
		cout<<"Underflow!"<<endl;
		return;
	}
	if (brup > 1){
		if (llink[ind]!=-1 && dlink[ind]!=-1){
			info[ind]=-1;
			dlink[llink[ind]]=dlink[ind];
			llink[dlink[ind]]=llink[ind];
			while (info[x] != -1)
				x++;
			LRMP=x;
			brup--;
			cout<<"Element sa indeksom ["<<ind<<"] je izbacen!"<<endl;
		}
		else if (llink[ind]==-1){
			info[ind]=-1;
			llink[dlink[ind]]=-1;
			HEAD=dlink[ind];
			while (info[x] != -1)
				x++;
			LRMP=x;
			brup--;
			cout<<"Element sa indeksom ["<<ind<<"] je izbacen!"<<endl;
		}	
		else if (dlink[ind]==-1){
			info[ind]=-1;
			dlink[llink[ind]]=-1;
			while (info[x] != -1)
				x++;
			LRMP=x;
			brup--;
			cout<<"Element sa indeksom ["<<ind<<"] je izbacen!"<<endl;
		}
	}
	else if (brup == 1){
		HEAD = -1;
		LRMP = 0;
		brup = 0;
		cout<<"Lista je ispraznjena!"<<endl;
	}
	else cout<<"Nemoguce brisanje! Lista vec prazna! "<<endl;
}