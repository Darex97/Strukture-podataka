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
	char* strarray[] = {"hey", "sup", "dogg"};
	tab.insert(strarray);
	tab.display();
	char* drugi[] = {"sup", "sup", "sup"};
	cout<<endl;
	tab.insert(drugi);
	tab.display();
	}
	catch(char *is)
	{
		cout<<is<<endl;
	}
	system("pause");
}