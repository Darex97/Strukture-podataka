#include "GraphAsLists.h"
#include<iostream>
using namespace std;

GraphAsLists::GraphAsLists(void)
{
	this->start=NULL;
	this->numOfNodes=0;
}
LinkedNode* GraphAsLists::findNode(int el)
{
	LinkedNode *ptr=start;

	while(ptr!=NULL && ptr->node!=el)
		ptr=ptr->next;
	return ptr;
}
Edge* GraphAsLists::findEdge(int el1,int el2)
{
	LinkedNode *pel1=findNode(el1);
	LinkedNode *pel2=findNode(el2);

	if(pel1==NULL || pel2==NULL)
		return NULL;
	Edge *ptr=pel1->adj;
	while(ptr!=NULL && ptr->dest!=pel2)
		ptr=ptr->link;
	return ptr;
}
bool GraphAsLists::insertNode(int el)
{
	LinkedNode *newNode=new LinkedNode(el,NULL,this->start,0);
	if (newNode==NULL)
		return false;
	this->start=newNode;
	this->numOfNodes++;
	return true;
}
bool GraphAsLists::insertEdge(int el1,int el2)
{
	LinkedNode *pel1=findNode(el1);
	LinkedNode *pel2=findNode(el2);
	
	if(pel1==NULL || pel2==NULL)
		return false;
	Edge *ptr=new Edge(pel2,pel1->adj);
	if(ptr==NULL)
		return false;
	pel1->adj=ptr;
	return true;
}
void GraphAsLists::print()
{
	LinkedNode *ptr=this->start;
	while(ptr!=NULL)
	{
		cout<<ptr->node<<"->";
		Edge *pa=ptr->adj;
		while(pa!=NULL)
		{
			cout<<pa->dest->node<<"|";
			pa=pa->link;
		}
		cout<<"\r\n";
		ptr=ptr->next;
	}
}
int** GraphAsLists::AdjecencyMatrix()
{
	int **matrix;
	matrix=new int*[this->numOfNodes+1];   
	for(int i=0;i<this->numOfNodes+1;i++)
		matrix[i]=new int[this->numOfNodes+1];

	for(int i=0;i<this->numOfNodes+1;i++)   
		for(int j=0;j<this->numOfNodes+1;j++)
			matrix[i][j]=0;





	LinkedNode *ptr1=this->start;
	int i=1;
	while(ptr1!=NULL)   
	{
		matrix[0][i]=ptr1->node;
		matrix[i][0]=ptr1->node;
		i++;
		ptr1=ptr1->next;
	}






	for(int i=1;i<=this->numOfNodes;i++)
	{
		for(int j=1;j<=this->numOfNodes;j++)
		{
			if(this->findEdge(matrix[i][0],matrix[0][j])!=NULL)
			{
				matrix[i][j]=1;
			}
		}
	}
	return matrix;
}
void GraphAsLists::printMatrix(int** matrix)
{
	cout<<matrix[0][0]<<" ";
	for(int i=1;i<=this->numOfNodes;i++)
		cout<<matrix[0][i]<<" ";
	cout<<endl;
	for(int i=1;i<=this->numOfNodes;i++)
	{
			for(int j=0;j<=this->numOfNodes;j++)
			{
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
	}
}
GraphAsLists::~GraphAsLists(void)
{
}
