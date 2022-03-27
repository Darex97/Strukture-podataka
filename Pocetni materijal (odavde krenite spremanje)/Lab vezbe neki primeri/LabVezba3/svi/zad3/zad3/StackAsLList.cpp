#include "StackAsLList.h"

StackAsLList::StackAsLList()
{
	vrh=NULL;
}
void StackAsLList::push(int x)
{
	vrh=new Node(x,vrh);
}
int StackAsLList::pop()
{
	if(vrh==NULL)
		throw "Potkoracenje";
	int rez=vrh->getinfo();
	Node *tmp=vrh;
	vrh=vrh->getnext();
	delete tmp;
	return rez;
}
int StackAsLList::getvrh()
{
	if(vrh==NULL)
		cout<<"Magacin je prazan!"<<endl;
	return vrh->getinfo();
}
void StackAsLList::stampaj()
{
	for(Node *tmp=vrh;tmp!=NULL;tmp=tmp->getnext())
		cout<<tmp->getinfo()<<endl;
	cout<<"/////"<<endl;
}