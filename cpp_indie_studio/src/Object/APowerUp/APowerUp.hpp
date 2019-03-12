/*
** EPITECH PROJECT, 2018
** APowerUp
** File description:
** Abstract class
*/

#pragma once
#include <cstddef>
#include <utility>

#include "Character/ACharacter.hpp"
#include "Object/AObject.hpp"

namespace bbm {
	class ICharacter;
	class APowerUp : public AObject {
	public:
		APowerUp(std::size_t rarity,
			 bool isUnique, int x, int y);
		virtual ~APowerUp() = default;

	public:
		virtual void assignPlayer(ACharacter &character) = 0;
		bool getStatus() const { return _isActive; }
		std::pair<int, int> getPos() const { return std::make_pair(_x, _y); }

	protected:
		std::size_t _rarity;
		bool _isUnique;
		int _x;
		int _y;
		bool _isActive = true;
	};
}
