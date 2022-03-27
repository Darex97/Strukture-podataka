#pragma once

template <class T>
class StaticBSTree
{
private:
	T* arrayOfNodes;
	unsigned int numberOfNodes;

public:
	StaticBSTree();
	StaticBSTree(T* arrayOfNodes, unsigned int numberOfNodes);

	~StaticBSTree();

	bool isEmpty() const { return this->numberOfNodes == 0; }

	void print() const;
};

template <class T>
StaticBSTree<T>::StaticBSTree()
{
	this->arrayOfNodes = nullptr;
	this->numberOfNodes = 0;
}

template <class T>
StaticBSTree<T>::StaticBSTree(T* arrayOfNodes, unsigned int numberOfNodes)
{
	this->arrayOfNodes = arrayOfNodes;
	this->numberOfNodes = numberOfNodes;
}

template <class T>
StaticBSTree<T>::~StaticBSTree()
{
	if (this->arrayOfNodes)
	{
		delete[] this->arrayOfNodes;
	}
}

template <class T>
void StaticBSTree<T>::print() const
{
	if (this->isEmpty())
	{
		cout << "Tree is empty!" << endl;
	}
	else
	{
		for (unsigned int i = 0; i < this->numberOfNodes; i++)
		{
			if (this->arrayOfNodes[i] != T(0))
			{
				cout << this->arrayOfNodes[i];
			}
			else
			{
				cout << "-";
			}

			cout << " ";
		}

		cout << endl;
	}
}