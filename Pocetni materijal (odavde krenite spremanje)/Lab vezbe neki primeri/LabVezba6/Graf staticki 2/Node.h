
#if !defined NODE
#define NODE


#include<iostream.h>
#include"Izuzetak.h"

template<class T>

class Node
{
	public:
	T info;
	int status;
	Node<T>()
	{
		status=0;
	}
	Node<T>(T el,int st)
	{
		info=el;
		status=st;
	}
	T visit()
	{
		return info;
	}
};

#endif