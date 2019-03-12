//
// EPITECH PROJECT, 2018
// Game
// File description:
// nothing
//

#include <iostream>
#include <math.h>
#include <fstream>
#include "Game.hpp"

arc::Vec2<float> arc::Game::calcVecDir(int dir, float dirval)
{
	arc::Vec2<float> vecdir(0, 0);

	switch (dir) {
		case arc::Game::Dir::LEFT:
		vecdir.x = -dirval;
		break;
		case arc::Game::Dir::RIGHT:
		vecdir.x = dirval;
		break;
		case arc::Game::Dir::UP:
		vecdir.y = -dirval;
		break;
		case arc::Game::Dir::DOWN:
		vecdir.y = dirval;
		break;
	}
	return (vecdir);
}

int arc::Game::getBlockIdxAt(const std::vector<arc::Block> &blocks,
	Vec2<float> pos)
{
	for (size_t i = 0; i < blocks.size(); i ++) {
		if (floor(blocks[i].pos.x) == floor(pos.x) &&
			floor(blocks[i].pos.y) == floor(pos.y))
			return (blocks[i].textureIdx);
	}
	return (-1);
}

const arc::blocksLayers &arc::Game::getBlocksLayers() const
{
	return (_maps);
}

const std::vector<arc::Vec2<size_t>> &arc::Game::getMapsSizes() const
{
	return (_mapsSizes);
}

void arc::Game::saveScore(const std::string &player_name) const
{
	std::ofstream ofs;

	ofs.open(_scores_path, std::ios_base::app);
	ofs << player_name + " " + std::to_string(_score) << std::endl;
	ofs.close();
}

const std::vector<std::string> &arc::Game::getScores()
{
	std::ifstream ifs(_scores_path);
	std::string line;

	_scores.clear();
	while (std::getline(ifs, line))
		_scores.push_back(line);
	ifs.close();
	return (_scores);
}

const std::string	&arc::Game::getCurrentScore()
{
	_sscore = std::to_string(_score);
	return (_sscore);
}

const std::vector<std::string> &arc::Game::getTexturesPaths() const
{
	return (_blocks_paths);
}

void	arc::Game::setBlocks(const std::vector<int> &blocks)
{
	_blocks = blocks;
}