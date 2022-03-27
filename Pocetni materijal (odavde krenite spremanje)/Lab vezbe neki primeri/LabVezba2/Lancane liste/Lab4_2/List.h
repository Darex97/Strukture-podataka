// List.h: interface for the List class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIST_H__BD82A2BA_E6A1_45C6_84CC_01D978371EA3__INCLUDED_)
#define AFX_LIST_H__BD82A2BA_E6A1_45C6_84CC_01D978371EA3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Node.h"

class List  
{
	Node *head, *tail;
public:
	List();
	virtual ~List();

	bool isEmpty();
	void addHead(int);
	void addTail(int);
	int deleteHead();
	int deleteTail();
	void display();
	void jediG();

};

#endif // !defined(AFX_LIST_H__BD82A2BA_E6A1_45C6_84CC_01D978371EA3__INCLUDED_)
