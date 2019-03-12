/*
** EPITECH PROJECT, 2018
** PowerSpeed
** File description:
** Class PowerSpeed
*/

#pragma once

#include "APowerUp.hpp"

namespace bbm {
	constexpr float INCREMENT_SEED = 0.05f;

	class PowerSpeed : public APowerUp {
	public:
		PowerSpeed(int x, int y);
		~PowerSpeed() = default;

	public:
		void assignPlayer(ACharacter &character) override;
	};
}
