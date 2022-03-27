#pragma once
#include "element.h"
#include <cmath>

template <class T, class R>
class tablica
{
protected:
	unsigned int length;	//velicina tablice
	unsigned int count;		//broj elemenata u tablici
protected:
	unsigned int h(element<T,R> obj)
	{
		return (f(obj.getKey())%length);
	}
	virtual unsigned int f(char *s)//hash funkcija
	{
		unsigned int res=0;
		unsigned int a=7;
		for(int i=0; s[i]!=0; i++)
			res=res<<a^s[i];
		return res;
	}
public:
	unsigned int getLength() { return length; }
	/*virtual double getLoadFactor()
	{
		return (double)count/(double)length;
	}*/
};
