//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Common header file
//

#pragma once

#include "Block.hpp"

namespace arc {
	using blocksLayers = std::vector<std::vector<Block>>;

	enum KeyCode {
		LEFT = 128,
		RIGHT,
		UP,
		DOWN,
		ESCAPE,
		ENTER,
		BACKSPACE
	};
}
