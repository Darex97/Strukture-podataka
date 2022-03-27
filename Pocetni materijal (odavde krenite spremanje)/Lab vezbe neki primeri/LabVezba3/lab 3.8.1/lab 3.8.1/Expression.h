#include "Stack.h"
#include <iostream>
#include <cstring>


using namespace std;

class Expression
{
	char izraz[100];

public:
	
	Expression()
	{
		cout<<"Unesite izraz:"<<endl;
		gets(izraz);
	}

	~Expression()
	{

	}

	double toNumber(char* x)		//pretvara string u broj
	{
		int e=1;			//10^e
		double r=0;			//rezultat
		int p='9'-'0';		//prvi broj u ASCII tabeli
		for (int i = strlen(x)-1; i >=0; i--)
			r+=(x[i]%p)*pow(10,e++);
		return r;
	}

	double postfixCount( Stack<double> &c)	//izracunava vrednost izraza datog u postfix notaciji
	{
		int i=0;
		char* pom;
		pom = new char('\0');
		int h=0;
		while(izraz[i]!='\0')
		{
			if(izraz[i]!='+'||izraz[i]!='-'||izraz[i]!='*'||izraz[i]!='/'||izraz[i]!='^')	//proverava da li smo dosli do znaka operacije
			{
				int j=i;
				while(izraz[j]!=' ')					//trazi string koji predstavlja operand
					pom[h++]=izraz[j++];
				double r=toNumber(pom);					// i pretvara ga u broj
				push_e_double(r,c);								// i salje ga na stek
				i=++j;
			}
			double r=operation(izraz[i],c);					//obavlja operaciju na koju ukazuje tekuci karakter
			push_e_double(r,c);									//vraca rez na stek
			i++;
		}
		return pop_e(c);									//kraj izraza, vraca sa steka rezultat i salje kao povratnu vrednost f-je
	}

	double operation(char c, Stack<double> &s)							//obavlja operaciju na koju ukazuje karakter c
	{
		double x=pop_e(s), y=pop_e(s);						//vraca operande sa steka
		switch(c)										//izvrsava odredjenu operaciju u zavisnosti od c i vraca rezultat
		{
		case '+':
			return x+y;
		case '-':
			return x-y;
		case '*':
			return x*y;
		case '/':
			return x/y;
		case '^':
			return pow(x,y);
		default:
			break;
		}
	}

	double pop_e(Stack<double> &s)
	{
		return s.pop();
	}

	char pop_e_char(Stack<char> &s)
	{
		return s.pop();
	}

	const char getTop_e_char(Stack<char> &s)
	{
		return s.getTop();
	}

	void push_e_double(double x, Stack<double> &s)
	{
		s.push(x);
	}

	void push_e_char(char x, Stack<char> &s)
	{
		s.push(x);
	}

	char* infix2Postfix()								//definitivno najgora f=ja, zato nisam uzeo u obir "{}","[]", vec samo "()"
	{													//i mozda moze da se optimizuje
		Stack<char> s(20);
		char *novi_izraz;
		novi_izraz = new char[30];
		int i=0;
		while(izraz[i]!='\0')
		{
			if(izraz[i]=='(')
			{
				push_e_char(izraz[i],s);
				i++;
			}
			else if(izraz[i]=='+'||izraz[i]=='-'||izraz[i]=='*'||izraz[i]=='/'||izraz[i]=='^')		//ukoliko se naidje na operator mora se voditi racuna o prioritetu operatora
			{
				if(s.top!=-1)
				{
					if(izraz[i]=='*'||izraz[i]=='/'||izraz[i]=='^')					//ukoliko je tekuci operator nizeg prioriteta na izlazni izraz se dodaje onaj sa steka,
						if(getTop_e_char(s)=='+'||getTop_e_char(s)=='-')			//a tekuci se dodaje na stek;
						{											//ali ako je tekuci operator viseg prioriteta, onda se on dodaje na izlazni izraz.
							strcat(novi_izraz," ");
							int h=0;
							while(novi_izraz[h]!='\0')
								h++;
							novi_izraz[h]=izraz[i];
							i++;
						}
						else
						{
							strcat(novi_izraz," ");
							int h=0;
							while(novi_izraz[h]!='\0')
								h++;
							novi_izraz[h]=pop_e_char(s);
							push_e_char(izraz[i],s);
							i++;
						}
					else
					{
						if(getTop_e_char(s)=='*'||getTop_e_char(s)=='/'||getTop_e_char(s)=='^')
						{
							strcat(novi_izraz," ");
							push_e_char(izraz[i],s);
							i++;
						}
						else
						{
							strcat(novi_izraz," ");
							int h=0;
							while(novi_izraz[h]!='\0')
								h++;
							novi_izraz[h]=pop_e_char(s);
							push_e_char(izraz[i],s);
							i++;
						}
					}
				}
				i++;
			}
			else if(izraz[i]==')')							//ukoliko se naleti na ")" skida se sa steka sve do "(" zajedno sa njom, stim sto se u 
			{												//izlazni izraz ne dodaju zagrade
				while(getTop_e_char(s)!='(')
				{
					strcat(novi_izraz," ");
					int h=0;
					while(novi_izraz[h]!='\0')
						h++;
					novi_izraz[h]=pop_e_char(s);
				}
				strcat(novi_izraz," ");
				pop_e_char(s);
			}
			else if(izraz[i]==' ')
			{
				i++;
			}
			else								//ako se naidje na operand
			{
				cout<<izraz[i];
				int h=0;
					while(novi_izraz[h]!='\0')
						h++;
					novi_izraz[h]=izraz[i];
				i++;
			}
		}
		i=0;
		while(novi_izraz[i]!='\0')
			cout<<novi_izraz[i++];
		cout<<endl;
		return novi_izraz;
	}

	
};
