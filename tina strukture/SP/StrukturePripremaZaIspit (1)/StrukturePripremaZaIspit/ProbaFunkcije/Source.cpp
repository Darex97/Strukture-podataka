#pragma once
#include <iostream>
#include <stack>
#include "BSTree.h"
#include <algorithm> 
#include <chrono>
#include <time.h>
#include "MinHeap.h"
#include "Graph.h"
#include "DLList.h"
#include "SLList.h"
#include "ChainedHashTable.h"
#include "Student.h"
#include "MatrixNode.h"
#include "SparseMatrix.h"
#include "KeySLList.h"
#define x 33
using namespace std;
using namespace std::chrono;

string generateString();
void hashTest(unsigned int(*hash)(string)) {
	int* arr = new int[1000];
	int num = 0;
	int collisions = 0;
	for (int i = 0; i < 1000; i++)
		arr[i] = 0;
	for (int i = 0; i < 800; i++) {
		int h = hash(generateString())%1000;
		if (arr[h] == 1)
			collisions++;
		else {
			arr[h] = 1;
			num++;
		}
	}
	cout << "Out of 800  " << num << " were placed." << endl;
	cout << "Number of collisions : " << collisions << endl;
	for (int i = 0; i < 800; i++)
		cout << ((arr[i]) ? "taken" : "") << endl;
		
}
unsigned int hashFunction(int key) {
	return (key * x) ^ 2945734311;

}
unsigned int hashFunction1(string s) {
	int hash = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] != '-')
			hash = hash + (s[i] * i);
	return hash;
}
unsigned int hashFunction(string s) {
	int hash = 0;
	for (int i = 0; i < s.length(); i++)
		if (s[i] >= 'a' && s[i] <= 'z')
			hash = (hash + (s[i] * 33)) ^ 2945734311;
		else if (s[i] >= '0' && s[i] <= '9')
			hash = (s[i] - '0') * i + hash;
	return hash;
}
string generateString() {
	string s;
	for (int i = 0; i < 10; i++)
		if (i == 2 || i == 7)
			s += '-';
		else if (i < 2 || i>7)
			s += 'a'+rand()%26;
		else
			s += '0'+rand()%9;
	return s;
}

bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' || c=='^');
}
bool isVariable(char c) {
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}
int operatorPrecedance(char c) {
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else return -1;
}
void infixToPostfix(string string) {
	stack<char> s;
	int i = 0;
	while (string[i] != ';') {
		if (string[i] == '(')
			s.push(string[i]);
		else if (string[i] == ')') {
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}

			s.pop();
		}
		else if (isVariable(string[i]))
			cout << string[i];
		else if (string[i] == '^')
			s.push(string[i]);

		else if (isOperator(string[i])) {
			
				while (!s.empty()  && operatorPrecedance(string[i]) <= operatorPrecedance(s.top()))
				{
					cout << s.top();
					s.pop();
				}
				s.push(string[i]);
			
		}	
		i++;
	}
	while (!s.empty()) {
		if (isOperator(s.top())) {
			cout << s.top();
			s.pop();
		}
	}
}
void parenthesesMatch(string s) {
	unsigned int i = 0;
	stack<char> st;
	while (i < s.length()) {
		if (s[i] == '(')
			st.push(s[i]);
		else if (s[i] == ')')
			if (st.empty()) {
				cout << "Unmatched number of open and closed parentheses" << endl;
				return;
			}
			else
				st.pop();
		i++;
	}
	if (!st.empty())
		cout << "Unmatched number of open and closed parentheses" << endl;
	else
		cout << "Expression is valid" << endl;
}
int MinMaxBinary(int* niz, int n, int d, int g) {
	int t = (niz[d] + niz[g])/2-1;
	int s = (d + g) / 2 + d;
	while (d <= g) {
		if (niz[s] == t)
			return niz[s];
		else if (niz[s] > t)
			g = s - 1;
		else
			d = s + 1;
		s = (g - d) / 2 + d;
	}
	return NULL;
}
bool palindrome(string s) {
	if (s.length() <= 1)
		return true;
	else
	{
		string t = s.substr(1, s.length() - 2);
		return (toupper(s[0]) == toupper(s[s.length() - 1])) && palindrome(t);
	}
}
int efficientFibonacci(int n, int a[]) {
	if (a[n-1]>0)
		return a[n-1];
	else {
		a[n-1] = efficientFibonacci(n - 1,a) + efficientFibonacci(n - 2,a);
		return a[n-1];
	}
}
int efficientFibonacci(int n) {
		int a[2];
		a[0] = 1;
		a[1] = 1;
		realloc(a, n * sizeof(int));
		return efficientFibonacci(n, a);
	
}
int fibonacci(int n) {
	if (n <= 2)
		return 1;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}
