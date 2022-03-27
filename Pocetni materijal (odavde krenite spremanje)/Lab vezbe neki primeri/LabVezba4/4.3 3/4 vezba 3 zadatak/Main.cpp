#include"HashObject.h"
#include"ChainedScatterObject.h"
#include<iostream>
#include "HashTable.h"
#include "ChainedScatterTable.h"
using namespace std;
void main()
{
	try{
	ChainedScatterTable<char*,int>tab(32);
	
	tab.insert(ChainedScatterObject<char*,int>("auto",NULL));
	tab.insert(ChainedScatterObject<char*,int>("break",NULL));
	tab.insert(ChainedScatterObject<char*,int>("case",NULL));
    tab.insert(ChainedScatterObject<char*,int>("char",NULL));
	tab.insert(ChainedScatterObject<char*,int>("const",NULL));
	tab.insert(ChainedScatterObject<char*,int>("continue",NULL));
	tab.insert(ChainedScatterObject<char*,int>("default",NULL));
	tab.insert(ChainedScatterObject<char*,int>("do",NULL));
	tab.insert(ChainedScatterObject<char*,int>("double",NULL));
	tab.insert(ChainedScatterObject<char*,int>("else",NULL));
	tab.insert(ChainedScatterObject<char*,int>("enum",NULL));
	tab.insert(ChainedScatterObject<char*,int>("extern",NULL));
	tab.insert(ChainedScatterObject<char*,int>("float",NULL));
	tab.insert(ChainedScatterObject<char*,int>("for",NULL));
	tab.insert(ChainedScatterObject<char*,int>("goto",NULL));
	tab.insert(ChainedScatterObject<char*,int>("if",NULL));
	tab.insert(ChainedScatterObject<char*,int>("int",NULL));
	tab.insert(ChainedScatterObject<char*,int>("long",NULL));
	tab.insert(ChainedScatterObject<char*,int>("register",NULL));
	tab.insert(ChainedScatterObject<char*,int>("return",NULL));
	tab.insert(ChainedScatterObject<char*,int>("short",NULL));
	tab.insert(ChainedScatterObject<char*,int>("signed",NULL));
	tab.insert(ChainedScatterObject<char*,int>("sizeof",NULL));
	tab.insert(ChainedScatterObject<char*,int>("static",NULL));
	tab.insert(ChainedScatterObject<char*,int>("struct",NULL));
	tab.insert(ChainedScatterObject<char*,int>("switch",NULL));
tab.insert(ChainedScatterObject<char*,int>("typedef",NULL));
tab.insert(ChainedScatterObject<char*,int>("union",NULL));
tab.insert(ChainedScatterObject<char*,int>("unsigned",NULL));
tab.insert(ChainedScatterObject<char*,int>("void",NULL));
tab.insert(ChainedScatterObject<char*,int>("volatile",NULL));
tab.insert(ChainedScatterObject<char*,int>("while",NULL));
	tab.display();
	}
	catch(char *is)
	{
		cout<<is<<endl;
	}

}