#pragma once
class BSTree
{
protected:
	int *_array;
	int length;
	int end;  //cuvace indeks poslednjeg elementa
	int numOfElements;
public:
	BSTree(int length);
	void insert(int el);
	void print();
	int numOfUnique();
	int TreeHeight();
	int TreeWeight();
	void deleteTerminals();
	BSTree* MirrorCopy();
	void IterativePreorder();
	~BSTree();
};

