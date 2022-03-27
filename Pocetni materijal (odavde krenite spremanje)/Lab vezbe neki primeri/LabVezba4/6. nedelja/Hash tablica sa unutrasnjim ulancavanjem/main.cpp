#include "HashTable.h"
#include <iostream.h>

void main()
{
	Exception g;
	HashTable tab(67);
	try
	{
		

		tab.Insert(HashObject("asm","asm"));
		tab.Insert(HashObject("auto","auto"));
		tab.Insert(HashObject("bool","bool"));
		tab.Insert(HashObject("break","break"));
		tab.Insert(HashObject("case","case"));
		tab.Insert(HashObject("catch","catch"));
		tab.Insert(HashObject("char","char"));
		tab.Insert(HashObject("class","class"));
		tab.Insert(HashObject("const","const"));
		tab.Insert(HashObject("const_cast","const_cast"));//10
		tab.Insert(HashObject("continue","continue"));
		tab.Insert(HashObject("default","default"));
		tab.Insert(HashObject("delete","delete"));
		tab.Insert(HashObject("do","do"));
		tab.Insert(HashObject("double","double"));
		tab.Insert(HashObject("dynamic_cast","dinamic_cast"));
		tab.Insert(HashObject("else","else"));
		tab.Insert(HashObject("enum","enum"));
		tab.Insert(HashObject("explicit","explicit"));
		tab.Insert(HashObject("export","export"));//20
		tab.Insert(HashObject("extern","extern"));
		tab.Insert(HashObject("false","false"));
		tab.Insert(HashObject("float","float"));
		tab.Insert(HashObject("for","for"));
		tab.Insert(HashObject("friend","friend"));
		tab.Insert(HashObject("goto","goto"));
		tab.Insert(HashObject("if","if"));
		tab.Insert(HashObject("inline","inline"));
		tab.Insert(HashObject("int","int"));
		tab.Insert(HashObject("long","long"));//30
		tab.Insert(HashObject("mutable","mutable"));
		tab.Insert(HashObject("namespace","namespace"));
		tab.Insert(HashObject("new","new"));
		tab.Insert(HashObject("operator","operator"));
		tab.Insert(HashObject("or","or"));
		tab.Insert(HashObject("private","private"));
		tab.Insert(HashObject("protected","protected"));
		tab.Insert(HashObject("public","public"));
		tab.Insert(HashObject("register","register"));
		tab.Insert(HashObject("reinterpret_cast","reinterpret_cast"));//40
		tab.Insert(HashObject("return","return"));
		tab.Insert(HashObject("short","short"));
		tab.Insert(HashObject("signed","signed"));
		tab.Insert(HashObject("sizeof","sizeof"));
		tab.Insert(HashObject("static","static"));
		tab.Insert(HashObject("static_cast","static_cast"));
		tab.Insert(HashObject("struct","struct"));
		tab.Insert(HashObject("switsh","switch"));
		tab.Insert(HashObject("template","template"));
		tab.Insert(HashObject("this","this"));//50
		tab.Insert(HashObject("throw","throw"));
		tab.Insert(HashObject("true","true"));
		tab.Insert(HashObject("try","try"));
		tab.Insert(HashObject("typedef","typedef"));
		tab.Insert(HashObject("typeid","typeid"));
		tab.Insert(HashObject("typename","typename"));
		tab.Insert(HashObject("union","union"));
		tab.Insert(HashObject("unsigned","unsigned"));
		tab.Insert(HashObject("using","using"));
		tab.Insert(HashObject("virtual","virtual"));//60
		tab.Insert(HashObject("void","void"));
		tab.Insert(HashObject("volatile","volatile"));
		tab.Insert(HashObject("wchar_t","wchar_t"));
		tab.Insert(HashObject("while","while"));
		
		tab.Display();
		cout<<endl;
		cout<<endl;


		tab.Withdraw("char");

		tab.Display();

		HashObject obj=tab.Find("wchar_t");
		obj.Print();
		cout<<endl;
		cout<<endl;
	}
	catch (Exception::Error f)
	{
		cout<<"******** "<<g.messages[f]<<" **********"<<endl;
	}
	
}