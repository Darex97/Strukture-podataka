#include "StackAsArray.h"
#include <iostream>
using namespace std;

void main()
{
	try
	{
		StackAsArray niz(5);
		
		niz.push(4);
		niz.push(5);
		niz.push(7);
		niz.push(10);
		
		int br = niz.numberOfElements();
		cout << "Niz od " << br << " elementa:" << endl;
		niz.print();
		
		cout << "Niz posle skidanja 2 elementa:" << endl;
		niz.pop();
		niz.pop();
		niz.print();
		
		cout << "Trenutni broj elemenata:" << endl;
		br = niz.numberOfElements();
		cout << br << endl;
		
		cout << "Element sa vrha steka: " << endl;
		int a = niz.getTop();
		cout << a << endl;
		
		/*cout << "Dodajem vise elemenata od dozvoljenog da isprobam izuzetke..." << endl;
		niz.push(5);
		niz.push(7);
		niz.push(10);
		niz.push(7);
		niz.push(10);*/
		
		cout << "Izbacujem elemente vise nego sto ima da isprobam izuzetke..." << endl;
		niz.pop();
		niz.pop(); 
		niz.pop();
	}
	catch (char * s)
	{
		cout << s << endl;
	}
	catch (...)
	{
		cout << "Greska!" << endl;
	}
}