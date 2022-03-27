#pragma once
#include<iostream>
using namespace std;
class stek2
{
private:
	int *a;
	int n;
	int top1;
	int top2;
public:
	stek2(int t);
	~stek2(void);
	void pushstek1(int el);
	void puchstek2(int el);
	int popstek1();
	int popstek2();
	void stampajstek1();
	void stampajstek2();
};
