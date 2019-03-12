/*
** EPITECH PROJECT, 2018
** PowerRange
** File description:
** Class PowerRange
*/

#pragma once

#include "APowerUp.hpp"

namespace bbm {
	class PowerRange : public APowerUp {
	public:
		PowerRange(int pos);
		~PowerRange() override = default;

	public:
		void assignPlayer(ICharacter &character) override;
	};
}
