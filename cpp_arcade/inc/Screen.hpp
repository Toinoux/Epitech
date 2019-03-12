//
// EPITECH PROJECT, 2018
// Screen
// File description:
// Arcade Screen Class
//

#pragma once

#include <memory>
#include "IGraphic.hpp"

namespace arc {
	class Screen {
	public:
		void	draw() const;
		void	drawMap(const std::vector<Block> &,
			const arc::Vec2<size_t> &) const;
		void	setLayers(const blocksLayers &,
			const std::vector<Vec2<size_t>> &);
		void	setLib(std::shared_ptr<arc::IGraphic>);
	private:
		blocksLayers	_layers;
		std::vector<Vec2<size_t>> _mapsSizes;
		std::shared_ptr<arc::IGraphic>	_glib;
	};
}
