#pragma once
class CBigNumSorter
{
	int **matrix;
	int row;
	int column;
public:
	CBigNumSorter(void);
	CBigNumSorter(int n,int m);
	void Add(int* num,int n);
	void Sort();
	void stampaj();
	~CBigNumSorter(void);
};

