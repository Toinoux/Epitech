/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** MultiMenu
*/

#include <iostream>
#include "MultiMenu.hpp"

namespace bbm {
	MultiMenu::MultiMenu(irr::IrrlichtDevice *device, MyEventReceiver &event)
		: AScene(device, event),
		  _sceneManager(device->getSceneManager()),
		  _driver(device->getVideoDriver()),
		  _play(Animation(_sceneManager, "dist/play.x")),
		  _clic("sounds/clic.wav", Sound::SOUND)
	{
		_initScene();
		_device->setWindowCaption(L"Bomberman - Multi");
	}

	MultiMenu::~MultiMenu()
	{
		_sceneManager->clear();
	}

	void MultiMenu::_initScene()
	{
		irr::video::ITexture *sky = _driver->getTexture("dist/skybox.png");

		_sceneManager->addCameraSceneNode(0);
		_sceneManager->getActiveCamera()->bindTargetAndRotation(false);
		_sceneManager->addLightSceneNode(0, irr::core::vector3df(60, -20, 100), irr::video::SColorf(5.0f, 5.0f, 5.0f));
		_sceneManager->addLightSceneNode(0, irr::core::vector3df(0, 10, 30), irr::video::SColorf(5.0f, 5.0f, 5.0f));
		_sceneManager->addSkyBoxSceneNode(sky, sky, sky, sky, sky, sky);

		_play.loadAnimationMap(bbm::playAnimation);
		_play.getModel()->setScale(irr::core::vector3df(4, 4, 4));
		_play.addRotation(irr::core::vector3df(0, 90, 0));
		_play.addPosition(irr::core::vector3df(0, 5, 50));
		_play.setLoop(true);
		_play.play("MOVE");
	}

	int MultiMenu::_handleEvent()
	{
		if (_event.isKeyPressed(irr::KEY_RETURN))
			return 0;
		else if (_event.isKeyPressed(irr::KEY_ESCAPE))
			 return (42);
		return -1;
	}

	const std::string MultiMenu::_handleEnter(int idx)
	{
		if (idx == 0)
			return ("GAME");
		return "MAIN";
	}

	const std::string MultiMenu::run()
	{
		int ret;

		_driver->beginScene(true, true, irr::video::SColor(0, 255, 255, 255));
		ret = _handleEvent();
		if (ret != -1)
			return _handleEnter(ret);
		_sceneManager->drawAll();
		_driver->endScene();
		return "MULTI";
	}
}
