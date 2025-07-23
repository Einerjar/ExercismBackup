#include "alphametics.h"
using namespace std;
namespace alphametics {

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
				output_vector.emplace_back(input.substr(start_idx, idx - start_idx - 1));
				start_idx = idx + 2;
			}
		}
		// Wrap up. Throw the rest in and return.
		output_vector.emplace_back(input.substr(start_idx));
		return output_vector;
	}
	// TODO: add your solution here
	optional<unordered_map<char, int>> solve(string input) {
		// Declare vars.
		string lhs, rhs;
		// Find the first equal sign, then minus 1 to get the leading space out.
		int eq_sign = input.find('=') - 1;
		// Init empty map to start.
		unordered_map<char, int> leaders;

		map<char, int> coeffs;

		// Possible solutions for each char.
		unordered_map<char, vector<int>> candidates;
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
		char first_term = rhs.at(0);
		auto is_leader = leaders.find(first_term);

		vector<char> chars_in_order;

		if (is_leader == leaders.end()) {
			leaders[first_term] = 0;
		}
		// Get the possible candidates for each character.
		for (const auto& pair : coeffs) {
			vector<int> possible = { 1,2,3,4,5,6,7,8,9 };
			if (leaders.find(pair.first) == leaders.end()) {
				possible.emplace_back(0);
			}
			candidates[pair.first] = possible;
			chars_in_order.emplace_back(pair.first);
		}

		const int num_coeffs = chars_in_order.size();
		vector<int> digits = { 0,1,2,3,4,5,6,7,8,9 };


		unordered_set<string> visited;

		while (next_permutation(digits.begin(), digits.end())) {
			int value = 0;
			bool leading_zero = false;

			for (int i = 0; i < num_coeffs; i++) {
				auto char_at = chars_in_order[i];
				if (digits[i] == 0 && leaders.find(char_at) != leaders.end()) {
					leading_zero = true;
					break;
				}
				value += coeffs[char_at] * digits[i];
			}

			if (leading_zero) {
				continue;
			}

			if (value == 0) {
				unordered_map<char, int> output;
				for (int i = 0; i < num_coeffs; i++) {
					auto char_at = chars_in_order[i];
					output[char_at] = digits[i];
				}
				return output;
			}
		}



		// No solution. Quit.
		return nullopt;
	}
}  // namespace alphametics