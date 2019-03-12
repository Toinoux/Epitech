/*
** EPITECH PROJECT, 2018
** Player
** File description:
** Class Player
*/

#include "Player.hpp"

bbm::Player::Player(const std::size_t id) : ACharacter(id)
{
}

bbm::Player::Player(Player &player) : ACharacter(player)
{
}

bbm::Player &bbm::Player::operator=(Player &character)
{
        character.setNick(_nick);
        character.setID(_id);
        character.setKick(_canKick);
        character.setThrow(_canThrow);
        character.setBombAmount(_bombAmount);
        character.setBombRange(_bombRange);
        character.setLives(_lives);
	return character;
}
