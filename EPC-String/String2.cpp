#include "String2.h"
#include <cstring>
#include <iostream>

//////////Sprint 1//////////

String2::String2() {
	str = nullptr;
}

String2::String2(const char* buffer) {
	this->setString(buffer);
}

char* String2::c_str() const {
	return this->str;
}

int String2::length() const {
	int length = 0;
	char* tmp = this->str;

	while (*tmp != '\0') {
		length++;
		tmp++;
	}

	return length;
}

void String2::append(const String2& _other) {

	char* newString = new char[this->length() + _other.length() + 1];

	this->strcpy(newString, this->str, this->length());
	this->strcpy(newString + this->length(), _other.str, _other.length());

	newString[this->length() + _other.length()] = '\0';

	delete[] this->str;
	this->str = newString;
}

String2::~String2() {
	delete[] str;
}

//////////Sprint 2//////////

// move constructer
String2::String2(String2&& _other) noexcept {
	this->str = _other.str;
	_other.str = nullptr;
}

// move assignment
String2& String2::operator=(String2&& _other) noexcept {

	// self-asignment check
	if (this != &_other) {

		// delete old data
		if (this->str) {
			delete[] this->str;
		}

		this->str = _other.c_str();
		_other.str = nullptr;
	}

	return *this;
}

// copy constructor
String2::String2(const String2& source) {
	char* buffer = source.c_str();
	this->setString(buffer);
}

//copy assignment
String2 String2::operator=(const String2& source) {
	if (this != &source) {

		delete[] this->str;

		this->setString(source.c_str());
	}

	return *this;
}

void String2::operator = (const char* buffer) {
	this->setString(buffer);
}

//////////Sprint 3//////////

String2& String2::operator+=(const String2& _other)
{
	if (this != &_other)
	{
		this->append(_other);
	}

	return *this;
}

String2& String2::operator+=(const char* _other)
{
	const auto charLength = strlen(_other);
	const auto totalLength = this->length() + charLength;
	char* buffer = new char[totalLength + 1];

	std::copy(str, str + this->length(), buffer);
	std::copy(_other, _other + charLength, buffer + this->length());
	buffer[totalLength] = '\0';

	std::swap(str, buffer);

	delete[] buffer;

	return *this;
}

String2 String2::operator+(const String2& _other) const
{
	const auto totalLength = this->length() + _other.length();
	char* buffer = new char[totalLength + 1];

	std::copy(str, str + this->length(), buffer);
	std::copy(_other.str, _other.str + _other.length(), buffer + this->length());
	buffer[totalLength] = '\0';

	return String2(buffer);
}

String2 String2::operator+(const char* _other) const
{
	const auto charLength = strlen(_other);
	const auto totalLength = this->length() + charLength;
	char* buffer = new char[totalLength + 1];

	std::copy(str, str + this->length(), buffer);
	std::copy(_other, _other + charLength, buffer + this->length());
	buffer[totalLength] = '\0';

	return String2(buffer);
}

//////////Sprint 4//////////

// Im Header

//////////Helper-Functions//////////

void String2::strcpy(char* destination, const char* source, int length) {
	for (size_t i = 0; i < length; i++) {
		*(destination + i) = *(source + i);
	}
}

void String2::setString(const char* buffer) {
	int i = 0;
	int n = static_cast<int>(strlen(buffer));
	//Allocating str memory of char[n+1]
	// +1 for the null character

	str = new char[n + 1];
	for (; i < n; i++) {
		str[i] = buffer[i]; //Copying from buffer to str
	}
	str[i] = '\0';
}