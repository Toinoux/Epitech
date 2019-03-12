/*
** EPITECH PROJECT, 2018
** PowerSpeed
** File description:
** Class PowerSpeed
*/

#include <iostream>
#include "PowerSpeed.hpp"

bbm::PowerSpeed::PowerSpeed(int x, int y)
	: APowerUp(10, false, x, y)
{}

void bbm::PowerSpeed::assignPlayer(bbm::ACharacter &character)
{
	_isActive = false;
	character.addSpeed(INCREMENT_SEED);
	std::cout << "A player now run faster" << std::endl;
}
