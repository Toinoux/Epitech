//
// EPITECH PROJECT, 2018
// getInstance
// File description:
// Return Class's Instance
//

#include <memory>
#include "ArcadeSnake.hpp"

extern "C" std::shared_ptr<arc::IGame> getGameInstance()
{
	std::shared_ptr<arc::IGame> instance(new arc::Snake);
	return (instance);
}
