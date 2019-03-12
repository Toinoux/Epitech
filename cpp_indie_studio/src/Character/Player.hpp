/*
** EPITECH PROJECT, 2018
** Player
** File description:
** Class Player
*/

#pragma once
#include <iostream>
#include <cstddef>

#include "ACharacter.hpp"

namespace bbm {
	class Player : public ACharacter {
	public:
		Player() = delete;
		Player(std::size_t id);
		~Player() = default;
		Player(Player &player);
		Player &operator=(Player &player);
	};
}
