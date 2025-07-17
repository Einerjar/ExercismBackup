#include "kindergarten_garden.h"

using namespace std;

namespace kindergarten_garden {

	static map<char, Plants> plant_map = {
		{'V', Plants::violets},
		{'C', Plants::clover},
		{'R', Plants::radishes},
		{'G', Plants::grass}
	};


// TODO: add your solution here
	array<Plants, 4> plants(string diagram, string name) {
		// Turn the child's string name an index by evaluating the
		// character as an int and subtracting the value of 'A'.
		char first_letter = name[0];
		int idx_val = 2*(first_letter - 'A');

		// Find the point of row-change by looking for \n.
		int newline_start = diagram.find("\n") + 1;

		// Define the 4 idcs this name is concerned with.
		array<int, 4> idcs_to_get = { 
			idx_val, idx_val + 1, 
			newline_start + idx_val, 
			newline_start + 1 + idx_val 
		};

		// Add the plants at the relevant indices.
		array<Plants, 4> plants_in_care;
		for (int idx = 0; idx < plants_in_care.size(); idx++) {
			plants_in_care[idx] = plant_map.find(diagram[idcs_to_get[idx]])->second;
		}

		return plants_in_care;


	}

}  // namespace kindergarten_garden
