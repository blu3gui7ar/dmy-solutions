#include <gtest/gtest.h>
#include <vector>
#include <map>
#include "common.hpp"

class FactorizeCachedTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 初始化素数表 (100以内的素数)
        is_prime = vector<bool>(101, true);
        sieve(101, is_prime);
    }

    vector<bool> is_prime;
    map<int, int> prime_counts;
};

TEST_F(FactorizeCachedTest, TestPrimeNumber) {
    prime_counts.clear();
    factorize_cached(17, is_prime, prime_counts);
    ASSERT_EQ(prime_counts.size(), 1);
    EXPECT_EQ(prime_counts[17], 1);
}

TEST_F(FactorizeCachedTest, TestCompositeNumber) {
    prime_counts.clear();
    factorize_cached(12, is_prime, prime_counts);
    ASSERT_EQ(prime_counts.size(), 2);
    EXPECT_EQ(prime_counts[2], 2);
    EXPECT_EQ(prime_counts[3], 1);
}

TEST_F(FactorizeCachedTest, TestPowerOfPrime) {
    prime_counts.clear();
    factorize_cached(8, is_prime, prime_counts);
    ASSERT_EQ(prime_counts.size(), 1);
    EXPECT_EQ(prime_counts[2], 3);
}

TEST_F(FactorizeCachedTest, TestOne) {
    prime_counts.clear();
    factorize_cached(1, is_prime, prime_counts);
    EXPECT_TRUE(prime_counts.empty());
}

TEST_F(FactorizeCachedTest, TestLargePrime) {
    prime_counts.clear();
    // 假设素数表足够大，包含101
    is_prime.resize(102, true);
    is_prime[101] = true;
    factorize_cached(101, is_prime, prime_counts);
    ASSERT_EQ(prime_counts.size(), 1);
    EXPECT_EQ(prime_counts[101], 1);
}

TEST_F(FactorizeCachedTest, TestMultipleFactors) {
    prime_counts.clear();
    factorize_cached(30, is_prime, prime_counts);
    ASSERT_EQ(prime_counts.size(), 3);
    EXPECT_EQ(prime_counts[2], 1);
    EXPECT_EQ(prime_counts[3], 1);
    EXPECT_EQ(prime_counts[5], 1);
}
