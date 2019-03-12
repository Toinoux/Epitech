//
// EPITECH PROJECT, 2018
// *
// File description:
// graphic class OpenGL
//


#pragma once

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Error.hpp"
#include "IGraphic.hpp"

namespace arc
{
	constexpr char  font_path[] = "arcade.ttf";
	class OpenGL : public IGraphic
	{
	public:
		void test() { std::cout << "OpenGL" << std::endl; }
		void setup() final;

		void clear() final;
		void display() const final;
		bool getWindowStatus() const final;
		static void glDisplay();

		int createBlock(const std::string &) final;
		void drawBlock(size_t, const Vec2 &, const Vec2 &) const final;

		void drawText(const std::string &,
			      const Vec2 &, size_t) final;

		void destroy() final;

		int getKeyCode() const final;
	private:
		bool				_quit;
		std::vector<std::string>	_blocks;
		TTF_Font			*_font;
		SDL_Window			*_wd;
		SDL_Renderer			*_renderer;
		SDL_GLContext			_glctx;
		SDL_Surface			*_sfont;
		GLuint				_font_texture;
	private:
		static constexpr size_t width = 640;
		static constexpr size_t height = 480;
		static constexpr size_t font_size = 20;
	};
}
