
#include"klasa.h"
#include<iostream.h>
void main()
{

	listel a;



	a.AddToTail(2);
	
	
	a.AddToHead(5);
//	cout << a.tellfromHead() << endl;

	a.AddToHead(6);
	a.AddToHead(3);
	
//	a.print();
	

	a.AddToTail(2);	
	a.AddToTail(4);
	a.AddToTail(7);
	a.AddToTail(8);
	
/*	a.deleteFromHead();
	a.deleteFromHead();
	a.deleteFromHead();
	a.deleteFromHead();
	a.deleteFromHead();
	a.deleteFromHead();
	a.deleteFromHead();
	a.deleteFromHead();
	a.deleteFromHead();
	a.deleteFromHead();
*/	cout << "ENTER" << endl;
	
	a.deleteFromTail();
	a.deleteFromTail();
	a.deleteFromTail();
	a.deleteFromTail();
	a.deleteFromTail();
	a.deleteFromTail();
	a.deleteFromTail();
	a.deleteFromTail();
	a.deleteFromTail();
	a.deleteFromTail();
	cout << "KRAJ\n";
/*	
	a.print();

	cout <<"Glava sadrzi :\t" <<  a.tellfromHead() << endl ;

	cout <<"Rep sadrzi:\t" <<  a.tellfromTail() << endl ;
*/
}