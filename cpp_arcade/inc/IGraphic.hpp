/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Graphic interface header
*/

#pragma once

#include <string>
#include "Common.hpp"

namespace arc {
	class IGraphic {
	public:
		virtual ~IGraphic() = default;

		virtual void setup() = 0;

		virtual void clear() = 0;
		virtual void display() const = 0;
		virtual bool isWindowOpen() const = 0;

		virtual int createTexture(const std::string &) = 0;
		virtual void drawBlock(const arc::Block &,
					const arc::Vec2<size_t> &) const = 0;

		virtual bool pollEvent() = 0;

		virtual void drawText(const std::string &,
			const Vec2<float> &, const Vec2<size_t> &) = 0;

		virtual void setTextAttributes(size_t, size_t) = 0;

		virtual void closeWindow() = 0;
		virtual void destroy() = 0;

		virtual int getKeyCode() const = 0;
	};
}
