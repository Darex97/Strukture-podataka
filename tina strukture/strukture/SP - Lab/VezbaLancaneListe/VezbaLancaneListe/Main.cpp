#include <iostream>

using namespace std;

#include "SLList.h"
#include "DSException.h"

int main()
{
	SLList<int>* list = new SLList<int>();

	try
	{
		list->addToHead(3);
		list->addToHead(5);
		list->addToHead(4);
		list->addToHead(3);
		list->addToHead(2);
		list->addToHead(1);
		list->addToHead(1);
		list->addToHead(2);
		list->addToHead(1);

		cout << "Singly Linked List before removing duplicates." << endl;
		list->printAll();

		list->removeDuplicates();

		cout << "Singly Linked List after removing duplicates." << endl;
		list->printAll();
	}
	catch (const DSException& ex)
	{
		cout << "Error Message: " << ex.getMessage() << endl;
	}
	catch (const exception& ex)
	{
		cout << "Error Message: " << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Caught unknown exception." << endl;
	}

	delete list;

	return 0;
}