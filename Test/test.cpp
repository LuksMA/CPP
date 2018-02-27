#include "pch.h"
#include "utility.hpp"
#include "SimpleTestData.hpp"


namespace {
	SimpleTestData ST;

	// Input Data
	vector<int> id = { 1,2,3,4,5,6,7,8,9,10 };
	vector<vector<double>> y = { { 1,2,3,4,5,3,3,3,3,3 } };
	vector<vector<int>> actions = { { 1,1,1,1,1,2,2,2,2,2 } };
	vector<vector<int>> x = { { 1,2,3,4,5,1,2,3,4,5 } };
	// Solutions
	vector<double> freq = { 0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5 };
	vector<int> cutA = { 2,1,1,1,1,2,1,1,1,1 };
	vector<int> cutB = { 2,2,1,1,1,2,2,1,1,1 };
	vector<int> matchedA = { 0,1,1,1,1,1,0,0,0,0 };
	vector<int> matchedB = { 0,0,1,1,1,1,1,0,0,0 };
	double expA = 3.4;
	double expB = 3.6;

	// test stored data
	TEST(SimpleTestData, TestDataStore) {
		EXPECT_EQ(ST.getID(), id);
		EXPECT_EQ(ST.getY(), y);
		EXPECT_EQ(ST.getActions(), actions);
		EXPECT_EQ(ST.getX(), x);
		EXPECT_EQ(ST.getFrequency(), freq);
		EXPECT_EQ(ST.getCutA(), cutA);
		EXPECT_EQ(ST.getCutB(), cutB);
		EXPECT_EQ(ST.getMatchedA(), matchedA);
		EXPECT_EQ(ST.getMatchedB(), matchedB);
		EXPECT_DOUBLE_EQ(ST.getExpA(), expA);
		EXPECT_DOUBLE_EQ(ST.getExpB(), expB);
	}

	// test preprocessing data
	TEST(SimpleTestData, TestDataProcess) {
		EXPECT_EQ(ST.condFreq(), freq);
		EXPECT_EQ(ST.treatAssign(2), cutA);
		EXPECT_EQ(ST.treatAssign(3), cutB);
		EXPECT_EQ(ST.treatMatch(2), matchedA);
		EXPECT_EQ(ST.treatMatch(3), matchedB);
	}

	// test expectations
	TEST(SimpleTestData, TestData) {
		EXPECT_DOUBLE_EQ(ST.expectation(2), expA);
		EXPECT_DOUBLE_EQ(ST.expectation(3), expB);
	}
}