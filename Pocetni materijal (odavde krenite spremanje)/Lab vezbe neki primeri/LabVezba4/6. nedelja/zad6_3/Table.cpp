// Table.cpp: implementation of the Table class.
//
//////////////////////////////////////////////////////////////////////

#include "Table.h"
#include "Object.h"
#include <iostream.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Table::Table(unsigned int n){
	duzina = n;
	brup = 0;
	niz = new Object[duzina];
}

Table::~Table(){
	for(unsigned int i = 0;i<duzina;i++)
		niz[i].deleteRecord();
	delete [] niz;
}

void Table::display(){
	for(unsigned int i = 0;i<duzina;i++){
		if (!niz[i].free){
			cout<<"["<<i<<"]"<<" |";
			niz[i].print();
			cout<<"|"<<niz[i].next<<endl;
		}
		else cout<<"["<<i<<"]"<<endl;
	}
}

void Table::Insert(Object obj){
	if (brup == this->getLenght()){
		cout<<"Tablica je puna!"<<endl;
		return;
	}
	else {
		long probe = this->h(obj);
		if (!niz[probe].free){
			while(niz[probe].next != -1)
				probe = niz[probe].next;
			long tail = probe;
			probe = g(probe);
			while(!niz[probe].free && probe != tail)
				probe = g(probe);
			if (probe == tail){
				cout<<"Lose rasipanje!"<<endl;
				return;
			}
			niz[tail].next = probe;
		}
		niz[probe] = obj;
		niz[probe].next = -1;
		niz[probe].free = false;
		brup++;
	}
}

Object Table::find(char *k){
	long probe = f(k)%duzina;
	while ( !niz[probe].isEqualKey(k) && niz[probe].next != -1)
		probe = niz[probe].next;
	if (niz[probe].isEqualKey(k)) return niz[probe];
	else cout<<"Element sa zadatim klucem ne postoji"<<endl;
}

void Table::withdraw(char *k){
	if (brup == 0){
		cout<<"Tablica je prazna!"<<endl;
		return;
	}
	long probe = f(k)%duzina;
	long prev = -1;
	while (probe != -1 && !niz[probe].isEqualKey(k)){
		prev = probe;
		probe = niz[probe].next;
	}
	if (probe == -1){
		cout<<"Nemoguce izbacivanje!"<<endl;
		return;
	}
	if (prev != -1){
		niz[prev].next = niz[probe].next;
		niz[probe].deleteRecord();
		niz[probe].free = true;
	}
	else {
		if (niz[probe].next == -1){
			niz[probe].deleteRecord();
			niz[probe].free = true;
		}
		else {
			long nextEl = niz[probe].next;
			niz[probe].deleteRecord();
			niz[probe] = niz[nextEl];
			niz[probe].next = niz[nextEl].next;
			niz[nextEl] = Object();
			niz[nextEl].free = true;
		}
	}
	brup--;
}

unsigned int Table::h(Object obj){
	return (f(obj.getKey())%duzina);
}

unsigned int Table::f(char *k){
	unsigned int res=0;
	unsigned int a=7;
	for (int i=0;k[i]!=0;i++)
		res=res<<a^k[i];
	return res;
}

unsigned int Table::g(unsigned int i){
	return (i+1)%duzina;
}
