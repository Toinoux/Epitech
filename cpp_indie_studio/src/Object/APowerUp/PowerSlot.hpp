/*
** EPITECH PROJECT, 2018
** PowerSlot
** File description:
** Class PowerSlot
*/

#pragma once

#include "APowerUp.hpp"

namespace bbm {
	class PowerSlot : public APowerUp {
	public:
		PowerSlot(int pos);
		~PowerSlot() override = default;

	public:
		void assignPlayer(ICharacter &character) override;
	};
}
