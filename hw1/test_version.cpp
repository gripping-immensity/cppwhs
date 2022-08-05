#include <gtest/gtest.h>
#include "lib.h"

TEST(HelloTest, ValidVersion) {
    EXPECT_GT(version(), 0);
}

