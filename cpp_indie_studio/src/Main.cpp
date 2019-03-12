//
// EPITECH PROJECT, 2018
// main
// File description:
// test
//

//#include <irr/irrlicht.h>
#include <iostream>

#include "Core/ICore.hpp"
#include "Core/CoreServer.hpp"
#include "Core/CoreClient.hpp"
#include "Core/CoreAI.hpp"
#include "Core/CorePlayer.hpp"

#include "IEntity.hpp"

#include "Object/AObject.hpp"
#include "Object/APowerUp/APowerUp.hpp"
#include "Object/AWall/AWall.hpp"

#include "Character/ACharacter.hpp"
#include "Character/AAI.hpp"
#include "Character/Player.hpp"

#include "Graphics/GameMenu.hpp"

#include "Parser.hpp"

#include "Threads/ThreadPool.hpp"

#include "Sound.hpp"

int bbm::g_globalVolume = 100;
std::string bbm::g_ip = "";
int bbm::g_port = 0;

int main(int ac, const char **av)
{
	bbm::Parser parser;

	parser.parsArgs(ac, av);
	bbm::g_port = parser.checkArgs("port") == bbm::NO_EXIST ?
		bbm::DEFAULT_PORT : parser.checkArgs("port");

	if (parser.checkArgs("server") == bbm::NO_VALUE) {
		try {
			bbm::CoreServer core(bbm::g_port, 4);

			core.run();
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			return 1;
		}
	} else {
		try {
			bbm::GameMenu menu;

			menu.run();
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			return 1;
		}
	}
	return 0;
}
