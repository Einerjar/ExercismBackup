#pragma once
#include <string>
#include <array>
#include <map>

namespace kindergarten_garden {

// TODO: add your solution here
	enum class Plants {
		clover,
		grass,
		violets,
		radishes
	};

	std::array<Plants, 4> plants(std::string diagram, std::string name);


}  // namespace kindergarten_garden