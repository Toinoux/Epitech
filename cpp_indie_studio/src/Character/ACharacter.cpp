/*
** EPITECH PROJECT, 2018
** indie studio
** File description:
** ACharacter.hpp
*/

#include <iostream>

#include "ACharacter.hpp"

bbm::ACharacter::ACharacter(const size_t id) : _x(0), _y(0), _id(id), _canKick(false),
					       _canThrow(false), _bombAmount(1), _bombRange(0),
					       _lives(3)
{}

bbm::ACharacter::ACharacter() : _x(0), _y(0), _id(0), _canKick(false),
				_canThrow(false), _bombAmount(1), _bombRange(0),
				_lives(3)
{}


bbm::ACharacter::ACharacter(const bbm::ACharacter &character)
{
	auto pos = character.getPos();
	_x = pos.first;
	_y = pos.second;
	_nick = character.getNick();
	_id = character.getID();
	_canKick = character.canKick();
	_canThrow = character.canThrow();
	_bombAmount = character.getBombAmount();
	_bombRange = character.getBombRange();
	_lives = character.getLives();
}

#include <mutex>
std::mutex mutmut;

std::ostream &bbm::operator<<(std::ostream &io, bbm::ACharacter &aChar)
{

	std::unique_lock<std::mutex>(mutmut);
	auto pos = aChar.getPos();
	io << "{Player_" << static_cast<int>(aChar.getID()) << "}" << std::endl
		<< "[Pos: " << static_cast<int>(pos.first) << " - "
		<< static_cast<int>(pos.second) << "]" << std::endl
		<< "[Kick: " << (aChar.canKick() ? "True" : "False")
		<< "]" << std::endl
		<< "[Throw: " << (aChar.canThrow() ? "True" : "False")
		<< "]" << std::endl
		<< "[Bomb amount: " << static_cast<int>(aChar.getBombAmount()) << "]" << std::endl
		<< "[Bomb range: " << static_cast<int>(aChar.getBombRange()) << "]" << std::endl
		<< "[Move: " << (aChar.getMove() ? "True" : "False")
		<< "[Lives: " << static_cast<int>(aChar.getLives()) << "]" << std::endl;
	return io;
}

std::string &bbm::operator<<(std::string &output, bbm::ACharacter &aChar)
{
	auto pos = aChar.getPos();
	output.append(std::to_string(pos.first) + " " + std::to_string(pos.second) + " "
		      + std::to_string(aChar.canKick())
		      + std::to_string(aChar.canThrow())
		      + std::to_string(aChar.getBombAmount())
		      + std::to_string(aChar.getBombRange())
		      + std::to_string(aChar.getMove())
		      + std::to_string(aChar.getCardinal())
		      + std::to_string(aChar.getLives()) + "\r");
	return output;
}

bbm::ACharacter &bbm::operator>>(const std::string &input, bbm::ACharacter &aChar)
{
	try {
		std::unique_lock<std::mutex>(mutmut); // DELETE

		aChar.setPos(std::stof(&input[3]),
			     std::stof(&input[input.find(' ') + 1]));
		auto strPos = input.rfind(' ') + 1;
		aChar.setKick((input[strPos++] == true) ? true : false);
		aChar.setThrow((input[strPos++] == true) ? true : false);
		aChar.setBombAmount(input[strPos++] - 48);
		aChar.setBombRange(input[strPos++] - 48);
		aChar.setMove((input[strPos++] == 49) ? true : false);
		Direction tmp = static_cast<bbm::Direction>(input[strPos++] - 48);
		aChar.setCardinal(tmp);
		aChar.setLives(input[strPos] - 48);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return aChar;
}

void bbm::ACharacter::hurt()
{
	_lives--;
	if (_lives < 0)
		_lives = 0;
	if (_lives == 0) {
		_isMoving = false;
		_card = SOUTH;
	}
}

bbm::Timer &bbm::ACharacter::getTimer()
{
	return _clock;
}