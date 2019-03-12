/*
** EPITECH PROJECT, 2018
** client1
** File description:
** client2
*/

#include <iostream>
#include <string>
#include <exception>

#include "Core/CorePlayer.hpp"

int main(int ac, char *av[])
{
	try {
		std::string ip(av[1]);
		std::cout << ip << std::endl;
		bbm::CorePlayer player(42069, ip);

		player.run();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
