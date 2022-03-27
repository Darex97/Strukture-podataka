#pragma once
#include "element.h"
#include <cmath>

template <class T, class R>
class tablica
{
protected:
	unsigned int lenght;	//velicina tablice
	unsigned int count;		//broj elemenata u tablici
protected:
	virtual unsigned int f(char *s)//hash funkcija
	{
		unsigned int res=0;
		unsigned int a=7;
		for(int i=0; s[i]!=0; i++)
			res=res<<a^s[i];
		return res;
	}
	unsigned int h(element<T,R> obj)
	{
		return (f(obj.getKey())%lenght);
	}
	int g(int i)///sekundarna transformacija
	{
		return (i+1)%lenght;
	}
public:
	unsigned int getLength() { return lenght; }
};