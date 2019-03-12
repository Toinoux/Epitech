/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** GameMenu
*/

#include "Graphics/LobbySolo.hpp"
#include "Graphics/OptionsMenu.hpp"
#include "Graphics/PlayMenu.hpp"
#include "Graphics/GameMenu.hpp"
#include "Graphics/GameRender.hpp"
#include "Graphics/MultiMenu.hpp"

namespace bbm {
	GameMenu::GameMenu() : _actualScene("MAIN"), _newScene("MAIN")
	{
		_device = irr::createDevice(irr::video::EDT_OPENGL,
					    irr::core::dimension2d<irr::u32>(1920,1080), 32, false,
					    false, true, &_event);
		_sceneMap["PLAY"] = [this]() { _scene.reset(); _scene.reset(new PlayMenu(_device, _event)); };
		_sceneMap["GAME"] = [this]() { _ai = dynamic_cast<LobbySolo &>(*_scene).getAI(); _scene.reset(); std::cout << "RENDER" << std::endl; _scene.reset(new GameRender(_device, _event, _ai)); };
		_sceneMap["NEW"] = [this]() { _scene.reset(); _scene.reset(new LobbySolo(_device, _event)); };
		_sceneMap["LOAD"] = [this]() { _scene.reset(); _scene.reset(new PlayMenu(_device, _event)); };
		_sceneMap["MULTI"] = [this]() { _scene.reset(); _scene.reset(new MainMenu(_device, _event)); };
		_sceneMap["MAIN"] = [this]() { _scene.reset(); _scene.reset(new MainMenu(_device, _event)); };
		_sceneMap["OPTIONS"] = [this]() { _scene.reset(); _scene.reset(new OptionsMenu(_device, _event)); };
		if (_sceneMap.find(_actualScene) == _sceneMap.end())
			throw std::runtime_error("Invalid call from menu");
		_sceneMap[_actualScene]();
	}

	GameMenu::~GameMenu()
	{
		_scene.reset();
		_device->drop();
	}

	int GameMenu::run()
	{
		while (_device->run()) {
			_newScene = _scene->run();
			if (_newScene == "EXIT")
				break;
			if (_newScene != _actualScene) {
				if (_sceneMap.find(_newScene) == _sceneMap.end())
					throw std::runtime_error("Invalid call from menu");
				_sceneMap[_newScene]();
				_actualScene = _newScene;
			}
		}
		return (0);
	}
}
