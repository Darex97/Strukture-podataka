class Exception
{
public:
	Exception();
	~Exception();

	enum Error
	{
		FULL,	
		POOR,
		NOT,
		EM Y,
	};

	char* messages[4];
};