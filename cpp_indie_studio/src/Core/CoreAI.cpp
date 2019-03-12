/*
** EPITECH PROJECT, 2018
** CoreAI
** File description:
** class
*/

#include <thread>
#include <iostream>
#include <exception>

#include "CoreAI.hpp"

bbm::CoreAI::CoreAI(const int port, const std::string &ipAddr) : CoreClient(port, ipAddr, AAI(NOID)),
								 _collisionMap(MAP_SIZE * MAP_SIZE, BLANK),
								 _dangerMap(MAP_SIZE * MAP_SIZE, BLANK),
								 _difficultyAI(_sock)
{}

bbm::CoreAI::~CoreAI()
{}

void bbm::CoreAI::run()
{
	try {
		std::cout << "Runs AI !" << std::endl;
		_getNewID();
		_difficultyAI.setId(_id);
		std::cout << "Your ID is " << _id << "\n";
		while (!_isEnded) {
			_play();
			_interpretCmd(CMDS_GAME_CLIENT);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	} catch (std::exception &e) {
		std::cerr << "IA just crashed : " << e.what() << std::endl;
		/* exit(12); */
	}
	std::cout << "End of AI" << std::endl;
}

void bbm::CoreAI::_play()
{
	std::cout << "AI Playing ...\n";
	_difficultyAI.findNewPos(_playerList[_id].getPos().first, _playerList[_id].getPos().second, _map);
}

void bbm::CoreAI::_updateCollisions()
{
	int counter = 0;

	for (auto &it : _map) {
		if (it == UNBREAKABLE_WALL || it == BREAKABLE_WALL || it == BOMB)
			_collisionMap[counter] = INACCESSIBLE;
		else
			_collisionMap[counter] = ACCESSIBLE;
		counter++;
	}
}

void bbm::CoreAI::_updateDangers()
{
	int counter = 0;

	for (auto &it : _map) {
		if (it == BOMB)
			_collisionMap[counter] = DANGEROUS;
		else
			_collisionMap[counter] = SAFE;
		counter++;
	}
}
