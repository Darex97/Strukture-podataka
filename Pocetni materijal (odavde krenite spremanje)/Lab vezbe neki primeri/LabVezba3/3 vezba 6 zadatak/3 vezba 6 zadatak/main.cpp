#include "dekkaolista.h"
#include "cvor.h"
#include<iostream>
using namespace std;
void main()
{
	dekkaolista a;
	a.addtohead(1);
	a.addtohead(2);
	a.addtotail(3);
	a.addtotail(4);
	a.printall();
	cout<<endl;
	cout<<a.deletefromhead()<<endl;
	cout<<a.deletefromtail()<<endl;

}
