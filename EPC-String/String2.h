#pragma once

#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t

class String2
{
private:

	char* str;

public:

	//////////Sprint 1//////////

	String2();

	String2(const char* buffer);

	char* c_str() const;

	int length() const;

	void append(const String2& _other);

	~String2();

	//////////Sprint 2//////////

	void operator = (const char*);

	//copy constructor
	String2(const String2& source);

	//copy assignment
	String2 operator=(const String2& rhs);

	//move constructor
	String2(String2&& _other) noexcept;

	//move assignment
	String2& operator=(String2&& _other) noexcept;

	//////////Sprint 3//////////

	String2 operator+(const String2& _other) const;

	String2 operator+(const char* _other) const;

	String2& operator+=(const String2& _other);

	String2& operator+=(const char* _other);

	//Konvertierungsfunktion
	operator char* () const { return str; }

	//////////Sprint 4////////// 

	//Source: https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp

	class Iterator {

		using iterator_category = std::forward_iterator_tag;
		using difference_type = ptrdiff_t;
		using value_type = char;
		using pointer = const char*;
		using reference = const char&;

	public:

		Iterator(pointer ptr) : m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() const { return m_ptr; }

		// Prefix increment
		Iterator& operator++() { m_ptr++; return *this; }

		// Postfix increment
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

		// Prefix decrement
		Iterator& operator--() { m_ptr--; return *this; }

		// Postfix decrement
		Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

		friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
		friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

	private:

		pointer m_ptr;

	};

	Iterator begin() const { return Iterator(this->str); }
	Iterator end() const { return Iterator(this->str + this->length()); }

	//////////Helper-Functions//////////

	void setString(const char* buffer);

	void strcpy(char* destination, const char* source, int length);

};

