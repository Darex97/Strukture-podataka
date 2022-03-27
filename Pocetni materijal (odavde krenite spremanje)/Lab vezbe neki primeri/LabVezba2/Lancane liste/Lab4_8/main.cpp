#include <iostream.h>
#include "StatSLList.h"

void main()
{
	StatSLList lista(4);
	for (int i=0;i<4;i++)
	{
		int pom;
		cout<<"Unesite element na pocetak liste: ";
		cin>>pom;
		cout<<endl;
		lista.adHead(pom);
	}
	lista.prikazi();
	lista.bubbleSort();
	lista.prikazi();
	
}