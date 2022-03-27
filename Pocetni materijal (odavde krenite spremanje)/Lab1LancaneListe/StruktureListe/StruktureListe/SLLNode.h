#pragma once
#include<iostream>
using namespace std;
template<class T>
class SLLNode {
public:
	T info;
	SLLNode<T>* next;//pokazivac na naredni cvor
//public:
	SLLNode() { next = NULL; }//Ovim KK ces napraviti poslednji cvor
	//Tako mislim jer ce njegov pointer da bude NULL
	//Glupost. Jednostavno, nemas element pa ti je next NULL. Dobro,
	//sad si vise u ovom  pa znas. ;)
	SLLNode(T i) { info = i;next = NULL; }
	SLLNode(T i, SLLNode<T>* n) {
		info = i;
		next = n;
	}
	~SLLNode() {};
	T print(){ return info; }
	bool isEqual(T el) { return el == info; }
	friend ostream&  operator << <>(ostream& out,const SLLNode<T>& n);
};
template<class T>
ostream& operator<< <> (ostream& out, const SLLNode<T>& n) {
	out << "Glava: " << n.info;
	return out;
}
