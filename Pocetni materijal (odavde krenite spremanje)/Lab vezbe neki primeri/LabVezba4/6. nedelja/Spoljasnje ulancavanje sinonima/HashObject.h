class HashObject
{
protected:
	char *key;
	char *name;
	char *number;

public:
	HashObject(); HashObject(char* na, char* nu);
	~HashObject();

	HashObject operator=(HashObject obj);

	char* GetKey();

	void Print();
};