// EPC-String.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "String2.h"

int main()
{
	String2 test("Hello");
	String2 test2("World");
	String2 test3 = "Servus";
	test3.append(test2);

	std::cout << test3.c_str() << " mit einer Length von: " << test3.length() << std::endl;

	return 0;

}