#include<iostream>

using namespace std;

class HashObject
{
protected:
	int key;    
	int *broj;   

public:
	HashObject(){key = 0 ; broj = NULL ;}
	HashObject(int k){ key = k ; broj = NULL ; }
	HashObject(int k, int *obj) { key = k ; broj = obj ; }
	const HashObject& operator=(const HashObject& obj)
	{
		key = obj.key;
		broj = obj.broj;
		return *this;
	} 
	void deleteRecord(){ if(broj){ delete broj; broj = NULL; } }  
	int getKey() { return key; }
	int* getRecord() { return broj; }
	bool isEqualKey(int k) { return k == key ; }
	void Print() { cout<<key<<" | "<<broj<< endl; }
}
	