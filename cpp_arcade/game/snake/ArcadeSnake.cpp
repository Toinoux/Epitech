//
// EPITECH PROJECT, 2018
// ArcadeSnake
// File description:
// Snake game
//

#include <thread>
#include <math.h>
#include <unistd.h>
#include <iostream>
#include "Utilities.hpp"
#include "ArcadeSnake.hpp"

void arc::Snake::initBlocksPaths()
{
	_blocks_paths = {
		"./game/snake/assets/topleft",
		"./game/snake/assets/topright",
		"./game/snake/assets/botleft",
		"./game/snake/assets/botright",
		"./game/snake/assets/tophead",
		"./game/snake/assets/bothead",
		"./game/snake/assets/lefthead",
		"./game/snake/assets/righthead",
		"./game/snake/assets/toptail",
		"./game/snake/assets/bottail",
		"./game/snake/assets/lefttail",
		"./game/snake/assets/righttail",
		"./game/snake/assets/vermiddle",
		"./game/snake/assets/hormiddle",
		"./game/snake/assets/apple",
		"./game/snake/assets/orange",
		"./game/snake/assets/grass",
		"./game/snake/assets/lake"
	};
}

arc::Snake::Snake() :
_dir(arc::Snake::Dir::LEFT),
_apple(arc::Vec2<int>(arc::Utilities::randInt(0, arc::Snake::col - 1),
	arc::Utilities::randInt(0, arc::Snake::row - 1))),
_score_mul(5),
_playing(true),
_mapSizes(arc::Snake::col, arc::Snake::row),
_firstTurn(true),
_foodId(arc::Snake::Block::APPLE)
{
	_score = 0;
	_scores_path = "./game/snake/scores.txt";
	_mapsSizes.push_back(arc::Vec2<size_t>
			(arc::Snake::col, arc::Snake::row));
	_mapsSizes.push_back(arc::Vec2<size_t>
			(arc::Snake::col, arc::Snake::row));
	initBlocksPaths();
	std::vector<arc::Block> map = arc::Utilities::createMap(
		arc::Snake::row, arc::Snake::col);
	_maps.push_back(arc::Utilities::createMap(0, 0));
	_maps.push_back(map);
	int ox = arc::Snake::col / 2;
	for (size_t i = 0; i < arc::Snake::len; i++)
		_snake.push_back(arc::Vec2<int>(ox + i, arc::Snake::row / 2));
	time(NULL);
}

void	arc::Snake::foodHandler(std::vector<arc::Block> &map)
{
	size_t i = 0;

	_foodId = _score % 9 == 0 && _score > 0 ? arc::Snake::Block::ORANGE :
	arc::Snake::Block::APPLE;
	while (i < _snake.size()) {
		if (_apple.x == _snake[i].x && _apple.y == _snake[i].y) {
			_apple.x = arc::Utilities::randInt(0,
				arc::Snake::col - 1);
			_apple.y = arc::Utilities::randInt(0,
				arc::Snake::row - 1);
			i = 0;
			_snake.push_back(arc::Vec2<int>(0, 0));
			_score += _score_mul * (_score % 9 == 0 ? 2 : 1);
			_score_mul *= 1.1;
		}
		i++;
	}
	map.push_back(arc::Block(_blocks[_foodId],
		arc::Vec2<float>(_apple.x, _apple.y)));
}

std::shared_ptr<arc::IGame>	arc::Snake::getInstance() const
{
	std::shared_ptr<arc::IGame> instance(new arc::Snake);
	return (instance);
}

void	arc::Snake::updatePosition()
{
	Vec2<float> newpos(0, 0);
	std::vector<Vec2<int>> tmp = _snake;

	switch (_dir) {
		case arc::Snake::Dir::LEFT:
		newpos.x = -1;
		break;
		case arc::Snake::Dir::RIGHT:
		newpos.x = 1;
		break;
		case arc::Snake::Dir::TOP:
		newpos.y = -1;
		break;
		case arc::Snake::Dir::BOT:
		newpos.y = 1;
		break;
	}
	for (size_t i = 1; i < _snake.size(); i++)
		_snake[i] = tmp[i - 1];
	_snake[0].y += newpos.y;
	_snake[0].x += newpos.x;
}

void	arc::Snake::handleKey(int key)
{
	switch (key) {
		case arc::KeyCode::LEFT:
		_dir = _dir != arc::Snake::Dir::RIGHT ?
		arc::Snake::Dir::LEFT : _dir;
		break;
		case arc::KeyCode::RIGHT:
		_dir = _dir != arc::Snake::Dir::LEFT ?
		arc::Snake::Dir::RIGHT : _dir;
		break;
		case arc::KeyCode::UP:
		_dir = _dir != arc::Snake::Dir::BOT ?
		arc::Snake::Dir::TOP : _dir;
		break;
		case arc::KeyCode::DOWN:
		_dir = _dir != arc::Snake::Dir::TOP ?
		arc::Snake::Dir::BOT : _dir;
		break;
	}
}

