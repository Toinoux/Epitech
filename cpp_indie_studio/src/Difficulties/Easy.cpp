//
// EPITECH PROJECT, 2018
// Easy
// File description:
// file
//

#include "Easy.hpp"

<<<<<<< HEAD
/*
        y = x / map size
        if x == 0 x = 0 else x = x % map size
*/
bbm::Easy::Easy(SocketManager &sock) : ADifficulties(), _sock(sock)
=======
bbm::Easy::Easy() : ADifficulties()
>>>>>>> b7fc4841a46e9b29962014210eef911b9a5946b0
{}

void bbm::Easy::setId(int id)
{
        _id = id;
}

void bbm::Easy::_tryToPutBomb(std::pair<int, int> pos)
{
<<<<<<< HEAD
        // SEND MSG BOMB TO SERVER
        
        std::cout << "BOMB: " << pos.first << " | " << pos.second << std::endl;
=======
	std::cout << "BOMB: " << pos.first << " | " << pos.second << std::endl;
>>>>>>> b7fc4841a46e9b29962014210eef911b9a5946b0
}

void bbm::Easy::_tryToMove(std::pair<int, int> pos)
{
<<<<<<< HEAD
        // SEND MSG BOMB TO SERVER
        std::string sign;

        std::cout << "Try to move (" << _id << ") [" << _xAI << "-" << _yAI <<"] -> [" << _xGoal << "-" << _yGoal <<"]\n";
        if (_xAI < _xGoal) {
                sign = bbm::Direction::WEST;
                std::cout << "GO West\n";
        }
        else if (_xAI > _xGoal) {
                sign = bbm::Direction::EAST;
                std::cout << "GO East\n";
        }
        if (_yAI < _yGoal) {
                sign = bbm::Direction::SOUTH;
                std::cout << "GO South\n";
        }
        else if (_yAI > _yGoal) {
                sign = bbm::Direction::NORTH;
                std::cout << "GO North\n";
        }
        _sock.sendMsg(_id, Serializer::makeCommand(_id, REQUEST_MOVE, sign));
        std::cout << "MOVE: " << pos.first << " | " << pos.second << std::endl;
}

std::pair<int, int> bbm::Easy::_setNewGoal(std::vector<std::pair<int, int>> pos)
{
<<<<<<< HEAD
        _rand = std::rand() % pos.size();
        std::pair<int, int> newPos;
        if (pos.size() > 0) {
                _xGoal = pos[_rand].first;
                _yGoal = pos[_rand].second;
                newPos.first = pos[_rand].first;
                newPos.second = pos[_rand].second;
        }
        std::cout << "newPosX: " << newPos.first << " newPosY: " << newPos.second << std::endl;
        return newPos;
}

std::vector<std::pair<int, int>> bbm::Easy::_checkPossibilities(std::string map, bbm::Texture)
{
	std::vector<std::pair<int, int>> blankPos;
	std::vector<std::pair<int, int>> wallPos;

	if (_xAI + 1 < MAP_SIZE && map[GET_MAP_VALUE(_xAI + 1, _yAI)] == bbm::BLANK)
		blankPos.push_back(std::pair<int, int>(_xAI + 1, _yAI));
	if (_yAI + 1 < MAP_SIZE && map[GET_MAP_VALUE(_xAI, _yAI + 1)] == bbm::BLANK)
		blankPos.push_back(std::pair<int, int>(_xAI, _yAI + 1));
	if (_xAI - 1 >= 0  && map[GET_MAP_VALUE(_xAI - 1, _yAI)] == bbm::BLANK)
		blankPos.push_back(std::pair<int, int>(_xAI - 1, _yAI));
	if (_yAI - 1 >= 0 && map[GET_MAP_VALUE(_xAI, _yAI - 1)] == bbm::BLANK)
		blankPos.push_back(std::pair<int, int>(_xAI, _yAI - 1));
	if (_xAI + 1 < MAP_SIZE && map[GET_MAP_VALUE(_xAI + 1, _yAI)] == bbm::BREAKABLE_WALL)
		wallPos.push_back(std::pair<int, int>(_xAI + 1, _yAI));
	if (_yAI + 1 < MAP_SIZE && map[GET_MAP_VALUE(_xAI, _yAI + 1)] == bbm::BREAKABLE_WALL)
		wallPos.push_back(std::pair<int, int>(_xAI, _yAI + 1));
	if (_xAI - 1 >= 0  && map[GET_MAP_VALUE(_xAI - 1, _yAI)] == bbm::BREAKABLE_WALL)
		wallPos.push_back(std::pair<int, int>(_xAI - 1, _yAI));
	if (_yAI - 1 >= 0 && map[GET_MAP_VALUE(_xAI, _yAI - 1)] == bbm::BREAKABLE_WALL)
		wallPos.push_back(std::pair<int, int>(_xAI, _yAI - 1));
	std::cout << "size: blank " << blankPos.size() << " - wall " << wallPos.size() << "\n";
	if (wallPos.size() > 0 && blankPos.size() < 2)
		_tryToPutBomb(_setNewGoal(wallPos));
	else if (blankPos.size() > 0)
		_tryToMove(_setNewGoal(blankPos));
	return blankPos;
}

std::pair<float, float> bbm::Easy::findNewPos(float xAI, float yAI, std::string map)
{
	std::vector<std::pair<int, int>> pos;
	std::srand(std::time(nullptr));
	_rand = std::rand() % 3;
	_xAI = xAI;
	_yAI = yAI;
	pos = _checkPossibilities(map, bbm::BLANK);
	return std::pair<float, float>(_xAI, _yAI);
}
