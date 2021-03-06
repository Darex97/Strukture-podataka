#include <iostream.h>
#include "hainedHashTable.h"

int main(){
	ChainedHashTable<char*,int> tab(5);
	HashObject<char*,int> p1("Aleksandar Vukasinovic",7350771);
	try{
		tab.insert(p1);
		p1 = HashObject<char*,int> "Danilo Vulovic",7267257);
		tab.insert(p1);
		p1 = HashObject<char*,int> ("Bane Velikic",5551234);
		tab.insert(p1);
		tab.display();
		cout<<endl;
		p1 = HashObject<char*,int> ("Strahinja Zivkovic",8982559);
		tab.insert(p1);
		tab.display();
		tab.withdraw("Aleksandar Vukasinovic");
		cout<<endl;
		cout<<"Lista posle brisanja"<<endl;
		tab.display();
		cout<<endl;
	}
	catch (char* s){ cout<<s<<endl;}

	return 0;
}