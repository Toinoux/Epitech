/*
** EPITECH PROJECT, 2018
** CoreServer
** File description:
** class
*/

#include <iostream>
#include <memory>
#include <utility>

#include "Character/ACharacter.hpp"
#include "Character/AAI.hpp"
#include "Character/Player.hpp"
#include "CoreServer.hpp"
#include "Generator.hpp"
#include "Timer.hpp"
#include "Object/ABomb/DefaultBomb.hpp"

bbm::CoreServer::CoreServer(int port, int nbPlayers)

	: _tp(), _isEnded(false), _map(MAP_SIZE * MAP_SIZE, UNBREAKABLE_WALL),
	  _sock(port), _nbPlayers(nbPlayers), _nbAI(0)
{}

bbm::CoreServer::~CoreServer()
{
	for (auto &i : _playerList)
		_sock.sendMsg(i.first, Serializer::makeCommand(SERVERID, QUIT, ""));
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "Server shutting down..." << std::endl;
}

void bbm::CoreServer::run()
{
	std::string tmp;
	Generator world;
	Timer tic;

	_managePlayer();
	_launchAI();
	world.generateMap(_map, _playerList);
	while (!_isEnded) {
		_interpretCmd(CMDS_GAME_SERVER);
		if (!_isEnded) {
			_updateWorld();
			if (tic.elapsedMilliSecond(TICKRATE)) {
				_mapData();
				_playerData();
			}
		}
	}
}

void bbm::CoreServer::_removeGarbage()
{
	while (std::find_if(_bombList.begin(), _bombList.end(), [](std::unique_ptr<ABomb> &elem){return elem->getStatus() == 0;}) != _bombList.end())
		_bombList.erase(std::find_if(_bombList.begin(), _bombList.end(), [](std::unique_ptr<ABomb> &elem){return elem->getStatus() == 0;}));
	while (std::find_if(_powerList.begin(), _powerList.end(), [](std::unique_ptr<APowerUp> &elem){return elem->getStatus() == 0;}) != _powerList.end())
		_powerList.erase(std::find_if(_powerList.begin(), _powerList.end(), [](std::unique_ptr<APowerUp> &elem){return elem->getStatus() == 0;}));
}

void bbm::CoreServer::_updateWorld()
{
	_updateBombs();
	_updatePlayers();
	_updatePowerUps();
	_removeGarbage();
}

void bbm::CoreServer::_updateBombs()
{
	for (auto &i : _bombList) {
		if (i->checkDetonation())
			i->detonate(_map, _playerList, _bombList, _powerList);
	}
}

void bbm::CoreServer::_movePlayer(bbm::ACharacter &player)
{
	float x = player.getPos().first;
	float y = player.getPos().second;

	if (player.getCardinal() == WEST)
		x = x - RADIUS_PLAYER - player.getSpeed();
	else if (player.getCardinal() == EAST)
		x = x + RADIUS_PLAYER + player.getSpeed();
	else if (player.getCardinal() == SOUTH)
		y = y + RADIUS_PLAYER + player.getSpeed();
	else if (player.getCardinal() == NORTH)
		y = y - RADIUS_PLAYER - player.getSpeed();
	if (_checkBorder(x, y) == false && _checkCollideWall(x, y) == false &&
	(_checkCollideBomb(x, y) == false ||
	_map[GET_MAP_VALUE(static_cast<int>(player.getPos().first), static_cast<int>(player.getPos().second))] == BOMB)) {
		if (player.getCardinal() == WEST)
			player.setPos(x + RADIUS_PLAYER, y);
		else if (player.getCardinal() == EAST)
			player.setPos(x - RADIUS_PLAYER, y);
		else if (player.getCardinal() == SOUTH)
			player.setPos(x, y - RADIUS_PLAYER);
		else if (player.getCardinal() == NORTH)
			player.setPos(x, y + RADIUS_PLAYER);
	}
}

bool bbm::CoreServer::_checkBorder(float x, float y)
{
	return x < 0.0f || y < 0.0f || x > MAP_SIZE + 0.0f || y > MAP_SIZE + 0.0f;
}

