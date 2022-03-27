// List.cpp: implementation of the List class.
//
//////////////////////////////////////////////////////////////////////
#include <iostream.h>
#include "List.h"
#include "Node.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

List::List(){
	head = tail = NULL;
}

List::~List(){
	while(!isEmpty()){
		int tmp = deleteHead();
	}
}

bool List::isEmpty(){ return head==NULL;}

void List::addHead(int el){
	if(isEmpty()){
		head = new Node(el,head);
		tail = head;
	}
	else head = new Node(el,head);
}

void List::addTail(int el){
	if(isEmpty()){
//		cout<<"prazna lista"<<endl;
		tail = new Node(el,NULL);
		head = tail;
	}
	else {
		tail->next = new Node(el,NULL);
		tail = tail->next;
	}
}

int List::deleteHead(){
	int el = head->info;
	Node *tmp = head;
	if(head==tail) head = tail = NULL;
	else head = head->next;
	delete tmp;
	return el;
}

int List::deleteTail(){
	int el = tail->info;
	Node* tmp = tail;
	if(head==tail) head = tail = NULL;
	else{
		Node *tmp = head;
		while(tmp->next != NULL){
			tail=tmp;
			tmp=tmp->next;
		}
		tail->next=NULL;
	}
	delete tmp;
	return el;
}

void List::display(){
	Node *tmp;
	cout<<"HEAD-->";
	for (tmp=head;tmp!=NULL;tmp=tmp->next)
		cout<<"["<<tmp->info<<"]-->";
	cout<<"TAIL"<<endl;
}

void List::jediG(){
	cout<<"Eve ga: "<<head->info<<endl;
}

/*
int List::deleteTail(){
	int el = tail->info;
	Node* tmp = tail;
	if(head==tail) head = tail = NULL;
	else{
		Node* tmp;
		for(tmp=head;tmp->next!=NULL;tmp=tmp->next)
			tail=tmp;
		tail->next=NULL;
	}
	delete tmp;
	return el;
}*/
