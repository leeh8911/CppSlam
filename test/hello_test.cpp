#include "src/hello.h"

#include <gtest/gtest.h>

TEST(HelloTest, CallHello) { CallHello(); }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}