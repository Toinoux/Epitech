//
// EPITECH PROJECT, 2018
// Arcade
// File description:
// Arcade Machine
//

#include <thread>
#include <unistd.h>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "Error.hpp"
#include "Utilities.hpp"
#include "Arcade.hpp"

#include <ncurses.h>

arc::Machine::Machine() :
_cur_lib(0),
_cur_game(0),
_cursor_pos(0),
_player("noname"),
_display_game(false),
_pause(false),
_i(0),
_tmp(-19)
{
}

arc::Machine::~Machine()
{
}

void	arc::Machine::displayLibs() const
{
	for (size_t i = 0; i < _libsNames.size(); i++) {
		_libs[_cur_lib]->setTextAttributes(10, 0xffffff);
		if (i == _cur_lib && _cursor_pos == 1)
			_libs[_cur_lib]->setTextAttributes(10, 0x15a3f1);
		_libs[_cur_lib]->drawText(_libsNames[i],
			arc::Vec2<float>(5, i + 5), arc::Vec2<size_t>(11, 15));
	}
}

void	arc::Machine::displayGames() const
{
	for (size_t i = 0; i < _gamesNames.size(); i++) {
		_libs[_cur_lib]->setTextAttributes(10, 0xffffff);
		if (i == _cur_game && _cursor_pos == 2)
			_libs[_cur_lib]->setTextAttributes(10, 0x15a3f1);
		_libs[_cur_lib]->drawText(_gamesNames[i],
			arc::Vec2<float>(48, i + 5), arc::Vec2<size_t>(60, 15));
	}
}

void	arc::Machine::sortScores(std::vector<std::string> &scores) const
{
	std::sort(scores.begin(), scores.end(),
		[](const std::string &a, const std::string &b) {
			std::istringstream iss(a);
			std::istringstream iss2(b);
			std::string n1;
			std::string n2;
			iss >> n1 >> n1;
			iss2 >> n2 >> n2;
			if (!arc::Utilities::isNumber(n1) ||
				!arc::Utilities::isNumber(n2))
				return (false);
			return std::stoi(n1) > std::stoi(n2);
		});
}

void	arc::Machine::displayScores() const
{
	std::vector<std::string> scores = _games[_cur_game]->getScores();

	_libs[_cur_lib]->setTextAttributes(10, 0xffffff);
	if (_cursor_pos == 2)
		_libs[_cur_lib]->setTextAttributes(10, 0x15a3f1);
	_libs[_cur_lib]->drawText("Hall of Fame:", arc::Vec2<float>(1, 8),
		arc::Vec2<size_t>(25, 15));
	_libs[_cur_lib]->setTextAttributes(10, 0xffffff);
	sortScores(scores);
	for (size_t i = 0; i < scores.size() && i < SCORES_LIMIT; i++) {
		_libs[_cur_lib]->drawText(scores[i],
			arc::Vec2<float>(1, 9 + i), arc::Vec2<size_t>(25, 15));
	}
	if (scores.size() < 1)
		_libs[_cur_lib]->drawText("No score yet",
			arc::Vec2<float>(1, 10), arc::Vec2<size_t>(25, 15));
}

void	arc::Machine::displayPlayerInput() const
{
	_libs[_cur_lib]->setTextAttributes(10, 0xffffff);
	_libs[_cur_lib]->drawText("Player's name:",
		arc::Vec2<float>(1, 5), arc::Vec2<size_t>(25, 15));
	_libs[_cur_lib]->drawText(_player, arc::Vec2<float>(1, 6),
		arc::Vec2<size_t>(25, 15));
	if (_cursor_pos == 0) {
		_libs[_cur_lib]->setTextAttributes(10, 0x15a3f1);
		_libs[_cur_lib]->drawText(_player + "_",
			arc::Vec2<float>(1, 6), arc::Vec2<size_t>(25, 15));
	}
}

