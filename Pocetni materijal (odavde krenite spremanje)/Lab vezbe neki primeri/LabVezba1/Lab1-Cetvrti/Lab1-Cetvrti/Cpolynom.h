#pragma once
class Cpolynom
{
	double *coef;
	int order;
public:
	Cpolynom();
	Cpolynom(int order);
	void Coef(int exp,double koef );
	void stampaj();
	Cpolynom& Div(Cpolynom p1,Cpolynom p2);
	~Cpolynom();
};
