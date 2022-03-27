#pragma once
#include <cmath>
#include <math.h>
#include "HashObject.h"
#include "Pretplatnik.h"

template <class T, class R>
class HashTable
{
protected:
	int lenght;	//velicina tablice
	int count;	//broj elemenata u tablici
public:
	//HashTable(void);
//	virtual ~HashTable(void);
	int h(HashObject<T,R> obj);
	virtual int f(int i);
	virtual int f(double d);
	virtual int f(char* s);
	virtual int g(int i);
	int getLenght();
	virtual double getLoadFactor();
};

template <class T, class R>
int HashTable<T,R>::h(HashObject<T,R> obj)
{
	return (f(obj.getKey())%lenght);
}
//primarna transformacija
template <class T, class R>
int HashTable<T,R>::f(int i)
{
	return abs(i);
}
template <class T, class R>
int HashTable<T,R>::f(double d)
{
	if(d==0) return 0;
	else
	{
		int exponent;
		double mantissa=frexp(d,&exponent);
		return (int) ((2*fabs(mantissa)-1)*~0U);
	}
}
template <class T, class R>
int HashTable<T,R>::f(char *s)
{
	unsigned int res=0;
	unsigned int a=7;
	for(int i=0;s[i]!=0;i++)
		res=res<<a^s[i];
	return res;
}

//sekundarna transformacija
template <class T, class R>
int HashTable<T,R>::g(int i)
{
	return (i+1)%lenght;
}
template <class T, class R>
int HashTable<T,R>::getLenght()
{
	return this->lenght;
}
template <class T, class R>
double HashTable<T,R>::getLoadFactor()
{
	return (double)count/(double)lenght;
}




