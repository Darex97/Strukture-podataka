#include"Stack.h"
#include<iostream>
using namespace std;

void main()
{
	try
	{
		Stack stek(30);
		char* izraz=new char[20];
		cout<<"Unesi mat izraz"<<endl;
		cin>>izraz;
		int duzina=strlen(izraz);
		int i=0;
		while (i<duzina && izraz[i]!=' ')
		{
			if(izraz[i]>='0' && izraz[i]<='9')
			{
				izraz[i]=izraz[i]-'0';
				izraz[i]=izraz[i]*10;
				stek.push(izraz[i]);
			}
			else
				switch(izraz[i])
				{
					case '+':
						{
							int zbir=0;
							zbir+=stek.pop();
							zbir+=stek.pop();
							stek.push(zbir);
							break;
						}
					case '-':
						{
							int drugi=stek.pop();
							int prvi=stek.pop();
							stek.push(prvi-drugi);
							break;
						}
					case '*':
						{
							int pom=1;
							pom*=stek.pop();
							pom*=stek.pop();
							stek.push(pom);
							break;
						}
					case '/':
						{
							int donji=stek.pop();
							int gornji=stek.pop();
							stek.push(gornji/donji);
							break;
						}
					case '^':
						{
							double exp=stek.pop();
							double base=stek.pop();
							base=pow(base,exp);
							stek.push(base);
						}
				}
			i++;
		}
		cout<<"Rez:"<<stek.pop()<<endl;
	}
	catch(char* message)
	{
		cout<<message<<endl;
	}
}