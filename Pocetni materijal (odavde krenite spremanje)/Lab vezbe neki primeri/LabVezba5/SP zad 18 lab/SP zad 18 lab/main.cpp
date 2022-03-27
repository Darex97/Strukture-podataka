#include "MaxHeap.h"
void main()
	
{
	MaxHeap a(10);
	MaxHeap b(10);
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);
	a.insert(7);
	
	a.insert(12);
	a.print();
	b.insert(22);
	b.insert(32);
	b.insert(41);
	b.insert(25);
	b.insert(16);
	b.insert(17);
	cout<<endl;
	b.print();
	cout<<endl;
	a.spojiDvaMax(b);
	a.print();
	cout<<endl;
	a.konverzija(b);
	b.print();
	system("pause");
}
