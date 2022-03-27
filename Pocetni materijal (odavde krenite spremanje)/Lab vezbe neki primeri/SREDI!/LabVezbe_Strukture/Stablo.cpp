#include <iostream.h>
#include <math.h>

struct elem
{
	int info, level;
	elem *left, *right;
};

class Binary_Tree
{
	elem *root;
	void del(elem *root);
	int findheight(elem *root);
	void print(elem* root);
public:
	Binary_Tree() { root = 0; }
	~Binary_Tree() { if (root != 0) del(root); }
	void add(int vr);
	void unos();
	int height();
	void stampa();
	void showstablo();
};

void Binary_Tree :: del(elem* root)
{
	if (root -> left != 0)
		del(root -> left);
	if (root -> right != 0)
		del(root -> right);
	delete root;
}

int Binary_Tree :: findheight(elem *root)
{
	int res = -1, pom;
	if (root -> left != 0)
	{
		root -> left -> level = root -> level + 1;
		res = findheight(root -> left);
	}
	if (root -> right != 0)
	{
		root -> right -> level = root -> level + 1;
		pom = findheight(root -> right);
		if (pom > res)
			res = pom;
	}
	res++;
	return res;
}

void Binary_Tree :: print(elem* root)
{
	cout << " " << root -> info << ",";
	cout << "{";
	if (root -> left != 0)
		print(root -> left);
	cout << "},";
	cout << "{";
	if (root -> right != 0)
		print(root -> right);
	cout << "} ";
}

void Binary_Tree :: add(int vr)
{
	elem *pom = new elem;
	pom -> info = vr;
	pom -> left = 0;
	pom -> right = 0;
	if (root == 0)
		root = pom;
	else
	{
		elem *pok = root;
		int ins = 0;
		while (!(ins))
			if (pok -> info < vr)
			{
				if (pok -> right == 0)
				{
					pok -> right = pom;
					ins = 1;
				}
				else
					pok = pok -> right;
			}
			else
			{
				if (pok -> left == 0)
				{
					pok -> left = pom;
					ins = 1;
				}
				else
					pok = pok -> left;
			}
	}
}

void Binary_Tree :: unos()
{
	int n, i, vr;
	cout << "Koliko elemenata zelite uneti: ";
	cin >> n;
	if (n > 0)
	{
		cout << "Unesite elemente: ";
		for (i = 0; i < n; i++)
		{
			cin >> vr;
			add(vr);
		}
	}
}

int Binary_Tree :: height()
{
	if (root == 0)
		return -1;
	else
	{
		root -> level = 0;
		return findheight(root);
	}
}

void Binary_Tree :: stampa()
{
	cout << "{";
	if (root != 0)
		print(root);
	cout << "}" << endl;
}

void Binary_Tree :: showstablo()
{
	struct prim
	{
		elem* pok;
		int pol;
		prim* next;
	} *left, *right, *first;
	int h = findheight(root);
	int min = 0, step = -1, hm, i, curpol = 0;
	elem* cur;
	if (h > -1)
	{
		first = new prim;
		left = right = first;
		first -> pok = root;
		first -> pol = 0;
		first -> next = 0;
		while (left != 0)
		{
			cur = left -> pok;
			if (left -> pol < min)
				min = left -> pol;
			if (cur -> left != 0)
			{
				right -> next = new prim;
				right = right -> next;
				right -> pok = cur -> left;
				right -> pol = left -> pol - pow(2, h - cur -> level);
				right -> next = 0;
			}
			if (cur -> right != 0)
			{
				right -> next = new prim;
				right = right -> next;
				right -> pok = cur -> right;
				right -> pol = left -> pol + pow(2, h - cur -> level);
				right -> next = 0;
			}
			left = left -> next;
		}
		while (first != 0)
		{
			cur = first -> pok;
			if (step != -1)
				if (cur -> level != step)
				{
					cout << endl;
					curpol = 0;
				}
			step = cur -> level;
			hm = first -> pol - min;
			for (i = 0; i < hm - curpol; i++)
				cout << " ";
			cout << cur -> info;
			if (cur -> info < 10)
				cout << " ";
			curpol = hm + 2;
			left = first;
			first = first -> next;
			delete left;
		}
		cout << endl;
	}
	else
		cout << "Stablo is empty\n";
}

void main()
{
	Binary_Tree bt;
	bt.unos();
	cout << "Visina stabla je " << bt.height() << endl;
	bt.stampa();
	bt.showstablo();
}


