#include <iostream>
using namespace std;
class Cvor
{
public:
	int info;
	Cvor* lc;
	Cvor* dc;
	Cvor()
	{
		info=-1;
		lc=dc=NULL;
	}
	Cvor(int el)
	{
		info=el;
		lc=dc=NULL;
	}
	Cvor(int el,Cvor * l,Cvor * d)
	{
		info=el;
		lc=l;
		dc=d;
	}
	int uporedi( int el)
	{
		if(info<el)
			return -1;
		else 
			if(info>el)
				return 1;
			else return 0;
	}

};
