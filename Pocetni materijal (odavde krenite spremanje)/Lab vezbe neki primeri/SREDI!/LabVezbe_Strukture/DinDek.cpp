//vezba III 7

#include <iostream.h>
#include <string.h>

template <class T>
class DDek {

    protected:
	
	struct element {
      T info;    
	  struct element *llink,*dlink; 	
    };
    element *prvi,*zadnji;
    
	int max,br;

	public:
    
	         DDek(int max1);
	         DDek();  
		    ~DDek();
	         Ubaci(T& x,int strana);
			 Ispisi();
   	    bool PrazanJe();
	            
	
};

template <class T>
bool DDek<T>::PrazanJe() {
if (br==0) return true; 
           else
           return false;

}

template <class T>
DDek<T>::DDek(int max1) {
	max=max1;
	br=0;
	prvi=NULL;
    zadnji=NULL; 
}

template <class T>
DDek<T>::Ubaci(T& x,int strana) {
    
	element *novi;
    	
	novi=new element;
	novi->info=x;
    	
	if (prvi==NULL) {	
	    novi->llink=NULL;
	    novi->dlink=NULL;
		prvi=novi;
        zadnji=novi;	
	} 
	else 
	{
        // 2 za desno 1 za levo
		if (strana==2) {
		
		novi->dlink=NULL;
		novi->llink=zadnji;
		zadnji->dlink=novi;
		zadnji=novi;  } 
		
		else {
        
		novi->llink=NULL;
		novi->dlink=prvi;
		prvi->llink=novi;
		prvi=novi;
		
		}
			

	}	
	br++;	
}

/*template <class T>
DDek<T>::Izbaci() {
    element *pom;
    if (!PrazanJe()) {
		if (zadnji->info>prvi->info) {
	        pom=zadnji; 
			zadnji=zadnji->llink; 
            if (zadnji==NULL) prvi=NULL;
			delete pom;
		}
		
		
	}
	
}*/

template <class T>
DDek<T>::~DDek() {
  element *sledeci,*tekuci;    
  tekuci=prvi;
  
  while(tekuci!=NULL) {
     sledeci=tekuci->dlink;
     delete tekuci;
     tekuci=sledeci;  
     if (tekuci!=NULL) { 
	     sledeci=tekuci->dlink;  
	 
	 } 
  }	  
  prvi=NULL;
  zadnji=NULL;
  br=0; 

}
template <class T>
DDek<T>::Ispisi() {
    T pom;
	element *tekuci;
	
    cout<<"S leva na desno Dek= ";
	if (!PrazanJe()) {
	   tekuci=prvi;
	   while (tekuci!=NULL) {
          pom=tekuci->info; 
	      cout<<pom<<" "; 
          tekuci=tekuci->dlink; 	
	   }
	   
	} else 
    cout<<"Dek je prazan";
}

class Text {

       private:
          
		  char* rec;
       
	   public:
          
		  Text();
		  Text(char* s);
		  //~Text() { delete rec;};
		  ~Text () {   };
		  friend istream& operator>>(istream& in ,Text& t);
          friend ostream& operator<<(ostream& out,Text& t);
          friend bool operator==(Text& t1,Text& t2); 
          friend bool operator>(Text& t1,Text& t2); 
		  //Text& operator=(Text& t1);  
};

Text::Text() {
    rec=new char[2];
}

Text::Text(char* s) {
    rec=new char[strlen(s)];
    strcpy(rec,s);
}

istream& operator>>(istream& in ,Text& t) { 
	return in>>t.rec;
}
          
ostream& operator<<(ostream& out,Text& t) { 
	return out<<t.rec;
}

bool operator==(Text& t1,Text& t2) { 
	if (strcmp(t1.rec,t2.rec)==0) return true; else
		                          return false;
} 

bool operator>(Text& t1,Text& t2) { 
	
	if (strcmp(t1.rec,t2.rec)==1) return true; else
		                          return false;
}
/*
Text& Text::operator=(Text& t1) { 
Text t("x");
strcpy(t.rec,t1.rec);

return t;
}*/

void main() {

int izbor, str;
DDek<Text> dek(10);
Text t1;
char* pom=new char[2];

while (izbor!=3) {

cout<<"OPERACIJE ZA RAD SA DEKOM  \n";
cout<<"---------------------------\n";
cout<<"1-UBACI NOVI ELEMENT U DEK \n";
cout<<"2-ISPISI SADRZAJ DEKA      \n";
cout<<"3-KRAJ                     \n";
cout<<"---------------------------\n";
cout<<"VAS IZBOR JE:\n";

cin>>izbor;
    switch(izbor) {
	case 1:
        cout<<"\n";
		cout<<"Unesi sa koje strane uacujes podatak(1 s'leva, 2 s'desna )";
		cin>>str;
		cout<<"UNESI PODATAK KOJI SE UBACUJE :";cin>>pom;
		dek.Ubaci(Text(pom),str);
		cout<<"\n";
		break; 

  
	
	case 2: 
        cout<<"\n";
		cout<<"SADRZAJ STEKA :\n";
		dek.Ispisi();
		cout<<"\n\n";
		break;
	
	}

}

}

