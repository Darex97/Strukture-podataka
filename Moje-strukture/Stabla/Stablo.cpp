#include "Stablo.h"
#include"Cvor.h"
Stablo::~Stablo()
{
	deleteTre(root);
}
void Stablo::deleteTre(Cvor* t)
{
	if (t != NULL)
	{
		deleteTre(t->left);
		deleteTre(t->right);
		delete t;
	}

}
void Stablo::insert(int el,int dan,int testiran)
{
	Cvor* p = root, * prev = NULL;
	while (p != NULL) {
		prev = p;
		if (p->isLT(el))
			p = p->right;
		else
			p = p->left;
	}
	if (root == NULL)
		root = new Cvor(el,dan,testiran);
	else if (prev->isLT(el))
		prev->right = new Cvor(el,dan,testiran);
	else prev->left = new Cvor(el,dan,testiran);
	brel++;
}
Cvor* Stablo::search(Cvor* p, int el)
{
	while (p != NULL)
		if (p->isEQ(el))
			return p;
		else if (p->isGT(el))
			p = p->left;
		else p = p->right;
	return NULL;
}
void Stablo::preorder(Cvor* p)
{
	if (p != NULL)
	{
		p->visit();
		preorder(p->left);
		preorder(p->right);
	}
}
void Stablo::inorder(Cvor* p)
{
	if (p != NULL)
	{
		inorder(p->left);
		p->visit();
		inorder(p->right);


	}

}
void Stablo::postorder(Cvor* p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		p->visit();


	}
}
void Stablo::balance(int data[], int first, int last)
{
	/*if (first <= last)
	{
		int middle = (first + last) / 2;   // treba se odkomentarise zbog modifikaciju
		insert(data[middle]);
		balance(data, first, middle - 1);
		balance(data, middle + 1, last);



	}*/

}
int Stablo::height()
{
	return height(root);
}
int Stablo::height(Cvor* k)
{
	if (k == NULL)
		return 0;
	if (k->left == NULL && k->right == NULL)
		return 1;
	return 1 + max(height(k->left), height(k->right));
}
int Stablo::max(int a, int b)
{
	if (a > b)
		return a;
	else return b;
}

int Stablo::maxLvl() {
	
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	int v = height();
	int* zasvakiNivo;
	zasvakiNivo = new int[v];
	for (int i = 0; i < v; i++)
		zasvakiNivo[i] = 0;
	maxLvl(root, zasvakiNivo);
		int max = 0;
		for(int i=0;i<v;i++)
		{
			if (zasvakiNivo[max] < zasvakiNivo[i])
				max = i;
		}
		delete[] zasvakiNivo;
		return max;

}
int Stablo::maxLvl(Cvor* p, int* count)
{
	
	if (p != NULL)
	{
		maxLvl(p->left, count);
//			count[dubina(p)]++;  Nisam zavrsio ima jos 2 fje da se odrade 255 linija koda pa do 344
		maxLvl(p->right, count);
	}
	return 0;//obrisi ovo
}
int Stablo::Vratizbir() // JUN2020
{	
	return Vratizbir(root);
}
int Stablo::Vratizbir(Cvor* p)
{
	if (p == NULL)
		return 0;
	if (p->left == NULL && p->right == NULL)
		return 0;
	int k = 0;
	if (p->left == NULL)
		return k = p->right->key;
	if (p->right == NULL)
		return k = p->left->key;
	
	k = p->left->key + p->right->key;
	if (k > Vratizbir(p->left) && k > Vratizbir(p->right))
		return k;
	else if (Vratizbir(p->left) > Vratizbir(p->right))
		return Vratizbir(p->left);
	else return Vratizbir(p->right);
	

		

}
Cvor* Stablo::nadji(int v)//jun2 2020
{
	
	return nadji(root, v);

}
Cvor* Stablo::nadji(Cvor* r, int value)
{
	Cvor* p = r;
	if (p == NULL)
		return r;
	if (p->left == NULL && p->right == NULL)
		return r;
	int k = p->key - value;
	if (k < 0)
		k = k * -1;
	int l, d;
	if (p->right == NULL)
	{
		l = p->left->key - value;
		if (l < 0)
			l = l * -1;
		if (k <= l)
			return p;
		else nadji(p->left, value);
	}
	if (p->left == NULL)
	{
		d = p->right->key - value;
		if (d < 0)
			d = d * -1;
		if (k <= d)
			return p;
		else nadji(p->right, value);
	}
	l = p->left->key - value;
	if (l < 0)
		l = l * -1;
	d = p->right->key - value;
	if (d < 0)
		d = d * -1;
	if(l<=d)
	{
		if (k <= l)
			return p;
		else nadji(p->left, value);
	}
	else
	{
		if (k <= d)
			return p;
		else nadji(p->right, value);
	}
}
Cvor* Stablo::testirani(int day)
{
	return testirani(root, day);
}
Cvor* Stablo::testirani(Cvor* cvor, int day)//decembar 2020
{
	Cvor* p = cvor;
	if (p == NULL)
		return p;
	if (p->left == NULL && p->right == NULL)
		return p;
	int d=day;
	if (p->dana < d)
	{
		if (p->left == NULL)
			return testirani(p->right, day);
		if (p->right == NULL)
			return testirani(p->left, day);
		if (testirani(p->left, day)->testiranih > testirani(p->right, day)->testiranih)
			return testirani(p->left, day);
		else
			return testirani(p->right, day);
	}	
	if (p->right == NULL)
		if (p->testiranih > testirani(p->left, day)->testiranih)
			return p;
		else
			return testirani(p->left, day);
	if (p->left == NULL)
		if (p->testiranih > testirani(p->right, day)->testiranih)
			return p;
		else
			return testirani(p->right, day);
	if (testirani(p->left, day)->testiranih > testirani(p->right, day)->testiranih)
	{
		if (p->testiranih > testirani(p->left, day)->testiranih)
			return p;
		else return testirani(p->left, day);
	}
	else
	{
		if (p->testiranih > testirani(p->right, day)->testiranih)
			return p;
		else return testirani(p->right, day);
	}
}