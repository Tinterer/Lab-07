#include <iostream>
#include "set.h"
#include <gtest/gtest.h>

TEST(SummTest, summ) {
	BigInt num1("123");
	BigInt num2("123");
	BigInt res(num1 + num2);
	BigInt exp("246");

	EXPECT_EQ((res == exp), 1);
}

