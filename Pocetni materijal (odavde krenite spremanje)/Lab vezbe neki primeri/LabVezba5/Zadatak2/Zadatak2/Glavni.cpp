#include "BSTree.h"
#include <iostream>

using namespace std;

void main()
{
	try{
	BSTree<int> test(10);
	test.insert(5);
	test.insert(1);
	test.insert(7);
	test.insert(5);
	test.insert(8);
	test.insert(3);
	cout<<"Broj razlicitih cvorova je : "<<test.nodeNum()<<endl;
	}
	catch(char *greska){ cout<<greska<<endl;}
}