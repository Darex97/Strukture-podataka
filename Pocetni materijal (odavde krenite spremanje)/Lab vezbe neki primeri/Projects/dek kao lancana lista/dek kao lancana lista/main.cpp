#include "Node.h"
#include "DequeAsLList.h"
#include <iostream>
using namespace std;

void main()
{
	try
	{
		DequeAsLList niz;

		niz.enqueueHead(5);
		niz.enqueueHead(7);
		niz.enqueueHead(10);
		cout << "Dodajem na glavu " << niz.numberOfElements() << " elemenata: " << endl;
		niz.print();
		cout << endl;

		niz.enqueueTail(19);
		niz.enqueueTail(8);
		cout << "Dodajem na rep jos 2 elemenata: " << endl;
		niz.print();
		cout << endl;

		cout << "Element sa pocetka deka: " << endl;
		int a = niz.getHead();
		cout << a << endl;

		cout << "Element sa kraja deka: " << endl;
		int b = niz.getTail();
		cout << b << endl;
	
		cout << "Brisem 2 elementa sa glave: " << endl;
		niz.dequeueHead();
		niz.dequeueHead();
		niz.print();
		cout << endl;

		cout << "Brisem 2 elementa sa repa: " << endl;
		niz.dequeueTail();
		niz.dequeueTail();
		niz.print();
		cout << endl;

		//praznim dek da proverim izuzetak
		niz.dequeueTail();
		cout << "Pokusavam da obrisem iz praznog deka..." << endl;
		niz.dequeueTail();
	}
	catch (char * s)
	{
		cout << s << endl;
	}
	catch (...)
	{
		cout << "Nepoznata greska" << endl;
	}
}