#pragma once
class String2
{
	char* str;

public:
	String2();

	String2(const char* buffer);

	void setString(const char* buffer);

	String2(const String2& source);

	void operator = (const char*);

	void append(const String2& toAdd);

	char* c_str() const;

	int length() const;

	void strcpy(char* destination, const char* source, int length);

	~String2();
};

