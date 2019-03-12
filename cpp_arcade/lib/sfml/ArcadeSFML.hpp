//
// EPITECH PROJECT, 2018
// ArcadeSFML
// File description:
// SFML Class
//

#pragma once

#include <typeinfo>
#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "IGraphic.hpp"

namespace arc {

	class SFML : public IGraphic {
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
		std::vector<sf::Texture *> _blocks;
		sf::RenderWindow *_wd;
		sf::Event _event;
		sf::Color _color;
		sf::Font _font;
	private:
		size_t _font_size;
		const size_t width = 1920;
		const size_t height = 1280;
	};
}
