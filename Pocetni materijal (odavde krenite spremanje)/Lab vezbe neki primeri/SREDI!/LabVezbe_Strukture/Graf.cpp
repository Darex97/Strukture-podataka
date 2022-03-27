#include <fstream.h>

struct elem
{
	int id;
	elem *next;
};

class Graph
{
	int n;
	elem* sus[100];
	int ind[100], outd[100];
	void addEdge(int a, int b);
public:
	Graph(int v);
	~Graph();
	Graph& input();
	int ponors();
};

Graph :: Graph(int v)
{
	n = v;
	for (int i = 0; i < n; i++)
	{
		sus[i] = 0;
		ind[i] = 0;
		outd[i] = 0;
	}
}

Graph :: ~Graph()
{
	int i;
	elem* pom;
	for (i = 0; i < n; i++)
		while (sus[i] != 0)
		{
			pom = sus[i];
			sus[i] = sus[i] -> next;
			delete pom;
		}
}

void Graph :: addEdge(int a, int b)
{
	elem* pom;
	pom = new elem;
	pom -> id = b;
	pom -> next = sus[a];
	sus[a] = pom;
	outd[a]++;
	ind[b]++;
}

Graph& Graph :: input()
{
	int n, m, i, a, b;
	ifstream f("input.txt", ios::in);
	f >> n >> m;
	Graph &G(n);
	for (i = 0; i < m; i++)
	{
		f >> a >> b;
		G.addEdge(a, b);
	}
	f.close();
	return G;
}

int Graph :: ponors()
{
	int i, brp = 0;
	cout << "Ponori su:";
	for (i = 0; i < n; i++)
	if ((outd[i] == 0) && (ind[i] > 0))
	{
		brp++;
		cout << " " << i;
	}
	cout << endl << "Broj ponora: " << brp << endl;
	return brp;
}

void main()
{
	Graph G = G.input();
	G.ponors();
}
