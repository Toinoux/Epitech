//
// EPITECH PROJECT, 2018
// ArcadeSnake
// File description:
// Snake Game
//

#pragma once

#include "Game.hpp"

namespace arc {

	class Snake : public Game {
	public:
		Snake();
		std::shared_ptr<arc::IGame>	getInstance() const final;
		arc::GameStatus			update(int) final;
	private:
		bool	isDead(const std::vector<arc::Block> &);
		void	foodHandler(std::vector<arc::Block> &);
		void	initObstacles();
		void	initBlocksPaths();
		void	updatePosition();
		void	handleKey(int);
		void	drawSnake(std::vector<arc::Block> &);
		size_t	getHeadTailBlock(size_t);
		size_t	getAngleBlock(size_t);
	private:
		static constexpr size_t len = 4;
		static constexpr size_t row = 24;
		static constexpr size_t col = 36;
		enum Dir {
			TOP,
			LEFT,
			RIGHT,
			BOT
		};
		enum Block {
			TOPLEFT,
			TOPRIGHT,
			BOTLEFT,
			BOTRIGHT,
			TOPHEAD,
			BOTHEAD,
			LEFTHEAD,
			RIGHTHEAD,
			TOPTAIL,
			BOTTAIL,
			LEFTTAIL,
			RIGHTTAIL,
			VERMIDDLE,
			HORMIDDLE,
			APPLE,
			ORANGE,
			GRASS,
			LAKE
		};
	private:
		std::vector<Vec2<int>>	_snake;
		std::vector<arc::Block>	_obstacles;
		Dir			_dir;
		Vec2<int>		_apple;
		float			_score_mul;
		bool			_playing;
		arc::Vec2<size_t>	_mapSizes;
		bool			_firstTurn;
		int			_foodId;
	};
}
