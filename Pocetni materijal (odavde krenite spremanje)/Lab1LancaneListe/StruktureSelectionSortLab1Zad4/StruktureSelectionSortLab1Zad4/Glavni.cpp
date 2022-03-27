#include"CvorListe.h"
#include"SLL.h"
#include<iostream>
using namespace std;

void main() {
	SLL lista,listaBubble;
	cout << "SelectionSort:" << endl;
	lista.addToHead(19);
	lista.addToHead(24);
	lista.addToHead(5);
	lista.addToHead(6);
	lista.addToHead(23);
	lista.printAll();
	cout << "Nakon sortiranja: " << endl;
	lista.SelectionSort();
	lista.printAll();
	cout << "BubbleSort:" << endl;
	listaBubble.addToHead(13);
	listaBubble.addToHead(2);
	listaBubble.addToHead(15);
	listaBubble.addToHead(2);
	listaBubble.addToHead(72);
	listaBubble.printAll();
	listaBubble.BubbleSort();
	//lista.printAll();

}