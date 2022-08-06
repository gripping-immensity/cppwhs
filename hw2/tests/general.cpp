#include <gtest/gtest.h>
#include "util.hpp"

TEST(Hw2Tests, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);
}

TEST(Hw2Tests, BasicSplitTest) {
    std::string s = "1.2.3.4";
    auto result = Split(s, '.');
    std::vector<std::string> expected_result = {"1", "2", "3", "4"};

    ASSERT_EQ(expected_result, result);
}

TEST(Hw2Tests, AnotherSplitTest) {
    std::string s = "78.158.5.183	0	1";
    auto result = Split(s, '\t');
    std::vector<std::string> expected_result = {"78.158.5.183", "0", "1"};

    ASSERT_EQ(expected_result, result);
}

TEST(Hw2Tests, BasicParseIpAddressTest) {
    std::string s = "165.255.112.201";
    auto result = ParseIpAddress(s);
    IpAddress expected{165, 255, 112, 201};

    ASSERT_EQ(expected, result);
}
