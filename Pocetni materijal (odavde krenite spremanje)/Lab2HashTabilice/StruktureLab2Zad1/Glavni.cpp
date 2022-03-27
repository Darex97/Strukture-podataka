#include"HashTable.h"
void main() 
{
	try {
		HashTable hTab(5);
		HashObject o1("for", 0);
		HashObject o2("do", 1);
		HashObject o3("for", 3);
		HashObject o4("for", 4);
		hTab.insert(o1);
		hTab.insert(o2);
		hTab.insert(o3);
		hTab.insert(o4);
		hTab.printAll();
        hTab.find("do")->print();
		cout << endl;
		hTab.find(o4)->print();
	}
	catch (char* izuzetak)
	{
		cout << izuzetak << endl;
	}
}