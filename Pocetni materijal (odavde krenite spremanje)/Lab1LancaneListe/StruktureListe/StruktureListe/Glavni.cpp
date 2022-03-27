#include<iostream>
using namespace std;
#include"SLList.h"
#include"SLLNode.h"
#include"DLList.h"
#include"DLLNode.h"
void main() {
	try {
		//Cvorovi
	/*	cout << "<<<<< Cvorovi >>>>>" << endl;

		SLLNode<int> Poslednji(5);
		SLLNode<int> Pretposlednji(6, &Poslednji);
		SLLNode<int> JedanPrePretposlednjeg(9, &Pretposlednji);
		cout << JedanPrePretposlednjeg.print() << endl;
		cout << Pretposlednji.print() << endl;
		cout << Poslednji.print() << endl;
		//Singly linked list = SLL

		cout << "<<<<< SLL >>>>>" << endl;
		SLList<int> Lista;
		Lista.addToHead(1);
		Lista.addToHead(17);
		Lista.addToTail(64);
		
		cout << *(Lista.getHead()) << endl;//ova funkcija mi vraca 
		//adresu zato moram da stavim zvezdicu na pocetak
		//kako bi mi stampao vrednost na toj adresi
		Lista.printAll();
		cout << endl;
		if (Lista.isEmpty())
		{
			cout << "Lista jeste prazna." << endl;
		}
		else
		{
			cout << "Lista nije prazna." << endl;
		}
		
		cout<<"Izbrisani element: "<< Lista.deleteFromHead()<<endl;
		Lista.printAll();
	
		cout << "Izbrisani element: " << Lista.deleteFromTail()<<endl;
		Lista.printAll();
		cout << endl << endl;
		//Dodavanje
		Lista.addToHead(12);
		Lista.addToHead(72);
		Lista.addToHead(90);
		Lista.addToHead(8);

		Lista.printAll();
		cout << endl;
		//Brisanje
		Lista.deleteEl(72);

		Lista.deleteEl(16);
		Lista.deleteEl(1);
	    Lista.printAll();
		cout << endl;
	*/	
		//Doubly Linked List= DLL

		DLList<int> Dlista;
		cout << "<<<<< DLL >>>>>" << endl;
		Dlista.addToHead(10);
		Dlista.addToHead(9);
		Dlista.addToHead(1);
		Dlista.addToHead(17);
		Dlista.addToHead(8);
		Dlista.addToHead(6);
		Dlista.addToHead(3);
		Dlista.printAll();
		Dlista.MovePartToEnd(6, 9);
		cout << endl;
		
		Dlista.printAll();

		
	}

	catch (char* izuzetak) {
		cout << izuzetak << endl;
	}
}