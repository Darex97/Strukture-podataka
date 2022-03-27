#pragma once

class CPolynom
{
private:
	double* niz;
	int order;
public:
	CPolynom();
	CPolynom(int red);
	~CPolynom();
	void dodaj (int stepen, double koef);
	CPolynom& saberi(CPolynom& P2);
	void print();
};