//vezba I 7

#include<iostream.h>

class Polje
{
protected:
  int*p;
  int n;
 
  public:
    Polje(int k);
   ~Polje();
   void unesi();
   void stampaj();
   void sortiraj();
   void podeli(Polje *p1,Polje *p2, int k);
};

Polje::Polje (int k)
	{
	  p=new int[k];
	  n=k;
	}
	
	Polje::~Polje()
	{
	  delete[]p;
	  n=0;
	}

	void Polje::unesi()
	{
	  cout<<"Unesi elemente polja"<<endl;
	    for(int i=0;i<n;i++)
		  cin>>p[i];
    }

	void Polje::stampaj()
	{
	  cout<<"Polje je"<<endl;
	  if(n==0)
	    cout<<"przno"<<endl;
      else
	  for(int i=0;i<n;i++)
	    cout<<p[i]<<" ";
	}

	void Polje::sortiraj()
	{
	  int i,j;
	  int pom;
	  for( i=0;i<n-1;i++)
	  {
	    for(j=n-1;j>i;--j)
		if(p[j]>p[j+1])
		{
		  pom=p[j];
		  p[j]=p[j+1];
		  p[j+1]=pom;
		}
	  }
    }

	void Polje::podeli(Polje *p1,Polje *p2,int k)
	{ 
	  for(int i=0;i<n;i++)
	  {
	    if(p[i]>k)
		{
		  p1->p[p1->n]=p[i];
		  p1->n++;
		}
	    else
		{
		  p2->p[p2->n]=p[i];
		  p2->n++;
		}
	  }
	}

	void main()
	{
	  int n,k;
	  cout<<"Unesi broj elemenata polja"<<endl;
	  cin>>n;
	  Polje p1(n);
      Polje p2(n);
	  Polje niz(n);
	  	  
	  niz.unesi();
	//  Polje p1= new Polje(n);
	 // Polje p2= new Polje(n);
//	  p1.n = 0;
//	  p2.n=0;
	  cout<<"Unesi broj k"<<endl;
	  cin>>k;
	  niz.podeli(&p1,&p2,k);
	  cout<<"Polje p1:"<<endl;
	  p1.stampaj();
	  cout<<"Polje p2:"<<endl;
	  p1.stampaj();
	}


