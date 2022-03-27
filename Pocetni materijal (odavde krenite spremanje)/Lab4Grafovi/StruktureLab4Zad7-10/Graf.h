#pragma once
#include<iostream>
using namespace std;

class Graf 
{
public:
	int **matSusedstva;
	int brEl;
	int maxDim;
	int* nizCvorova;

	Graf();
	Graf(int);
	void dodajCvor(int);
	void dodajVezu(int, int);
	int nadjiCvor(int);
	void stampajGraf();
	//zad. 7
	void maxUlazni();
	//zad. 8
	void maxIzlazni();
	//zad. 9
	void nulaUlazni();
	//zad. 10
	void nulaIzlazni();

};