bool bbm::CoreServer::_checkCollideWall(float x, float y)
{
	return _map[GET_MAP_VALUE(static_cast<int>(x), static_cast<int>(y))] == BREAKABLE_WALL
		|| _map[GET_MAP_VALUE(static_cast<int>(x), static_cast<int>(y))] == UNBREAKABLE_WALL;
}

bool bbm::CoreServer::_checkCollideBomb(float x, float y)
{
	return _map[GET_MAP_VALUE(static_cast<int>(x), static_cast<int>(y))] == BOMB;
}

void bbm::CoreServer::_updatePlayers()
{
	for (auto &i : _playerList) {
		if (i.second.getLives() != 0 && i.second.getTimer().elapsedMilliSecond(TICKRATE) && i.second.getMove())
			_movePlayer(i.second);
	}
}

void bbm::CoreServer::_updatePowerUps()
{
	for (auto &i : _powerList) {
		for (auto &pl : _playerList) {
			if (i->getPos().first == static_cast<int>(pl.second.getPos().first) && i->getPos().second == static_cast<int>(pl.second.getPos().second))
				i->assignPlayer(pl.second);
		}
	}
}

void bbm::CoreServer::_managePlayer()
{
	Timer tic;

	std::cout << "Entering Lobby..." << std::endl;
	while (_playerList.size() < _nbPlayers && _isLaunched == false) {
		auto fd = _sock.acceptSocket();
		if (fd > 0) {
			bbm::Player p(fd);
			_playerList[fd] = p;
			_playerList[fd].setNick("Player_" + std::to_string(fd));
			_playerList[fd].setID(fd);
			std::cout << _playerList[fd].getNick() << " joined the game" << std::endl;
			if (_playerList.size() == 1)
				_adminFd = fd;
		}
		_interpretCmd(CMDS_LOBBY_SERVER);
		if (tic.elapsedMilliSecond(TICKRATE))
			_lobbyData();
	}
	std::cout << "Quitting Lobby..." << std::endl;
}

void bbm::CoreServer::_launchAI()
{
	size_t count = 0;
	int fd = -1;

	std::cout << "Launching AI..." << std::endl;
	for (size_t i = 0; i < _nbAI; i++)
		_aiList.push_back(std::make_unique<CoreAI>(_sock.getPort(), _sock.getIP()));
	while (count < _nbAI) {
		fd = _sock.acceptSocket();
		auto &slot = *_aiList[count];
		if (fd > 0) {
			bbm::AAI ai(fd);
			_playerList[fd] = ai;
			_playerList[fd].setNick("AI_" + std::to_string(fd));
			std::cout << "Accepted new client: " << _playerList[fd].getNick() << std::endl;
			_tp.addTask(slot);
			count++;
		}
		_interpretCmd(CMDS_LOBBY_SERVER);
	}
	std::cout << _nbAI << " AI launched" << std::endl;
}

void bbm::CoreServer::_interpretCmd(const std::vector<bbm::Command> &cmds)
{
	std::string tmp;
	std::vector<std::string> filterCmds;

	for (auto it = _playerList.begin(); it != _playerList.end() && !_isEnded; it++) {
		try {
			_sock.recvMsg(it->first, tmp);
		} catch (const std::runtime_error &) { continue; }
		Parser::parseCmds(filterCmds, tmp);
		for (auto &i : filterCmds)
			if (!_isEnded && i.size() > 1 && std::find(cmds.begin(), cmds.end(), Serializer::extractCommand(i)) != cmds.end() && _execCmd.find(Serializer::extractCommand(i)) != _execCmd.end()) {
				(this->*(_execCmd[Serializer::extractCommand(i)]))(it->first, i);
			}
	}
}

void bbm::CoreServer::_requestId(int fd, const std::string &message)
{
	if (message[0] == NOID)
		_sendId(fd);
	else {
		try { _sock.sendMsg(fd, Serializer::makeCommand(fd, MSG, FAILURE)); }
		catch (const std::runtime_error &) {}
	}
}

