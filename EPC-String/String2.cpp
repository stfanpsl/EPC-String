#include "String2.h"
#include <cstring>
#include <iostream>


String2::String2() {
	str = nullptr;
}

String2::String2(const char* buffer) {
	this->setString(buffer);
}

//NEW --> Move Constructer
String2::String2(String2&& other) {
	this->str = other.str;
	other.str = nullptr;
}

// move assignment
String2& String2::operator=(String2&& rhs) noexcept {

	// self-asignment check
	if (this != &rhs) {

		// delete old data
		if (this->str) {
			delete[] this->str;
		}

		this->str = rhs.c_str();
		rhs.str = nullptr;
	}

	return *this;
}

void String2::setString(const char* buffer) {
	int i = 0;
	int n = strlen(buffer);
	//Allocating str memory of char[n+1]
	// +1 for the null character
	str = new char[n + 1];
	for (; i < n; i++)
		str[i] = buffer[i]; //Copying from buffer to str
	str[i] = '\0';
}


String2::String2(const String2& source) {
	char* buffer = source.c_str();
	this->setString(buffer);
}

char* String2::c_str() const {
	return this->str;
}

String2::~String2() {

	delete[] str;

}

int String2::length() const {
	int length = 0;
	const char* tmp = this->str;

	while (*tmp != '\0') {
		length++;
		tmp++;
	}

	return length;
}

void String2::operator = (const char* buffer) {
	this->setString(buffer);
}

//copy assignment
String2 String2::operator=(const String2& rhs) {
	if (this != &rhs) {
		this->setString(rhs.c_str());
	}

	return *this;
}


void String2::append(const String2& toAdd) {

	char* newString = new char[this->length() + toAdd.length() + 1];

	this->strcpy(newString, this->str, this->length());
	this->strcpy(newString + this->length(), toAdd.str, toAdd.length());

	newString[this->length() + toAdd.length()] = '\0';

	delete[] this->str;
	this->str = newString;
}


void String2::strcpy(char* destination, const char* source, int length) {
	for (size_t i = 0; i < length; i++) {
		*(destination + i) = *(source + i);
	}
}

String2& String2::operator+=(const String2& _other)
{
	if (this != &_other)
	{
		auto totalLength = this->length() + _other.length();
		char* buffer = new char[totalLength + 1];

		std::copy(str, str + this->length(), buffer);
		std::copy(_other.str, _other.str + _other.length(), buffer + this->length());
		buffer[totalLength] = '\0';

		std::swap(str, buffer);


		delete[] buffer;
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
