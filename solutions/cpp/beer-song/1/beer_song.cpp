#include "beer_song.h"

using namespace std;

namespace beer_song {

	string get_bottle_plurality(int num) {
		if (num == 1) {
			return " bottle ";
		}
		return " bottles ";
	}

// TODO: add your solution here
	string verse(int num_bottles) {
		switch (num_bottles) {
		case 0:
			return "No more bottles of beer on the wall, no more bottles of beer.\n"
				"Go to the store and buy some more, 99 bottles of beer on the wall.\n";
		
		case 1:
			return "1 bottle of beer on the wall, 1 bottle of beer.\n"
				"Take it down and pass it around, no more bottles of beer on the "
				"wall.\n";
		default:
			string str_bottles = to_string(num_bottles);
			return str_bottles + " bottles of beer on the wall, " + str_bottles + " bottles of beer.\n"
				"Take one down and pass it around, " + to_string(num_bottles - 1) 
				+ get_bottle_plurality(num_bottles - 1) + "of beer on the wall.\n";
	}
	}

	string sing(int start_num, int end_num) {
		string big_string = "";
		for (int num_bottles = start_num; num_bottles >= end_num; num_bottles--) {
			big_string += verse(num_bottles);
			if (num_bottles != end_num) {
				big_string += "\n";
			}
		}
		return big_string;
	}

	string sing(int start_num) {
		string big_string = "";
		for (int num_bottles = start_num; num_bottles >= 0; num_bottles--) {
			big_string += verse(num_bottles);
			if (num_bottles != 0) {
				big_string += "\n";
			}
		}
		return big_string;
	}


}  // namespace beer_song
