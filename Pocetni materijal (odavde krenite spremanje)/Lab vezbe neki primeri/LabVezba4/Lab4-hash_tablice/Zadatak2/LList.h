#include "HashObject.h"
class LList
{
	HashObject *head;
public:
	LList();
	void addtohead(char*,char*,char*);
	void deletefromhead();
	void deleteEl(char*);
	HashObject* gethead(){return head;};
	bool IsEmpty(){return head==NULL;};
};