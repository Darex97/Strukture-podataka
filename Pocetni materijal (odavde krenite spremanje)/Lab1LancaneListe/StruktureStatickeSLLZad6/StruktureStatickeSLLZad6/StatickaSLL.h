#pragma once
class StatickaSLL {
public:
	int* info;//niz intedzera
	int* next;//sada ovo nisu pokazivaci, nego nizovi
	int size;
	StatickaSLL();
	StatickaSLL(int s);
	~StatickaSLL();
	void addToHead(int el);
	void print();
	void bubbleSort(bool rastuci);
};