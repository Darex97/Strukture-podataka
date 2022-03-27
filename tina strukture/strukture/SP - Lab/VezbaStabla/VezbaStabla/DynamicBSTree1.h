#pragma once

#include <iostream>

using namespace std;

#include "BSTNode.h"
#include "StaticQueue.h"
#include "StaticBSTree.h"

template <class T>
class DynamicBSTree1
{
private:
	BSTNode<T>* root;
	unsigned int numberOfNodes;
	unsigned int height;

public:
	DynamicBSTree1();

	void deleteTree(BSTNode<T>* node);

	~DynamicBSTree1() { this->deleteTree(this->root); }

	unsigned int getNumberOfNodes() const { return this->numberOfNodes; }
	unsigned int getHeight() const { return this->height; }
	bool isEmpty() const { return this->numberOfNodes == 0; }

	void insert(T element);
	BSTNode<T>* search(BSTNode<T>* node, T element) const;

	BSTNode<T>* search(T element) const { return this->search(this->root, element); }

	void breadthFirst() const;
	void preorder(BSTNode<T>* node) const;

	void preorder() const { this->preorder(this->root); }

	void dynamicBSTToArray(BSTNode<T>* node, T arrayOfNodes[], unsigned int index) const;

	StaticBSTree<T>* staticBSTree() const;
};

template <class T>
DynamicBSTree1<T>::DynamicBSTree1()
{
	this->root = nullptr;
	this->numberOfNodes = this->height = 0;
}

template <class T>
void DynamicBSTree1<T>::deleteTree(BSTNode<T>* node)
{
	if (node != nullptr)
	{
		this->deleteTree(node->left);
		this->deleteTree(node->right);

		delete node;

		this->numberOfNodes--;
	}
}

template <class T>
void DynamicBSTree1<T>::insert(T element)
{
	if (this->isEmpty())
	{
		this->root = new BSTNode<T>(element);
		this->height++;
	}
	else
	{
		BSTNode<T>* current = this->root;
		BSTNode<T>* previous = nullptr;

		unsigned int currentHeight = 1;

		while (current != nullptr)
		{
			previous = current;
			currentHeight++;

			current = (current->isLower(element)) ? current->right : current->left;
		}

		if (previous->isLower(element))
		{
			previous->right = new BSTNode<T>(element);
		}
		else
		{
			previous->left = new BSTNode<T>(element);
		}

		if (this->height < currentHeight)
		{
			this->height = currentHeight;
		}
	}

	this->numberOfNodes++;
}

template <class T>
BSTNode<T>* DynamicBSTree1<T>::search(BSTNode<T>* node, T element) const
{
	if (this->isEmpty())
	{
		return nullptr;
	}

	while (node != nullptr && !node->isEqual(element))
	{
		node = (node->isLower(element)) ? node->right : node->left;
	}

	return node;
}

template <class T>
void DynamicBSTree1<T>::breadthFirst() const
{
	if (this->isEmpty())
	{
		cout << "Tree is empty!" << endl;
	}
	else
	{
		BSTNode<T>* current = this->root;
		StaticQueue<BSTNode<T>*>* queue = new StaticQueue<BSTNode<T>*>((int)this->numberOfNodes);

		queue->enqueue(current);

		while (!queue->isEmpty())
		{
			current = queue->dequeue();

			cout << current->key << " ";

			if (current->left != nullptr)
			{
				queue->enqueue(current->left);
			}

			if (current->right != nullptr)
			{
				queue->enqueue(current->right);
			}
		}

		cout << endl;

		delete queue;
	}
}

template <class T>
void DynamicBSTree1<T>::preorder(BSTNode<T>* node) const
{
	if (node != nullptr)
	{
		cout << node->key << " ";

		this->preorder(node->left);
		this->preorder(node->right);
	}
}

template <class T>
void DynamicBSTree1<T>::dynamicBSTToArray(BSTNode<T>* node, T arrayOfNodes[],
	unsigned int index) const
{
	if (node != nullptr)
	{
		arrayOfNodes[index] = node->key;

		this->dynamicBSTToArray(node->left, arrayOfNodes, 2 * index + 1);
		this->dynamicBSTToArray(node->right, arrayOfNodes, 2 * index + 2);
	}
}

template <class T>
StaticBSTree<T>* DynamicBSTree1<T>::staticBSTree() const
{
	if (this->isEmpty())
	{
		return new StaticBSTree<T>();
	}
	else
	{
		unsigned int length = (2 << (this->height - 1)) - 1, index = 0;

		T* arrayOfNodes = new T[length]();

		this->dynamicBSTToArray(this->root, arrayOfNodes, index);

		return new StaticBSTree<T>(arrayOfNodes, length);
	}
}