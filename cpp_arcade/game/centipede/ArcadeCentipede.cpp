//
// EPITECH PROJECT, 2018
// ArcadeCentipede
// File description:
// Centipede game
//

#include "Utilities.hpp"
#include "ArcadeCentipede.hpp"
#include <unistd.h>

void arc::Centipede::initBlocksPaths()
{
	_blocks_paths = {
		"./game/centipede/assets/Head_DL",
		"./game/centipede/assets/Head_D",
		"./game/centipede/assets/Head_DR",
		"./game/centipede/assets/Head_L",
		"./game/centipede/assets/Head_R",
		"./game/centipede/assets/Body_DL",
		"./game/centipede/assets/Body_D",
		"./game/centipede/assets/Body_DR",
		"./game/centipede/assets/Body_L",
		"./game/centipede/assets/Body_R",
		"./game/centipede/assets/Lsr",
		"./game/centipede/assets/Obtscl_1",
		"./game/centipede/assets/Obtscl_2",
		"./game/centipede/assets/Obtscl_3",
		"./game/centipede/assets/Obtscl_4",
		"./game/centipede/assets/Obtscl_5",
		"./game/centipede/assets/Plyr",
		"./game/centipede/assets/Terrain",
	};
}

arc::Centipede::Centipede() :
	_firstTurn(true),
	_playing(true),
	_isFiring(false),
	_isShotOnScreen(false),
	_isChiloOnScreen(false),
	_prevChiloDir(ChiloDir::LEFT),
	_shotPos(0, 0),
	_playerPos(col / 2 - 0.5, row - 1)
{
	_score = 0;
	_scores_path = "./game/centipede/scores.txt";
	initBlocksPaths();
	_maps.push_back(arc::Utilities::createMap(0, 0));
	_mapsSizes.push_back(arc::Vec2<size_t>(row, col));
	srand(time(NULL));
}

arc::Centipede::Chilopod::Chilopod(int len) :
_length(len),
_dir(ChiloDir::DOWN),
_pos(col * 0.7, 0)
{
}

std::shared_ptr<arc::IGame> arc::Centipede::getInstance() const
{
	std::shared_ptr<arc::IGame> instance(new arc::Centipede);
	return (instance);
}

bool arc::Centipede::checkIfFree
(arc::Vec2<float> pos, std::vector<arc::Block> map)
{
	for (arc::Block block : map)
		if ((pos.x - 1 <= block.pos.x && block.pos.x <= pos.x + 1) &&
		(pos.y - 1 <= block.pos.y && block.pos.y <= pos.y + 1))
			return false;
	return true;
}

std::vector<arc::Block> arc::Centipede::initObstacleOnMap()
{
	int nbObstcl = (row + col) / 2;
	std::vector<arc::Block> obstcl;
	arc::Vec2<float> pos(
		arc::Utilities::randInt(0, arc::Centipede::col - 1),
		arc::Utilities::randInt(0, arc::Centipede::row - 3));

	for (int i = 0; i < nbObstcl; i++) {
		while (checkIfFree(pos, obstcl) == false) {
			pos.x = arc::Utilities::randInt
				(0, arc::Centipede::col - 1);
			pos.y = arc::Utilities::randInt
				(0, (arc::Centipede::row - 1) * 0.7);
		}
		arc::Block tmp(_blocks[15], pos);
		obstcl.push_back(tmp);
	}
	return obstcl;
}

std::vector<arc::Block> arc::Centipede::putObstcl(std::vector<arc::Block> map)
{
	map.insert(map.end(), _obstcl.begin(), _obstcl.end());
	return map;
}

void arc::Centipede::handleKey(int key)
{
	switch (key) {
	case arc::KeyCode::LEFT:
		_playerPos.x - 0.3 < 0 ? 0 : _playerPos.x -= 0.3;
		break;
	case arc::KeyCode::RIGHT:
		_playerPos.x + 0.3 > col - 0.8 ? 0 : _playerPos.x += 0.3;
		break;
	case arc::KeyCode::UP:
		_playerPos.y - 0.3 < row * 0.7 ? 0 : _playerPos.y -= 0.3;
		break;
	case arc::KeyCode::DOWN:
		_playerPos.y + 0.3 > row - 1 ? 0 :  _playerPos.y += 0.3;
		break;
	case ' ':
		_isFiring = true;
		break;
	}
}

