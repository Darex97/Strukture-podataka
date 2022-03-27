
class CStaticSortDList
{ 
public:
	int *prev;
	int *next;
	int *value;
	int lrmp,head;
	int dim;
public:
	CStaticSortDList(int maxNo)
	{
		dim=maxNo;
		prev=new int[dim];
		next=new int[dim];
		value=new int[dim];
		lrmp=0;
		head=-1;
		for(int i=0;i<dim;i++)
		{
			prev[i]=i-1;
			value[i]=9999;
			if(i==dim-1)
			{
				next[i]=-1;
			}
			else
			{
				next[i]=i+1;
			}
		}
	}

   void AddToHead(int );
   void Sort(bool rastuci);
   void printList();
};