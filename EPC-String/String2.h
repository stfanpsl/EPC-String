#pragma once
class String2
{
	char* str;

public:
	String2();

	String2(const char* buffer);

	void change(const String2* str);

	void setString(const char* buffer);

	String2(const String2& source);

	void operator = (const char*);

	String2 operator=(const String2& rhs);

	void append(const String2& toAdd);

	char* c_str() const;

	int length() const;

	void strcpy(char* destination, const char* source, int length);

	~String2();

	String2(String2&& other);

};

