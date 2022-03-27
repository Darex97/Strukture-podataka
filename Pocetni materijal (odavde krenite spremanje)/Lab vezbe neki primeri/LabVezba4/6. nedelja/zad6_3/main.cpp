#include "Table.h"
#include <iostream.h>

void main()
{
	Table tab(67);
		
		tab.Insert(Object("asm","ams"));
		tab.Insert(Object("auto","auto"));
		tab.Insert(Object("bool","bool"));
		tab.Insert(Object("break","break"));
		tab.Insert(Object("case","case"));
		tab.Insert(Object("catch","catch"));
		tab.Insert(Object("char","char"));
		tab.Insert(Object("class","class"));
		tab.Insert(Object("const","const"));
		tab.Insert(Object("const_cast","const_cast"));//10
		tab.Insert(Object("continue","continue"));
		tab.Insert(Object("default","default"));
		tab.Insert(Object("delete","delete"));
		tab.Insert(Object("do","do"));
		tab.Insert(Object("double","double"));
		tab.Insert(Object("dynamic_cast","dinamic_cast"));
		tab.Insert(Object("else","else"));
		tab.Insert(Object("enum","enum"));
		tab.Insert(Object("explicit","explicit"));
		tab.Insert(Object("export","export"));//20
		tab.Insert(Object("extern","extern"));
		tab.Insert(Object("false","false"));
		tab.Insert(Object("float","float"));
		tab.Insert(Object("for","for"));
		tab.Insert(Object("friend","friend"));
		tab.Insert(Object("goto","goto"));
		tab.Insert(Object("if","if"));
		tab.Insert(Object("inline","inline"));
		tab.Insert(Object("int","int"));
		tab.Insert(Object("long","long"));//30
		tab.Insert(Object("mutable","mutable"));
		tab.Insert(Object("namespace","namespace"));
		tab.Insert(Object("new","new"));
		tab.Insert(Object("operator","operator"));
		tab.Insert(Object("or","or"));
		tab.Insert(Object("private","private"));
		tab.Insert(Object("protected","protected"));
		tab.Insert(Object("public","public"));
		tab.Insert(Object("register","register"));
		tab.Insert(Object("reinterpret_cast","reinterpret_cast"));//40
		tab.Insert(Object("return","return"));
		tab.Insert(Object("short","short"));
		tab.Insert(Object("signed","signed"));
		tab.Insert(Object("sizeof","sizeof"));
		tab.Insert(Object("static","static"));
		tab.Insert(Object("static_cast","static_cast"));
		tab.Insert(Object("struct","struct"));
		tab.Insert(Object("switsh","switch"));
		tab.Insert(Object("template","template"));
		tab.Insert(Object("this","this"));//50
		tab.Insert(Object("throw","throw"));
		tab.Insert(Object("true","true"));
		tab.Insert(Object("try","try"));
		tab.Insert(Object("typedef","typedef"));
		tab.Insert(Object("typeid","typeid"));
		tab.Insert(Object("typename","typename"));
		tab.Insert(Object("union","union"));
		tab.Insert(Object("unsigned","unsigned"));
		tab.Insert(Object("using","using"));
		tab.Insert(Object("virtual","virtual"));//60
		tab.Insert(Object("void","void"));
		tab.Insert(Object("volatile","volatile"));
		tab.Insert(Object("wchar_t","wchar_t"));
		tab.Insert(Object("while","while"));
		
		tab.display();
		cout<<endl;
		cout<<"Trazeni element: "<<endl;
		tab.find("asm").print();
		cout<<endl;
		cout<<endl;


		tab.withdraw("operator");

		tab.display();

		Object obj=tab.find("wchar_t");
		obj.print();
		cout<<endl;
		cout<<endl;
	
}