#include "klasa.h"
#include<iostream.h>

listel::listel()
	{
		head = 0;
		tail = 0;
		
	}
	
bool listel::IsEmpty()
	{
		return head == 0;
	}
void listel::AddToHead(int t)
	{
		if(IsEmpty())
		{
			cvor *pom;
			pom = new cvor;
	
			pom->info = t;
			pom->link = pom;

			head = pom;	
			tail = pom;
		}
		else
		{
			cvor *pom;
			pom = new cvor;
	
			pom->info = t;
			pom->link = head;

			head = pom;	
			tail->link = head;
		}
	}
void listel::AddToTail(int t)
	{
		if(IsEmpty())
			AddToHead(t);
		else
		{
			
		  tail->link = new cvor;
		  tail = tail->link;
		  tail->info = t;
		  tail->link = head;
		}
	}

int listel::tellfromHead()
	{
		if(IsEmpty())
			return head->info; 
		
		cout << "Lista je prazna \n" ;
		return 0;
	}

int listel::tellfromTail()
	{
		if(IsEmpty())
		{
			cout << "Lista je prazna \n";
				return 0;
		}
		else 
			return tail->info;
	
	}

void listel::print()
	{
		cvor *pom = head; 
		
		if(IsEmpty())
			cout << "Lista je prazna \n";
		else
		{

		while(pom->link != head)
		{
			cout << "\t" << pom->info << endl;
			pom = pom->link;
		}
			cout << "\t" << pom->info << endl;
		
		}
	}
	
void listel::deleteFromHead()
{	
	if(IsEmpty())
	{
		cout << "Lista je prazna \n" ;
		tail = 0;
	}
		
		else
		{	cvor *pom = head; 

			cout << "Obrisani element je : " << head->info << endl;
			
			if(head != tail)
			{
				head = head->link;
				tail->link = head;
			}
			else 
				head = tail = 0;
			delete pom;
		}
	
}

void listel::deleteFromTail()
{
	if(IsEmpty())
	{
		cout << "Lista je prazna \n" ;
		tail = 0;
	}
		
		else
		{
			cvor *pom = head;
			if(head == tail)
				deleteFromHead();
			else
			{	
				while(pom->link != tail)
					pom = pom->link;

				cout << "Obrisani element je : " << tail->info << endl;
	
				tail = pom;

				pom = pom->link;
				
				tail->link = head;

				delete pom;
		
				
			}
			
		}
}	


listel::~listel()
{

	while(! this->IsEmpty())
	{
		deleteFromHead();
	}

}

