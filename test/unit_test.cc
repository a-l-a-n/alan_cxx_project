#include <gtest/gtest.h>
#include "utils.h"

TEST(PositiveTest, HandlesPositiveInput) {
  EXPECT_TRUE(process::IsPositive(1));
}

TEST(PositiveTest, HandlesNegativeInput) {
  EXPECT_FALSE(process::IsPositive(-1));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
