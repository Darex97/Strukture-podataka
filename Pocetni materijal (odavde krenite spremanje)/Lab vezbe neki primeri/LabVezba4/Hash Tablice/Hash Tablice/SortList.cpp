#include "SortList.h"
#include "SLLNode.h"
#include<iostream>
using namespace std;

SortList::~SortList(void)
{
}
void SortList::addToHead(int el) {
	head = new SLLNode(el, head);
	if (tail == NULL) tail = head;
	}

void SortList::printAll()
{
	for(SLLNode *tmp=head; tmp!=NULL; tmp=tmp->next)
	{
		cout<<tmp->print()<<"";
	}
}
void SortList::BubbleSort() {
	SLLNode *ptr1;
	SLLNode *ptr2, *prev2;
	for (ptr1=tail; ptr1!=head; ptr1=prev2) {
		prev2 = NULL;
		for (ptr2=head; ptr2!=ptr1; ptr2=ptr2->next) {
			if (ptr2->info > ptr2->next->info) {
				SwapNeighbors(ptr2, prev2);
			}
			prev2 = ptr2;
		}
	}
}

HashObject SortList::getNextEl(HashObject obj)
{
	SLLNode *tmp= findNode(el);
	if(tmp->next==NULL)
		throw "nema elementa";
	else
		return ((tmp->next)->info);

SLLNode* SortList::findNode(HashObject obj)
{
	
}
void SortList::SwapNeighbors(SLLNode* ptr, SLLNode* prev) {
	if (prev == NULL) {
		head = ptr->next;
		ptr->next = ptr->next->next;
		head->next = ptr;
	} else {
		prev->next = ptr->next;
		ptr->next = ptr->next->next;
		prev->next->next = ptr;
	}
}
