// HashObject.h: interface for the HashObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HASHOBJECT_H__822F91D8_19A8_4377_9DA8_5F3DBB4AAFF5__INCLUDED_)
#define AFX_HASHOBJECT_H__822F91D8_19A8_4377_9DA8_5F3DBB4AAFF5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SLLNode.h"

template <class T, class R>
class HashObject 
{
protected:
	T key;
	R record;
public:
	HashObject(){ key = (T)0; record = NULL;}
	HashObject(T k){ key = k; record = NULL;}
	HashObject(T k, R object){ key = k; record = object;}
	HashObject& operator=(HashObject& obj){
		key = obj.key;
		record = obj.record;
		return *this;
	}
	bool operator==(HashObject& obj){
		return record == obj.record;
	}
	void deleteRecord(){ if(record){ record = NULL;}}
	T getKey(){ return key;}
	R getRecord(){ return record;}
	bool isEqualKey(T k){ return key == k;}
	void print(){ cout<<key<<"|"<<record;}
};

#endif // !defined(AFX_HASHOBJECT_H__822F91D8_19A8_4377_9DA8_5F3DBB4AAFF5__INCLUDED_)
