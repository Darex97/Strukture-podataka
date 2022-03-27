#include "GraphAsLists.h"


//GraphAsLists::GraphAsLists(void)
//{
//}
bool GraphAsLists::insertNode(int el)
{
	LinkedNode *newNode=new LinkedNode(el,NULL,this->start,0);
	if (newNode==NULL)
		return false;
	this->start=newNode;
	this->nodeNum++;
	return true;
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
LinkedNode* GraphAsLists::indegMax()
{
	int result=0;
	LinkedNode *RESULT;

	LinkedNode *ptr1=this->start;
	while(ptr1!=NULL)
	{
		Edge *ptr2=ptr1->adj;
		while(ptr2!=NULL)
		{
			ptr2->dest->indeg++;
			ptr2=ptr2->link;
		}
		ptr1=ptr1->next;
	}

	ptr1=this->start;

	while(ptr1!=NULL)
	{
		if(result<ptr1->indeg)
		{
			result=ptr1->indeg;
			RESULT=ptr1;
		}
		ptr1=ptr1->next;
	}
	return RESULT;
}
LinkedNode* GraphAsLists::outdegMax()
{
	int result=0;
	LinkedNode *RESULT;
	LinkedNode *ptr1=this->start;

	while(ptr1!=NULL)
	{
		Edge *ptr2=ptr1->adj;
		while(ptr2!=NULL)
		{
			ptr1->outdeg++;
			ptr2=ptr2->link;
		}
		ptr1=ptr1->next;
	}

	ptr1=this->start;

	while(ptr1!=NULL)
	{
		if(result<ptr1->outdeg)
		{
			result=ptr1->outdeg;
			RESULT=ptr1;
		}
		ptr1=ptr1->next;
	}
	return RESULT;
}
LinkedNode* GraphAsLists::zeroIndeg()// sredi return!!!
{
	LinkedNode *result;
	LinkedNode *ptr1=this->start;

	while(ptr1!=NULL)
	{
		Edge *ptr2=ptr1->adj;
		while(ptr2!=NULL)
		{
			ptr2->dest->indeg++;
			ptr2=ptr2->link;
		}
		ptr1=ptr1->next;
	}

	ptr1=this->start;

	while(ptr1!=NULL && ptr1->indeg!=0)
	{
		ptr1=ptr1->next;
	}
	if(ptr1==NULL)
		throw "Ne postoji cvor sa 0 ulaznim stepenom";
	else
	{
		result=ptr1;
		return result;
	}

}
LinkedNode* GraphAsLists::zeroOutdeg()
{
	LinkedNode *ptr1=this->start;

	while(ptr1!=NULL)
	{
		if(ptr1->adj==NULL)
			return ptr1;
		ptr1=ptr1->next;
	}
	throw"Ne postoji cvor sa 0 izlaznim stepenom.";
}
int** GraphAsLists::AdjecencyMatrix()
{
	int **matrix;
	matrix=new int*[this->nodeNum+1];   //// matrica ce imati po jednu kolonu i vrstu vise zbog predstavljanja cvorova
	for(int i=0;i<this->nodeNum+1;i++)
		matrix[i]=new int[this->nodeNum+1];

	for(int i=0;i<this->nodeNum+1;i++)    ////inicijalizujemo celu matricu susedstva na 0.
		for(int j=0;j<this->nodeNum+1;j++)
			matrix[i][j]=0;

	LinkedNode *ptr1=this->start;
	int i=1;
	while(ptr1!=NULL)   //popunjavamo 0-tu vrstu i 0-tu kolonu vrednostima cvorova
	{
		matrix[0][i]=ptr1->node;
		matrix[i][0]=ptr1->node;
		i++;
		ptr1=ptr1->next;
	}

	for(int i=1;i<=this->nodeNum;i++)/// popunjavanje matrice susedstva vrednostima 0 i 1
	{
		for(int j=1;j<=this->nodeNum;j++)
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
	for(int i=1;i<=this->nodeNum;i++)
		cout<<matrix[0][i]<<" ";
	cout<<endl;
	for(int i=1;i<=this->nodeNum;i++)
	{
			for(int j=0;j<=this->nodeNum;j++)
			{
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
	}
}
GraphAsLists::~GraphAsLists(void)
{
}
