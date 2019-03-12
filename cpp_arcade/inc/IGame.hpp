/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Game interface header
*/

#pragma once

#include <memory>
#include <string>
#include "Common.hpp"

namespace arc {
	enum GameStatus {
		GAMEOVER,
		PLAYING
	};

	class IGame {
	public:
		virtual ~IGame() = default;

		virtual std::shared_ptr<arc::IGame> getInstance() const = 0;

		virtual arc::GameStatus update(int) = 0;

		virtual const std::vector<arc::Vec2<size_t>> &getMapsSizes()
		const = 0;

		virtual const arc::blocksLayers &getBlocksLayers() const = 0;
		virtual void setBlocks(const std::vector<int> &) = 0;
		virtual const std::vector<std::string> &getTexturesPaths()
		const = 0;

		virtual void saveScore(const std::string &) const = 0;
		virtual const std::vector<std::string> &getScores() = 0;
		virtual const std::string &getCurrentScore() = 0;
	};
}
