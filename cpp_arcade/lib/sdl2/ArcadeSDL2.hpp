//
// EPITECH PROJECT, 2018
// *
// File description:
// graphic class SDL2
//


#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "Error.hpp"
#include "IGraphic.hpp"

namespace arc
{
	constexpr char  font_path[] = "./fonts/arcade2.ttf";
	class SDL2 : public IGraphic
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
		SDL_Window			*_wd;
		SDL_Renderer			*_renderer;
		SDL_Event			_event;
		SDL_Color			_color;
		size_t				_font_size;
		TTF_Font			*_font;
		std::vector<SDL_Texture *>	_blocks;
	private:
		static constexpr size_t width = 960;
		static constexpr size_t height = 640;
		static constexpr size_t font_size = 20;
	};
}
