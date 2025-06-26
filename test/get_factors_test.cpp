#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "common.hpp"

class GetFactorsTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(GetFactorsTest, TestPrimeNumber) {
    std::vector<int> expected = {1, 7};
    auto result = get_factors(7);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(expected, result);
}

TEST_F(GetFactorsTest, TestPerfectSquare) {
    std::vector<int> expected = {1, 2, 3, 4, 6, 9, 12, 18, 36};
    auto result = get_factors(36);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(expected, result);
}

TEST_F(GetFactorsTest, TestRegularNumber) {
    std::vector<int> expected = {1, 2, 3, 4, 6, 8, 12, 24};
    auto result = get_factors(24);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(expected, result);
}

TEST_F(GetFactorsTest, TestOne) {
    std::vector<int> expected = {1};
    auto result = get_factors(1);
    EXPECT_EQ(expected, result);
}

TEST_F(GetFactorsTest, TestDifferentTypes) {
    std::vector<long> expected = {1L, 2L, 4L, 8L, 16L};
    auto result = get_factors(16L);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(expected, result);
}

