#include "levenshtein.h"

namespace levenshtein {

int calculate_levenshtein_distance(const std::string& s1, const std::string& s2) {
  const std::size_t len1 = s1.length();
  const std::size_t len2 = s2.length();

  // Create a matrix to store distances between prefixes of s1 and s2.
  // dp[i][j] will be the Levenshtein distance between the first i characters
  // of s1 and the first j characters of s2.
  std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1));

  // Initialize the first row and column of the matrix.
  // The distance from an empty string to a string of length k is k.
  for (std::size_t i = 0; i <= len1; ++i) {
    dp[i][0] = i;
  }
  for (std::size_t j = 0; j <= len2; ++j) {
    dp[0][j] = j;
  }

  // Fill the rest of the matrix.
  for (std::size_t i = 1; i <= len1; ++i) {
    for (std::size_t j = 1; j <= len2; ++j) {
      int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
      dp[i][j] = std::min({
          dp[i - 1][j] + 1,        // Deletion from s1
          dp[i][j - 1] + 1,        // Insertion into s1
          dp[i - 1][j - 1] + cost  // Substitution/match
      });
    }
  }

  // The Levenshtein distance is the value in the bottom-right cell of the matrix.
  return dp[len1][len2];
}

}  // namespace levenshtein
