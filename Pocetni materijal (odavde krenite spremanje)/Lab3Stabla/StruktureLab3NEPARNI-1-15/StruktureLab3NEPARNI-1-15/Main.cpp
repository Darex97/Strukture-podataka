#include"DinamicBSTree.h"
void main()
{
	DinamicBSTree d;
	d.insert(3);
	d.insert(1);
	d.insert(2);
	d.insert(6);
	d.insert(5);
	d.insert(9);
	d.insert(10);
	
	cout << "Inorder stabla:" << endl;
	d.visit();
	cout << "Visina stabla je: " << d.height() << endl;
	cout << "Moment stabla je: " << d.momentOfTree() << endl;
	cout << "Tezina stabla je: " << d.tezina() << endl;
	cout << "Leva suma - desna suma: " << (d.findMaximal())->key << endl;
	cout << "Nivo sa najvise cvorova: " << d.najviseCvorova() << endl;
	d.getDeepest();
	cout<<"2015 popravni: "<<d.CountGreater(1)<<endl;
	cout << "Izbrisano je " << d.deleteRightLeaves() << " desnih listova." << endl;
	d.visit();
	d.brisanjeListova();
	cout << "Inorder nakon brisanja listova: " << endl;
	d.visit();
	d.mirror();
	cout << "Inorder nakon mirror kopije." << endl;
	d.visit();

	DinamicBSTree prvi;
	DinamicBSTree *drugi = new DinamicBSTree();
	prvi.insert(2);
	prvi.insert(1);
	prvi.insert(9);
	prvi.insert(6);
	prvi.insert(4);
	prvi.insert(8);

	drugi->insert(4);
	drugi->insert(5);
	drugi->insert(1);
	drugi->insert(2);
	drugi->insert(12);

	cout << "Inorder prvog stabla: " << endl;
	prvi.visit();

	cout << "Inorder drugog stabla: " << endl;
	drugi->visit();

	prvi.spajamStabla(*drugi);
	delete drugi;
	cout << "Inorder spojenih stabala: " << endl;
	prvi.visit();
	system("pause");
}