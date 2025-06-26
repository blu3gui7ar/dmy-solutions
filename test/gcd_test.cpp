#include <gtest/gtest.h>
#include "common.hpp"

class GCDTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(GCDTest, TestWithZero) {
    EXPECT_EQ(5, gcd(5, 0));
    EXPECT_EQ(5, gcd(0, 5));
    EXPECT_EQ(0, gcd(0, 0));
}

TEST_F(GCDTest, TestPositiveNumbers) {
    EXPECT_EQ(1, gcd(3, 7));
    EXPECT_EQ(6, gcd(12, 18));
    EXPECT_EQ(5, gcd(15, 25));
}

TEST_F(GCDTest, TestNegativeNumbers) {
    EXPECT_EQ(5, gcd(-15, 25));
    EXPECT_EQ(5, gcd(15, -25));
    EXPECT_EQ(5, gcd(-15, -25));
}

TEST_F(GCDTest, TestEqualNumbers) {
    EXPECT_EQ(7, gcd(7, 7));
    EXPECT_EQ(12, gcd(12, 12));
}

TEST_F(GCDTest, TestDifferentTypes) {
    EXPECT_EQ(2, gcd<int>(4, 6));
    EXPECT_EQ(2, gcd<long>(4L, 6L));
}
