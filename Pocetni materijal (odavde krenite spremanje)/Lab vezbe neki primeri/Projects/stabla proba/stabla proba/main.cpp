#include "BSTNode.h"
#include "BSTree.h"

void main()
{
	BSTree tree;

	tree.insert(5);
	tree.insert(4);
	tree.insert(10);
	tree.insert(8);
	tree.insert(7);
	tree.insert(6);
	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
	tree.insert(9);
	
	cout << "Inorder: " << endl;
	tree.inorder();

	cout << endl;

	cout << "Preorder: " << endl;
	tree.preorder();

	cout << endl;
	cout << "Postorder: " << endl;
	tree.postorder();
	cout << endl;
}