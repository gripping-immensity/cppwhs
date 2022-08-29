#include <gtest/gtest.h>
#include <iostream>
#include "util.h"

TEST(IpReprTests, String) {
    EXPECT_EQ("hello", GetStringRepr("hello"));
    EXPECT_EQ("a", GetStringRepr(std::string{"a"}));
    std::string x = "xy";
    std::string y = GetStringRepr(x);
    EXPECT_EQ(x, y);
    std::string r = "lll";
    EXPECT_EQ(r, GetStringRepr(r));
    EXPECT_EQ((void *)(r.c_str()), (void *) (GetStringRepr(r).c_str()));
    EXPECT_EQ("", GetStringRepr(""));
}

TEST(IpReprTests, Int) {
    EXPECT_EQ("255", GetStringRepr(int8_t{-1}));
    EXPECT_EQ("0.0.0.0", GetStringRepr(int32_t{0}));
    EXPECT_EQ("127.0.0.1", GetStringRepr(int32_t{2130706433}));
}

TEST(IpReprTests, Tuple) {
    EXPECT_EQ("0", GetStringRepr(std::tuple<int>{0}));
    EXPECT_EQ("1.1.1.1",
              GetStringRepr(std::tuple<std::string, std::string, std::string, std::string>{"1", "1", "1", "1"}));
}

TEST(IpReprTests, Vector) {
    EXPECT_EQ("5.5.5.5", GetStringRepr(std::vector<char>{'5', '5', '5', '5'}));
    EXPECT_EQ("100.99.88.77", GetStringRepr(std::vector<int>{100, 99, 88, 77}));
}

TEST(IpReprTests, List) {
    EXPECT_EQ("50.1", GetStringRepr(std::list<long long>{50, 1}));
}

