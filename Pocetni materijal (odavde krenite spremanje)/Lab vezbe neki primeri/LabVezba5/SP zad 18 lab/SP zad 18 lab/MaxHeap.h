#pragma once
#include "iostream"
using namespace std;
class MaxHeap
{
public:
	int* array;
	int lenght;
	int brEl;
	MaxHeap(int n)
	{
		lenght=n;
		brEl=0;
		array=new int[n+1];
		for (int i = 0; i < n+1; i++)
		{
			array[i]=0;
		}
	}
	~MaxHeap()
	{
		delete [] array;
	}
	bool isEmpty()
	{
		return brEl==0;
	}
	void insert(int e)
	{
	//	if(brEl==lenght-1)
		//	throw  new SBPException("full");
		brEl++;
		int i=brEl;
		while(i>1 && array[i/2]<e)
		{
			array[i]=array[i/2];
			i=i/2;
		}
		array[i]=e;
	}
	void print()
	{
		/*if(i<lenght+1)
		{ 
			
			
 			preorder(2*i);
		  
			preorder(2*i+1);
			  cout<<array[i]<<" ";
			
		}*/
		for (int i = 1; i < lenght+1; i++)
		{
			cout<<array[i]<<" ";
		}
	}
	void spojiDvaMax(MaxHeap &k)
	{
		int* pom=new int[lenght+1];
			for (int i = 1; i < lenght+1; i++)
		{
			pom[i]=array[i];
		}
		this->lenght=lenght+k.lenght;
		array=new int[lenght+1];
		for (int i = 0; i < lenght; i++)
		{
			array[i]=0;
		}
		for (int i = 1; i < lenght+1; i++)
		{
			array[i]=pom[i];
		}
		for(int i=1;i<k.lenght;i++)
		{
			this->insert(k.array[i]);
		}
	}
	 void insert_u_minheap(int e)
	{
			brEl++;
		int i=brEl;
		while(i>1 && array[i/2]>e)
		{
			array[i]=array[i/2];
			i=i/2;
		}
		array[i]=e;
	 }

	void konverzija(MaxHeap &k)
    {
		
		for (int i = 0; i < lenght; i++)
		{  
			if(array[i]!=0)
			k.insert_u_minheap(array[i]);
		}
	}
};