int binarySearch(int niz[], int n, int d, int g) {
	if (niz[d] > n)
		return -1;

	int s = (g-d) / 2 + d;
	while (d <= g) {
		if (niz[s] == n)
			return s;
		else if (niz[s] < n)
			d = s + 1;
		else
			g = s - 1;
		s = (g - d) / 2 + d;
	}
	return -1;
}
int halfBinaryHalfLinear(int niz[],int n,int val) {
	if (niz[0] > val)
		return -1;

	
	int d = 0;
	int g = (n - 1) / 2;
	int s = (g - d) / 2 + d;

	if (niz[g] < val)
		goto jump;

	
	while (d <= g) {
		if (niz[s] == val)
			return s;
		else if (niz[s] < val)
			d = s + 1;
		else
			g = s - 1;
		s = (g - d) / 2 + d;
	}

	jump:
	if (niz[n / 2-1] < val)
	{
		int i = n / 2;
		while (i < n && niz[i] != val)
			i++;
		if (i <= n)
			return i;
	}
	return -1;;
}
int main() {
	try {
		//int a[10] = { 2,3,5,6,8,12 };
		//string s = "a+b*(c^d-e)^(f+g*h)-i;";
		//infixToPostfix(s);
		//cout << endl;
		//parenthesesMatch(s);
		//cout << MinMaxBinary(a, 6, 0, 5);
		/*BSTree b;
		b.insert(3);
		b.insert(2);
		b.insert(16);
		b.insert(12);
		b.insert(1);
		b.insert(7);
		b.insert(10);
		b.insert(20);
		b.insert(18);
		b.insert(6);
		
		cout << b.levelDif(16, 5) << endl;
		//cout << b.deepestNode(b.getRoot(),b.height(b.getRoot()))->value << endl;
		/*cout << b.height(b.getRoot()) << endl;
		cout << b.depth(66) << endl;
		*/
		//cout << b.maxChildren()->value << endl;
		//b.postorder();
		//cout << palindrome("ablE was I ere I saw elba");
		//MinHeap<int>* h = new MinHeap<int>(10);
		srand((unsigned int)time(NULL));
		/*KeySLList<int, int> lista;
		lista.insertOrUpdate(1, 14);
		lista.printList();
		lista.insertOrUpdate(7, 54);
		lista.printList();
		lista.insertOrUpdate(3, 31);
		lista.printList();
		lista.insertOrUpdate(16, 17);
		lista.printList();
		lista.insertOrUpdate(1, 0);
		lista.printList();
		lista.insertOrUpdate(0, 11);
		lista.printList();
		lista.insertOrUpdate(0, 0);
		lista.printList();
		*/
		//hashTest(hashFunction1);
		//hashTest(hashFunction);
		//cout << generateString();
	
		/*for (int i = 0; i < 10; i++)
			h->insert(rand() % 21);
		h->printHeap();
		int i;
		cout << "Input a number to compare to :" << endl;
		cin >> i;
		cout << "\nNo. of elements lower than " << i << " : " << h->traverse(i) << endl;
		/*{
			auto start1 = high_resolution_clock::now();
			cout << efficientFibonacci(34) << endl;
			auto stop1 = high_resolution_clock::now();
			auto duration1 = duration_cast<microseconds>(stop1 - start1);

			cout << "Time taken by the efficient function: "
				<< duration1.count() << " microseconds" << endl;

			auto start = high_resolution_clock::now();
			int* a1 = new int[34 + 1];
			a1[1] = 1;
			a1[2] = 1;
			cout << efficientFibonacci(34, a1) << endl;
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);

			cout << "Time taken by the efficient function: "
				<< duration.count() << " microseconds" << endl;

			auto start2 = high_resolution_clock::now();
			cout << fibonacci(34) << endl;
			auto stop2 = high_resolution_clock::now();
			auto duration2 = duration_cast<microseconds>(stop2 - start2);

			cout << "Time taken by using an expensive function: "
				<< duration2.count() << " microseconds" << endl; }

		*/
		/*Graph drustvenaMreza;
		drustvenaMreza.insertNode(5);
		drustvenaMreza.insertNode(11);
		drustvenaMreza.insertNode(13);
		drustvenaMreza.insertNode(15);
		drustvenaMreza.insertNode(7);

		drustvenaMreza.insertEdge(5, 11);
		//drustvenaMreza.insertEdge(5, 13);
		drustvenaMreza.insertEdge(11, 15);
		drustvenaMreza.insertEdge(15, 7);
		drustvenaMreza.insertEdge(13, 15);
		drustvenaMreza.insertEdge(13, 7);
		drustvenaMreza.insertEdge(7, 13);*/

		/*drustvenaMreza.printGraph();
		cout << drustvenaMreza.numberOfLoops() << endl;
		drustvenaMreza.insertEdge(7, 7);
		cout << drustvenaMreza.numberOfLoops() << endl;*/
		//cout << drustvenaMreza.canConnect(5,13,3) << endl;
/*
		SLList<int> lista;
		lista.insertTail(8);
		lista.insertTail(11);
		lista.insertTail(2);
		lista.insertHead(13);
		lista.insertHead(31);
		lista.insertHead(5);

		cout << endl;
		lista.printList();
		lista.remove(2);
		cout << endl;
		lista.printList();
		lista.remove(11);
		cout << endl;
		lista.printList();
		lista.remove(5);
		cout << endl;
		lista.printList();
		lista.remove(13);
		cout << endl;
		lista.printList();
		lista.remove(8);
		cout << endl;
		lista.printList();
		lista.remove(39);
		cout << endl;
		lista.printList();*/
		SparseMatrix mat(5, 4);
		//mat.insert(3, 3, 15);
		mat.insert(1, 0, 5);
		mat.insert(0, 2, 30);
		mat.insert(2, 0, 9);
		mat.insert(1, 1, 7);
		mat.insert(0, 1, 3);
		mat.insert(1, 2, 11);
		mat.insert(4, 2, 74);
		mat.insert(3, 1, 21);
		mat.insert(3, 3, 8);

		mat.printArraysDebug();
		mat.printDebug();

		mat.remove(1, 2);
		mat.printArraysDebug();
		mat.printDebug();

		mat.remove(1, 0);
		mat.printArraysDebug();
		mat.printDebug();

		mat.remove(2, 0);
		mat.printArraysDebug();
		mat.printDebug();

		//lista.insertBefore(14, 5);
		//lista.insertBefore(44, 2);
		cout << "-----------------------------" << endl;
		//lista.insertAfter(22, 2);
		//lista.insertAfter(0, 14);

		//lista.printList();
		//lista.remove(0);
		//cout << endl;
		//lista.printList();
		//lista.remove(14);
		//cout << endl;
		//lista.printList();
		//lista.remove(22);
		//cout << endl;
		//lista.printList();

		/*while (!lista.isEmpty())
		{
			lista.removeFromTail();
			lista.printList();
			cout << endl;
		}
		cout << lista.getHead();*/

	/*ChainedHashTable<int, Student>* table=new ChainedHashTable<int, Student>(10);
	Student s("Strahinja", "Stamenkovic", 17413);

	table->insert(HashObject<int,Student>(s.getIndex(),s));
	table->print();
	table->withdraw(17413);
	table->print();*/
	/*int* a = new int[10];
	for (int i = 0; i < 5; i++)
		a[i] = i + 2;
	for (int i = 5; i < 10; i++)
		a[i] = rand() % 20 + 7;
	a[8] = 10;
	for (int i = 0; i < 10; i++)
		cout << a[i]<<" ";
	
	cout << endl<< halfBinaryHalfLinear(a, 10,10 );
	*/

		return 0;
	}
	catch (exception& e)
	{
		cout<<e.what()<<endl;
	}
}