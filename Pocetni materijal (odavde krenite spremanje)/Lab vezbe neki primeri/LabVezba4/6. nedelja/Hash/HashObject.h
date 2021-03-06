class HashObject
{
private:
	char *key;
	long record;
public:
	HashObject();
	
	HashObject(cha * k);
	
	HashObject(char* k, long object);
	
	HashObject& operator=(HashObject& obj);
	
	bool operator==(HashObject& obj);
	
	void DeleteRecord()
	{ 
		if(record)
			record = NULL;
	}

	char* GetKey()
	{
		return key;
	}

	long GetRecord()
	{ 
		return record;
	}

	bool IsEqualKey(char* k)
	{ 
		return key == k;
	}

	void Print();
};