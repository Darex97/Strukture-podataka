#pragma once
class Cpolynom
{
	double *coef;
	int order;
public:
	Cpolynom(void);
	Cpolynom(int order);
	void Coef(int exp,double coef);
	Cpolynom& Derivate(int n);
	void stampaj();
	~Cpolynom(void);
};

