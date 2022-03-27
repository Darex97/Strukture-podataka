#pragma once
class Polinom
{
private:
	double *niz;
	int order;
public:
	Polinom();
	Polinom(int red);
	void dodaj(int stepen,double koef );
	Polinom& saberi(Polinom& P1);
	void stampaj();
	~Polinom(void);
};

