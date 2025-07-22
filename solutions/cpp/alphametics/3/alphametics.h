#pragma once

#include <map>
#include <optional>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

namespace alphametics {

	class DFSNode {
	public:
		std::map<char, int> current_vals;
		std::set<int> used;


		DFSNode(std::map<char, int> new_vals, std::set<int> new_used);

		std::vector<DFSNode> successors(std::map<char, std::vector<int>> candidates);

		bool is_terminal();
	};

// TODO: add your solution here
	std::optional<std::map<char, int>> solve(std::string input);

	// Helpers
	void populate_coeffs(std::map<char, int>& coeffs, std::string substr, bool is_lhs);
	std::vector<std::string> tokenize(std::string input, char delim);

}  // namespace alphametics