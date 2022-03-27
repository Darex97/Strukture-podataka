// Object.cpp: implementation of the Object class.
//
//////////////////////////////////////////////////////////////////////

#include "Object.h"
#include <iostream.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Object::Object(){
	key = 0;
	record = NULL;
	next = -1;
	free = true;
}

Object::Object(char *k){
	key = k;
	record = NULL;
	next = -1;
	free = true;
}

Object::Object(char *k, char *r){
	key = k;
	record = r;
	next = -1;
	free = true;
}

Object::Object(char *k, char *r, unsigned int i){
	key = k;
	record = r;
	next = i;
	free = true;
}

Object::~Object(){
}

void Object::deleteRecord(){
	if (record) record = NULL;
}

bool Object::isEqualKey(char *k){
	return (key == k);
}

void Object::print(){
	cout<<key<<"|"<<record;
}
