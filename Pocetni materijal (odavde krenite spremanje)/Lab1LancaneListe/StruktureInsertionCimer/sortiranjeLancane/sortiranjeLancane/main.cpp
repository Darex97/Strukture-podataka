#include "LLista.h"
void main()
{
	//Fja insertSorted:
	/*LLista l1,l2;
	l1.addToHead(25);
	l1.addToHead(20);
	l1.addToHead(15);
	l1.addToHead(10);
	l1.addToHead(5);
	l2.addToHead(37);
	l2.addToHead(27);
	l2.addToHead(7);
	l2.addToHead(3);
	l2.addToHead(2);
	l1.Stampaj();
	l2.Stampaj();
	l1.insertSorted(l2);
	l1.Stampaj();*/

	//Fja update():
	/*LLista l;
	l.addToHead(25);
	l.addToHead(18);
	l.addToHead(16);
	l.addToHead(5);
	l.addToHead(2);
	l.Stampaj();
	l.update(25, 75);
	l.Stampaj();
	*/

	//fja groupDuplicates()
	LLista l;
	l.addToHead(5);
	l.addToHead(8);
	l.addToHead(5);
	l.addToHead(7);
	l.addToHead(8);
	l.addToHead(5);
	l.addToHead(8);
	l.addToHead(7);
	l.addToHead(5);
	l.Stampaj();
	l.groupDuplicates();
	l.Stampaj();


	//l.bubbleSort();
	//l.Stampaj();
	//l.insertionSort();
	//l.Stampaj();
	//l.selectionSort();
	//l.Stampaj();
	
}