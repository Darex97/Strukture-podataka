#pragma once
class Polinom
{
private:
	double *nizkoef;
	int stepen;
public:
	Polinom();
	Polinom(int order);
	void Coef(int exp,double koef );
	void stampaj();
	void pomnozi(Polinom P1,Polinom P2);
	Polinom& podeli(Polinom P1,Polinom P2);//ova f-ja vraca polinom zato sto mora da vrati i ostatak.
	~Polinom();
};