size_t arc::Snake::getHeadTailBlock(size_t i)
{
	size_t bl_index = arc::Snake::Block::RIGHTHEAD;

	if (i == 0) {
		if (_snake[i].x < _snake[i + 1].x)
			bl_index = arc::Snake::Block::LEFTHEAD;
		else if (_snake[i].y < _snake[i + 1].y)
			bl_index = arc::Snake::Block::TOPHEAD;
		else if (_snake[i].y > _snake[i + 1].y) {
			bl_index = arc::Snake::Block::BOTHEAD;
		}
	} else {
		bl_index = arc::Snake::Block::RIGHTTAIL;
		if (_snake[i].x < _snake[i - 1].x)
			bl_index = arc::Snake::Block::LEFTTAIL;
		else if (_snake[i].y < _snake[i - 1].y)
			bl_index = arc::Snake::Block::TOPTAIL;
		else if (_snake[i].y > _snake[i - 1].y)
			bl_index = arc::Snake::Block::BOTTAIL;
	}
	return (bl_index);
}

size_t arc::Snake::getAngleBlock(size_t i)
{
	size_t bl_index = arc::Snake::Block::TOPRIGHT;
	int nx = _snake[i + 1].x - _snake[i].x;
	int ny = _snake[i + 1].y - _snake[i].y;
	int px = _snake[i - 1].x - _snake[i].x;
	int py = _snake[i - 1].y - _snake[i].y;

	if (nx == py && ny == px && ((nx == 1 && ny == 0)
		|| (px == 1 && py == 0)))
		bl_index = arc::Snake::Block::TOPLEFT;
	else if ((nx > px && ny > py && nx == 1
		&& ny == 0 && px == 0 && py == -1)
		|| (px > nx && py > ny && px == 1
			&& py == 0 && nx == 0 && ny == -1))
		bl_index = arc::Snake::Block::BOTLEFT;
	else if ((nx > px && ny < py && nx == 0 && ny == -1
		&& px == -1 && py == 0)  || (px > nx && py < ny
		&& px == 0 && py == -1 && nx == -1 && ny == 0))
		bl_index = arc::Snake::Block::BOTRIGHT;
	return (bl_index);
}

void	arc::Snake::drawSnake(std::vector<arc::Block> &map)
{
	for (size_t i = 0; i < _snake.size(); i++) {
		size_t bl_index = arc::Snake::Block::HORMIDDLE;
		if (i == 0 || i == _snake.size() - 1)
			bl_index = getHeadTailBlock(i);
		else if (_snake[i].x == _snake[i - 1].x
			&& _snake[i].x == _snake[i + 1].x)
			bl_index = arc::Snake::Block::VERMIDDLE;
		else if (_snake[i].y != _snake[i - 1].y
			|| _snake[i].y != _snake[i + 1].y)
			bl_index = getAngleBlock(i);
		arc::Vec2<float> pos((float)_snake[i].x, (float)_snake[i].y);
		arc::Block b(_blocks[bl_index], pos);
		map.push_back(b);
	}
}

bool arc::Snake::isDead(const std::vector<arc::Block> &map)
{
	int a = _blocks[arc::Snake::Block::APPLE];
	int l = arc::Game::getBlockIdxAt(map,
		arc::Vec2<float>(_snake[0].x - 1, _snake[0].y));
	int r = arc::Game::getBlockIdxAt(map,
		arc::Vec2<float>(_snake[0].x + 1, _snake[0].y));
	int t = arc::Game::getBlockIdxAt(map,
		arc::Vec2<float>(_snake[0].x, _snake[0].y - 1));
	int b = arc::Game::getBlockIdxAt(map,
		arc::Vec2<float>(_snake[0].x, _snake[0].y + 1));

	if (_snake[0].x < 0 || (size_t)_snake[0].x >= arc::Snake::col ||
		_snake[0].y < 0 || (size_t)_snake[0].y >= arc::Snake::row)
		return (true);
	if ((l != -1 && l != a && _dir == arc::Snake::Dir::LEFT)
		|| (r != -1 && r != a && _dir == arc::Snake::Dir::RIGHT)
		|| (t != -1 && t != a && _dir == arc::Snake::Dir::TOP)
		|| (b != -1 && b != a && _dir == arc::Snake::Dir::BOT))
		return (true);
	return (false);
}

void arc::Snake::initObstacles()
{
	for (size_t i = 0; i < 10; i++) {
		arc::Block b (_blocks[arc::Snake::Block::LAKE],
			arc::Vec2<float>(arc::Utilities::randInt(0,
				arc::Snake::col - 1)
			, arc::Utilities::randInt(0,
				arc::Snake::row - 1)));
		if (b.pos.y != arc::Snake::row / 2)
			_obstacles.push_back(b);
	}
}

arc::GameStatus arc::Snake::update(int key)
{
	std::vector<arc::Block> map;

	if (!_playing || key == arc::KeyCode::ESCAPE)
		return (arc::GameStatus::GAMEOVER);
	handleKey(key);
	drawSnake(map);
	if (_firstTurn) {
		_maps[0] = arc::Utilities::createMap(arc::Snake::row,
			arc::Snake::col, _blocks[arc::Snake::Block::GRASS]);
		initObstacles();
	}
	map.insert(map.end(), _obstacles.begin(), _obstacles.end());
	_playing = !isDead(map);
	foodHandler(map);
	updatePosition();
	_firstTurn = false;
	_maps[1] = map;
	std::this_thread::sleep_for(std::chrono::milliseconds(60));
	return (arc::GameStatus::PLAYING);
}
