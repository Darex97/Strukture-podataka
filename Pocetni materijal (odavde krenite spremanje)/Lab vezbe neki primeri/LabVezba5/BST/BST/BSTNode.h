#pragma once
#include<iostream>
template<class T>
class BSTNode
{
public:
	T key;
	BSTNode<T> *l,*r;
public:
	BSTNode()
	{
		l=NULL;
		r=NULL;
	}
	BSTNode(T el)
	{
      l=NULL;
		r=NULL;
		key=el;
	}
	BSTNode(BSTNode<T> *left,BSTNode<T> *right,T el)
	{
		l=left;
		r=right;
		key=el;
	}
	bool Manje(T el)
	{
		if(key<el)
			return true;
		else
			return false;
	}
	bool Vece(T el)
	{
		if(key>el)
			return true;
		else
			return false;
	}
	bool Jednaki(T el)
	{
		if(key==el)
			return true;
		else
			return false;
	}
	void Setkey(T el)
	{
		key=el;
	}
	T Getkey()
	{
		return key;
	}
	void print()
	{
		cout<<key<<endl;
	}
};