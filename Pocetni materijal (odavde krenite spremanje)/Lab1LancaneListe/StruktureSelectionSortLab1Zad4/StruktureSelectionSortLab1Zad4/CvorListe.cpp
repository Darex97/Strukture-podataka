#include"CvorListe.h"
#include<iostream>
using namespace std;

CvorListe::CvorListe() {
	this->next = NULL;
}
CvorListe::CvorListe(int a) {
	this->info = a;
	this->next = NULL;
}
CvorListe::CvorListe(int a, CvorListe* novi)
{
	this->info = a;
	this->next = novi;
}
CvorListe::~CvorListe() {}
void CvorListe::print() {
	cout << this->info << " " << endl;
}
bool CvorListe::isEqual(int a) {
	return (a == this->info);
}