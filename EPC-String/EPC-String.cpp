// EPC-String.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "String2.h"
//#include "doctest.h"
//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


int main()
{
	/*
	const String2 testString1("Servus"); std::cout << testString1.c_str() << std::endl;
	String2 testString2("Hello"); std::cout << testString2.c_str() << std::endl;
	String2 copyString(testString1); std::cout << copyString.c_str() << std::endl;
	testString2 = testString1; std::cout << testString2.c_str() << std::endl;

	String2 s5 = std::move(testString1);
	String2 Test;
	Test = std::move(s5);
	*/

	String2 s1("Hello");
	const String2 s2("World");
	//s1 += s2; std::cout << s1.c_str() << std::endl;
	String2 s3 = s1 + s2;
	//s3 += "Hello"; std::cout << s3.c_str() << std::endl;
	const String2 s4 = s3 + "World"; std::cout << s4.c_str() << std::endl;
	puts(s4);

	return 0;

}

/*


TEST_CASE("VectorDoesNotChange") {

	String2 test2("World");
	String2 test3 = "Servus";
	test3.append(test2);

	CHECK_EQ("ServusWorld", test3.c_str());

}

*/