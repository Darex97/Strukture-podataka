template <class T>
class BSTNode
{
	T key;
	BSTNode<T> *left, *right;
	BSTNode() { left = right = NULL;};
	BSTNode(int el) { key = el; left = right = NULL;};
	BSTNode(int el, BSTNode<T>* It, BSTNode<T> * rt) {
	key = el; left t= It; right = rt;
}
bool isLT(T el){
	if(key < el) return true;
	else return false;
};
bool isGT(T el){
	if(key > el) return true;
	else return false;
};
bool isEQ(T el){
	if(key == el) return true;
	else return false;
};
void setKey(T el){ key = el; };

T getKey() { return key; };

void visit() { cout << key << " ";};

};