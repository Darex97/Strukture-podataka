// Object.h: interface for the Object class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBJECT_H__332FE73D_2FA3_4F13_A954_AACFD7F4A83C__INCLUDED_)
#define AFX_OBJECT_H__332FE73D_2FA3_4F13_A954_AACFD7F4A83C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Object  
{
	char *key;
	char *record;
public:

	bool free;
	unsigned int next;

	Object();
	Object(char*);
	Object(char*, char*);
	Object(char*, char*, unsigned int);
	virtual ~Object();
	void deleteRecord();
	inline char* getKey(){ return key;}
	inline char* getRecord(){ return record;}
	bool isEqualKey(char*);
	void print();

};

#endif // !defined(AFX_OBJECT_H__332FE73D_2FA3_4F13_A954_AACFD7F4A83C__INCLUDED_)
