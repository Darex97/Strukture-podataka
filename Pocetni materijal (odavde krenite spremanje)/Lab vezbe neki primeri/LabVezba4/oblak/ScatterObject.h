#include "HashObject.h"
template<class T,class R>
class ScatterObject : public HashObject<T,R>
{
public:
	bool free;
	ScatterObject() : HashObject<T,R>() {}
	ScatterObject(T k) : HashObject<T,R>(k) {}
	ScatterObject(T k,R* obj) : HashObject<T,R>(k,obj) {}
};
