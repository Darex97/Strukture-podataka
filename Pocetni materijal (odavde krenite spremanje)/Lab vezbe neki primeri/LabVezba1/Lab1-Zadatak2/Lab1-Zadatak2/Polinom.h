#pragma once
class Polinom
{
private:
	int stepen;
	double* nizkoef;
public:
	Polinom();
	Polinom(int order);
	void Coefs(int* exp,double* coef,int no);
	void Sub(Polinom& p1,Polinom& p2);
	void stampaj();
	~Polinom(void);
};

