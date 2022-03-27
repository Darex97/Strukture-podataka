#include <iostream>
using namespace std;
class MaxHeap
{
public:
	int * info;
	int brEl;
	int maxEl;
	MaxHeap()
	{
		brEl=0;
		info=NULL;
		maxEl=0;
	}
	MaxHeap(int a)
	{
		brEl=0;
		info=new int[a];
		maxEl=a;
	}
	~MaxHeap()
	{
		delete [] info;
	}
	void ubaci(int el)
	{
		if(brEl==maxEl-1)
		{
			cout<<"hip je pun";
			return;
		}
		brEl++;
		int i=brEl;
		while(info[i]>el && i!=1)
		{
			info[i]=info[i/2];
			i=i/2;
		}
		info[i]=el;

	}


};
