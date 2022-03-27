#include <iostream.h>
#include "List.h"

int main(){

	List obj;

	obj.addTail(0);
	obj.addHead(1);
	obj.addHead(2);
	obj.addTail(5);
	cout<<"pre brisanja"<<endl;
	obj.display();
	obj.jediG();
	obj.addHead(3);
	obj.deleteHead();
	obj.deleteTail();
	cout<<"Posle brisanja"<<endl;
	obj.display();

	return 0;

}