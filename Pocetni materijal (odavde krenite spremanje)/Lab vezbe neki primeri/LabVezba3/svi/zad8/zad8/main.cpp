#include "Stek.h"
#include <string>
using namespace std;
void main()
{
	try
	{
		Stek a;
		char* b=new char[20];
		cout<<"Uneti matematicki izraz"<<endl;
		cin>>b;
		int n=strlen(b);
		for(int i=0;i<n;i++)
		{
			if(b[i]>'0'&&b[i]<'9')
				a.push(b[i]-'0');
			else
				switch(b[i])
				{
					case '+':{
						int s=0;
						s+=a.pop();
						s+=a.pop();
						a.push(s);
						break;}
					case '-':{
						int y=a.pop();
						int x=a.pop();
						a.push(x-y);
						break;}
					case '*':{
						int p=1;
						p*=a.pop();
						p*=a.pop();
						a.push(p);
						break;}
					case '/':{
						int del=a.pop();
						int delj=a.pop();
						a.push(delj/del);
							 break;}
				}
		}
		cout<<"Rezultat je: "<<a.pop()<<endl;;
	}
	catch(char* a)
	{
		cout<<a<<endl;
	}
}