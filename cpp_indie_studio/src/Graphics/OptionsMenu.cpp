/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** OptionsMenu
*/

#include <iostream>
#include "OptionsMenu.hpp"

namespace bbm {
	OptionsMenu::OptionsMenu(irr::IrrlichtDevice *device, MyEventReceiver &event)
		: AScene(device, event),
		  _sceneManager(device->getSceneManager()),
		  _driver(device->getVideoDriver()),
		  _volume(Animation(_sceneManager, "dist/audio.x")),
		  _slider(Animation(_sceneManager, "dist/slider.x")),
		  _plus(Animation(_sceneManager, "dist/plus.x")),
		  _minus(Animation(_sceneManager, "dist/moins.x")),
		  _idx(0),
		  _clic("sounds/clic.wav", Sound::SOUND)
	{
		_initScene();
		_device->setWindowCaption(L"Bomberman - Options");
	}

	OptionsMenu::~OptionsMenu()
	{
		_sceneManager->clear();
	}

	void OptionsMenu::_initScene()
	{
		irr::video::ITexture *sky = _driver->getTexture("dist/skybox.png");

		_sceneManager->addCameraSceneNode(0);
		_sceneManager->getActiveCamera()->bindTargetAndRotation(false);
		_sceneManager->addLightSceneNode(0, irr::core::vector3df(60, -20, 100), irr::video::SColorf(5.0f, 5.0f, 5.0f));
		_sceneManager->addLightSceneNode(0, irr::core::vector3df(0, 10, 30), irr::video::SColorf(5.0f, 5.0f, 5.0f));
		_sceneManager->addSkyBoxSceneNode(sky, sky, sky, sky, sky, sky);
		_volume.loadAnimationMap(bbm::playAnimation);
		_volume.getModel()->setScale(irr::core::vector3df(4, 4, 4));
		_volume.addRotation(irr::core::vector3df(0, 90, 0));
		_volume.addPosition(irr::core::vector3df(0, 5, 50));
		_volume.setLoop(true);
		_volume.play("MOVE");

		_slider.loadAnimationMap(bbm::sliderAnimation);
		_slider.getModel()->setScale(irr::core::vector3df(4, 4, 4));
		_slider.addRotation(irr::core::vector3df(0, 90, 0));
		_slider.addPosition(irr::core::vector3df(-10, -10, 50));
		_slider.setLoop(false);
		_slider.play("MOVE " + std::to_string(g_globalVolume) + "%");

		_plus.loadAnimationMap(bbm::plusAnimation);
		_plus.getModel()->setScale(irr::core::vector3df(4, 4, 4));
		_plus.addRotation(irr::core::vector3df(0, 90, 0));
		_plus.addPosition(irr::core::vector3df(40, -10, 50));
		_plus.setLoop(false);
		_plus.play("FIXE");

		_minus.loadAnimationMap(bbm::plusAnimation);
		_minus.getModel()->setScale(irr::core::vector3df(4, 4, 4));
		_minus.addRotation(irr::core::vector3df(0, 90, 0));
		_minus.addPosition(irr::core::vector3df(-40, -10, 50));
		_minus.setLoop(false);
		_minus.play("FIXE");
	}

	int OptionsMenu::_handleEvent()
	{
		if (_event.isKeyPressed(irr::KEY_LEFT)
		    || _event.isKeyPressed(irr::KEY_RIGHT)) {
			if (_event.isKeyDown(irr::KEY_LEFT)) {
				_slider.setFPS(-60);
				_slider.play("MOVE " + std::to_string(g_globalVolume) + "%");
				g_globalVolume -= (g_globalVolume > 0) ? 25 : 0;
				_minus.play("MOVE");
				_clic.play();
			} else {
				_slider.setFPS(60);
				g_globalVolume += 25;
				if (g_globalVolume > 100)
					g_globalVolume = 100;
				else
					_slider.play("MOVE " + std::to_string(g_globalVolume) + "%");
				_plus.play("MOVE");
				_clic.play();
			}
		} else if (_event.isKeyPressed(irr::KEY_ESCAPE)
			   || _event.isKeyPressed(irr::KEY_RETURN))
			return 42;
		return -1;
	}

	const std::string OptionsMenu::_handleEnter(int)
	{
		return "MAIN";
	}

	const std::string OptionsMenu::run()
	{
		int ret;

		_driver->beginScene(true, true, irr::video::SColor(0, 255, 255, 255));
		ret = _handleEvent();
		if (ret != -1)
			return _handleEnter(ret);
		_sceneManager->drawAll();
		_driver->endScene();
		return "OPTIONS";
	}
}
