#pragma once
#include <iostream>

template <class T, class R>
class HashObject
{
protected:
	T key;
	R* record;
public:
	HashObject(void);
	HashObject(T k);
	HashObject(T k, R* object);
	HashObject<T,R>& operator=(HashObject const& obj);
	bool operator==(HashObject const& obj);
	void deleteRecord();
	T getKey();
	R* getRecord();
	bool isEqualKey(T k);
	virtual void print();
	//virtual ~HashObject(void);
};
template <class T, class R>
HashObject<T,R>::HashObject()
{
	this->key=(T)0;
	this->record=NULL;
}
template <class T, class R>
HashObject<T,R>::HashObject(T k)
{
	this->key=k;
	this->record=NULL;
}
template <class T, class R>
HashObject<T,R>::HashObject(T k, R *object)
{
	this->key=k;
	this->record=object;
}
template <class T, class R>
HashObject<T,R>& HashObject<T,R>::operator =(const HashObject<T,R> &obj)
{
	this->key=obj.key;
	this->record=obj.record;
	return *this;
}
template <class T, class R>
bool HashObject<T,R>::operator ==(const HashObject<T,R> &obj)
{
	return this->record==obj.record;
}
template <class T, class R>
void HashObject<T,R>::deleteRecord()
{
	if(this->record)
	{
		delete this->record;
		this->record=NULL;
	}
}
template <class T, class R>
T HashObject<T,R>::getKey()
{
	return this->key;
}
template <class T, class R>
R* HashObject<T,R>::getRecord()
{
	return this->record;
}
template <class T, class R>
bool HashObject<T,R>::isEqualKey(T k)
{
	return this->key==k;
}
template <class T, class R>
void HashObject<T,R>::print()
{
	cout << this->key << "| " << record;
}


