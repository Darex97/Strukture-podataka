// hainedHashTable.h: interface for the ChainedHashTable class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HAINEDHASHTABLE_H__471F3BA5_71B0_4B11_A59E_F78F382DB6B3__INCLUDED_)
#define AFX_HAINEDHASHTABLE_H__471F3BA5_71B0_4B11_A59E_F78F382DB6B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "HashTable.h"
#include "HashObject.h"
#include "SLList.h"
//#include "SLLNode.h"

template <class T, class R>
class ChainedHashTable : public HashTable<T,R>  
{
protected:
	SLList<HashObject<T,R> > *array;
public:
	ChainedHashTable(unsigned int len){
		lenght = len;
		count = 0;
		array = new SLList<HashObject<T,R> >[len];
	}
	~ChainedHashTable(){
		HashObject<T,R> obj;
		for(unsigned int i=0;i<lenght;i++){
			try{
				obj = array[i].getHeadEl();
				while(true){
					obj.deleteRecord();
					obj = array[i].getNextEl(obj);
				}
			}
			catch (char* s){ cout<<s<<endl;}
		}
		delete [] array;
	}
	void display(){
		for (unsigned int i=0;i<lenght;i++){
			cout<<"["<<i<<"]"<<"X->";
			HashObject<T,R> obj;
			try{
				obj = array[i].getHeadEl();
				while (true){
					obj.print();
					cout<<"->";
					obj = array[i].getNextEl(obj);
				}
			}
			catch(char* s){ cout<<s<<endl;}
		}
	}
	void insert(HashObject<T,R> obj){
		array[h(obj)].addToHead(obj);
		count++;
	}
	void withdraw(HashObject<T,R> obj){
		array[h(obj)].deleteEl(obj);
		count--;
	}
	void withdraw(T key){
		HashObject<T,R> obj = find(key);
		withdraw(obj);
	}
	HashObject<T,R> find(T key){
		HashObject<T,R> obj;
		unsigned int i = f(key)%lenght;
		obj = array[i].getHeadEl();
		while(!(obj.isEqualKey(key)))
			obj = array[i].getNextEl(obj);
		return obj;
	}
};

#endif // !defined(AFX_HAINEDHASHTABLE_H__471F3BA5_71B0_4B11_A59E_F78F382DB6B3__INCLUDED_)
