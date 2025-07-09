#pragma once
#include <string>

namespace beer_song {

// TODO: add your solution here
	// Verse fcn.
	std::string verse(int num_bottles);

	// Sing fcn.
	std::string sing(int start_num);
	std::string sing(int start_num, int end_num);

	std::string get_bottle_plurality(int num);

}  // namespace beer_song
