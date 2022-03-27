// HashTable.h: interface for the HashTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HASHTABLE_H__C03608D2_1B79_4BAF_90A9_4E41A0F73CB4__INCLUDED_)
#define AFX_HASHTABLE_H__C03608D2_1B79_4BAF_90A9_4E41A0F73CB4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "HashObject.h"
#include <math.h>

template <class T, class R>
class HashTable
{
protected:
	unsigned int lenght;
	unsigned int count;
protected:
	unsigned int h(HashObject<T,R> obj){
		return (f(obj.getKey())%lenght);
	}
	virtual unsigned int f(int i){ return abs(i);}
	virtual unsigned int f(double d){
		if(d==0) return 0;
		else {
			int exponent;
			double mantissa = frexp(d, &exponent);
			return (unsigned int)((2*fabs(mantissa)-1*~0U));
		}
	}
	virtual unsigned int f(char* s){
		unsigned int res = 0;
		unsigned int a = 7;
		for(int i=0;s[i]!=0;i++)
			res = res<<a^s[i];
		return res;
	}
	virtual unsigned int g(unsigned int i){
		return (i+1)%lenght;
	}
public:
	unsigned int getLenght(){ return lenght;}
	virtual double getLoadFactor(){
		return (double)count/(double)lenght;
	}
};

#endif // !defined(AFX_HASHTABLE_H__C03608D2_1B79_4BAF_90A9_4E41A0F73CB4__INCLUDED_)
