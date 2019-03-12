/*
** EPITECH PROJECT, 2018
** AAI
** File description:
** Abstract class AI
*/

#include "AAI.hpp"

bbm::AAI::AAI(const size_t id) : ACharacter(id)
{
}

bbm::AAI::AAI(const AAI &ai) : ACharacter(ai)
{
}

bbm::AAI &bbm::AAI::operator=(AAI &character)
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
