#include "alphametics.h"

using namespace std;

namespace alphametics {

	DFSNode::DFSNode(map<char, int> new_vals, set<int> new_used) {
		current_vals = new_vals;
		used = new_used;
	}

	std::vector<DFSNode> DFSNode::successors(map<char, vector<int>> candidates) {
		std::vector<DFSNode> succs;

		for (const auto& pair : current_vals) {
			if (pair.second == -1) {

				auto possible_for_val = candidates[pair.first];
				int num_candidates = possible_for_val.size();

				for (int idx = 0; idx < num_candidates; idx++) {
					int val_to_add = possible_for_val.at(idx);
					if (used.find(val_to_add) != used.end()) {
						continue;
					}
					auto new_base_vals = current_vals;
					auto new_base_used = used;

					new_base_used.emplace(val_to_add);
					new_base_vals[pair.first] = val_to_add;

					succs.emplace_back(DFSNode(new_base_vals, new_base_used));
				}

			}
		}

		return succs;
	}

	bool DFSNode::is_terminal() {
		return used.size() == current_vals.size(); 
	}

	void populate_coeffs(map<char, int>& coeffs, string substr, bool is_lhs) {
		int multiplier = 1;
		int sign;

		// Positive if LHS, Negative otherwise.
		if (is_lhs) {
			sign = 1;
		}
		else {
			sign = -1;
		}

		// Iterate backwards through the string.
		for (int idx = substr.length() - 1; idx >= 0; idx--) {
			int val_to_add = sign * multiplier;

			char char_to_eval = substr.at(idx);
			auto val = coeffs.find(char_to_eval);

			// Init key if not found yet.
			if (val == coeffs.end()) {
				coeffs.insert({ char_to_eval, 0 });
			}
		
			// Add value.
			coeffs[char_to_eval] += val_to_add;

			// 10x the multiplier.
			multiplier = multiplier * 10;

		}

	}

	vector<string> tokenize(string input, char delim) {
		int start_idx = 0, str_len = input.size();
		vector<string> output_vector;

		for (int idx = 0; idx < str_len; idx++) {
			if (input.at(idx) == delim) {
				output_vector.emplace_back(input.substr(start_idx, idx-start_idx-1));
				start_idx = idx+ 2;
			}
		}

		// Wrap up. Throw the rest in and return.
		output_vector.emplace_back(input.substr(start_idx));
		return output_vector;
	}

// TODO: add your solution here
	optional<map<char, int>> solve(string input) {
		// Declare vars.
		string lhs, rhs;

		// Find the first equal sign, then minus 1 to get the leading space out.
		int eq_sign = input.find('=') - 1;

		// Init empty map to start.
		map<char, int> initial, coeffs, leaders;

		// Possible solutions for each char.
		map<char, vector<int>> candidates;

		// Split into LHS and RHS.
		lhs = input.substr(0, eq_sign);
		rhs = input.substr(eq_sign + 4);

		// Solve LHS by adding value to coeffs.
		auto lhs_pieces = tokenize(lhs, '+');
		int num_addends = lhs_pieces.size();
		for (int idx = 0; idx < num_addends; idx++) {

			char first_term = lhs_pieces.at(idx).at(0);
			auto is_leader = leaders.find(first_term);
			
			if (is_leader == leaders.end()) {
				leaders[first_term] = 0;
			}
			populate_coeffs(coeffs, lhs_pieces.at(idx), true);
		}

		// Solve RHS by removing value from coeffs.
		populate_coeffs(coeffs, rhs, false);
		
		// Get the possible candidates for each character.
		for (const auto& pair : coeffs) {
			vector<int> possible = { 1,2,3,4,5,6,7,8,9 };
			if (leaders.find(pair.first) == leaders.end()) {
				possible.emplace_back(0);
			}
			candidates[pair.first] = possible;
			initial[pair.first] = -1;
		}


		// Init discovery with the first
		set<map<char, int>> visited;

		stack<DFSNode> discovery;
		discovery.push(DFSNode(initial, {}));

		// Main loop.
		while (discovery.size() > 0) {
			DFSNode viewing = discovery.top();
			discovery.pop();

			// Check if already visited this node and skip if so.
			if (visited.find(viewing.current_vals) != visited.end()) {
				continue;
			}

			// Add node to visited.
			visited.emplace(viewing.current_vals);

			if (!viewing.is_terminal()) {
				auto succs = viewing.successors(candidates);
				int succ_size = succs.size();

				for (int idx = 0; idx < succ_size; idx++) {
					discovery.push(succs.at(idx));
				}

				continue;

			}


			// Main check. See if the coeffs and vals add to 0.
			int value_of_node = 0;

			for (const auto& pair : viewing.current_vals) {
				value_of_node += coeffs[pair.first] * viewing.current_vals[pair.first];
			}
			
			if (value_of_node == 0) {
				return viewing.current_vals;
			}


		}

		// No solution. Quit.
		return nullopt;

	}

}  // namespace alphametics
