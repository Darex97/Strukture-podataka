#pragma once
#include<iostream>
using namespace std;
class Cvor
{public:
	int key;
	int dana, testiranih;//modifikacija
	Cvor* left, * right;

	~Cvor(){}
	Cvor() { key = 0; left = right = NULL; }
	Cvor(int e,int d,int t) { key = e; left = right = NULL; dana = d; testiranih = t;}//modifikovano
	Cvor(int el, int d, int t, Cvor* lt, Cvor* rt) { key = el; left = lt; right = rt; dana = d; testiranih = t; }//modifikovano za decembar 2020
	bool isLT(int el)
	{
		if (key < el)
			return true;
		else return false;
	}
	bool isGT(int el)
	{
		if (key > el)
			return true;
		else return false;
	}
	bool isEQ(int el)
	{
		if (key == el)
			return true;
		else return false;
	}
	void setKey(int el) { key = el; }
	int getKey() { return key; }
	void visit() { cout << key << " "; }









};