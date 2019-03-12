//
// EPITECH PROJECT, 2018
// *
// File description:
// graphic class NCurses
//


#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "IGraphic.hpp"

namespace arc
{
	class Ncurses : public IGraphic
	{
	public:
		void setup() final;

		void clear() final;
		void display() const final;
		bool isWindowOpen() const final;

		int createTexture(const std::string &) final;
		void drawBlock(const Block &,
			const Vec2<size_t> &) const final;

		bool pollEvent() final;

		void drawText(const std::string &,
			const Vec2<float> &, const Vec2<size_t> &) final;
		void setTextAttributes(size_t, size_t) final;

		void destroy() final;
		void closeWindow() final;

		int getKeyCode() const final;

	private:
		int					_ch;
		bool					_isWin;
		short					_textColorI = 1;
		short					_drawColorI = 200;
		std::vector<std::string>		_blocks;
		std::vector<int>			_blocksColor;
		bool					_event;
	private:
		int setColor(std::string content, int index);
	};
}
