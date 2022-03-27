#include <iostream>
using namespace std;
//#include "Node.h"
#include "SparseMatrix.h"


int main(){

	SparseMatrix obj(10);
	obj.addElement(0,0,10);
	obj.addElement(1,1,12);
	obj.addElement(0,1,5);
	obj.addElement(0,8,20);
	obj.addElement(1,6,12);
	obj.addElement(3,1,45);
	obj.addElement(5,1,13);
	obj.addElement(9,9,57);
	obj.display();
	cout<<"Faktor zauzeca je: "<<obj.getLoadFactor()<<endl;

	system("pause");
	return 0;
}