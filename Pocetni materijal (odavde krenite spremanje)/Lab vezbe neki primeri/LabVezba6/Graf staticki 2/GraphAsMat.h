

#if !defined GRAPHASMAT
#define GRAPHASMAT

#include<iostream.h>
#include"Izuzetak.h"
#include"Node.h"

template<class T>

class GraphAsMat
{
	Node<T>* node;
	int dim;
	int numOfNodes;
	int** mat;
	public:
		GraphAsMat<T>(int n)
		{
			dim=n;
			node=new Node<T>(0,0);
			numOfNodes=0;
			mat=new int*[dim];
			for(int i=0;i<dim;i++)
				mat[i]=new int[dim];
			for(i=0;i<dim;i++)
				for(int j=0;j<dim;j++)
					mat[i][j]=-1;
		}
		bool isEmpty()
		{
			return numOfNodes==0;
		}
		int findNode(T el)
		{
			if(isEmpty())
				throw Izuzetak("Graf nema cvorova!");
			for(int i=0;i<numOfNodes;i++)
				if (node[i].visit()==el) return i;
				throw Izuzetak("Elemenat nije pronadjen!");
		}

		void insertNode(T el)
		{
			node[numOfNodes].info=el;
			numOfNodes++;
		}

		void deleteNode(T el)
		{
			int k;
			try
			{
			k=findNode(el);
			for(int i=0;i<numOfNodes;i++)
				for(int j=k;j<numOfNodes-1;j++)
					mat[i][j]=mat[i][j+1];
			for(j=0;j<numOfNodes;j++)
				for(i=k;i<numOfNodes-1;i++)
					mat[i][j]=mat[i+1][j];
			for(i=0;i<numOfNodes;i++)
			{
				mat[i][numOfNodes-1]=-1;
				mat[numOfNodes-1][i]=-1;
			}
				
			numOfNodes--;
			}
			catch(Izuzetak d)
			{
				d.prikazi();
			}
		}

		int findEdge(T el1, T el2)
		{
			int i,j;
			try
			{
				i=findNode(el1);
				j=findNode(el2);
				return mat[i][j];
			}
			catch(Izuzetak d)
			{
				d.prikazi();
			}
		}

		void insertEdge(T el1, T el2)
		{
			int i,j;
			try
			{
				i=findNode(el1);
				j=findNode(el2);
				mat[i][j]=j;
			}
			catch(Izuzetak d)
			{
				d.prikazi();
			}
		}


		void deleteEdge(T el1, T el2)
		{
			
			int i,j;
			try
			{
				i=findNode(el1);
				j=findNode(el2);
				mat[i][j]=-1;
			}
			catch(Izuzetak d)
			{
				d.prikazi();
			}
		}

		void printMat()
		{
			cout<<endl<<"Potezi izmedju cvorova:"<<endl;
			for(int i=0;i<numOfNodes;i++)
			{
				for(int j=0;j<numOfNodes;j++)
					cout<<"\t"<<mat[i][j];
				cout<<endl;
			}
		}
		
		void printNode()
		{
			cout<<"Cvorovi koji imaju ulazni stepen NULA :"<<endl;
			for(int j=0;j<numOfNodes;j++)
			{
				for(int i=0;i<numOfNodes;i++)
					if(mat[i][j]==j) break;
				if (i==numOfNodes) cout<<"\t"<<node[j].visit();//ako u koloni matrice nema elemenata koji su jednaki indeksu cvora
			}
			cout<<endl<<endl;
		}
		
};

#endif
		


			

				

