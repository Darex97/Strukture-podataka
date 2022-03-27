#include"ChainedHashTable.h"
void main()
{
	ChainedHashTable t(1000);
	HashObject o1(2546123,"Lazar Todic");
	HashObject o2(2546127,"Mirko");
	HashObject o3(4546123,"Todic");
	HashObject o4(4566432,"Milja");
	HashObject o5(6753333,"Cika Crni");

	t.insert(o1);
	t.insert(o2);
	t.insert(o3);
	t.insert(o4);
	t.insert(o5);

	t.display();
}