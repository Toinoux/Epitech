//
// EPITECH PROJECT, 2018
// DefaultBomb
// File description:
// file
//

#include "Core/ICore.hpp"
#include "DefaultBomb.hpp"

bbm::DefaultBomb::DefaultBomb(int x, int y) : ABomb(x, y)
{}

bool bbm::DefaultBomb::checkDetonation()
{
	if (_clock.elapsedSecond(SECONDS_BEFORE_EXPLOSION))
		return true;
	return false;
}

void bbm::DefaultBomb::detonate(std::string &map,
			std::unordered_map<int, ACharacter> &players,
			std::vector<std::unique_ptr<ABomb>> &bombs,
			std::vector<std::unique_ptr<APowerUp>> &powers)
{
	if (!_isActive)
		return;
	_isActive = false;
	map[GET_MAP_VALUE(_x, _y)] = BLANK; // set map au powerup
	for (int i = 0; i >= -_range; i--)
		if (_checkCase(_x + i, _y, map, players, bombs, powers) == true)
			break;
	for (int i = 1; i <= _range; i++)
		if (_checkCase(_x + i, _y, map, players, bombs, powers) == true)
			break;
	for (int i = -1; i >= -_range; i--)
		if (_checkCase(_x, _y + i, map, players, bombs, powers) == true)
			break;
	for (int i = 1; i <= _range; i++)
		if (_checkCase(_x, _y + i, map, players, bombs, powers) == true)
			break;
	//creer ici le nouveau powerup
}