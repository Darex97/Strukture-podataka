#include"BSTree.h"
#include"StackAsArray.h"
#include<iostream>
#include<math.h>
using namespace std;


BSTree::BSTree(int length)
{
	this->length=length;
	this->_array=new int[length+1];
	this->numOfElements=0;
	for(int i=0;i<this->length;i++)
		this->_array[i]=-1;
}
BSTree* BSTree::MirrorCopy()
{
	BSTree *tree=new BSTree(this->length);
	return tree;

}
//void BSTree::IterativePreorder()
//{
//	int tmp=0;
//	StackAsArray stack(this->length);
//	if (tmp!=this->end)
//	{
//		stack.push(this->_array[tmp]);
//		while (!stack.IsEmpty())
//		{
//			tmp=stack.pop();
//			cout<<this->_array[tmp]<<endl;
//			if ()
//		}
//
//	}
//}
void BSTree::insert(int el)
{
	if (this->numOfElements==this->length)
		throw "Stablo je popunjeno.";
	else
	{
			int i=0;
			while(i<this->length && this->_array[i]!=-1)
			{
				if (el<this->_array[i] )
					i=2*i+1;
				else
					i=2*i+2;
			}
			if (this->_array[i]==-1)
			{
				this->_array[i]=el;
				this->numOfElements++;
				cout<<"Element "<<el<<"-indeks "<<i<<endl; 
				int j=this->length-1;
				while (j>=0 && this->_array[j]==-1)
					j--;
				if (this->_array[j]!=-1)
					this->end=j;
			}
			else
				throw "Nema odgovarajuceg mesta u stablu.";
	}
	//cout<<(end)<<endl;
}
int BSTree::numOfUnique()
{
	int numOfUnique=0;
	for (int i=0;i<this->length;i++)
	{
		int found=0;
		for (int j=0;j<this->length;j++)
		{
			if (this->_array[i]==this->_array[j] && i!=j)
				found=1;
		}
		if (found==0)
			numOfUnique++;
	}
	return numOfUnique;
}
int BSTree::TreeHeight()
{
	cout<<"Indeks poslednjeg elementa: "<<this->end<<endl;
	int treeHeight=0;
	treeHeight=(int)(log((double)(this->end))/log((double)2));
	return treeHeight+1;
}
int BSTree::TreeWeight()
{
	int treeWeight=0;
	int i=0;
	while ((2*i+1)!=this->end && (2*i+2)!=this->end)
	{
		if (this->_array[i]!=-1)
		{
			if (this->_array[2*i+1]==-1 && this->_array[2*i+2]==-1)
				treeWeight++;
		}
		i++;
	}
	if ((2*i+2)==this->end)
	{
		if (this->_array[2*i+1]==-1 && this->_array[2*i+2]==-1)
			treeWeight++;
	}
	else
	{
		if (this->_array[2*i+1]==-1)
			treeWeight++;
	}
	for (i;i<this->end;i++)
	{
		if (this->_array[i]!=-1)
			treeWeight++;
	}
	return treeWeight;
}
void BSTree::deleteTerminals()
{
	int i=0;
	while ((2*i+1)!=this->end && (2*i+2)!=this->end)
	{
		if (this->_array[i]!=-1)
		{
			if (this->_array[2*i+1]==-1 && this->_array[2*i+2]==-1)
				this->_array[i]=-1;
		}
		i++;
	}
	if ((2*i+2)==this->end)
	{
		if (this->_array[2*i+1]==-1 && this->_array[2*i+2]==-1)
			this->_array[i]=-1;
	}
	else
	{
		if (this->_array[2*i+1]==-1)
			this->_array[i]=-1;
	}
	for (i;i<this->end;i++)
	{
		if (this->_array[i]!=-1)
			this->_array[i]=-1;
	}
}
void BSTree::print()
{
	for (int i=0;i<this->length;i++)
	{
		if (this->_array[i]!=-1)
			cout<<this->_array[i]<<",";
		else
			cout<<" ,";
	}
	cout<<endl;
}
BSTree::~BSTree(void)
{
}
