//
// EPITECH PROJECT, 2018
// CorePlayer
// File description:
// class
//

#include <iostream>
#include <thread>

#include "CorePlayer.hpp"

bbm::CorePlayer::CorePlayer(int port, const std::string &ipAddr)
	: CoreClient(port, ipAddr, Player(NOID))
{}

bool bbm::CorePlayer::inGame()
{
	return !_isEnded;
}

void bbm::CorePlayer::run()
{
	if (!_isEnded)
		_interpretCmd(CMDS_GAME_CLIENT);
}

bool bbm::CorePlayer::inLobby()
{
	_interpretCmd(CMDS_LOBBY_CLIENT);
	return !_isLaunched;
}

void bbm::CorePlayer::enterLobby(int nb)
{
	_requestId();
	_addSlot(nb, ADD_AI);
	_requestLaunch();
	std::cout << "Requesting launch w/ " << nb << " AI" << std::endl;
}