void bbm::CoreServer::_sendId(int fd)
{
	std::cout << "Player " << fd << " : Obtain an ID" << std::endl;
	_sock.sendMsg(fd, Serializer::makeCommand(SERVERID,
						  Command::SEND_ID, fd));
	if (fd == _adminFd) {
		_sock.sendMsg(fd, Serializer::makeCommand(SERVERID, MSG, YOU_ARE_ADMIN));
		std::cout << "Player " << fd << " : Obtain admin privilege" << std::endl;
	}
}

void bbm::CoreServer::_requestLaunch(int fd, const std::string &)
{
	if (fd == NOID)
		return;
	if (fd == _adminFd) {
		std::cout << "Player " << fd << " : Requested to launch the game" << std::endl;
		_launched();
	}
	else
		_sock.sendMsg(fd, Serializer::makeCommand(SERVERID, MSG, NOT_AUTHORIZED));
}

void bbm::CoreServer::_launched()
{
	std::vector<int> playerList;

	for (auto it = _playerList.begin(); it != _playerList.end(); it++){
		playerList.push_back(it->first);
	}
	auto totalPlayers = _playerList.size() + _nbAI;
	_sock.sendMsg(playerList, Serializer::makeCommand(SERVERID, LAUNCHED, totalPlayers));
	std::cout << "Server : Launching game for [" << totalPlayers << "] players..." << "\n";
	_isLaunched = true;
}

void bbm::CoreServer::_mapData()
{
	std::vector<int> playerList;

	for (auto &it : _playerList)
		playerList.push_back(it.first);
	_sock.sendMsg(playerList, Serializer::makeCommand(SERVERID, MAP_DATA, _map));
}

void bbm::CoreServer::_playerData()
{
	// x SPACE y SPACE CAN_KICK ; CAN_THROW ; BOMB_AMOUNT ; BOMB_RANGE ; LIVES
	std::vector<int> list;
	std::string tmp;

	for (auto &it : _playerList)
		list.push_back(it.first);
	for (auto &it : _playerList) {
		tmp.clear();
		tmp.push_back(it.first);
		tmp << _playerList[it.first];
		/* std::cout << "OUI OUI OUI" << _playerList[it.first] << std::endl; */
		_sock.sendMsg(list, Serializer::makeCommand(SERVERID, PLAYER_DATA, tmp));
	}
}

void bbm::CoreServer::_lobbyData()
{
	std::string tmp;
	std::vector<int> playerList;

	tmp.push_back(_playerList.size());
	for (auto &it : _playerList)
		playerList.push_back(it.first);
	for (auto &it : _playerList) {
		tmp.push_back(it.second.getNick().size());
		tmp.append(it.second.getNick());
	}
	tmp.push_back(_nbAI);
	_sock.sendMsg(playerList, Serializer::makeCommand(SERVERID, LOBBY_DATA, tmp));
}

void bbm::CoreServer::_addSlot(int fd, const std::string &message)
{
	if (fd == NOID) {
		_sock.sendMsg(fd, Serializer::makeCommand(SERVERID, MSG, NEED_ID));
		return;
	}
	if (fd == _adminFd && message[1] == Command::ADD_SLOT) {
		_nbPlayers += message[2];
		std::cout << "Player " << fd << " : Added " << std::to_string(message[2])
			  << " players" << std::endl;
	} else if (fd == _adminFd && message[1] == Command::ADD_AI) {
		_nbAI += message[2];
		std::cout << "Player " << fd << " : Added " << std::to_string(message[2])
			  << " ia" << std::endl;
	} else {
		_sock.sendMsg(fd, Serializer::makeCommand(fd, Command::MSG, NOT_AUTHORIZED));
	}
}

void bbm::CoreServer::_subSlot(int fd, const std::string &message)
{
	if (fd == NOID) {
		_sock.sendMsg(fd, Serializer::makeCommand(fd, MSG, NEED_ID));
		return;
	}
	if (fd == _adminFd && _playerList.size() < _nbPlayers
		&& message[1] == Command::ADD_SLOT) {
		_nbPlayers -= std::stoi(message.c_str() + 2);
		std::cout << "Player " << fd << " : Removed " << std::stoi(message.c_str() + 2)
		<< " players" << std::endl;
	} else if (fd == _adminFd && message[1] == Command::ADD_AI) {
		_nbAI -= std::stoi(message.c_str() + 2);
		if (static_cast<int>(_nbAI) < 0)
			_nbAI = 0;
		std::cout << "Player " << fd << " : Removed " << std::stoi(message.c_str() + 2)
		<< " AI" << std::endl;
	} else
		_sock.sendMsg(fd, Serializer::makeCommand(fd, Command::MSG, NOT_AUTHORIZED));
}

