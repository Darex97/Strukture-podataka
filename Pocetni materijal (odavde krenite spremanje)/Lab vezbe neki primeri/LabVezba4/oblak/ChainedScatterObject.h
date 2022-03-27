#include "ScatterObject.h"
template <class T,class R>
class ChainedScatterObject:public ScatterObject<T,R>
{
public:
	long next;
public:
	ChainedScatterObject():ScatterObject<T,R>() {next=-1;}
	ChainedScatterObject(T k):ScatterObject<T,R>(k) {next=-1;}
	ChainedScatterObject(T k,R* obj):ScatterObject<T,R>(k,obj) {next=-1;}
	ChainedScatterObject(T k,R* obj,unsigned int n):ScatterObject<T,R>(k,obj) {next=n;}
};
