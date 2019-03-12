/*
** EPITECH PROJECT, 2018
** APowerUp
** File description:
** Abstract class PowerUp
*/

#include "APowerUp.hpp"

bbm::APowerUp::APowerUp(const std::size_t rarity,
			const bool isUnique, int x, int y)
	: _rarity(rarity), _isUnique(isUnique), _x(x), _y(y)
{}
