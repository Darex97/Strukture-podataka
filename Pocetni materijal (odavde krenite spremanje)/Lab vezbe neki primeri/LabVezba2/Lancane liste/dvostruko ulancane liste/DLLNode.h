class DLLNode
{
public:
	int info;
	DLLNode *prev,*next;

	DLLNode();
	DLLNode(int el);
	~DLLNode();
};