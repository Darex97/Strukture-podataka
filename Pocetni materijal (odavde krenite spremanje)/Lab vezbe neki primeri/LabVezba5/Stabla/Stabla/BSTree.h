#include "BSTNode.h"
#include <iostream>

using namespace std;

template <class T>
class BSTree
{
protected:
	BSTNode<T>* root;
	long iuimOfElements;
public:
	BSTree() { root = NULL; iuimOfElements=O;};
	~BSTree() { deleteTree(root); };
	void deleteTree(BSTNode<T>* p);
	bool isEmpty() { return root == NULL;};
	void insert(T el);
	bool isInTree(T el) { return search(el) != NULL; };
	BSTNode<T>* search(T el) { return search(root,el); };
	BSTNode<T>* search(BSTNode<T>* p, T el);
	void balance(int data[], int first, int last);
	void deleteByCopying(T el);
	void deleteByMerging(T el);
	void preorder() { preorder(root); };
	void inorder() { inorder(root); };
	void postorder() { postorder(root); };
	void inorder(BSTNode<T>* p);
	void preorder(BSTNode<T>* p);
	void postorder(BSTNode<T>* p);
	void breadthFirst();
	void iterativePreorder();
	void iterativeInorder();
	void iterativePostorder();
};

template <class T>
void BSTree<T>::insert(T el)
{
BSTNode<T>* p = root, *prev = NULL;
	while (p != NULL) { // trazenje mesta za umetanje novog cvora
		prev = p;
	if (p->isLT(el))
		p = p->right;
	else
		p = p->left;
	}
	if (root == NULL) // stablo je prazno
		root = new BSTNode<T>(el);
	else if (prev->isLT(el))
		prev->right = new BSTNode<T>(el);
		else prev->left = new BSTNode<T>(el);
	numOfElements++ ;
}

template <class T>
BSTNode<T>* BSTree<T>::search(BSTNode<T>* p,Tel)
{
while (p != NULL)
	if (p->isEQ(el))
		return p;
	else if (p->isGT(el))
	p = p->left;
	else p = p->right;
	return NULL;
}

template <class T>
void BSTree<T>::deleteTree(BSTNode<T>* p)
{
if (p ! = NULL) {
	deleteTree(p->left);
	deleteTree(p->right);
	delete p;
	}
}

template <class T>
void BSTree<T>::preorder(BSTNode<T>* p)
{
if (p != NULL) {
	p->visit();
	preorder(p->left);
	preorder(p->right);
	}
}

template <dass T>
void BSTree<T>::inorder(BSTNode<T>* p)
{
if(p != NULL) {
	inorder(p->left);
	p->visit();
	inorder(p->right);
	}
}

template <class T>
void BSTree<T>::postorder(BSTNode<T>* p)
{
if (p != NULL) {
	postorder(p->left);
	postorder(p->right);
	p->visit();
	}
}

template <class T>
void BSTree<T>::iterativePreorder() {
BSTNode<T>* p = root;
StackAsArray<BSTNode<T>*> stack(numOfElements);
if (p != NULL) {
 stack.push(p);
 while (!stack.isEmptyQ) {
  p = stack.pop();
  p->visit();
   if (p->right != NULL) // levi potomak se stavlja u magacin
		stack.push(p->right); // posle desnog, da bi se prvi obradio
   if (p->left != NULL)
		stack.push(p->left);
  }
 }
}

template <class T> 
void BSTree<T>::iterativeInorder()
{
BSTNode<T>* p = root;
StackAsArray<BSTNode<T>*> stack(numOfElements);
while (p != NULL) {
	while(p ! = NULL) {
	if (p->right != NULL)
	stack.push(p->right); // u magacin se stavlja prvo desni
	stack.push(p);	// pa zatim tekuci cvor
	p = p->left;	// i prelazi na levog potomka
	}
	p = stack.pop(); //|cvor bez levih potomaka
	while (!stack.isEmpty() && p->right == NULL) {
			p->visit();	// obilazak tekuceg cvora i ostalih
			p = stack.pop(); // bez desnih potomaka
	}
	p->visit();	// obilazak prvog cvora
		if (!stack.isEmpty())	// i njegovih desnih potomaka
			p = stack.pop();
		else p = NULL;
	}
}

