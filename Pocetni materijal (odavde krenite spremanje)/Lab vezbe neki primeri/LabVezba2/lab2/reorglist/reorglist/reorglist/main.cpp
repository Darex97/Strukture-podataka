#include "ReorgList.h"

void main()
{
	ReorgList r;

	for(int i = 0; i < 10; i++)
		r.addToHead();

	r.print();

	r.getToStart(28);


	r.print();

	r.getTransp(41);

	r.print();

	int x;
	cin >> x;
}