void	arc::Machine::displayMenu()
{
	_libs[_cur_lib]->drawBlock(arc::Block(_blocks["bg"
		+ std::to_string(_i)],
	arc::Vec2<float>(0, 0)), arc::Vec2<size_t>(1, 1));
	_libs[_cur_lib]->drawBlock(arc::Block(_blocks["arrow"],
		arc::Vec2<float>((_cursor_pos * 3 + 1) * 3, 6)),
	arc::Vec2<size_t>(25, 25));
	_libs[_cur_lib]->setTextAttributes(27, 0x15a3f1);
	_libs[_cur_lib]->drawText("Arcade", arc::Vec2<float>(5, 1),
		arc::Vec2<size_t>(14, 25));
	displayPlayerInput();
	displayLibs();
	displayGames();
	displayScores();
	_libs[_cur_lib]->setTextAttributes(10, 0x15a3f1);
	if ((_i > 0 && _i < 10) || (_i > 20 && _i < 30))
		_libs[_cur_lib]->drawText("Press ENTER to start",
			arc::Vec2<float>(14, 14), arc::Vec2<size_t>(25, 15));
	_i = _i == 40 ? 0 : _i + 1;
}

void	arc::Machine::changeLib(int next)
{
	size_t old_lib = _cur_lib;

	if (_cur_lib == 0 && next < 0)
		_cur_lib = _libs.size() - 1;
	else if (_cur_lib + next >= _libs.size())
		_cur_lib = 0;
	else
		_cur_lib += next;
	if (old_lib == _cur_lib)
		return;
	_libs[old_lib]->closeWindow();
	_libs[old_lib]->destroy();
	_libs[_cur_lib]->setup();
	_screen.setLib(_libs[_cur_lib]);
	if (_display_game) {
		_pause = true;
		initGameBlocks();
	}
	initBlocks();
}

void	arc::Machine::changeGame(int next)
{
	if (_cur_game == 0 && next < 0)
		_cur_game = _games.size() - 1;
	else if (_cur_game + next >= _games.size())
		_cur_game = 0;
	else
		_cur_game += next;
}

void arc::Machine::handleArrowKey(int key)
{
	switch (key) {
		case arc::KeyCode::DOWN:
		changeLib(_cursor_pos == 1 ? 1 : 0);
		changeGame(_cursor_pos == 2 ? 1 : 0);
		break;
		case arc::KeyCode::UP:
		changeLib(_cursor_pos == 1 ? -1 : 0);
		changeGame(_cursor_pos == 2 ? -1 : 0);
		break;
		case arc::KeyCode::LEFT:
		_cursor_pos = _cursor_pos == 0 ? 2 : _cursor_pos - 1;
		break;
		case arc::KeyCode::RIGHT:
		_cursor_pos = _cursor_pos == 2 ? 0 : _cursor_pos + 1;
		break;
	}
}

void arc::Machine::handleSpecialKey(int key)
{
	switch (key) {
		case 'a': case 'A':
		changeLib(-1);
		break;
		case 'z': case 'Z':
		changeLib(1);
		break;
		case 'q': case 'Q':
		changeGame(-1);
		newGame();
		break;
	}
	handleSpecialKey2(key);
}

void arc::Machine::handleSpecialKey2(int key)
{
	switch (key) {
		case 's': case 'S':
		changeGame(1);
		newGame();
		break;
		case 'r': case 'R':
		newGame();
		break;
		case 'p': case 'P':
		_pause = _pause == false ? true : false;
		break;
	}
}

void arc::Machine::onKeyPressed(int key)
{
	if (_cursor_pos != 0 || _display_game)
		handleSpecialKey(key);
	if (_display_game == true)
		return;
	switch (key) {
		case arc::KeyCode::ENTER:
		newGame();
		break;
		case arc::KeyCode::ESCAPE:
		_libs[_cur_lib]->closeWindow();
		break;
		default:
		if (_cursor_pos == 0 && (_player.size() < NAME_LIMIT
			|| key == arc::KeyCode::BACKSPACE))
			arc::Utilities::inputString(_player, key);
		break;
	}
	handleArrowKey(key);
}

void arc::Machine::initGameBlocks()
{
	std::vector<int> blocks;
	std::vector<std::string> blocks_paths;

	blocks_paths = _game->getTexturesPaths();
	for (size_t i = 0; i < blocks_paths.size(); i++)
		blocks.push_back(
			_libs[_cur_lib]->createTexture(blocks_paths[i]));
	_game->setBlocks(blocks);
}

void arc::Machine::newGame()
{
	_display_game = true;
	_game = _games[_cur_game]->getInstance();
	initGameBlocks();
}

