//
// EPITECH PROJECT, 2018
// ArcadePacman
// File description:
// Pacman game
//

#include <iostream>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "Utilities.hpp"
#include "ArcadePacman.hpp"

void arc::Pacman::initBlocksPaths()
{
	_blocks_paths = {
		"./games/pacman/assets/map",
		"./games/pacman/assets/pacman_lefto"		
	};
}

arc::Pacman::Pacman() :
_pacman(arc::Vec2f(1.0, 5.0)),
_dir(arc::Direction::RIGHT),
_pacman_spd(0.5)
{
	_score = 0;
	_scores_path = "./games/pacman/scores.txt";
	initBlocksPaths();
	_maps.push_back(arc::Utilities::createMap(0, 0));
	_maps.push_back(arc::Utilities::createMap(0, 0));
	time(NULL);
}

std::shared_ptr<arc::IGame>	arc::Pacman::getInstance() const
{
	std::shared_ptr<arc::IGame> instance(new arc::Pacman);
	return (instance);
}

void	arc::Pacman::updatePosition()
{
	Vec2f newpos(0.0, 0.0);

	switch (_dir) {
		case arc::Direction::LEFT:
		newpos.x = -_pacman_spd;
		break;
		case arc::Direction::RIGHT:
		std::cout << _pacman_spd << std::endl;
		newpos.x = _pacman_spd;
		break;
		case arc::Direction::UP:
		newpos.y = -_pacman_spd;
		break;
		case arc::Direction::DOWN:
		newpos.y = _pacman_spd;
		break;
	}
	std::cout << newpos.x << std::endl;
	_pacman.y += newpos.y;
	_pacman.x += newpos.x;
}


arc::gameStatus	arc::Pacman::update(int key)
{
	arc::map2d map = arc::Utilities::createMap(arc::Pacman::row,
		arc::Pacman::col);

	if (key == arc::KeyCode::ESCAPE)
		return (arc::gameStatus::GAMEOVER);
	updatePosition();
	std::cout << _pacman.x << std::endl;
	map[ceil(_pacman.y)][ceil(_pacman.x)] = _blocks[arc::Pacman::Block::PACOPENL];
	_maps[0] = arc::Utilities::createMap(1, 1,
		_blocks[arc::Pacman::Block::BG]);
	_maps[1] = map;
	usleep(100000);
	return (arc::gameStatus::PLAYING);
}


std::vector<arc::move> arc::Pacman::getBlocksMoves() const
{

}