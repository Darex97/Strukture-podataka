#include "sort.h"
#include "cvor.h"
#include<iostream>
using namespace std;
void main()
{
	sort a;
	a.addtohead(9);
	a.addtohead(5);
	a.addtohead(8);
	a.addtohead(10);
	a.addtohead(3);
	//a.bubblesort();
	a.selectionsort();
	a.printall();
}
