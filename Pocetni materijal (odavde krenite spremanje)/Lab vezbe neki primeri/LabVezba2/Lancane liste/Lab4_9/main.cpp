#include <iostream.h>
#include "StatSLList.h"

int main(){
	StatSLList lista(5);
	for (int i=0;i<5;i++){
		int pom;
		cout<<"Unesite element na pocetak liste: ";
		cin>>pom;
		cout<<endl;
		lista.adHead(pom);
	}
	lista.prikazi();
	lista.brisi(2);
	lista.adHead(6);
	lista.brisi(0);
	lista.adHead(7);
	lista.brisi(4);
	lista.adHead(8);
	lista.prikazi();


	return 0;
}