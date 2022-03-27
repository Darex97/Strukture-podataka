#include <iostream>
#include "HashObject.h"
#include "HashTable.h"

using namespace std;

int main(void) {
	HashTable table(50);
	
	try {
		HashObject record1("void", "void");
		table.insert(record1);
		table.insert(record1);
		
		HashObject record2("char", "char");
		table.insert(record2);

		HashObject record3("while", "while");
		table.insert(record3);

		HashObject record4("continue", "continue");
		table.insert(record4);

		HashObject record5("catch", "catch");
		table.insert(record5);

		table.withdraw("void");
		table.withdraw("catch");

		table.printTable();
	}
	catch(char* msg) {
		cout << "There was an error: " << msg << endl;
	}

	int t;
	cin >> t;

	return 0;
}