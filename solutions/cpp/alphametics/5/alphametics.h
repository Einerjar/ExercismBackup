#pragma once
#include <unordered_map>
#include <optional>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

namespace alphametics {
	// TODO: add your solution here
	std::optional<std::unordered_map<char, int>> solve(std::string input);
	// Helpers
	void populate_coeffs(std::map<char, int>& coeffs, std::string substr, bool is_lhs);
	std::vector<std::string> tokenize(std::string input, char delim);
}  // namespace alphametics