void arc::Centipede::changeObstcl(int block, int textIdx)
{
	if (textIdx == _blocks[15])
		_obstcl[block].textureIdx -= 1;
	else if (textIdx == _blocks[14])
		_obstcl[block].textureIdx -= 1;
	if (textIdx == _blocks[13])
		_obstcl[block].textureIdx -= 1;
	else if (textIdx == _blocks[12])
		_obstcl.erase(_obstcl.begin() + block);
}

bool arc::Centipede::isTouchingObtscl(arc::Vec2<float> pos)
{
	int count = 0;

	for (arc::Block block : _obstcl) {
		if (block.pos.x - 1 <= pos.x && pos.x <= block.pos.x + 1 &&
		    block.pos.y - 2 <= pos.y && pos.y <= block.pos.y) {
			changeObstcl(count, block.textureIdx);
			return true;
		}
		count++;
	}
	return false;
}

void arc::Centipede::changeChilopod(int block)
{
	_chilopods.erase(_chilopods.begin() + block);
}

void arc::Centipede::whereTouchingChilopod(int block,
	arc::Vec2<float> pos __attribute((unused)))
{
	arc::Centipede::Chilopod chilopods = *(_chilopods.begin() + block);

	_score += 1;
	_chilopods.erase(_chilopods.begin() + block);
}

bool arc::Centipede::isTouchingChilopod(arc::Vec2<float> pos)
{
	int count = 0;

	for (arc::Centipede::Chilopod chilo : _chilopods) {
		if (chilo._pos.x - 1 <= pos.x && pos.x <= chilo._pos.x + 1 &&
		    chilo._pos.y - 2 <= pos.y && pos.y <= chilo._pos.y) {
			whereTouchingChilopod(count, pos);
			return true;
		}
		count++;
	}
	return false;
}

std::vector<arc::Block> arc::Centipede::manageShot
(std::vector<arc::Block> map)
{
	if (!_isShotOnScreen) {
		_shotPos.x = _playerPos.x;
		_shotPos.y = _playerPos.y;
		_isShotOnScreen = true;
	}
	arc::Block b(_blocks[10], _shotPos);
	map.push_back(b);
	_shotPos.y -= 2;
	if (_shotPos.y < 0 || isTouchingObtscl(_shotPos)
	|| isTouchingChilopod(_shotPos))
		_isFiring = false;
	return map;
}

std::vector<arc::Block> arc::Centipede::managePlayer
(std::vector<arc::Block> map)
{

	if (_isFiring)
		map = manageShot(map);
	else
		_isShotOnScreen = false;
	arc::Block b(_blocks[16], _playerPos);
	map.push_back(b);

	return map;
}

void arc::Centipede::Chilopod::createChilopod(int textIdx)
{
	int i = 0;

	arc::Block head(textIdx, _pos);
	_wBody.push_back(head);
	while (i < _length) {
		arc::Block body(textIdx + 5, _pos);
		_wBody.push_back(body);
		i++;
	}
}

void arc::Centipede::Chilopod::createChilopod(int textIdx, int length)
{
	int i = 0;

	arc::Block head(textIdx, _pos);
	_wBody.push_back(head);
	while (i < length) {
		arc::Block body(textIdx + 5, _pos);
		_wBody.push_back(body);
		i++;
	}
}

arc::Centipede::Chilopod arc::Centipede::getHeadNewPos
(arc::Centipede::Chilopod chilopod)
{
	switch (chilopod._dir) {
	case ChiloDir::LEFT:
		chilopod._pos.x -= 0.9;
		break;
	case ChiloDir::RIGHT:
		chilopod._pos.x += 0.9;
		break;
	case ChiloDir::DOWN:
		chilopod._pos.y += 1;
		break;
	case ChiloDir::DOWNRIGHT:
		chilopod._pos.y += 0.7;
		chilopod._pos.x += 0.7;
		break;
	case ChiloDir::DOWNLEFT:
		chilopod._pos.y += 0.7;
		chilopod._pos.x -= 0.7;
		break;
	}
	return chilopod;
}

