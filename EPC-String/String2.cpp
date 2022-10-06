#include "String2.h"
#include <cstring>
#include <iostream>


String2::String2() {
	str = nullptr;
}

String2::String2(const char* buffer) {
	this->setString(buffer);
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

