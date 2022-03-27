#include"StackJedan.h"
#include"StackAsArray.h"
#include<iostream>
#include"Queue.h"
using namespace std;

void main() {
	try {
		cout << "<<<<<< STACK >>>>>>>"<<endl;
		StackAsArray PrviStek(5);
		PrviStek.push(10);
		PrviStek.push(6);
		PrviStek.push(9);
		PrviStek.push(20);
		PrviStek.push(67);
		cout << "Popovan: "<< PrviStek.pop()<<endl;
		cout <<"Broj elemenata: " <<PrviStek.numberOfElements() << endl;
		cout << "<<<<<< RED >>>>>>>"<<endl;
		Queue Nizic(5);
		cout << Nizic.getHead();
		Nizic.enqueue(1);
		Nizic.enqueue(2);
		Nizic.enqueue(4);
		Nizic.enqueue(8);
		cout <<"Izbrisan: " <<Nizic.dequeue() << endl;
		cout <<"Glava: " <<Nizic.getHead() << endl;


	}
	catch (char* izuzetak)
	{
		cout << izuzetak;
	}

}