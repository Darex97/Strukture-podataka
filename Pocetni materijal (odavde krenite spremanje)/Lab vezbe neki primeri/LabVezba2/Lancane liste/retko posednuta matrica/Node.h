// Node.h: interface for the Node class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODE_H__DC1BC4AB_0728_4F0F_BA4B_F9A5C693A755__INCLUDED_)
#define AFX_NODE_H__DC1BC4AB_0728_4F0F_BA4B_F9A5C693A755__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Node  
{
public:
	int i;
	int j;
	int info;
	Node *linkk;
	Node *linkv;
	Node();
	Node(int, int, int, Node*, Node*);
	virtual ~Node();
	void print();
	bool isEqual(int);
};

#endif // !defined(AFX_NODE_H__DC1BC4AB_0728_4F0F_BA4B_F9A5C693A755__INCLUDED_)
