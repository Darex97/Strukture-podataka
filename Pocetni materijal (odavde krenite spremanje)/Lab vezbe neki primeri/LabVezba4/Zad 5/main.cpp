#include"element.h"
#include"ulancavanje.h"
#include<iostream>
#include "tablica.h"
#include "rasutatablica.h"
using namespace std;
void main()
{
	try{
	rasutatablica<char*,int>tab(10);
	tab.insert(ulancavanje<char*,int>("for",NULL));
	tab.insert(ulancavanje<char*,int>("while",NULL));
	tab.insert(ulancavanje<char*,int>("int",NULL));
	tab.display();
	cout<<endl;
	tab.insert(ulancavanje<char*,int>("for",NULL));
	tab.display();
	cout<<endl;
	tab.insert(ulancavanje<char*,int>("while",NULL));
	cout<<endl;
	tab.display();
	cout<<endl;
	tab.insert(ulancavanje<char*,int>("for",NULL));
	tab.display();
	cout<<endl;
	}
	catch(char *is)
	{
		cout<<is<<endl;
	}
	system("pause");
}