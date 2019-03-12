//
// EPITECH PROJECT, 2018
// ArcadeSolarFox
// File description:
// SolarFox game
//

#include <fstream>
#include <thread>
#include <cmath>
#include <unistd.h>
#include <iostream>
#include "Utilities.hpp"
#include "ArcadeSolarFox.hpp"

void arc::SolarFox::loadLevel()
{
	std::ifstream ifs("./game/solarfox/assets/levels/1.txt");
	std::string line;
	arc::Vec2<float> pos(1, 1);

	while (std::getline(ifs, line)) {
		pos.x = 1;
		for (size_t i = 0; i < line.size() 
			&& i < arc::SolarFox::col - 2; i++) {
			if (line[i] == '1')
				_levelMap.push_back(arc::Block(_blocks[GEM],
					arc::Vec2<float>(pos.x, pos.y)));
			pos.x += 1;
		}
		pos.y += 1;
	}
}

void arc::SolarFox::initBlocksPaths()
{
	_blocks_paths = {
		"./game/solarfox/assets/bg",
		"./game/solarfox/assets/bulleto",
		"./game/solarfox/assets/hbulleto",
		"./game/solarfox/assets/bulletv",
		"./game/solarfox/assets/hbulletv",
		"./game/solarfox/assets/gem",
		"./game/solarfox/assets/gunbot",
		"./game/solarfox/assets/guntop",
		"./game/solarfox/assets/spaceshipr",
		"./game/solarfox/assets/spaceshipl",
		"./game/solarfox/assets/spaceshipu",
		"./game/solarfox/assets/spaceshipd"
	};
}

arc::SolarFox::SolarFox() :
_playing(true),
_guntop(arc::Vec2<float>(arc::SolarFox::col - 1, 0)),
_gunbot(arc::Vec2<float>(0, arc::SolarFox::row - 1)),
_gunspd(0.1f),
_dir(1),
_spaceship(arc::Vec2<float>(arc::SolarFox::col / 2, arc::SolarFox::row / 2)),
_spaceshipDir(arc::Game::Dir::LEFT),
_spaceshipSpd(arc::SolarFox::spaceshipSpd),
_bulletSpd(0.5f),
_firstTurn(true),
_curScore(5),
_shootRate(40)
{
	_score = 0;
	_scores_path = "./game/solarfox/scores.txt";
	_mapsSizes.push_back(arc::Vec2<size_t>(1, 1));
	_mapsSizes.push_back(arc::Vec2<size_t>(arc::SolarFox::col, arc::SolarFox::row));
	initBlocksPaths();
	_maps.push_back(arc::Utilities::createMap(1, 1));
	_maps.push_back(arc::Utilities::createMap(0, 0));
	time(NULL);
}

std::shared_ptr<arc::IGame>	arc::SolarFox::getInstance() const
{
	std::shared_ptr<arc::IGame> instance(new arc::SolarFox);
	return (instance);
}

void arc::SolarFox::handleBulletsRange()
{
	auto it = _bullets.begin();
	while (it != _bullets.end()) {
		if (it->block.pos.x < 0 || it->block.pos.y < 0
			|| it->block.pos.x > arc::SolarFox::col - 1
			|| it->block.pos.y > arc::SolarFox::row - 1
			|| (it->ofPlayer &&
				(std::abs(it->block.pos.x - it->iPos.x) > 2 ||
					std::abs(it->block.pos.y - it->iPos.y)
					> 2))
			|| it->toDelete)
			_bullets.erase(it);
		else
			++it;
	}	
}

bool arc::SolarFox::isCollided(const Vec2<float> &a, const Vec2<float> &b,
	float size)
{
	return std::abs(a.x - b.x) < size
	&& std::abs(a.y - b.y) < size;
}

void arc::SolarFox::checkGemTouched(const Vec2<float> &bpos)
{
	auto it = _tmpMap.begin();

	while (it != _tmpMap.end()) {
		if (isCollided(it->pos, bpos, 0.5)) {
			_score += _curScore;
			_tmpMap.erase(it);
		} else
		++it;
	}
}

void arc::SolarFox::checkBulletTouched(arc::SolarFox::Bullet &pbullet)
{
	for (size_t i = 0; i <_bullets.size(); i++) {
		if (!_bullets[i].ofPlayer) {
			if (isCollided(_bullets[i].block.pos,
				pbullet.block.pos, 0.5)) {
				_bullets[i].toDelete = true;
				pbullet.toDelete = true;
			}			
		}
	}
}

void arc::SolarFox::handleBulletsCollisions()
{
	for (size_t i = 0; i < _bullets.size(); i++) {
		arc::SolarFox::Bullet b = _bullets[i];
		if (isCollided(b.block.pos, _spaceship, 0.5)) {
			_bullets[i].toDelete = true;
			_playing = false;
		}
		if (b.ofPlayer) {
			checkGemTouched(b.block.pos);
			checkBulletTouched(_bullets[i]);
		}
	}
}

