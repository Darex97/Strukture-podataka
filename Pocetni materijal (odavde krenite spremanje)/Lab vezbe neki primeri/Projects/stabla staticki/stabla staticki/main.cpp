#include "BTree.h"

void main()
{
	BTree stablo(10);

	stablo.insert(5);
	stablo.insert(3);
	stablo.insert(7);
	stablo.insert(1);
	stablo.insert(2);
	stablo.insert(4);
	stablo.insert(8);
	
	stablo.visit();
}