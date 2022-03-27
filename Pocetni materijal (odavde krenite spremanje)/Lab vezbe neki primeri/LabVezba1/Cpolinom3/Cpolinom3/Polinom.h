#pragma once
class Polinom
{
private:
	int stepen;
	double* nizkoef;
public:
	Polinom();
	Polinom(int order);
	void Koef(int* exp,double* coef,int no);
	void stampaj();
	void pomnozi(Polinom P1,Polinom P2);
	~Polinom();
};

