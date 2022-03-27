class SBPException
{
protected:
	char* m_msg;
public:
	SBPException(char *msg)
	{
		m_msg = msg;
	}
	~SBPException() {}
	char* getError() { return m_msg; }
};