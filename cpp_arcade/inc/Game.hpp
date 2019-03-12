/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Game header
*/

#pragma once

#include <string>
#include "IGame.hpp"

namespace arc {
	class Game : public IGame {
	public:
		const arc::blocksLayers &getBlocksLayers() const override;
		void saveScore(const std::string &) const override;
		const std::vector<std::string> &getScores() override;
		const std::string &getCurrentScore() override;
		const std::vector<std::string>
		&getTexturesPaths() const override;
		const std::vector<arc::Vec2<size_t>>
		&getMapsSizes() const override;
		void setBlocks(const std::vector<int> &) override;
	public:
		static int getBlockIdxAt(const std::vector<Block> &,
			Vec2<float>);
	protected:
		Vec2<float> calcVecDir(int, float);
	protected:
		arc::blocksLayers	_maps;
		std::string		_scores_path;
		int			_score;
		std::string		_sscore;
		std::vector<int>	_blocks;
		std::vector<std::string> _scores;
		std::vector<std::string> _blocks_paths;
		std::vector<arc::Vec2<size_t>> _mapsSizes;
		enum Dir {
			RIGHT,
			LEFT,
			UP,
			DOWN
		};
	};
}
