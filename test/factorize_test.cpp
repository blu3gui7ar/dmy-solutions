#include <gtest/gtest.h>
#include <map>
#include "common.hpp"

class FactorizeTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(FactorizeTest, TestNumberLessThanTwo) {
    std::map<int, int> expected = {};
    EXPECT_EQ(expected, factorize(1));
    EXPECT_EQ(expected, factorize(0));
    EXPECT_EQ(expected, factorize(-5));
}

TEST_F(FactorizeTest, TestPrimeNumber) {
    std::map<int, int> expected = {{7, 1}};
    EXPECT_EQ(expected, factorize(7));
}

TEST_F(FactorizeTest, TestPowerOfPrime) {
    std::map<int, int> expected = {{3, 4}};
    EXPECT_EQ(expected, factorize(81));  // 3^4
}

TEST_F(FactorizeTest, TestCompositeNumber) {
    std::map<int, int> expected = {{2, 2}, {5, 1}, {7, 1}};
    EXPECT_EQ(expected, factorize(140));  // 2^2 * 5 * 7
}

TEST_F(FactorizeTest, TestSquareOfPrime) {
    std::map<int, int> expected = {{13, 2}};
    EXPECT_EQ(expected, factorize(169));  // 13^2
}

TEST_F(FactorizeTest, TestDifferentTypes) {
    std::map<long, long> expected = {{3L, 2}, {5L, 1}};
    EXPECT_EQ(expected, factorize(45L));  // 3^2 * 5
}
