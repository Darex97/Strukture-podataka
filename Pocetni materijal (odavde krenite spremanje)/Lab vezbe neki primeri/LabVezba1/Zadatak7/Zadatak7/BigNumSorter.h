#pragma once
class CBigNumSorter
{
private:
	int rows;
	int columns;
	int **matrix;
public:
	CBigNumSorter();
	CBigNumSorter(int m,int n);
	void Add(int* num,int n);
	void Sort();
	void stampaj();
	~CBigNumSorter(void);
};

