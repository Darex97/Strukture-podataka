#pragma once
#include "HashObject.h"

class LList
{
public:
	HashObject* head;

	LList()
	{
		head = NULL;
	}
	void AddToHead(char* s)
	{
		head = new HashObject(s, head);
	}
	void deleteFromHead()
	{
		while (!isEmpty())
		{
			HashObject* pom = head;
			head = head->next;
			delete pom;
		}
	}
	void deleteEl(char* s)
	{
		HashObject* ptr = head;
		HashObject* prev;
			while (ptr != NULL && strcmp(ptr->key, s) != 0)
			{
				ptr = ptr->next;
			}
			if (ptr == NULL)
				throw "Ne postoji taj element";

			else 
				if(ptr->next == NULL)
			{
				head->next = NULL;
				delete ptr;
			}
			else
			{
				head = ptr->next;
				delete ptr;
			}
				
	}
	HashObject* getHead()
	{
		return head;
	}
	bool isEmpty()
	{
		return head == NULL;
	}

};