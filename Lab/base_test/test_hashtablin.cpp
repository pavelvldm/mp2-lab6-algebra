#include <gtest.h>
#include "HashTabLin.h"
#include "Polynom.h"
#include "HTL_Metd.cpp"
#include "Polynom_Metd.cpp"

TEST(HashTabLin, can_create_hash_table)
{
	ASSERT_NO_THROW(HashTabLin testTab);
}

TEST(HashTabLin, can_hash_string)
{
	string testString = "y^2 +2x^2y + 3z^2y";
	int testHash = HashIt(testString);
	int rightHash = 0;

	for (unsigned int i = 0; i < testString.size(); i++)
		rightHash += (int)testString[i];

	rightHash *= testString.size();
	rightHash %= 1000;

	EXPECT_EQ(rightHash, testHash);
}

TEST(HashTabLin, can_insert_data)
{
	Data testData;
	string testString = "y^2 +2x^2y + 3z^2y";
	testData.PolyString = testString;
	Polynom testPoly(testString);

	testData.key = "testPoly";
	testData.Poly = testPoly;

	HashTabLin testTab;

	ASSERT_NO_THROW(testTab.Insert(testData));
}

TEST(HashTabLin, cant_find_anything)
{
	HashTabLin testTab;
	EXPECT_EQ(nullptr, testTab.Find("testData"));
}

TEST(HashTabLin, can_find_data)
{
	Data testData;
	string testString = "y^2 +2x^2y + 3z^2y";
	string tS = testString;
	int rightHash = 0;

	for (unsigned int i = 0; i < testString.size(); i++)
		rightHash += (int)testString[i];

	rightHash *= testString.size();
	rightHash %= 1000;

	testData.PolyString = testString;
	Polynom testPoly(testString);

	testData.key = "testPoly";
	testData.Poly = testPoly;

	HashTabLin testTab;
	testTab.Insert(testData);
	Data* testAdd = testTab.Find("testPoly");

	EXPECT_EQ(tS, testAdd->PolyString);
}