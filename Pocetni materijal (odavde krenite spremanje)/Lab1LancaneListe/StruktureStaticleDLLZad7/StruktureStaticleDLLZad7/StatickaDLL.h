#pragma once
class StatickaDLL {
public:
	int* prev;
	int* info;
	int* next;
	int size;
	//int head;
public:
	StatickaDLL();
	StatickaDLL(int s);
	~StatickaDLL();
	void addToHead(int el);
	void print();
	void bubbleSort(bool rastuci);
};