void bbm::CoreServer::_victory(std::vector<int>)
{
}

void bbm::CoreServer::_loose(std::vector<int>)
{

}

void bbm::CoreServer::_stopMoving(int fd, const std::string &message)
{
	if (fd == NOID) {
		_sock.sendMsg(fd, Serializer::makeCommand(fd, MSG, NEED_ID));
		return;
	}
	if (fd != Serializer::extractId(message)) {
		_sock.sendMsg(fd, Serializer::makeCommand(fd, Command::MSG, NOT_AUTHORIZED));
		return;
	}
	_playerList[fd].setMove(false);
}

void bbm::CoreServer::_requestMove(int fd, const std::string &message)
{
	if (fd == NOID) {
		_sock.sendMsg(fd, Serializer::makeCommand(fd, MSG, NEED_ID));
		return;
	}
	if (fd != message.c_str()[0])
		return;
	_playerList[fd].setMove(true);
	_playerList[fd].setCardinal(static_cast<Direction>(message[2]));
	std::cout << "Player " << fd << " : Chose to move " << std::to_string(message[2]) << std::endl;
}

void bbm::CoreServer::_requestBomb(int fd, const std::string &message)
{
	if (fd == NOID || Serializer::extractId(message) != fd) {
		_sock.sendMsg(fd, Serializer::makeCommand(fd, MSG, NEED_ID));
		return;
	}
	if (_playerList[fd].getLives() == 0)
		return;
	if (_map[GET_MAP_VALUE(static_cast<int>(_playerList[fd].getPos().first),
				static_cast<int>(_playerList[fd].getPos().second))] != BLANK)
		return;
	// A FAIRE AUTRE CONDITION DE PLACEMENT DE BOMBE ICI
	_map[GET_MAP_VALUE(static_cast<int>(_playerList[fd].getPos().first),
				static_cast<int>(_playerList[fd].getPos().second))] = BOMB;
	_bombList.push_back(std::make_unique<DefaultBomb>(static_cast<int>(_playerList[fd].getPos().first),
			static_cast<int>(_playerList[fd].getPos().second)));
	std::cout << "Player " << fd << " : Placed a bomb" << std::endl;
}

void bbm::CoreServer::_damage(int fd)
{
	std::vector<int> playerList;

	for (auto &it : _playerList)
		playerList.push_back(it.first);
	_sock.sendMsg(playerList, Serializer::makeCommand(SERVERID, Command::DAMAGE, fd));
	std::cout << "Player " << fd << " : Was hit" << std::endl;
}

void bbm::CoreServer::_msg(int fd, const std::string &message)
{
	if (fd == NOID) {
		_sock.sendMsg(fd, Serializer::makeCommand(fd, MSG, NEED_ID));
		return;
	}
	std::cout << "Player " << fd << " : [" << message << "]" << std::endl;
}

void bbm::CoreServer::_ping(int fd, const std::string &)
{
	if (fd == NOID) {
		_sock.sendMsg(fd, Serializer::makeCommand(fd, MSG, NEED_ID));
		return;
	}
	_pong(fd);
}

void bbm::CoreServer::_pong(int fd, const std::string &)
{
	if (fd == NOID) {
		_sock.sendMsg(fd, Serializer::makeCommand(fd, MSG, NEED_ID));
		return;
	}
	_ping(fd);
}

void bbm::CoreServer::_ping(int fd)
{
	_sock.sendMsg(fd, Serializer::makeCommand(SERVERID, PING, MSG_PING));
}

void bbm::CoreServer::_pong(int fd)
{
	_sock.sendMsg(fd, Serializer::makeCommand(SERVERID, PONG, MSG_PONG));
}

void bbm::CoreServer::_quit(int fd, const std::string &)
{
	if (fd == _adminFd)
		_isEnded = true;
}
