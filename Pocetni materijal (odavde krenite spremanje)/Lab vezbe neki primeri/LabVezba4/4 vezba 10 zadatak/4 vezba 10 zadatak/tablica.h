#pragma once
#include "element.h"
#include <cmath>

template <class T, class R>
class tablica
{
protected:
	unsigned int length;	
	unsigned int count;
protected:
	unsigned int h(element<T,R> obj)
	{
		return (f(obj.getKey())%length);
	}
	virtual int f(int i){return i;}
	int g(int i)
	{
		return (i*i);//??
	}
};