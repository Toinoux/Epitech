/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** GameMenu
*/

#pragma once

#include <irr/irrlicht.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>
#include <utility>
#include <functional>
#include "Graphics/Event.hpp"
#include "Graphics/MainMenu.hpp"
#include "Graphics/AScene.hpp"

/*
** Create EventReceiver
** Create device (OpenGL, VSync), 32 bits
** Load vector of Scene, and map with key
** Scene must return key of map
*/

using ptrAScene = std::unique_ptr<bbm::AScene>;

namespace bbm {
	class GameMenu {
		public:
			GameMenu();
			~GameMenu();
			int run();
		private:
			irr::IrrlichtDevice *_device;
			MyEventReceiver _event;
			std::string _actualScene;
			std::string _newScene;
			ptrAScene _scene;
			int _ai;
			std::unordered_map<std::string, std::function<void()> > _sceneMap;
	};
}
