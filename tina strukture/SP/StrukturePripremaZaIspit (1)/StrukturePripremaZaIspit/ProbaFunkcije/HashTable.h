#pragma once
#include "HashObject.h"

template<class T,class R>
class HashTable {
protected:
	unsigned int length;
	unsigned int count;

	unsigned int h(HashObject<T, R>& obj) {
		return f(obj.getKey()) % length;
	}
	unsigned int h(T key) {
		return f(key) % length;
	}
	virtual unsigned int f(int i) { return 33*i^23; }
	virtual unsigned int f(double d) {
		if (d == 0) return 0;
		else {
			int exponent;
			double mantice = frexp(d, &exponent);
			return (unsigned int)((2 * fabs(mantice) - 1) * ~0U);
		}
	}
	virtual unsigned int f(char* c) {
		unsigned int res = 0;
		unsigned int a = 7;
		for (int i = 0; c[i] != 0; i++)
			res = res << a ^ c[i];
		return res;
	}

	virtual unsigned int g(unsigned int i) { return (i + 1) % length; }
public :
	unsigned int getLength() { return length; }
	unsigned int getLoadFactor() { return (double)count / (double)length; }

};