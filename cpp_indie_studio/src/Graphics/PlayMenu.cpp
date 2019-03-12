/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** PlayMenu
*/

#include <iostream>
#include "Graphics/PlayMenu.hpp"

namespace bbm {
	PlayMenu::PlayMenu(irr::IrrlichtDevice *device, MyEventReceiver &event)
		: AScene(device, event),
		_sceneManager(device->getSceneManager()),
		_driver(device->getVideoDriver()),
		_new(Animation(_sceneManager, "dist/new.x")),
		_load(Animation(_sceneManager, "dist/load.x")),
		_idx(0)
	{
		_initScene();
		_device->setWindowCaption(L"Bomberman - Play");
		_selectable.push_back(_new);
		_selectable.push_back(_load);
	}

	PlayMenu::~PlayMenu()
	{
		_sceneManager->clear();
	}

	void PlayMenu::_initScene()
	{
		irr::video::ITexture *sky = _driver->getTexture("dist/skybox.png");

		_sceneManager->addCameraSceneNode(0);
		_sceneManager->getActiveCamera()->bindTargetAndRotation(false);
		_sceneManager->addLightSceneNode(0, irr::core::vector3df(60, -20, 100), irr::video::SColorf(5.0f, 5.0f, 5.0f));
		_sceneManager->addLightSceneNode(0, irr::core::vector3df(0, 10, 30), irr::video::SColorf(5.0f, 5.0f, 5.0f));
		_sceneManager->addSkyBoxSceneNode(sky, sky, sky, sky, sky, sky);

		_new.loadAnimationMap(bbm::playAnimation);
		_new.getModel()->setScale(irr::core::vector3df(6, 6, 6));
		_new.addPosition(irr::core::vector3df(-5, -16, 50));
		_new.addRotation(irr::core::vector3df(0, 90, 0));
		_new.setLoop(true);
		_new.play("MOVE");

		_load.loadAnimationMap(bbm::playAnimation);
		_load.getModel()->setScale(irr::core::vector3df(6, 6, 6));
		_load.addPosition(irr::core::vector3df(-5, -40, 50));
		_load.addRotation(irr::core::vector3df(0, 90, 0));
		_load.setLoop(true);
	}

	int PlayMenu::_handleEvent()
	{
		if (_event.isKeyPressed(irr::KEY_DOWN)) {
			if (_selectable.size() - 1 == _idx)
				return -1;
			_selectable[_idx].reset();
			_idx = (_idx + 1) % _selectable.size();
			_selectable[_idx].play("MOVE");
		} else if (_event.isKeyPressed(irr::KEY_UP)) {
			if (_idx == 0)
				return -1;
			_selectable[_idx].reset();
			_idx = (_idx - 1) % _selectable.size();
			_selectable[_idx].play("MOVE");
		} else if (_event.isKeyPressed(irr::KEY_ESCAPE)) {
			return 42;
		}
		if (_event.isKeyPressed(irr::KEY_RETURN)) {
			return _idx;
		}
		return -1;
	}

	const std::string PlayMenu::_handleEnter(int idx)
	{
		if (idx == 0) {
			return "NEW";
		} else if (idx == 1) {
			return "LOAD";
		} else if (idx == 42)
			return "MAIN";
		return "PLAY";
	}

	const std::string PlayMenu::run()
	{
		int ret;

		_driver->beginScene(true, true, irr::video::SColor(0, 255, 255, 255));
		ret = _handleEvent();
		if (ret != -1)
			return _handleEnter(ret);
		_sceneManager->drawAll();
		_driver->endScene();
		return "PLAY";
	}
}