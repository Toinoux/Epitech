//
// EPITECH PROJECT, 2018
// Screen
// File description:
// Arcade Screen
//

#include "Screen.hpp"
#include <iostream>

void	arc::Screen::drawMap(const std::vector<Block> &blocks,
	const arc::Vec2<size_t> &mapSize) const
{
	for (size_t i = 0; i < blocks.size(); i++)
		_glib->drawBlock(blocks[i], mapSize);
}

void	arc::Screen::draw() const
{
	for (size_t i = 0; i < _layers.size(); i++) {
		drawMap(_layers[i], _mapsSizes[i]);
	}
}

void	arc::Screen::setLayers(const blocksLayers &layers,
			const std::vector<Vec2<size_t>> &mapsSizes)
{
	_layers = layers;
	_mapsSizes = mapsSizes;
}

void	arc::Screen::setLib(std::shared_ptr<IGraphic> glib)
{
	_glib = glib;
}
