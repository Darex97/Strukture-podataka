#include"HashObject.h"
#include"ChainedScatterObject.h"
#include<iostream>
#include "HashTable.h"
#include "ChainedScatterTable.h"
using namespace std;
void main()
{
	try{
	ChainedScatterTable<char*,int>tab(10);
	tab.insert(ChainedScatterObject<char*,int>("for",NULL));
	tab.insert(ChainedScatterObject<char*,int>("while",NULL));
	tab.insert(ChainedScatterObject<char*,int>("int",NULL));
	tab.display();
	}
	catch(char *is)
	{
		cout<<is<<endl;
	}

}