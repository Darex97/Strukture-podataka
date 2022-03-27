#pragma once

class CStaticSortList
{
public:
	int* info;
	int* next;
	int size;
	CStaticSortList(void) : size(0) {}
	CStaticSortList(int s);
	~CStaticSortList(void);
	void addToHead(int el);
	void print();
	void bubbleSort(bool rastuci);
};
