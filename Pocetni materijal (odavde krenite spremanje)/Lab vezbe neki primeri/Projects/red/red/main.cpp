#include "Node.h"
#include "QueueAsLList.h"
#include <iostream>
using namespace std;

void main()
{
	try
	{
		QueueAsLList niz;

		niz.enqueue(7);
		niz.enqueue(5);
		niz.enqueue(6);
		niz.enqueue(10);
		cout << "Red posle dodavanja " << niz.numberOfElements() << " elementa: " << endl;
		niz.print();
		cout << endl;

		cout << "Red posle brisanja 2 elementa:" << endl;
		niz.dequeue();
		niz.print();
		cout << endl;

		cout << "Element koji je prvi usao u red: " << endl;
		int a = niz.getHead();
		cout << a << endl;

		//brisem 3 elementa da isprobam gresku
		niz.dequeue();
		niz.dequeue();
		niz.dequeue();
		cout << "Pokusavam da obrisem iz praznog reda..." << endl;
		niz.dequeue();
	}
	catch (char* s)
	{
		cout << s << endl;
	}
	catch (...) {}
}