void	arc::Machine::inGame(int key)
{
	if (!_game)
		return;
	if (!_pause && _game->update(key) == arc::GameStatus::GAMEOVER) {
		_display_game = false;
		_game->saveScore(_player);
		_libs[_cur_lib]->destroy();
		initBlocks();
	}
	_libs[_cur_lib]->setTextAttributes(10, 0xffffff);
	if (!_pause) {
		_screen.setLayers(_game->getBlocksLayers(),
			_game->getMapsSizes());
		_screen.draw();
	} else
	_libs[_cur_lib]->drawText("Press P to continue",
		arc::Vec2<float>(14, 10), arc::Vec2<size_t>(40, 25));
	_libs[_cur_lib]->drawText(_game->getCurrentScore(),
		arc::Vec2<float>(1, 1), arc::Vec2<size_t>(40, 25));
}


void	arc::Machine::initBlocks2()
{

}

void	arc::Machine::initBlocks()
{
	_blocks["arrow"] = _libs[_cur_lib]->createTexture("./img/arrow-down");
	for (int i = 0; i < 41; i++) {
		_blocks["bg" + std::to_string(i)] =
		_libs[_cur_lib]->createTexture("./img/bg" + std::to_string(i));
	}
	for (int i = 0; i < 20; i++) {
		_blocks["lg" + std::to_string(i)] =
		_libs[_cur_lib]->createTexture("./img/logo/logo" +
			std::to_string(i));
	}
}

void arc::Machine::displayIntro()
{
	_libs[_cur_lib]->drawBlock(arc::Block(_blocks["lg"
		+ std::to_string(std::abs(_tmp))], arc::Vec2<float>(0, 0)),
	arc::Vec2<size_t>(1, 1));
	std::this_thread::sleep_for(
		std::chrono::milliseconds(45));
	_tmp += 1;
}

void	arc::Machine::start()
{
	_screen.setLib(_libs[_cur_lib]);
	_libs[_cur_lib]->setup();
	initBlocks();
	while (_libs[_cur_lib]->isWindowOpen()) {
		_libs[_cur_lib]->pollEvent();
		_libs[_cur_lib]->clear();
		_key = _libs[_cur_lib]->getKeyCode();
		onKeyPressed(_key);
		if (_tmp < 20)
			displayIntro();
		else if (_display_game)
			inGame(_key);
		else {
			displayMenu();
			std::this_thread::sleep_for(
				std::chrono::milliseconds(60));
		}
		_libs[_cur_lib]->display();
	}
	_libs[_cur_lib]->destroy();
}

void	arc::Machine::loadLib(const std::string &path)
{
	std::shared_ptr<arc::IGraphic> lib =
	_lloader.getInstance(path, "getGraphicInstance");

	if (lib) {
		if (_libs.size() > 0 && typeid(*(lib.get()))
			== typeid(*(_libs[0].get())))
			return;
		_libs.push_back(lib);
		_libsNames.push_back(arc::Utilities::getBaseName(path));
	} else {
		throw arc::ArcadeError(std::string(CANT_LOAD_LIB)
			+ " " + path);
	}
}

void	arc::Machine::loadLibs()
{
	std::vector<std::string> paths = arc::Utilities::readDir(LIBS_DIR);

	for (size_t i = 0; i < paths.size(); i++) {
		if (arc::Utilities::getFileExtension(paths[i]) == "so") {
			try {
				loadLib(paths[i]);
			} catch (ArcadeError &e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
	if (_libs.size() == 0)
		throw ArcadeError(NO_LIBS);
}

void	arc::Machine::loadGame(const std::string &path)
{
	std::shared_ptr<arc::IGame> game =
	_gloader.getInstance(path, "getGameInstance");

	if (game) {
		_games.push_back(game);
		_gamesNames.push_back(arc::Utilities::getBaseName(path));
	} else {
		throw arc::ArcadeError(std::string(CANT_LOAD_GAME)
			+ " " + path);
	}
}

void	arc::Machine::loadGames()
{
	std::vector<std::string> paths = arc::Utilities::readDir(GAMES_DIR);

	for (size_t i = 0; i < paths.size(); i++) {
		if (arc::Utilities::getFileExtension(paths[i]) == "so") {
			try {
				loadGame(paths[i]);
			} catch (ArcadeError &e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
	if (_games.size() == 0)
		throw ArcadeError(NO_GAMES);

}

std::vector<std::shared_ptr<arc::IGraphic> >	&arc::Machine::getLibs()
{
	return _libs;
}

std::vector<std::shared_ptr<arc::IGame> >	&arc::Machine::getGames()
{
	return _games;
}
