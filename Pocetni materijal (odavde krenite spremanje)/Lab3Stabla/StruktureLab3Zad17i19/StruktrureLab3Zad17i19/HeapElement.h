#pragma once
#include<iostream>
using namespace std;
class HeapElement 
{
public:
	int info;
	HeapElement *levi, *desni, *roditelj;
public:
	HeapElement() { levi = desni = roditelj=NULL; }
	HeapElement(int i, HeapElement* r)
	{
		info = i;
		roditelj = r;
		levi = desni = NULL;
	}
};
