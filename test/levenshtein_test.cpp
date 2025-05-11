#include "levenshtein.h"
#include "gtest/gtest.h"

// Test fixture for Levenshtein distance tests
class LevenshteinTest : public ::testing::Test {
 protected:
  // You can define helper functions or member variables here if needed
};

// Test case for empty strings
TEST_F(LevenshteinTest, EmptyStrings) {
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("", ""), 0);
}

// Test case for one empty string
TEST_F(LevenshteinTest, OneEmptyString) {
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("abc", ""), 3);
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("", "abc"), 3);
}

// Test case for identical strings
TEST_F(LevenshteinTest, IdenticalStrings) {
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("abc", "abc"), 0);
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("hello world", "hello world"), 0);
}

// Test case for single insertion
TEST_F(LevenshteinTest, SingleInsertion) {
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("cat", "cast"), 1);
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("ca", "cat"), 1);
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("at", "cat"), 1);
}

// Test case for single deletion
TEST_F(LevenshteinTest, SingleDeletion) {
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("cast", "cat"), 1);
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("cat", "ca"), 1);
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("cat", "at"), 1);
}

// Test case for single substitution
TEST_F(LevenshteinTest, SingleSubstitution) {
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("cat", "cot"), 1);
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("book", "boot"), 1);
}

// Test case for multiple operations
TEST_F(LevenshteinTest, MultipleOperations) {
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("kitten", "sitting"),
            3);  // s/k, i/i, t/t, t/t, e/i, n/n -> s/k, i/i, t/t, t/t, i/e, n/g (sub, sub, sub)
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("flaw", "lawn"), 2);
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("saturday", "sunday"), 3);
}

// Test case for strings with different order but same characters (example)
TEST_F(LevenshteinTest, DifferentOrderSameChars) {
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("apple", "apply"), 1);     // Not exactly same chars, but good example
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("abacaba", "abcabc"), 2);  // delete a, delete a
}

// Test case for longer strings
TEST_F(LevenshteinTest, LongerStrings) {
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("intention", "execution"), 5);
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("thisisalongstringexample", "thisisanotherlongstringexample"), 6);
}

// Test case for case sensitivity (assuming it's case sensitive by default)
TEST_F(LevenshteinTest, CaseSensitivity) {
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("apple", "Apple"), 1);
  EXPECT_EQ(levenshtein::calculate_levenshtein_distance("APPLE", "apple"), 5);
}
