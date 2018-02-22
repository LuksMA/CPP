#include "pch.h"
#include "sample1.h"

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