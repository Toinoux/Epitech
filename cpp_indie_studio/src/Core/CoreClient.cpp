/*
** EPITECH PROJECT, 2018
** CoreClient
** File description:
** class CoreClient
*/

#include <thread>
#include <utility>

#include "CoreClient.hpp"

bbm::CoreClient::CoreClient(const int port, const std::string &ipAddr, ACharacter character)
	: _character(character), _isLaunched(false), _isEnded(false),
	  _id(NOID), _nbPlayers(0), _map(MAP_SIZE * MAP_SIZE, UNBREAKABLE_WALL),
	  _sock(ipAddr, port)
{}

bbm::CoreClient::~CoreClient()
{
	std::cout << "Destroying Client" << std::endl;
}

void bbm::CoreClient::_getNewID()
{
	std::string tmp = "";
	_id = NOID;

	while (_id == NOID) {
		_sock.sendMsg(Serializer::makeCommand(_id, Command::REQUEST_ID, ""));
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		_sock.recvMsg(tmp);
		if (bbm::Serializer::isOk(tmp) && tmp[1] == Command::SEND_ID) {
			_id = tmp[2];
		} else
		tmp.clear();
	}
}


void bbm::CoreClient::_interpretCmd(const std::vector<bbm::Command> &cmds)
{
	std::string tmp;
	std::vector<std::string> filterCmds;

	_sock.recvMsg(tmp);
	Parser::parseCmds(filterCmds, tmp);
	for (auto &i : filterCmds)
		if (i.size() > 1 && std::find(cmds.begin(), cmds.end(), Serializer::extractCommand(i)) != cmds.end() && _execCmd.find(Serializer::extractCommand(i)) != _execCmd.end()) {
			(this->*(_execCmd[Serializer::extractCommand(i)]))(Serializer::extractId(tmp),
									   i);
		}
}

void bbm::CoreClient::_mapData(int fd, const std::string &message)
{
	if (fd != SERVERID)
		return;
	_map = message.c_str() + 2;
}

void bbm::CoreClient::_lobbyData(int fd, const std::string &)
{
	std::string tmp;

	if (fd != SERVERID) {
		return;
	}
}

void bbm::CoreClient::_playerData(int fd, const std::string &message)
{
	if (fd != SERVERID) {
		return;
	}
	int id = static_cast<int>(message[2]);
	if (_playerList.find(id) == _playerList.end()) {
		ACharacter player(id);
		_playerList[id] = player;
	}
	std::string tmp = message;
	tmp >> _playerList[id];
}

void bbm::CoreClient::_victory(int fd, const std::string &)
{
	if (fd != SERVERID)
		return;
	_isEnded = true;
	std::cout << "You win" << std::endl;
}

void bbm::CoreClient::_loose(int fd, const std::string &)
{
	if (fd != SERVERID)
		return;
	_isEnded = true;
	std::cout << "Game over" << std::endl;
}

void bbm::CoreClient::_requestMove(Direction direction)
{
	if (_playerList[_id].getLives() == 0)
		return;
	std::cout << "[Player] Asking to move :" << static_cast<int>(direction) << std::endl;
	_sock.sendMsg(Serializer::makeCommand(_id, REQUEST_MOVE, static_cast<int>(direction)));
}

void bbm::CoreClient::_stopMoving()
{
	_sock.sendMsg(Serializer::makeCommand(_id, STOP_MOVING, ""));
}

void bbm::CoreClient::_requestBomb()
{
	if (_playerList[_id].getLives() == 0)
		return;
	_sock.sendMsg(Serializer::makeCommand(_id, REQUEST_BOMB, ""));
}

void bbm::CoreClient::_requestId()
{
	_sock.sendMsg(Serializer::makeCommand(_id, REQUEST_ID, ""));
}

void bbm::CoreClient::_damage(int fd, const std::string &)
{
	if (fd != SERVERID)
		return;

}

void bbm::CoreClient::_requestLaunch()
{
	_sock.sendMsg(Serializer::makeCommand(_id, REQUEST_LAUNCH, ""));
}

void bbm::CoreClient::_addSlot(int nbSlot, Command cmd)
{
	_sock.sendMsg(Serializer::makeCommand(_id, cmd, nbSlot));
}

void bbm::CoreClient::_subSlot(int nbSlot)
{
	_sock.sendMsg(Serializer::makeCommand(_id, SUB_SLOT, nbSlot));
}

void bbm::CoreClient::_launched(int fd, const std::string &message)
{
	if (fd != SERVERID)
		return;
	_nbPlayers = static_cast<char>(message[2]);
	_isLaunched = true;
	std::cout << "[Client] Launched!" << std::endl;
}

void bbm::CoreClient::_msg(int , const std::string &message)
{
	if (message[0] != SERVERID) {
		std::cout << "[Client] MSG (NOT FROM SERVER): [" << message << "]." << std::endl;
		return;
	}
	std::cout << "[Client] MSG: [" << message.c_str() + 2 << "]." << std::endl;
}

void bbm::CoreClient::_ping(int fd)
{
	if (fd == _id)
		_sock.sendMsg(Serializer::makeCommand(_id, PING, MSG_PING));
	else
		_sock.sendMsg(fd, Serializer::makeCommand(_id, PING, MSG_PING));
}

void bbm::CoreClient::_pong(int fd)
{
	if (fd == _id)
		_sock.sendMsg(Serializer::makeCommand(_id, PING, MSG_PONG));
	else
		_sock.sendMsg(fd, Serializer::makeCommand(_id, PONG, MSG_PONG));
}

void bbm::CoreClient::_ping(int fd, const std::string &)
{
	if (fd == NOID) {
		_sock.sendMsg(fd, Serializer::makeCommand(fd, MSG, NEED_ID));
		return;
	}
	_pong(fd);
}

void bbm::CoreClient::_pong(int fd, const std::string &)
{
	if (fd == NOID) {
		_sock.sendMsg(fd, Serializer::makeCommand(fd, MSG, NEED_ID));
		return;
	}
	_ping(fd);
}

void bbm::CoreClient::quit()
{
	_sock.sendMsg(Serializer::makeCommand(_id, QUIT, ""));
}

const std::unordered_map<int, bbm::ACharacter> &bbm::CoreClient::getPlayers() const
{
	return _playerList;
}

void bbm::CoreClient::_sendId(int fd, const std::string &message)
{
	if (fd != SERVERID)
		return;
	_id = message.c_str()[2];
	std::cout << "[Client] Setting Id..." << std::endl;
}

void bbm::CoreClient::_quit(int, const std::string &)
{
	_isEnded = true;
}
