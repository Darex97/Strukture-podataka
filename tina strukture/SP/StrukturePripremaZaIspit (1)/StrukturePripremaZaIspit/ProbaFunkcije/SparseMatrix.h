#pragma once
#include "MatrixNode.h"
#include <string>
class SparseMatrix {
	MatrixNode** row;
	MatrixNode** column;

	int n, m;
public:
	SparseMatrix(int i, int j) {
		n = i;
		m = j;
		row = new MatrixNode * [n];
		column = new MatrixNode * [m];
		for (int i = 0; i < n; i++)
			row[i] = nullptr;
		for (int i = 0; i < m; i++)
			column[i] = nullptr;
	}
	~SparseMatrix() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				remove(i, j);
				/*cout << endl;
				cout << "--------------------------------------------------------" << endl;
				printArraysDebug();
				printDebug();
				cout << "--------------------------------------------------------" << endl;
				cout << endl;*/
			}
		delete[] row, column;
		row = column = nullptr;
	}
	void print() {
		for (int i = 0; i < n; i++) {
			if (row[i]) {
				MatrixNode* ptr = row[i];
				int j = 0;

				while (j<m) {
					if (ptr) {
						int k =ptr->getJ();
						while (k != j) {
							cout << "_(" << i << ',' << j << ")\t";;
							j++;
						}
						cout << ptr->getValue() << "(" << ptr->getI() << "," << ptr->getJ()<<")\t";
						ptr = ptr->getRight();
					}
					else
					{
						cout << "_(" << i << ',' << j << ")\t";;
					}
					
					j++;
				}
				cout << endl;
			}
			else {
				for (int j = 0; j < m; j++)
					cout << "_("<<i<<','<<j<< ")\t";
				cout << endl;
			}
		}
		cout << endl;
	}
	void printArrays() {
		char c('_');
		for (int i = 0; i < n; i++)
			if (row[i]) {
				MatrixNode* ptr = row[i];
				cout << ptr->getValue() << "\t(" << ptr->getI() << "," << ptr->getJ() << ")\t" << ptr->getDown() << "|" << ptr->getRight() <<"\t";
				cout << endl;
			}
			else
				cout << "_\t(" << i <<",x)\t"<< endl;

		cout << endl;
		for (int i = 0; i < m; i++)
			if (column[i]) {
				MatrixNode* ptr = column[i];
				cout << ptr->getValue() << "\t(" << ptr->getI() << "," << ptr->getJ() << ")\t" << ptr->getDown() << "|" << ptr->getRight()<<"\t";
				cout << endl;
			}
			else
				cout << "_\t(x," << i << ")\t" << endl;
		cout << endl << endl;
	}
	void printDebug() {
		for (int i = 0; i < n; i++) {
			if (row[i]) {
				MatrixNode* ptr = row[i];
				int j = 0;

				while (j < m) {
					if (ptr) {
						int k = ptr->getJ();
						while (k != j) {
							cout << "_(" << i << ',' << j << ")\t(_,_)\t";;
							j++;
						}
						cout << ptr->getValue() << "(" << ptr->getI() << "," << ptr->getJ() << ") ";
						cout << "(" << ((ptr->getDown()) ? std::to_string(ptr->getDown()->getValue()) : "_") << "," << ((ptr->getRight()) ? std::to_string(ptr->getRight()->getValue()) : "_") << ")\t";
						ptr = ptr->getRight();
					}
					else
					{
						cout << "_(" << i << ',' << j << ") (_,_)\t";;
					}

					j++;
				}
				cout << endl;
			}
			else {
				for (int j = 0; j < m; j++)
					cout << "_(" << i << ',' << j << ")\t(_,_)\t";
				cout << endl;
			}
		}
		cout << endl;
	}
	void printArraysDebug() {
		char c('_');
		for (int i = 0; i < n; i++)
			if (row[i]) {
				MatrixNode* ptr = row[i];
				cout << ptr->getValue() << "\t(" << ptr->getI() << "," << ptr->getJ() << ")\t" << ptr->getDown() << "|" << ptr->getRight() << " ";
				cout << "(" << ((ptr->getDown()) ? std::to_string(ptr->getDown()->getValue()) : "_") << "," << ((ptr->getRight()) ? std::to_string(ptr->getRight()->getValue()) : "_") << ")\t";
				cout << endl;
			}
			else
				cout << "_\t(" << i << ",x) (_,_)\t" << endl;

		cout << endl;
		for (int i = 0; i < m; i++)
			if (column[i]) {
				MatrixNode* ptr = column[i];
				cout << ptr->getValue() << "\t(" << ptr->getI() << "," << ptr->getJ() << ")\t" << ptr->getDown() << "|" << ptr->getRight() << " ";
				cout << "(" << ((ptr->getDown()) ? std::to_string(ptr->getDown()->getValue()) : "_") << "," << ((ptr->getRight()) ? std::to_string(ptr->getRight()->getValue()) : "_") << ")\t";
				cout << endl;
			}
			else
				cout << "_\t(x," << i << ") (_,_)\t" << endl;
		cout << endl << endl;
	}
	void insert(int i, int j, int val) {
		if (i >= n || j >= m)
			throw exception("Indices out of bounds.");
		MatrixNode* node = nullptr;

		if ((row[i] && row[i]->getJ() > j) || !row[i]) {
			node = new MatrixNode(i, j, val, row[i], nullptr);
			row[i] = node;
		}
		else {
			MatrixNode* ptr = row[i];
			MatrixNode* prev = nullptr;
			while (ptr != nullptr && ptr->getJ() < j)
			{
				prev = ptr;
				ptr = ptr->getRight();
			}

			node = new MatrixNode(i, j, val, ptr, nullptr);
			prev->getRightRef() = node;
		}
		if (column[j] && column[j]->getI() > i || !column[j]) {
			node->getDownRef() = column[j];
			column[j] = node;
			
		}
		else {
			MatrixNode* ptr = column[j];
			MatrixNode* prev = nullptr;
			while (ptr != nullptr && ptr->getI() < i)
			{
				prev = ptr;
				ptr = ptr->getDown();
			}
			prev->getDownRef() = node;
			node->getDownRef() = ptr;
		}
		/*cout << endl;
		cout << "--------------------------------------------------------" << endl;
		printArraysDebug();
		printDebug();
		cout << "--------------------------------------------------------" << endl;
		cout << endl;*/
	}
	void remove(int i, int j) {
		if(i>=n || j>=m)
			throw exception("Indices out of bounds.");
		if (!row[i] || !column[j])
			//throw exception("Element not found.");
			return;

		MatrixNode* node = row[i];

		if (row[i]->getJ() == j)
			row[i] = row[i]->getRight();
		else {
			MatrixNode* prev = nullptr;
			while (node && node->getJ()!=j) {
				prev = node;
				node = node->getRight();
			}
			if(!node)
				//throw exception("Element not found.");
				return;
			else {
				prev->getRightRef() = node->getRight();
			}
		}

		
		if (column[j]->getI() == i)
			column[j] = column[j]->getDown();
		else {
			MatrixNode* tmp = column[j];
			while (tmp && tmp->getDown() != node)
				tmp = tmp->getDown();
			if(!tmp)
				//throw exception("Element not found.");
				return;
			else {
				tmp->getDownRef() = node->getDown();
			}
		}

		delete node;
		node = nullptr;
	}
};