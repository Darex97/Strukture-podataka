#include "Node.h"
#include "StackAsLList.h"
#include <iostream>
using namespace std;

void main()
{
	try
	{
		StackAsLList niz;
		
		niz.addToTop(5);
		niz.addToTop(7);
		niz.addToTop(10);
		niz.addToTop(2);
		cout << "Stek posle dodavanja elemenata: " << endl;
		niz.print();
		
		cout << "Broj elemenata u steku: " << endl;
		int c = niz.numberOfElements();
		cout << c << endl;
		
		cout << "Stek posle brisanja " << niz.numberOfElements() <<  " elemenata:" << endl;
		niz.deleteFromTop();
		niz.deleteFromTop();
		niz.print();
		
		cout << "Citam sa vrha steka element ali ga ne brisem.." << endl;
		int a = niz.getElement();
		cout << a << endl;
		
		//brisem jos 2 elementa da postane prazan stek
		niz.deleteFromTop();
		niz.deleteFromTop();
		
		cout << "Pokusam da obrisem elemente iz praznog steka da se pojavi izuzetak.." << endl;
		niz.deleteFromTop();	
	}
	catch (char * s)
	{
		cout << s << endl;
	}
	catch (...)
	{  }
}