//
// EPITECH PROJECT, 2018
// ncurses
// File description:
// Ncurses Graphic Lib
//

#include <math.h>
#include <ncurses.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "Error.hpp"
#include "ArcadeNcurses.hpp"

void arc::Ncurses::setup()
{
	initscr();
	_isWin = true;
	notimeout(stdscr, TRUE);
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	nodelay(stdscr,TRUE);
	curs_set(0);
	start_color();
	_event = false;
}

void arc::Ncurses::clear()
{
	erase();
}

void arc::Ncurses::display() const
{
	refresh();
}

bool arc::Ncurses::isWindowOpen() const
{
	return _isWin;
}

int arc::Ncurses::setColor(std::string content, int index)
{
	short color = index + 200;
	std::string tmp(content);

	tmp = tmp.substr(tmp.find(":") + 1, tmp.size());
	std::string sr = tmp.substr(0, tmp.find(":"));
	tmp = tmp.substr(tmp.find(":") + 1, tmp.size());
	std::string sg = tmp.substr(0, tmp.find(":"));
	tmp = tmp.substr(tmp.find(":") + 1, tmp.size());
	std::string sb = tmp.substr(0, tmp.size());
	int r = std::stoi(sr.c_str());
	int g = std::stoi(sg.c_str());
	int b = std::stoi(sb.c_str());
	init_color(color, r, g, b);
	init_pair(index + 200, color, COLOR_BLACK);
	return index;
}

int arc::Ncurses::createTexture(const std::string &block)
{
	std::ifstream file (block + "/block.txt", std::ifstream::in);
	std::string content;
	std::string buf;

	if (!file)
		return -1;
	while (std::getline(file, buf))
		if (buf.empty() == false && content.empty() == true)
			content = buf;
		else if (buf.empty() == false)
			content = content + ":" + buf;
	_blocks.push_back(content);
	_blocksColor.push_back(setColor(content, _blocks.size() - 1));
	return _blocks.size() - 1;
}

bool arc::Ncurses::pollEvent()
{
	_ch = getch();
	_textColorI = 1;
	_drawColorI = 200;
	_event = !_event;
	return (_event);
}

void arc::Ncurses::drawBlock(const arc::Block &b,
	const arc::Vec2<size_t> &msize) const
{
	int x = ceil(b.pos.x * (float)COLS /
		(msize.x == 0 ? 1.0 : (float)msize.x));
	int y = ceil(b.pos.y * (float)LINES /
		(msize.y == 0 ? 1.0 : (float)msize.y));
	short color;

	if (_blocks.size() <= (size_t)b.textureIdx)
		return;
	color = _blocksColor[b.textureIdx];
	attron(COLOR_PAIR(color + 200));
	mvprintw(y, x, _blocks[b.textureIdx].substr
		(0, _blocks[b.textureIdx].find(":")).c_str());
	attroff(COLOR_PAIR(color + 200));
}

void arc::Ncurses::drawText(const std::string &text,
	const arc::Vec2<float> &pos, const arc::Vec2<size_t> &msize)
{
	int x = ceil((float)pos.x * (float)COLS /
		(msize.x == 0 ? 1.0 : (float)msize.x));
	int y = ceil((float)pos.y * (float)LINES /
		(msize.y == 0 ? 1.0 : (float)msize.y));

	attron(COLOR_PAIR(_textColorI - 1));
	mvprintw(y, x, text.c_str());
	attroff(COLOR_PAIR(_textColorI - 1));
}

void arc::Ncurses::setTextAttributes(size_t font_size __attribute__((unused)),
	size_t hexcolor)
{
	int r = (hexcolor >> 16) & 0xFF;
	int g = (hexcolor >> 8) & 0xFF;
	int b = (hexcolor) & 0xFF;

	init_color(_textColorI, 3.9 * r, 3.9 * g, 3.9 * b);
	init_pair(_textColorI, _textColorI, COLOR_BLACK);
	_textColorI++;
}

void arc::Ncurses::destroy()
{
	_blocks.clear();
	_blocksColor.clear();
	endwin();
}

void arc::Ncurses::closeWindow()
{
	_isWin = false;
	endwin();
}

int arc::Ncurses::getKeyCode() const
{
	switch (_ch) {
	case KEY_LEFT:
		return arc::KeyCode::LEFT;
	case KEY_RIGHT:
		return arc::KeyCode::RIGHT;
	case KEY_UP:
		return arc::KeyCode::UP;
	case KEY_DOWN:
		return arc::KeyCode::DOWN;
	case KEY_EXIT: case 27:
		return arc::KeyCode::ESCAPE;
	case KEY_ENTER: case 10:
		return arc::KeyCode::ENTER;
	case KEY_BACKSPACE:
		return arc::KeyCode::BACKSPACE;
	}
	return (_ch);
}
