#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H

#include <algorithm>
#include <string>
#include <vector>

namespace levenshtein {

/**
 * @brief Calculates the Levenshtein distance between two strings.
 *
 * The Levenshtein distance is a string metric for measuring the difference
 * between two sequences. Informally, the Levenshtein distance between two
 * words is the minimum number of single-character edits (insertions,
 * deletions or substitutions) required to change one word into the other.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return The Levenshtein distance between s1 and s2.
 */
int calculate_levenshtein_distance(const std::string& s1, const std::string& s2);

}  // namespace levenshtein

#endif  // LEVENSHTEIN_H
