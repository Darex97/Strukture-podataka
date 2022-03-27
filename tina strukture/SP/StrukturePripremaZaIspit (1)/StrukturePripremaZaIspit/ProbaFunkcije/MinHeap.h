#pragma once
#include <iostream>
#include <exception>
#include <array>
using namespace std;

template<class T>
class MinHeap {
private:
	T* niz;
	unsigned long currently;
	unsigned long length;

	unsigned int getLeftChildIndex(unsigned int i) { return 2 * i + 1; }
	unsigned int getRightChildIndex(unsigned int i) { return 2 * i + 2; }
	unsigned int getParentIndex(unsigned int i) { return (i - 1) / 2; }

	bool hasLeftChild(unsigned int i) { return getLeftChildIndex(i) < currently; }
	bool hasRightChild(unsigned int i) { return getRightChildIndex(i) < currently; }
	bool hasParent(unsigned int i) { return getParentIndex(i) >= 0; }

	T getLeftChild(unsigned int i) { return niz[getLeftChildIndex(i)]; }
	T getRightChild(unsigned int i) { return niz[getRightChildIndex(i)]; }
	T getParent(unsigned int i) { return niz[getParentIndex(i)]; }


	void swap(unsigned int i, unsigned int j) {
		T pom = niz[i];
		niz[i] = niz[j];
		niz[j] = pom;
	}
	bool isEmpty() { return currently == 0; }
public:
	MinHeap(unsigned long l) {
		length = l;
		currently = 0;
		niz = new T[length];
	}

	~MinHeap() { delete[] niz; }

	T pull() {
		if (isEmpty()) throw new exception("The heap is empty");
		T value = niz[0];
		niz[0] = niz[length - 1];
		currently--;
		downHeap();
		return value;
	}

	void insert(T el) {
		if (currently == length)
			throw new exception("The heap is full.");
		niz[currently++] = el;
		upHeap();
	}

	void upHeap() {
		unsigned int index = currently - 1;
		while (hasParent(index) && getParent(index) > niz[index])
		{
			swap(getParentIndex(index), index);
			index = getParentIndex(index);
		}
	}
	void downHeap() {
		unsigned int index = 0;
		while (hasLeftChild(index)) {												//proveravamo samo levo dete,jer ako nema levog deteta nema ni desnog
			unsigned int smallerChild = getLeftChildIndex(index);
			if (hasRightChild(index) && getRightChild(index) < niz[smallerChild])	//ako postoji desno i manje je od levog
				smallerChild = getRightChildIndex(index);
			if (niz[index] < niz[smallerChild])
				break;
			else
				swap(index, smallerChild);
			index = smallerChild;
		}
	}
	
	void breadthFirst() {
		cout << "Breadth first :" << endl;
		for (unsigned int i = 0; i < currently; i++)
			cout << niz[i] << "(" << i << ") ";
		cout << endl;
	}
	void printHeap()
	{
		cout << "Level by level :" << endl;
		unsigned int levelNumber = 0;
		unsigned int numItemsAtThisLevel = 1;
		unsigned int numPrintedThisLevel = 0;

		for (unsigned int i = 0; i < currently; i++)
		{
			if (numPrintedThisLevel == 0)
				cout << "\nlevel #" << levelNumber << " : ";

			cout << niz[i] << ' ';
			++numPrintedThisLevel;

			if (numPrintedThisLevel == numItemsAtThisLevel)
			{
				++levelNumber;
				numItemsAtThisLevel *= 2;
				numPrintedThisLevel = 0;
			}
		}

		cout << '\n';
	}
	void preorder(unsigned int i = 0) {
		if (i < currently) {
			cout << niz[i] << " ";
			preorder(getLeftChildIndex(i));
			preorder(getRightChildIndex(i));
		}
	}
	
	int traverse(T& no, unsigned int i = 0) {
		if (i < currently) {
			int num = traverse(no, getLeftChildIndex(i)) + traverse(no, getRightChildIndex(i));
			if (niz[i] < no) {									//moze se vrsiti bilo koja aritmeticka provera
				return num + 1;
			}
			else
				return num;

		}
		else
			return 0;
	}
	
};
