#include "BSTNode.h"
#include "BSTree.h"
#include <iostream>

using namespace std;

int main(void) {
	BSTree<int> tree;

	tree.insert(5);
	tree.insert(11);
	tree.insert(8);
	tree.insert(20);
	tree.insert(2);
	tree.insert(7);
	tree.insert(16);

	tree.print();

	cout << "Tree's weight is: " << tree.calculateWeight() << endl;

	int t;
	cin >> t;

	return 0;
}