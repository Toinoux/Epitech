//
// EPITECH PROJECT, 2018
// main
// File description:
// nothing
//

#include <stdlib.h>
#include <iostream>
#include <dlfcn.h>
#include "Error.hpp"
#include "Utilities.hpp"
#include "Arcade.hpp"
#include "IGame.hpp"

int	main(int ac, char const *av[])
{
	arc::Machine mch;

	if (ac != 2) {
		arc::Utilities::showUsage(av[0]);
		return (EXIT_FAIL);
	}
	try {
		mch.loadLib(av[1]);
		mch.loadLibs();
		mch.loadGames();
		mch.start();
	} catch (arc::ArcadeError &e) {
		std::cerr << e.what() << std::endl;
		return (EXIT_FAIL);
	}
	return (EXIT_SUCCESS);
}
