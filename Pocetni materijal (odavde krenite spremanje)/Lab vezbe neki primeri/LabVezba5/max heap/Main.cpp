#include <iostream>

#include "MaxHeap.h"

using namespace std;

void main()
{
	MaxHeap MH;
	
	MH.heapInsert(2);
	MH.heapInsert(6);
	MH.heapInsert(5);
	MH.heapInsert(3);
	MH.heapInsert(7);
	MH.heapInsert(8);

	MaxHeap mh;

	mh.heapInsert(0);
	mh.heapInsert(9);

	MaxHeap mix;

	mix.mix(MH,mh);

	mix.toMinHeap();

	char end;
	cin >> end;
}