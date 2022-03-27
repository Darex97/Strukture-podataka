#pragma once

#include "HashObject.h"

template <class K, class T>
class ScatterObject : public HashObject<K, T>
{
public:
	int status; // 0 - free; 1 - deleted; 2 - taken.

public:
	ScatterObject() : HashObject<K, T>() { this->status = 0; }
	ScatterObject(K key) : HashObject<K, T>(key) { this->status = 0; }
	ScatterObject(K key, T object) : HashObject<K, T>(key, object) { this->status = 0; }

	~ScatterObject() { }
};