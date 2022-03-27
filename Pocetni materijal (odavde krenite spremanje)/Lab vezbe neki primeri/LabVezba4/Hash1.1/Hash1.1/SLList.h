#include "HashObject.h"
class SLList
{
	HashObject *head;
public:
	SLList();
	void addtohead(int,char*);
	void deletefromhead();
	void deleteEl(char*);
	HashObject* gethead(){return head;};
	bool IsEmpty(){return head==NULL;};
};