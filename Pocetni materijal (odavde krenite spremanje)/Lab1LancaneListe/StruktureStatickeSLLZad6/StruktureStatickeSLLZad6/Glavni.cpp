#include"StatickaSLL.h"
#include<iostream>
using namespace std;

void main() {
	StatickaSLL s1(7);
	s1.addToHead(2);
	s1.addToHead(1);
	s1.addToHead(9);
	s1.addToHead(3);
	s1.addToHead(7);
	s1.print();
	s1.bubbleSort(1);
	s1.print();
}