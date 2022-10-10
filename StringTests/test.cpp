#include "pch.h"
#include "../EPC-String/String2.cpp"
#include "../EPC-String/String2.h"


//NEXT STEPS: https://www.codementor.io/@sandesh87/the-rule-of-five-in-c-1pdgpzb04f


TEST(StringTest, StringHatKorrekteLänge) {
	String2 test("World");
	
	EXPECT_EQ(5,test.length());
}

TEST(StringTest, StringWirdAngelegt) {
	String2 test("World");

	EXPECT_STREQ("World", test.c_str());
}


TEST(StringTest, StringWirdAppended) {

	//ASSERT
	String2 test2("World");
	String2 test = "Servus";

	//ACTION
	test.append(test2);

	//CHECK
	ASSERT_STREQ("ServusWorld", test.c_str());
}

TEST(StringTest, StringCopyOperator) {
	String2 testString1("Hello");
	const String2 testString2("Hello");
	String2 copyString(testString1);
	//testString2 = testString1;
	std::cout << copyString.c_str();
}