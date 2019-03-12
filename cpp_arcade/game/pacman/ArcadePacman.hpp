//
// EPITECH PROJECT, 2018
// ArcadePacman
// File description:
// Pacman Game
//

#pragma once

#include "Game.hpp"

namespace arc {
	class Pacman : public Game {
	public:
		Pacman();
		std::shared_ptr<arc::IGame>	getInstance() const final;
		arc::gameStatus update(int) final;
		std::vector<move> getBlocksMoves() const final;
	private:
		void	initBlocksPaths();
		void	updatePosition();
	private:
		Vec2f			_pacman;
		Direction		_dir;
		float			_pacman_spd;
		static constexpr size_t row = 30;
		static constexpr size_t col = 42;
		enum Block {
			BG,
			PACOPENL
		};
	};
}