void arc::SolarFox::bulletsHandler(std::vector<arc::Block> &map)
{
	for (size_t i = 0; i < _bullets.size(); i++) {
		_bullets[i].block.textureIdx = _bullets[i].textureIdx;
		if (_bullets[i].dir.x != 0)
			_bullets[i].block.textureIdx = 
		_bullets[i].textureIdx + 1;
		_bullets[i].block.pos.x += _bullets[i].dir.x;
		_bullets[i].block.pos.y += _bullets[i].dir.y;
		map.push_back(_bullets[i].block);
	}
	handleBulletsCollisions();
	handleBulletsRange();
}

void arc::SolarFox::shoot(int textureIdx, arc::Vec2<float> pos,
	arc::Vec2<float> dir, bool ofPlayer)
{
	arc::Block bullet(textureIdx, pos);

	_bullets.push_back(arc::SolarFox::Bullet(bullet, dir, ofPlayer));
}

void arc::SolarFox::gunsHandler(std::vector<arc::Block> &map)
{
	arc::Block gt(_blocks[GUNTOP], _guntop);
	arc::Block gb(_blocks[GUNBOT], _gunbot);

	if (_guntop.x <= 0)
		_dir = -1;
	else if (_guntop.x >= arc::SolarFox::col - 1)
		_dir = 1;
	if (arc::Utilities::randInt(0, 100 - _shootRate) == 1)
		shoot(_blocks[BULLETV], _gunbot,
			arc::Vec2<float>(0, -_bulletSpd));
	if (arc::Utilities::randInt(0, 100 - _shootRate) == 1)
		shoot(_blocks[BULLETV], _guntop,
			arc::Vec2<float>(0, _bulletSpd));
	_gunbot.x += _dir * _gunspd;
	_guntop.x += _dir * -_gunspd;
	bulletsHandler(map);
	map.push_back(gt);
	map.push_back(gb);
}

void	arc::SolarFox::updateSpaceship(std::vector<arc::Block> &map)
{
	arc::Block ss(_blocks[SPACESHIPL], _spaceship);

	if (_spaceship.x < 0 || _spaceship.x > arc::SolarFox::col - 1
		|| _spaceship.y < 0 || _spaceship.y > arc::SolarFox::row - 1)
		_playing = false;
	switch (_spaceshipDir) {
		case arc::Game::Dir::LEFT:
		ss.textureIdx = _blocks[SPACESHIPL];
		break;
		case arc::Game::Dir::RIGHT:
		ss.textureIdx = _blocks[SPACESHIPR];
		break;
		case arc::Game::Dir::UP:
		ss.textureIdx = _blocks[SPACESHIPU];
		break;
		case arc::Game::Dir::DOWN:
		ss.textureIdx = _blocks[SPACESHIPD];
		break;
	}
	map.push_back(ss);
}

void	arc::SolarFox::keyHandler(int key)
{
	switch (key) {
		case arc::KeyCode::LEFT:
		_spaceshipDir = _spaceshipDir != arc::Game::Dir::RIGHT ? 
		arc::Game::Dir::LEFT : _spaceshipDir;
		break;
		case arc::KeyCode::RIGHT:
		_spaceshipDir = _spaceshipDir != arc::Game::Dir::LEFT ? 
		arc::Game::Dir::RIGHT : _spaceshipDir;
		break;
		case arc::KeyCode::UP:
		_spaceshipDir = _spaceshipDir != arc::Game::Dir::DOWN ? 
		arc::Game::Dir::UP : _spaceshipDir;
		break;
		case arc::KeyCode::DOWN:
		_spaceshipDir = _spaceshipDir != arc::Game::Dir::UP ? 
		arc::Game::Dir::DOWN : _spaceshipDir;
		break;
	}
}

void	arc::SolarFox::specialKeyHandler(int key)
{
	switch (key) {
		case ' ':
		shoot(_blocks[BULLETO], _spaceship,
			calcVecDir(_spaceshipDir, _bulletSpd * 2), true);
		break;
		case 'w': case 'W':
		_spaceshipSpd = arc::SolarFox::spaceshipSpd * 
		(_spaceshipSpd == arc::SolarFox::spaceshipSpd ? 2 : 1);
		break;
	}
}

void	arc::SolarFox::updatePosition()
{
	arc::Vec2<float> vecdir = calcVecDir(_spaceshipDir, _spaceshipSpd);
	_spaceship.y += vecdir.y;
	_spaceship.x += vecdir.x;
}

void arc::SolarFox::newLevel()
{
	_tmpMap = _levelMap;
	_curScore += 5;
	_shootRate += _shootRate >= 90 ? 0 : 10;
}

arc::GameStatus	arc::SolarFox::update(int key)
{
	_maps[1].clear();
	if (!_playing || key == arc::KeyCode::ESCAPE)
		return (arc::GameStatus::GAMEOVER);
	arc::Vec2<float> pos(0, 0);
	if (_firstTurn) {
		loadLevel();
		_tmpMap = _levelMap;
		_maps[0].push_back(arc::Block(_blocks[BG], pos));
	}
	if (_tmpMap.size() == 0)
		newLevel();
	_firstTurn = false;
	keyHandler(key);
	specialKeyHandler(key);
	gunsHandler(_maps[1]);
	updateSpaceship(_maps[1]);
	updatePosition();
	_maps[1].insert(_maps[1].begin(), _tmpMap.begin(), _tmpMap.end());
	std::this_thread::sleep_for(std::chrono::milliseconds(40));
	return (arc::GameStatus::PLAYING);
}