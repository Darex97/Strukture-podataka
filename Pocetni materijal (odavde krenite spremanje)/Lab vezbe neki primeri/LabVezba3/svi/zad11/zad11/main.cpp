#include "Stek.h"
#include <string>
using namespace std;
char* infix2postfix(char* s)
{
	Stek a(30);
	Stek b(30);
	for(int i=0;i<strlen(s);i++)
		{
			if(s[i]>='0' && s[i]<='9')
				b.push(s[i]);
			else
			{
			switch(s[i])
			{
			case '(':
				{
					a.push(s[i]);
					break;
				}
			case ')':
				{
					char c;
					if(a.IsEmpty())
						throw "Nisu zatvorene sve zagrade";
					while(!a.IsEmpty() && a.gettop()!='(' )
					{
						c=a.pop();
						b.push(c);
					}

					if(a.gettop()=='(')
						a.pop();
					break;
				}
				case '+':
					{
						char t=a.gettop();
						
						switch(t)
						{
							case '+':
							case '-':
							case'*':
							case '/':
							case '^':
								{
									b.push(a.pop());
									a.push(s[i]);
									break;
								 }
							default:
								{
									a.push(s[i]);
								}
						}
						break;
					}
					case '-':
					{
						char t=a.gettop();
						
						switch(t)
						{
							case '+':
							case '-':
							case'*':
							case '/':
							case '^':
								{
									b.push(a.pop());
									a.push(s[i]);
									break;
								 }
								default:
								{									
									a.push(s[i]);
								}
						}
						break;
					}
					case '*':
					{
						char t=a.gettop();
						
						switch(t)
						{
							case'*':
							case '/':
							case '^':
								{
									b.push(a.pop());
									a.push(s[i]);
									break;
								 }
							case '+':
							case '-':
								{
									a.push(s[i]);
									break;
								}
						}
						break;
					}
			case '/':
					{
						if(a.IsEmpty())
							a.push(s[i]);
						else
						{
						char t=a.gettop();
						
						switch(t)
						{
							case'*':
							case '/':
							case '^':
								{
									b.push(a.pop());
									a.push(s[i]);
									break;
								 }
							case '+':
							case '-':
								{
									a.push(s[i]);
									break;
								}
						}
						}
						break;
					}
			case '^':
				{
					a.push(s[i]);
					break;
				}
			}
		}
		}
		while(!a.IsEmpty())
			b.push(a.pop());
		b.reverseastack();//ovo je jedina razlika u odnosu na 12-ti zad :-)
		char* z=new char[20];
		int i=0;
		while(!b.IsEmpty())
		{
			z[i]=b.pop();
			i++;
		}
		z[i]='\0';
		return z;
}
void main()
{
	try
	{
		char *s=new char[30];
		char *p=new char[30];
		cout<<"Unesi matematicki izraz (u infix notaciji):"<<endl;
		cin>>s;
		strcpy(p,infix2postfix(s));
		cout<<p<<endl;
		delete [] s;
		delete [] p;
	}
	catch(char *a)
	{
		cout<<a<<endl;
	}
}