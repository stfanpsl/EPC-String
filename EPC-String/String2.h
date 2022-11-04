#pragma once
class String2
{
	char* str;

public:

	//////////Sprint 1//////////
	
	String2();

	String2(const char* buffer);

	char* c_str() const;

	int length() const;

	void append(const String2& toAdd);

	~String2();

	//////////Sprint 2//////////

	void operator = (const char*);

	//copy constructor
	String2(const String2& source);
	
	//copy assignment
	String2 operator=(const String2& rhs);

	//move constructor
	String2(String2&& other) noexcept;
	
	//move assignment
	String2& operator=(String2&& rhs) noexcept;

	//////////Sprint 3//////////
	
	String2 operator+(const String2& _other) const;

	String2 operator+(const char* _other) const;

	String2& operator+=(const String2& _other);

	String2& operator+=(const char* _other);

	//Konvertierungsfunktion
	operator char* () const { return str; }

	//////////Sprint 4//////////
	
	class Iterator {


	};

	

	//////////Helper-Functions//////////

	void setString(const char* buffer);

	void strcpy(char* destination, const char* source, int length);

};

