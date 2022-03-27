#pragma once

#include <iostream>

using namespace std;

#include "BSTNode.h"
#include "StaticQueue.h"

template <class T>
class DynamicBSTree2
{
private:
	BSTNode<T>* root;
	unsigned int numberOfNodes;

public:
	DynamicBSTree2();

	void deleteTree(BSTNode<T>* node);

	~DynamicBSTree2() { this->deleteTree(this->root); }

	unsigned int getNumberOfNodes() const { return this->numberOfNodes; }
	bool isEmpty() const { return this->numberOfNodes == 0; }

	void insert(T element);
	BSTNode<T>* search(BSTNode<T>* node, T element) const;

	BSTNode<T>* search(T element) const { return this->search(this->root, element); }

	void breadthFirst() const;
	void preorder(BSTNode<T>* node) const;

	void preorder() const { this->preorder(this->root); }

	int levelWithMaxNumberOfNodes() const;
};

template <class T>
DynamicBSTree2<T>::DynamicBSTree2()
{
	this->root = nullptr;
	this->numberOfNodes = 0;
}

template <class T>
void DynamicBSTree2<T>::deleteTree(BSTNode<T>* node)
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
void DynamicBSTree2<T>::insert(T element)
{
	if (this->isEmpty())
	{
		this->root = new BSTNode<T>(element);
	}
	else
	{
		BSTNode<T>* current = this->root;
		BSTNode<T>* previous = nullptr;

		while (current != nullptr)
		{
			previous = current;

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
	}

	this->numberOfNodes++;
}

template <class T>
BSTNode<T>* DynamicBSTree2<T>::search(BSTNode<T>* node, T element) const
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
void DynamicBSTree2<T>::breadthFirst() const
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
void DynamicBSTree2<T>::preorder(BSTNode<T>* node) const
{
	if (node != nullptr)
	{
		cout << node->key << " ";

		this->preorder(node->left);
		this->preorder(node->right);
	}
}

template <class T>
int DynamicBSTree2<T>::levelWithMaxNumberOfNodes() const
{
	if (this->isEmpty())
	{
		return -1;
	}

	BSTNode<T>* current = this->root;
	StaticQueue<BSTNode<T>*>* queue = new StaticQueue<BSTNode<T>*>(this->numberOfNodes);

	int currentLevel = 0, levelWithMaxNoOfNodes = 0, maxNoOfNodes = 1;

	queue->enqueue(current);

	while (!queue->isEmpty())
	{
		int nodeCount = queue->getNumberOfElements();

		if (nodeCount > maxNoOfNodes)
		{
			levelWithMaxNoOfNodes = currentLevel;
			maxNoOfNodes = nodeCount;
		}

		while (nodeCount > 0)
		{
			current = queue->dequeue();

			if (current->left != nullptr)
			{
				queue->enqueue(current->left);
			}

			if (current->right != nullptr)
			{
				queue->enqueue(current->right);
			}

			nodeCount--;
		}

		currentLevel++;
	}

	delete queue;

	return levelWithMaxNoOfNodes;
}