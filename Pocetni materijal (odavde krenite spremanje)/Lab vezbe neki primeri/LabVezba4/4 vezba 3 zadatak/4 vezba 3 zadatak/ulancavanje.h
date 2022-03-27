#pragma once

template<class T,class R>
class ulancavanje:public element<T,R>
{
public:
	long next;
	ulancavanje():element<T,R>()
	{
		next=-1;
	}
	ulancavanje(T k):element<T,R>(k)
	{
		next=-1;
	}
	ulancavanje(T k,R *object):element<T,R>(k,object)
	{
		next=-1;
	}
	ulancavanje(T k,R *object,int n):element<T,R>(k,object)
	{
		next=n;
	}
};
