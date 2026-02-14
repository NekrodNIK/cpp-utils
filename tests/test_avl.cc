#include <gtest/gtest.h>
#include "../src/avl.hpp"

TEST(AvlInsertSuite, AvlInsertSimple) {
  auto tree = cpp_utils::AvlTreeSet<int>();
  tree.insert(10);
}


