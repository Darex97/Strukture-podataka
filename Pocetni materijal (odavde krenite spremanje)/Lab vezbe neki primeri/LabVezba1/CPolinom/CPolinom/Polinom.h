#pragma once


class CPolinom
{
	double* koeficijenti;
	int redPol;

public:
	CPolinom(int order);
	CPolinom(CPolinom&);
	~CPolinom(void);
	void Coef(int exp, double coef);
	CPolinom Add(CPolinom poly1, CPolinom poly2);
	void print();
};
