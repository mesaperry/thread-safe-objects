//
// Created by mgperry on 7/1/21.
//

#include "tso.h"

#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);
}
