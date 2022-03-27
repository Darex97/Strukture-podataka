#include "stek2.h"
#include<iostream>
using namespace std;
void main()
{
	try
	{
	stek2 a(10);
	cout<<"prvi stek:"<<endl;
	a.pushstek1(1);
	a.pushstek1(2);
	a.pushstek1(3);
	a.pushstek1(4);
	a.pushstek1(5);
	a.stampajstek1();
	cout<<"drugi stek:"<<endl;
	a.puchstek2(6);
	a.puchstek2(7);
	a.puchstek2(8);
	a.puchstek2(9);
	a.puchstek2(10);
	a.stampajstek2();
	cout<<"skinuti elementi sa prvog steka:"<<endl;
	cout<<a.popstek1()<<endl;
	cout<<a.popstek1()<<endl;
	cout<<a.popstek1()<<endl;
	cout<<"skinuti elementi sa drugog steka:"<<endl;
	cout<<a.popstek2()<<endl;
	cout<<a.popstek2()<<endl;
	cout<<a.popstek2()<<endl;
	cout<<a.popstek2()<<endl;
	}
	catch(char *iz)
	{
		cout<<iz<<endl;
	}

}

