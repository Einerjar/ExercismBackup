#include "protein_translation.h"

using namespace std;

namespace protein_translation {

// TODO: add your solution here
	static const map<string, string> codon_map= {
		{"AUG", "Methionine"},
		{"UUU", "Phenylalanine"},
		{"UUC", "Phenylalanine"},
		{"UUA", "Leucine"},
		{"UUG", "Leucine"},
		{"UCU", "Serine"},
		{"UCC", "Serine"},
		{"UCA", "Serine"},
		{"UCG", "Serine"},
		{"UAU", "Tyrosine"},
		{"UAC", "Tyrosine"},
		{"UGU", "Cysteine"},
		{"UGC", "Cysteine"},
		{"UGG", "Tryptophan"},
	};

	vector<string> proteins(string input) {
		vector<string> output;
		int input_len = input.size();

		for (int idx = 0; idx < input_len - 2; idx += 3) {
			string examine = input.substr(idx, 3);
			// Early exit if a stop is reached.
			if (examine == "UAA" || examine == "UAG" || examine == "UGA") {
				return output;
			}
			output.emplace_back(codon_map.find(examine)->second);
		}

		return output;
 
		
	}

}  // namespace protein_translation
