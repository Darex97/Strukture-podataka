#include "ChainedHashTable.h"
#include <iostream>
using namespace std;

void main()
{
	try
	{

	ChainedHashTable<int,char> imenik(5);
	HashObject<int,char> objekt(2212054,"Sandra Ilijin");
	HashObject<int,char> objekt21(2223454,"Kiki");
	HashObject<int,char> objekt34(8765422,"BlaBla");
	
	HashObject<int,char> objekt2(5288520,"Stevan Vasic");
	imenik.insert(objekt);
	imenik.insert(objekt21);
	imenik.insert(objekt34);
	imenik.insert(objekt2);

	imenik.display();
	}
	catch(char *iz)
	{
		cout << "greska: " << iz << endl;
	}
}

