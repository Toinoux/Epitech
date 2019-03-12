//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Arcade Machine
//

#pragma once

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include "DLLoader.hpp"
#include "Screen.hpp"
#include "IGame.hpp"

constexpr char LIBS_DIR[] = "./lib";
constexpr char GAMES_DIR[] = "./games";
constexpr char PRE_LIB_NAME[] = "lib_arcade_";
constexpr int NAME_LIMIT = 16;
constexpr int SCORES_LIMIT = 5;

namespace arc {
	class Machine {
	public:
		Machine();
		~Machine();
		void	start();
		void	loadLibs();
		void	loadGames();
	public:
		void	loadLib(const std::string &);
		void	loadGame(const std::string &);
		std::vector<std::shared_ptr<arc::IGraphic>>	&getLibs();
		std::vector<std::shared_ptr<arc::IGame>>	&getGames();
	private:
		void	initBlocks();
		void	initBlocks2();
		void	initGameBlocks();
		void	onKeyPressed(int);
		void	handleArrowKey(int);
		void	handleSpecialKey(int);
		void	handleSpecialKey2(int);
		void	changeLib(int);
		void	changeGame(int);
		void	displayIntro();
		void	displayLibs() const;
		void	displayGames() const;
		void	displayScores() const;
		void	displayPlayerInput() const;
		void	displayMenu();
		void	sortScores(std::vector<std::string> &make) const;
		void	inGame(int game);
		void	newGame();
	private:
		arc::DLLoader<arc::IGraphic>			_lloader;
		arc::DLLoader<arc::IGame>			_gloader;
		std::vector<std::string>			_libsNames;
		std::vector<std::string>			_gamesNames;
		size_t						_cur_lib;
		size_t						_cur_game;
		size_t						_cursor_pos;
		std::string					_player;
		Screen						_screen;
		std::unordered_map<std::string, size_t>		_blocks;
		std::vector<std::shared_ptr<arc::IGraphic>>	_libs;
		std::vector<std::shared_ptr<arc::IGame>>	_games;
		bool						_display_game;
		bool						_pause;
		std::shared_ptr<IGame>				_game;
		int						_i;
		int						_tmp;
		int						_key;
	};
}
