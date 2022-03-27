#include "GraphAsLists.h"
#include "Edge.h"
#include "LinkedNode.h"
#include <iostream>

using namespace std;

int main(void) {
	GraphAsLists<int> graf;

	graf.insertNode(1);
	graf.insertNode(2);
	graf.insertNode(3);
	graf.insertNode(4);

	graf.insertEdge(1, 2);
	graf.insertEdge(2, 3);
	graf.insertEdge(3, 4);
	graf.insertEdge(1, 1);

	graf.print();

	int p;
	graf.findThatNode(p);

	cout << "P je: " << p;

	int t;
	cin >> t;

	return 0;
}