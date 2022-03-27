#include "QueueAsLList.h"

QueueAsLList::QueueAsLList()
{
	head=tail=NULL;
}
void QueueAsLList::enqueue(int x)
{
	if(!IsEmpty())
	{
		tail->setnext(new Node(x,NULL));
		tail=tail->getnext();
	}
	else
		head=tail=new Node(x,NULL);
}
int QueueAsLList::dequeue()
{
	if(head==NULL)
		throw "Red je prazan";
	int rez=head->getinfo();
	Node* tmp=head;
	if(head==tail)
		head=tail=NULL;
	else
		head=head->getnext();
	delete tmp;
	return rez;
}
void QueueAsLList::stampaj()
{
	for(Node* tmp=head;tmp!=NULL;tmp=tmp->getnext())
		tmp->print();
	cout<<endl<<"/////"<<endl;
}