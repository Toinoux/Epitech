//
// EPITECH PROJECT, 2018
// Generator
// File description:
// INDIE PROJECT
//

#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include "Generator.hpp"
#include "Core/ICore.hpp"

void bbm::Generator::generateMap(std::string &map, bbm::mapPl &list) const
{
	std::srand(std::time(nullptr) + getpid());
	_fillWithWalls(map);
	_makeHoles(map, std::rand() % (MAX_HOLES - MIN_HOLES) + MIN_HOLES);
	_spawnPlayers(map, list);
	_linkPlayers(map, list);
}

void bbm::Generator::_spawnPlayers(std::string &map, bbm::mapPl &list) const
{
	std::vector<int> numbers;
	std::random_device rd;
	int pos = 0;

	for (int i = 0; i < MAP_SIZE * MAP_SIZE - 1; i++)
		numbers.push_back(i + 1);
	std::shuffle(numbers.begin(), numbers.end(), rd);
	for (auto &elem : list) {
		_createPlayer(map, numbers[pos], elem.second);
		pos += 1;
	}
}

void bbm::Generator::_createPlayer(std::string &map, int pos,
					ACharacter &player) const
{
	float x = pos % MAP_SIZE + 0.0f;
	float y = pos / MAP_SIZE + 0.0f;

	if (pos == 0)
		x = 0;
	std::cout << "Float generator player pos :"<<x << ":" << y << std::endl;
	player.setPos(x + 0.5f, y + 0.5f);
	map[GET_MAP_VALUE(static_cast<int>(x), static_cast<int>(y))] = BLANK;
	_generateCross(map, static_cast<int>(x), static_cast<int>(y));
}

void bbm::Generator::_generateCross(std::string &map, int x, int y) const {
	if (x + 1 < MAP_SIZE)
		map[GET_MAP_VALUE(x + 1, y)] = BLANK;
	if (x - 1 > 0)
		map[GET_MAP_VALUE(x - 1, y)] = BLANK;
	if (y + 1 < MAP_SIZE)
		map[GET_MAP_VALUE(x, y + 1)] = BLANK;
	if (y - 1 > 0)
		map[GET_MAP_VALUE(x, y - 1)] = BLANK;
}

void bbm::Generator::_linkPlayers(std::string &map, mapPl &list) const
{
	mapPl::iterator it = list.begin();
	mapPl::iterator itAfter = ++list.begin();
	for (unsigned int i = 0; i < list.size() - 1; i++) {
		if (_findPath(map, it->second.getPos(), itAfter->second.getPos()) == false) {
			_createPath(map, it->second.getPos(), itAfter->second.getPos());
			map[GET_MAP_VALUE(it->second.getPos().first, it->second.getPos().second)];
			map[GET_MAP_VALUE(itAfter->second.getPos().first, itAfter->second.getPos().second)];
		}
		it++;
		itAfter++;
	}
}

bool bbm::Generator::_findPath(const std::string &map, pair2f pos1, pair2f pos2) const
{
	if (pos1.first == pos2.first && pos1.second == pos2.second)
		return true;
	if (pos1.first > pos2.first && pos1.first - 1 > 0 &&
		(map[GET_MAP_VALUE(static_cast<int>(pos1.first), static_cast<int>(pos1.second))] == BREAKABLE_WALL ||
		map[GET_MAP_VALUE(static_cast<int>(pos1.first), static_cast<int>(pos1.second))] == BLANK)) {
		pos1.first -= 1.0f;
		if (_findPath(map, pos1, pos2))
			return true;
	}
	if (pos1.first < pos2.first && pos1.first + 1 < MAP_SIZE &&
		(map[GET_MAP_VALUE(static_cast<int>(pos1.first), static_cast<int>(pos1.second))] == BREAKABLE_WALL ||
		map[GET_MAP_VALUE(static_cast<int>(pos1.first), static_cast<int>(pos1.second))] == BLANK)) {
		pos1.first += 1.0f;
		if (_findPath(map, pos1, pos2))
			return true;
	}
	if (pos1.second > pos2.second && pos1.second - 1 > 0 &&
		(map[GET_MAP_VALUE(static_cast<int>(pos1.first), static_cast<int>(pos1.second))] == BREAKABLE_WALL ||
		map[GET_MAP_VALUE(static_cast<int>(pos1.first), static_cast<int>(pos1.second))] == BLANK)) {
		pos1.second -= 1.0f;
		if (_findPath(map, pos1, pos2))
			return true;
	}
	if (pos1.second < pos2.second && pos1.second + 1 < MAP_SIZE &&
		(map[GET_MAP_VALUE(static_cast<int>(pos1.first), static_cast<int>(pos1.second))] == BREAKABLE_WALL ||
		map[GET_MAP_VALUE(static_cast<int>(pos1.first), static_cast<int>(pos1.second))] == BLANK)) {
		pos1.second += 1.0f;
		if (_findPath(map, pos1, pos2))
			return true;
	}
	return false;
}

void bbm::Generator::_createPath(std::string &map, pair2f pos1, pair2f pos2) const
{
	map[GET_MAP_VALUE(static_cast<int>(pos1.first), static_cast<int>(pos1.second))] = BLANK;
	if (pos1.first - pos2.first < 0 && pos1.first + 1 < MAP_SIZE) {
		pos1.first += 1.0f;
		_createPath(map, pos1, pos2);
	}
	else if (pos1.first - pos2.first > 0 && pos1.first - 1 > 0) {
		pos1.first -= 1.0f;
		_createPath(map, pos1, pos2);
	}
	else if (pos1.second - pos2.second < 0 && pos1.second < MAP_SIZE) {
		pos1.second += 1.0f;
		_createPath(map, pos1, pos2);
	}
	else if (pos1.second - pos2.second > 0 && pos1.second > 0) {
		pos1.second -= 1.0f;
		_createPath(map, pos1, pos2);
	}
}

void bbm::Generator::_fillWithWalls(std::string &map) const
{
	for (int i = 0; i < static_cast<int>(map.size()); i++)
		map[i] = BREAKABLE_WALL;
}

void bbm::Generator::_makeHoles(std::string &map, int nbHoles) const
{
	for (int i = 0; i < nbHoles; i++) {
		int x = std::rand() % MAP_SIZE - 1;
		int y = std::rand() % MAP_SIZE - 1;
		int step = std::rand() % (MAX_STEPS - MIN_STEPS) + MIN_STEPS;
		_createHole(map, x, y, step);

	}
}

void bbm::Generator::_createHole(std::string &map, int x, int y, int step)
	const
{
	int card = std::rand() % 4 + 1;

	if (step == 0 || x <= 0 || y <= 0)
		return;
	map[GET_MAP_VALUE(x, y)] = UNBREAKABLE_WALL;
	if (card == 1 && y - 1 > 0)
		_createHole(map, x, y - 1, step - 1);
	else if (card == 2 && x + 1 < MAP_SIZE - 1)
		_createHole(map, x + 1, y, step - 1);
	else if (card == 3 && y + 1 < MAP_SIZE - 1)
		_createHole(map, x, y + 1, step - 1);
	else if (card == 4 && x - 1 > 0)
		_createHole(map, x - 1, y, step - 1);
}

void bbm::Generator::printMap(const std::string &map)
{
	for (int i = 0; i < static_cast<int>(map.size()); i++) {
		std::cout << std::to_string(map[i]);
		if ((i + 1) % MAP_SIZE == 0)
			std::cout << std::endl;
	}
}
