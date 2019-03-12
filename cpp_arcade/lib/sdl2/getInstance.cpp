//
// EPITECH PROJECT, 2018
// getInstance
// File description:
// Return Class's Instance
//

#include <memory>
#include "ArcadeSDL2.hpp"

extern "C" std::shared_ptr<arc::IGraphic> getGraphicInstance()
{
	std::shared_ptr<arc::IGraphic> instance(new arc::SDL2);
	return (instance);
}
