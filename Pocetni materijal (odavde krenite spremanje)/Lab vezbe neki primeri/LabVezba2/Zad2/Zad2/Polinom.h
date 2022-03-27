#pragma once

class CPolinom
{
	double* koeficijenti;
	int stepen;
public:
	CPolinom(int order);
	~CPolinom(void);
	void Coefs(int* exp, double* coef, int n);
	CPolinom Sub(CPolinom poli1, CPolinom poli2);
	void print();
};
