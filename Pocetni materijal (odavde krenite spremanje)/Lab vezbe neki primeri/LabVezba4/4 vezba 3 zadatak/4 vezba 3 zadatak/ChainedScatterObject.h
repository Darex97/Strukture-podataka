#pragma once

template<class T,class R>
class ChainedScatterObject:public HashObject<T,R>
{
public:
	long next;
	ChainedScatterObject():HashObject<T,R>()
	{
		next=-1;
	}
	ChainedScatterObject(T k):HashObject<T,R>(k)
	{
		next=-1;
	}
	ChainedScatterObject(T k,R *object):HashObject<T,R>(k,object)
	{
		next=-1;
	}
	ChainedScatterObject(T k,R *object,int n):HashObject<T,R>(k,object)
	{
		next=n;
	}
};
