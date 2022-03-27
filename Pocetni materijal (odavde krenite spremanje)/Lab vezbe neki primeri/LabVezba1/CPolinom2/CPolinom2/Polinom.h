#pragma once
class Polinom
{
private:
	double* koeficijenti;
	int stepen;
public:
	Polinom(int order);
	void Koef(int* exp,double* coef,int no);
	void stampaj();
	Polinom oduzmi(const Polinom P);
	~Polinom();
};

