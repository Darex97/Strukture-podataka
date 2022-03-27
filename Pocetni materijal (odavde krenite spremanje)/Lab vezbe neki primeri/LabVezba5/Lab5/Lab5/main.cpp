#include"BSTNode.h"
#include"BSTree.h"

void main()
{
	BSTree *tree1=new BSTree();
	BSTree *tree2=new BSTree();

	(*tree1).insert(4);
	(*tree1).insert(2);
	(*tree1).insert(6);
	//(*tree1).insert(3);
	//(*tree1).insert(9);
	//(*tree1).insert(0);
	//(*tree1).insert(4);
	//(*tree1).insert(0);
	//(*tree1).insert(6);
	tree2->insert(3);
	tree2->insert(0);
	tree2->insert(8);

	cout<<"Prvo stablo:"<<endl;
	(*tree1).inorder();
	/*cout<<"Drugo stablo:"<<endl;
	(*tree2).inorder();*/

	/*cout<<"Moment prvog stabla:"<<tree1->moment()<<endl;
	cout<<"Visina prvog stabla:"<<tree1->TreeHeight()<<endl;*/
	cout<<"Tezina prvog stabla:"<<tree1->TreeWeight()<<endl;
	//tree1->Delete();
	//cout<<"Stablo posle brisanja listova:"<<endl;
	//tree1->preorder();
	/*cout<<"Stablo 1 u ogledalu:"<<endl;
	(tree1->Mirror())->inorder();*/
	
	/*cout<<"Stablo 2 u ogledalu:"<<endl;
	(tree2->Mirror())->inorder();*/

	/*tree1->Merge(tree2->root);*/
	
	/*cout<<"Stablo posle spajanja:"<<endl;
	tree1->inorder();*/
	tree1->Delete();
	cout<<"Tezina prvog stabla nakon brisanja listova:"<<tree1->TreeWeight()<<endl;
}