#include"Niz.h"
#include<iostream>
using namespace std;
void main()
{
	try {
		Niz<int> a(5);
		for (int i = 0; i < 5; i++)
			cin >> a[i];

		Niz<int> b(10);

		

		int *k= a.getData();



		for (int i = 0; i < 5; i++)
			cout << a[i];
		for (int i = 0; i < 5; i++)
			cout << k[i];

	}
	catch(exception& e)
	{
		cout << e.what();
	}
	
}