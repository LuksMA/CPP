#include "pch.h"
#include "gtest/gtest.h"
#include "sample1.h"

//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}
//double square(const double x) {
//	return x * x;
//};



//TEST(SquareTest, PositiveNos) {
//	EXPECT_DOUBLE_EQ(324.0, square(18.0));
//	EXPECT_DOUBLE_EQ(645.16, square(25.4));
//	EXPECT_DOUBLE_EQ(2533.32029041, square(50.3321));
//}

//TEST(SquareTest, ZeroAndNegativeNos) {
//	ASSERT_EQ(0.0, square(0.0));
//	ASSERT_EQ(484.0, square(-22.0));
//}




//int main(int argc, char **argv) {
//	::testing::InitGoogleTest(&argc, argv);
//	return RUN_ALL_TESTS();
//}

namespace {
	// Tests Factorial().
	// Tests factorial of negative numbers.
	TEST(FactorialTest, Negative) {
		EXPECT_EQ(1, Factorial(-5));
		EXPECT_EQ(1, Factorial(-1));
		EXPECT_GT(Factorial(-10), 0);
	}

	// Tests factorial of 0.
	TEST(FactorialTest, Zero) {
		EXPECT_EQ(1, Factorial(0));
	}

	// Tests factorial of positive numbers.
	TEST(FactorialTest, Positive) {
		EXPECT_EQ(1, Factorial(1));
		EXPECT_EQ(2, Factorial(2));
		EXPECT_EQ(6, Factorial(3));
		EXPECT_EQ(40320, Factorial(8));
	}

	// Tests IsPrime()
	// Tests negative input.
	TEST(IsPrimeTest, Negative) {
		EXPECT_FALSE(IsPrime(-1));
		EXPECT_FALSE(IsPrime(-2));
		EXPECT_FALSE(IsPrime(INT_MIN));
	}

	// Tests some trivial cases.
	TEST(IsPrimeTest, Trivial) {
		EXPECT_FALSE(IsPrime(0));
		EXPECT_FALSE(IsPrime(1));
		EXPECT_TRUE(IsPrime(2));
		EXPECT_TRUE(IsPrime(3));
	}

	// Tests positive input.
	TEST(IsPrimeTest, Positive) {
		EXPECT_FALSE(IsPrime(4));
		EXPECT_TRUE(IsPrime(5));
		EXPECT_FALSE(IsPrime(6));
		EXPECT_TRUE(IsPrime(23));
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}