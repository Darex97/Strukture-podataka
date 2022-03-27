#include"QueueAsArray.h"
#include"StackAsArray.h"
#include<iostream>
using namespace std;

void main()
{
	StackAsArray niz;
	niz.enqueue(7);
	niz.enqueue(5);
	niz.print();
}