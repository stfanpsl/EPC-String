#include "pch.h"
#include "../EPC-String/String2.cpp"
#include "../EPC-String/String2.h"


TEST(StringTest, StringHatKorrekteLänge) {
	String2 test("World");

	EXPECT_EQ(5, test.length());
}

TEST(StringTest, LangesWortZuKurzesWort) {
	String2 test("HelloWorld");
	String2 test2("World");

	test = test2;

	EXPECT_STREQ("World", test.c_str());
}

TEST(StringTest, StringWirdAngelegt) {
	String2 test("World");

	EXPECT_STREQ("World", test.c_str());
}


TEST(StringTest, StringWirdAppended) {

	//ARRANGE
	String2 test2("World");
	String2 test = "Servus";

	//ACT
	test.append(test2);

	//ASSERT
	ASSERT_STREQ("ServusWorld", test.c_str());
	ASSERT_STREQ("World", test2.c_str());
}

TEST(StringTest, CopyConstructorAndCopyAssignment) {

	//ARRANGE
	const String2 testString1("Hello");
	String2 testString2("World");

	//ACT
	String2 copyString(testString1);
	testString2 = testString1;

	//ASSERT
	ASSERT_STREQ("Hello", testString2.c_str());
	ASSERT_STREQ("Hello", testString1.c_str());
}

TEST(StringTest, PlusGleichOperatorString) {

	//ARRANGE
	String2 s1("Hello");
	const String2 s2("World");

	//ACT
	s1 += s2;

	//ASSERT
	ASSERT_STREQ("HelloWorld", s1.c_str());
}

TEST(StringTest, PlusOperator) {

	//ARRANGE
	String2 s1("Hello");
	const String2 s2("World");

	//ACT
	String2 s3 = s1 + s2;;

	//ASSERT
	ASSERT_STREQ("HelloWorld", s3.c_str());
}

TEST(StringTest, PlusGleichOperatorConstChar) {

	//ARRANGE
	String2 s1("Hello");

	//ACT
	s1 += "World";

	//ASSERT
	ASSERT_STREQ("HelloWorld", s1.c_str());
}

TEST(StringTest, PlusOperatorConstChar) {

	//ARRANGE
	String2 s1("Hello");

	//ACT
	const String2 s2 = s1 + "World";

	//ASSERT
	ASSERT_STREQ("HelloWorld", s2.c_str());
}

TEST(StringTest, Iterator) {

	std::string testOutput = "";
	String2 test("Hello World");
	for (String2::Iterator it = test.begin(); it != test.end(); ++it) { testOutput += *it; }

	ASSERT_STREQ(test.c_str(), testOutput.c_str());
	//std::cout << (std::find(test.begin(), test.end(), 'W') != test.end()) << '\n';
}
