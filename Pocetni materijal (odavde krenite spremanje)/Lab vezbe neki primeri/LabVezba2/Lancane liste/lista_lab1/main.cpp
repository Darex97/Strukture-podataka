#include <iostream.h>


struct Cvor{
	int info;
	Cvor* sled;
};

Cvor *poc,*trn,*trn1;

void citaj1(int n){
	poc=NULL;
	for (int i=0;i<n;i++){
		Cvor *novi = new Cvor;
		cout<<"Unesite info vrednost cvora: \n";
		cin>>novi->info;
		novi->sled=poc;
		poc=novi;
	}
}

//void citaj2(int n){
	
void upisNaKraj(){
	int pom;
	cout<<"Unesite vrednost info dela novog cvora: ";
	cin>>pom;
	cout<<endl;
	trn=poc;
	Cvor *novi = new Cvor;
	novi->info=pom;
	novi->sled=NULL;
	while (trn->sled)
		trn=trn->sled;//ovde sad trn pokazuje na prvi element, pa na drugi itd.
	trn->sled = novi;
}

void ispis(){
	trn=poc;
	cout<<"BEGIN-->";
	while(trn){
		cout<<"["<<trn->info<<"|-->";
		trn=trn->sled;
	}
	cout<<"END"<<endl;
}

void sort(){
	int pom;
	for (trn=poc;trn->sled;trn=trn->sled)
		for (trn1=trn->sled;trn1;trn1=trn1->sled)
			if (trn->info >= trn1->info){
				pom=trn->info;
				trn->info=trn1->info;
				trn1->info=pom;
			}
}

int main(){

	int n;
	cout<<"Unesite pocetni broj elementa liste: ";
	cin>>n;
	cout<<endl;
	citaj1(n);
	ispis();
	upisNaKraj();
	sort();
	ispis();

	return 0;

}
