#include <iostream>
using namespace std;
class CvorStabla
{
public:
	int info;
	CvorStabla* levodete;
	CvorStabla* desnodete;
	CvorStabla()
	{
		levodete=desnodete=NULL;
	}
	CvorStabla( int pod)
	{
		info=pod;
		levodete=desnodete=NULL;
	}
	CvorStabla(CvorStabla* levo,CvorStabla* desno,int pod)
	{
		info=pod;
		levodete=levo;
		desnodete=desno;
	}
	int upoderi(int pod)
	{
		if(info<pod)
			return -1;
		else 
			if(info>pod)
			return 1;
			else 
			return 0;
	}
	void  obradi()
	{
			cout<<this->info<< " ";
	}
	
};
