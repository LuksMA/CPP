#include "pch.h"
#include "sample1.h"
#include "sample3.h"
#include <time.h>

namespace {
	class QuickTest : public testing::Test {
	protected:
		virtual void SetUp() {
			start_time_ = time(NULL);
		}

		virtual void TearDown() {
			const time_t end_time = time(NULL);
			EXPECT_TRUE(end_time - start_time_ <= 5) << "The test took too long.";
		}
		time_t start_time_;
	};


	class IntegerFunctionTest : public QuickTest {
		// We don't need any more logic than already in the QuickTest fixture.
		// Therefore the body is empty.
	};

	// Tests IsPrime()
	TEST_F(IntegerFunctionTest, IsPrime) {
		// Tests negative input.
		EXPECT_FALSE(IsPrime(-1));
		EXPECT_FALSE(IsPrime(-2));
		EXPECT_FALSE(IsPrime(INT_MIN));

		// Tests some trivial cases.
		EXPECT_FALSE(IsPrime(0));
		EXPECT_FALSE(IsPrime(1));
		EXPECT_TRUE(IsPrime(2));
		EXPECT_TRUE(IsPrime(3));

		// Tests positive input.
		EXPECT_FALSE(IsPrime(4));
		EXPECT_TRUE(IsPrime(5));
		EXPECT_FALSE(IsPrime(6));
		EXPECT_TRUE(IsPrime(23));
	}

	class QueueTest : public QuickTest {
	protected:
		virtual void SetUp() {
			// First, we need to set up the super fixture (QuickTest).
			QuickTest::SetUp();

			// Second, some additional setup for this fixture.
			q1_.Enqueue(1);
			q2_.Enqueue(2);
			q2_.Enqueue(3);
		}

		// By default, TearDown() inherits the behavior of
		// QuickTest::TearDown().  As we have no additional cleaning work
		// for QueueTest, we omit it here.
		//
		// virtual void TearDown() {
		//   QuickTest::TearDown();
		// }

		Queue<int> q0_;
		Queue<int> q1_;
		Queue<int> q2_;
	};


	// Now, let's write tests using the QueueTest fixture.

	// Tests the default constructor.
	TEST_F(QueueTest, DefaultConstructor) {
		EXPECT_EQ(0u, q0_.Size());
	}

	// Tests Dequeue().
	TEST_F(QueueTest, Dequeue) {
		int* n = q0_.Dequeue();
		EXPECT_TRUE(n == NULL);

		n = q1_.Dequeue();
		EXPECT_TRUE(n != NULL);
		EXPECT_EQ(1, *n);
		EXPECT_EQ(0u, q1_.Size());
		delete n;

		n = q2_.Dequeue();
		EXPECT_TRUE(n != NULL);
		EXPECT_EQ(2, *n);
		EXPECT_EQ(1u, q2_.Size());
		delete n;
	}
}

