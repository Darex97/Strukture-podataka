#pragma once
#include<iostream>
using namespace std;
class LinkedNode;
class Edge
{
public:
	LinkedNode* dest;
	Edge* link;
	int weight;
	inline Edge() { dest = NULL; link = NULL; weight = 0; }
	inline Edge(LinkedNode* destN, Edge* linkN,int w) { dest = destN; link = linkN; weight = w; }






};