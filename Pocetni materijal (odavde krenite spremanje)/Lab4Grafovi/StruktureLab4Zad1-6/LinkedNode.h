#pragma once
#include<iostream>
using namespace std;
#include"Edge.h"
class Edge;//forward declaration
//Ova vrsta dekleracije je neophodna iz sledeceg razloga:
//Klasa Edge ukljucuje klasu LinkedNode i obrnuto, sto znaci da kad ukljucim
//klasu Edge ovde, ona ukljuci i klasu LinkedNode, a ona ponovo Edge i tako se stvara
//beskonacna petlja, tj. StackOverflow.
class LinkedNode 
{
public:
	int node;//info
	Edge* adj;//sused
	LinkedNode* next;//naredni cvor
	int status;

	LinkedNode() { adj = NULL;next = NULL;status = 0; }
	LinkedNode(int n) 
	{
		node = n;
		adj = NULL;
		next = NULL;
		status = 0;
	}
	LinkedNode(int nodeN, Edge* adjN, LinkedNode* nextN, int statusN)
	{
		node = nodeN;
		adj = adjN;
		next = nextN;
		status = statusN;
	}
	void visit() { cout << node << endl; }

};