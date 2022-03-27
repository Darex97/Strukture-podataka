#pragma once

#include <string.h>

class DSException
{
private:
	char* message;

public:
	DSException(const char* message)
	{
		this->message = new char[strlen(message) + 1];
		strcpy_s(this->message, strlen(message) + 1, message);
	}

	~DSException()
	{
		if (this->message)
		{
			delete[] this->message;
		}
	}

	char* GetMessage() const { return this->message; }
};