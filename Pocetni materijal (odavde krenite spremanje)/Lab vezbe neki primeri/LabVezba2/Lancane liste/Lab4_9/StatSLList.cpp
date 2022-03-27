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
	for (int i=0;i<n-1;i++){
		link[i]=i+1;
		info[i]=-1;
	}
	link[n-1]=-1;
	info[n-1]=-1;
	header = -1;
	lrmp = 0;
	brup = 0;
	maxvel = n;

}

StatSLList::~StatSLList(){
	delete [] info;
	delete [] link;
}

void StatSLList::adHead(int a){
	if(brup<maxvel){
//		if(brup == 0)
//			link[lrmp]=-1;
		int x = 0;
		info[lrmp]=a;
		link[lrmp]=header;
		header=lrmp;
		while (info[x] != -1 && x<maxvel)
			x++;
		lrmp = x;
		brup++;
	}
	else cout<<"Nema vise mesta!"<<endl;
}

void StatSLList::prikazi(){
	if (brup != 0){
		int pom;
		pom = header;
		cout<<"StatSLLista : \n"<<endl;
		cout<<"HEAD-->"<<info[pom]<<"["<<pom<<"]-->";
		pom = link[pom];
		while (pom != -1){
			cout<<info[pom]<<"["<<pom<<"]-->";
			pom = link[pom];
		}
		cout<<"END\n"<<endl;
	}
	else cout<<"Lista je prazna!"<<endl;
}
void StatSLList::brisi(int ind){
	int x=0;
	if (info[ind]==-1 || ind>=maxvel){//OK
		cout<<"Overflow!"<<endl;
		return;
	}
	if (ind <0){//OK
		cout<<"Underflow!"<<endl;
		return;
	}
	if (brup > 1){
		int pom = header;
		if (link[ind]!=-1 && header!=ind){
			info[ind]=-1;
			while(link[pom]!=ind)
				pom=link[pom];
			link[pom]=link[ind];
			while (info[x] != -1)
				x++;
			lrmp=x;
			brup--;
			cout<<"Element sa indeksom ["<<ind<<"] je izbacen!"<<endl;
		}
		else if (link[ind]==-1){
			info[ind]=-1;
			while(link[pom]!=ind)
				pom=link[pom];
			link[pom]=-1;
			while (info[x] != -1)
				x++;
			lrmp=x;
			brup--;
			cout<<"Element sa indeksom ["<<ind<<"] je izbacen!"<<endl;
		}	
		else if (header == ind){
			info[ind]=-1;
			header = link[ind];
			while (info[x] != -1)
				x++;
			lrmp=x;
			brup--;
			cout<<"Element sa indeksom ["<<ind<<"] je izbacen!"<<endl;
		}
	}
	else if (brup == 1){
		header = -1;
		lrmp = 0;
		brup = 0;
		cout<<"Lista je ispraznjena!"<<endl;
	}
	else cout<<"Nemoguce brisanje! Lista vec prazna! "<<endl;
}