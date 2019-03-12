//
// EPITECH PROJECT, 2018
// ABomb
// File description:
// Abstract
//

#include "Core/ICore.hpp"
#include "ABomb.hpp"
#include "Object/APowerUp/APowerUp.hpp"

bbm::ABomb::ABomb(int x, int y) : _x(x), _y(y), _range(2), _isActive(true)
{}

std::pair<int, int> bbm::ABomb::getPos() const
{
	return std::make_pair(_x, _y);
}

void bbm::ABomb::setPos(int x, int y)
{
	_x = x;
	_y = y;
}

bool bbm::ABomb::_checkCase(int x, int y, std::string &map,
			std::unordered_map<int, ACharacter> &players,
			std::vector<std::unique_ptr<ABomb>> &bombs,
			std::vector<std::unique_ptr<APowerUp>> &powers)
{
	_checkPlayers(players, x, y);
	_checkBomb(x, y, map, players, bombs, powers);
	if (_removeFromMap(map, x, y) == true)
		return true;
	return false;
}

bool bbm::ABomb::_removeFromMap(std::string &map, int x, int y)
{
	if (x < 0 || y < 0 || x > MAP_SIZE - 1 || y > MAP_SIZE - 1)
		return false;
	if (map[GET_MAP_VALUE(x, y)] == BREAKABLE_WALL) {
		map[GET_MAP_VALUE(x, y)] = BLANK;
		return true;
	}
	return false;
}

void bbm::ABomb::_checkPlayers(std::unordered_map<int, ACharacter> &players,
				int x, int y)
{
	for (auto &i : players) {
		if (static_cast<int>(i.second.getPos().first) == x &&
			static_cast<int>(i.second.getPos().second) == y)
			i.second.hurt();
	}
}

void bbm::ABomb::_checkBomb(int x, int y, std::string &map,
			std::unordered_map<int, ACharacter> &players,
			std::vector<std::unique_ptr<ABomb>> &bombs,
			std::vector<std::unique_ptr<APowerUp>> &powers)
{
	for (auto &i : bombs) {
		if (static_cast<int>(i->getPos().first) == x &&
			static_cast<int>(i->getPos().second) == y)
			i->detonate(map, players, bombs, powers);
	}
}

bool bbm::ABomb::getStatus() const
{
	return _isActive;
}