arc::Centipede::Chilopod arc::Centipede::getNewHeadDir
(arc::Centipede::Chilopod chilopod)
{
	if (chilopod._dir == ChiloDir::DOWN) {
		chilopod._dir = _prevChiloDir;
		_prevChiloDir == ChiloDir::LEFT ? _prevChiloDir =
			ChiloDir::RIGHT : _prevChiloDir = ChiloDir::LEFT;
	} else if (chilopod._pos.x > arc::Centipede::col - 2
		|| chilopod._pos.x < 0 || chilopod._dir == ChiloDir::DOWNLEFT
		|| chilopod._dir == ChiloDir::DOWNRIGHT) {
		chilopod._dir = ChiloDir::DOWN;
	}
	if (chilopod._dir == ChiloDir::LEFT) {
		Vec2<float> pos(chilopod._pos.x - 1, chilopod._pos.y);
		if (!checkIfFree(pos, _obstcl))
			chilopod._dir = ChiloDir::DOWNLEFT;
	} else if (chilopod._dir == ChiloDir::RIGHT) {
		Vec2<float> pos(chilopod._pos.x + 1, chilopod._pos.y);
		if (!checkIfFree(pos, _obstcl))
			chilopod._dir = ChiloDir::DOWNRIGHT;
	}
	return chilopod;
}

arc::Centipede::Chilopod arc::Centipede::updateChilopodPos
(arc::Centipede::Chilopod chilopod)
{
	int count = chilopod._wBody.size() - 1;

	while (count > 0) {
		if (count == 1) {
			(*(chilopod._wBody.begin() + count)).pos =
				(*(chilopod._wBody.begin() + count - 1)).pos;
			(*(chilopod._wBody.begin())).pos = chilopod._pos;
		} else
			(*(chilopod._wBody.begin() + count)).pos =
				(*(chilopod._wBody.begin() + count - 1)).pos;
		count--;
	}
	return chilopod;
}

std::vector<arc::Block>	arc::Centipede::renderChilopod
(arc::Centipede::Chilopod chilo, std::vector<arc::Block> map)
{
	for (arc::Block block : chilo._wBody) {
		if (block.pos.x != -1 && block.pos.y != -1)
			map.push_back(block);
	}
	return map;
}

std::vector<arc::Centipede::Chilopod> arc::Centipede::checkIfOnScreen
(int count, std::vector<arc::Centipede::Chilopod>_chilopods)
{
	arc::Centipede::Chilopod chilo = *(_chilopods.begin() + count);

	if (chilo._pos.y > row)
		_chilopods.erase(_chilopods.begin() + count);
	return _chilopods;
}

std::vector<arc::Block> arc::Centipede::manageCentipedes
(std::vector<arc::Block> map)
{
	int count = 0;
	if (!_isChiloOnScreen) {
		Chilopod chilo(arc::Utilities::randInt(3, 10));
		chilo.createChilopod(_blocks[1]);
		_chilopods.push_back(chilo);
		_isChiloOnScreen = true;
	}
	for (Chilopod chilopod : _chilopods) {
		(*(_chilopods.begin() + count)) =
			getNewHeadDir((*(_chilopods.begin() + count)));
		(*(_chilopods.begin() + count)) =
			getHeadNewPos((*(_chilopods.begin() + count)));
		(*(_chilopods.begin() + count)) =
			updateChilopodPos((*(_chilopods.begin() + count)));
		map = renderChilopod(chilopod, map);
		_chilopods = checkIfOnScreen(count, _chilopods);
		count++;
	}
	_chilopods.empty() == true ? _isChiloOnScreen = false : 0;
	return map;
}

arc::GameStatus arc::Centipede::update(int key)
{
	std::vector<arc::Block> map;

	if (!_playing || key == arc::KeyCode::ESCAPE)
		return (arc::GameStatus::GAMEOVER);
	handleKey(key);
	if (_firstTurn)
		_obstcl = initObstacleOnMap();
	map = managePlayer(map);
	map = manageCentipedes(map);
	map = putObstcl(map);
	_maps[0] = map;
	_firstTurn = false;
	usleep(60000);
	return arc::GameStatus::PLAYING;
}
