#include <irr/irrlicht.h>
#include <iostream>
#include <vector>
#include "Graphics/Animation.hpp"
#include "Graphics/Event.hpp"
#include "Graphics/GameMenu.hpp"
#include <unistd.h>

int main(void)
{
	bbm::GameMenu menu;

	menu.run();

	return 0;
}