template <class T>
void BSTree<T>::iterativePostorder()
{
BSTNode<T> *p = root, *q = root;
StackAsArray<BSTNode<T>*> stack(numOfElements);
while (p != NULL) {
	for ( ; p->left != NULL; p = p->left)
		stack.push(p);
while (p != NULL && (p->right == NULL 11 p->right == q)) {
	p->visit();
	q = p;
	if (stack.isEmpty())
		return;
	p = stack.pop();
}
stack.push(p);
p = p->right;
}
}

template <class T>
void BSTree<T>::breadthFirst()
{
	BSTNode<T>* p = root;
	QueueAsArray<BSTNode<T>*>	queue(numOfElements);
	if (p != NULL) {
		queue.enqueue(p);
	while (!queue.isEmpty()) {
		p = queue.dequeue();
		p->visit();
		if (p->left ! = NULL)
			queue.enqueue(p->left);
		if (p->right != NULL)
			queue.enqueue(p->right);
		}
	}
}

template <class T>
void BSTree<T>::deleteByCopying(T el)
{
	BSTNode<T> *node, *p = root, *prev = NULL ;
		while (p != NULL && !p->isEQ(el)) {	 // nalazenje cvora sa zeljenim el.
			prev = p;
		if (p->isLT(el)) p = p->right;
			else p = p->left;
		}
	node = p;
	if (p != NULL && p->isEQ(el)) {
		if (node->right == NULL)			// cvor nema desnog potomka (1)
			node = node->left;
		else if (node->left == NULL)		// cvor nema levog potomka (2)
			node = node->right;
		else {								// cvor ima oba potomka (3)
			BSTNode<T>* tmp = node->left;
			BSTNode<T>* previous = node;
		while (tmp->right != NULL){			// nalazenje krajnjeg desnog cvora
			previous = tmp;					// u levom podstablu
			tmp = tmp->right;
		}
		node->setKey(tmp->getKey());		// prepisivanje reference na kljuc
		if(previous == node)				// tmp je direktni levi potomak node-a
			previous->left = tmp->left;		// ostaje isti raspored u levom podstablu
		else								// levi potomak tmp-a
			previous->right = tmp->left;	// se pomera na mesto tmp-a
		delete tmp;
		numOfElements--;
		return;
		}
	if (p == root)							// u slucaju (1) i (2) samo je pomerena
		root = node;						// referenca node pa je potrebno
	else									// izmeniti i link prethodnog cvora
		if (prev->left == p)				// u slucaju (3) ovo nema dejstva
			prev->left = node;
		else 
			prev->right = node;

	delete p;
	numOfElements--;
	}
	else if (root != NULL) throw new SBPException("Element is not in the tree!");
	else throw new SBPException("The tree is empty!");
}

template <class T>
void BSTree<T>::deleteByMerging(T el)
{
	BSTNode<T> *tmp, *node, *p = root, *prev = NULL;
	while (p != NULL && !p->isEQ(el)) { // nalazenje cvora sa zeljenim el.
		prev = p;
	if (p->isLT(el)) p = p->right;
		else p = p->left;
	}
	node = p;
	if (p != NULL && p->isEQ(el)) {
		if (node->right == NULL) // cvor nema desnog potomka (1)
			node = node->left;
		else if (node->left == NULL) // cvor nema levog potomka (2)
			node = node->right;
		else {	// cvor ima oba potomka (3)
			tmp = node->left;
		while (tmp->right != NULL) // nalazenje krajnjeg desnog cvora
			tmp = tmp->right; // u levom podstablu
		tmp->right = node->right; // prebacivanje desnog linka node-a u tmp
		node = node->left;	// na tekucem mestu bice prvi levi potomak
		}
	if (p == root)
		root = node;
	else if (prev->left == p)
		prev->left = node;
	else prev->right = node;
	delete p;
	numOfElements—;
	}
	else if (root != NULL) throw new SBPException("Element is not in the tree!");
	else throw new SBPException("The tree is empty!");
}

template <class T>
void BSTree<T>::balance(intdata[], int first, int last)
{
if (first <= last) {
	int middle = (first + last)/2;
	insert(data[middle]);
	balance(data,first,middle-l);
	balance(data,middle+l,last);
}
}

